package com.group12.logintest;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import org.jetbrains.annotations.NotNull;

import java.io.IOException;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class FlightActivity extends AppCompatActivity {

    EditText originPlace, destinationPlace, outboundDate, inboundDate;
    TextView responseView;
    Button searchButton, flightLogout, flightBack;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_flight);

        originPlace = (EditText) findViewById(R.id.originPlace);
        destinationPlace = (EditText) findViewById(R.id.destinationPlace);
        outboundDate = (EditText) findViewById(R.id.outboundDate);
        inboundDate = (EditText) findViewById(R.id.inboundDate);
        responseView = (TextView) findViewById(R.id.responseView);
        searchButton = (Button) findViewById(R.id.searchFlight);

        flightLogout = (Button) findViewById(R.id.flightLogout);
        flightBack = (Button) findViewById(R.id.flightBack);

        flightLogout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(FlightActivity.this, MainActivity.class));
            }
        });

        flightBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });


        searchButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                validation(originPlace.getText().toString(), destinationPlace.getText().toString(),
                        outboundDate.getText().toString(), inboundDate.getText().toString());

            }
        });
    }


    private void validation(String origin, String destination, String outbound, String inbound)
    {
        OkHttpClient client = new OkHttpClient();

        //"https://skyscanner-skyscanner-flight-search-v1.p.rapidapi.com/apiservices/browsequotes/v1.0/US/USD/en-US/" +
        //                                "{{origin}}/{{destination}}/{{outbound}}?inboundpartialdate={{inbound}}"
        //"https://skyscanner-skyscanner-flight-search-v1.p.rapidapi.com/apiservices/browsequotes/v1.0/US/USD/en-US/"+
        //                                origin+"/"+destination+"/"+outbound+"?inboundpartialdate="+inbound
        //"https://skyscanner-skyscanner-flight-search-v1.p.rapidapi.com/apiservices/browsequotes/v1.0/US/USD/en-US/SFO/JFK/2019-11-01?inboundpartialdate=2019-11-01"

        //REMEMBER: DATE FORMAT IS YYYY-MM-DD
        Request request = new Request.Builder()
                .url("https://skyscanner-skyscanner-flight-search-v1.p.rapidapi.com/apiservices/browsequotes/v1.0/US/USD/en-US/"+
                        origin+"/"+destination+"/"+outbound+"?inboundpartialdate="+inbound)
                .get()
                .addHeader("x-rapidapi-host", "skyscanner-skyscanner-flight-search-v1.p.rapidapi.com")
                .addHeader("x-rapidapi-key", "2c0dfd5706msh1c85a0bcf50792bp1260a5jsn149de2afa234")
                .build();

        try{
            Response response = client.newCall(request).execute();
        }catch (Exception e) {
            Log.e("ERROR", e.getMessage(), e);
        }

        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(@NotNull Call call, @NotNull IOException e) {
                e.printStackTrace();
                responseView.setText("ERROR");
            }

            @Override
            public void onResponse(@NotNull Call call, @NotNull Response response) throws IOException {
                if (response.isSuccessful()) {
                    final String myReponse = response.body().string();
                    FlightActivity.this.runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            responseView.setText(myReponse);
                        }
                    });
                }
            }
        });
    }
}

