package com.group12.logintest;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import org.jetbrains.annotations.NotNull;

import java.io.IOException;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class HotelActivity extends AppCompatActivity {
    EditText destinationPlace, guests, checkIn, checkOut;
    TextView responseView;
    Button searchHotel, hotelLogout, hotelBack;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_hotel);

        destinationPlace = (EditText) findViewById(R.id.destinationPlace);
        guests = (EditText) findViewById(R.id.guests);
        checkIn = (EditText) findViewById(R.id.checkIn);
        checkOut = (EditText) findViewById(R.id.checkOut);
        responseView = (TextView) findViewById(R.id.responseView);
        searchHotel = (Button) findViewById(R.id.searchHotel);
        hotelLogout = (Button) findViewById(R.id.hotelLogout);
        hotelBack = (Button) findViewById(R.id.hotelBack);

        hotelLogout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(HotelActivity.this, MainActivity.class));
            }
        });

        hotelBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });

        searchHotel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                validation(destinationPlace.getText().toString(), guests.getText().toString(),
                        checkIn.getText().toString(), checkOut.getText().toString());

            }
        });
    }

    private void validation(String destinationPlace, String guests, String checkIn, String checkOut)
    {
        OkHttpClient client = new OkHttpClient();
        /*
        url("https://test.api.amadeus.com/v2/shopping/hotel-offers?cityCode=" + destinationPlace +"&adults=" + guests +
                    "&radius=5&radiusUnit=KM&checkInDate=" + checkIn + "&checkOutDate=" + checkOut +
                    "&roomQuantity=1&paymentPolicy=NONE&includeClosed=false&bestRateOnly=true&view=FULL&sort=PRICE")
         //token info: https://test.api.amadeus.com/v1/security/oauth2/token/{access_token}
         */
        //REMEMBER: DATE FORMAT IS YYYY-MM-DD
        Request request = new Request.Builder()
                .url("https://test.api.amadeus.com/v1/security/oauth2/token/cokG7rah2ujfIWPdcXGJa4JoyzBBzhYq")
                .get()
                .addHeader("x-amadeus-host", "test.api.amadeus.com")
                //.addHeader("x-amadeus-key ", "cokG7rah2ujfIWPdcXGJa4JoyzBBzhYq")
                //.addHeader("x-amadeus-secret", "A2NniGw0hVsQHEyf")
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
                    final String myResponse1 = response.body().string();
                    HotelActivity.this.runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            responseView.setText(myResponse1);
                        }
                    });
                }
            }
        });
    }
}
