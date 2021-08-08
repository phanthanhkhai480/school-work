/**
 * Activity to implement Search Flight feature.
 *
 * @author Khai Phan and Carlianz Pura (03/14/2020)
 */

package com.example.assignment2;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.app.DatePickerDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.SeekBar;

import org.jetbrains.annotations.NotNull;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class FlightActivity extends AppCompatActivity {

    EditText originPlace, destinationPlace, outboundDate, inboundDate, price_filter;
    RecyclerView responseView;
    Button searchButton, flightLogout, flightBack;
    ImageView img_btn1, img_btn2;
    Boolean out_bound;
    SeekBar seekBar;
    FlightListAdapter myListAdapter;
    ArrayList<Flight> flightArrayList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_flight);

        //assigning all EditText field to local attribute for any later modification
        originPlace = (EditText) findViewById(R.id.originPlace);
        destinationPlace = (EditText) findViewById(R.id.destinationPlace);
        outboundDate = (EditText) findViewById(R.id.outboundDate);
        inboundDate = (EditText) findViewById(R.id.inboundDate);
        responseView = (RecyclerView) findViewById(R.id.responseView);
        searchButton = (Button) findViewById(R.id.searchFlight);

        flightLogout = (Button) findViewById(R.id.flightLogout);
        flightBack = (Button) findViewById(R.id.flightBack);
        img_btn1 = findViewById(R.id.calendar_btn_1);
        img_btn2 = findViewById(R.id.calendar_btn_2);

        seekBar = findViewById(R.id.seekBar);
        price_filter = findViewById(R.id.price_filter);
        flightArrayList = new ArrayList<>();

        myListAdapter = new FlightListAdapter(flightArrayList);
        responseView.setAdapter(myListAdapter);
        responseView.setLayoutManager(new LinearLayoutManager(getApplicationContext()));

        /*
          logOut user
         */
        flightLogout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(FlightActivity.this, MainActivity.class));     }
        });

        /*
          move back to the prior activity
         */
        flightBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {   finish();   }
        });

        /*
          send input data to validation method to filter the result
         */
        searchButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                flightArrayList.clear();
                myListAdapter.notifyDataSetChanged();
                validation(originPlace.getText().toString(), destinationPlace.getText().toString(),
                        outboundDate.getText().toString(), inboundDate.getText().toString());
            }
        });

        /*
          create a horizontal scroll bar to filter the price
         */
        seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                double price = progress*20;
                price_filter.setText(String.format("%.2f", price));
            }
            @Override
            public void onStartTrackingTouch(SeekBar seekBar) { }
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) { }
        });
        seekBar.setProgress(50);

        /*
         * calendar method to pick date and assign the date to either outbound or inbound
         * outbound and inbound will be determined when the user click on the calendar icon
         */
        //create a Calendar object
        final Calendar myCalendar = Calendar.getInstance();
        final DatePickerDialog.OnDateSetListener date = new DatePickerDialog.OnDateSetListener() {
            @Override
            public void onDateSet(DatePicker view, int year, int monthOfYear,
                                  int dayOfMonth) {
                // TODO Auto-generated method stub
                //set Year view and take selected argument
                myCalendar.set(Calendar.YEAR, year);
                //set Month view and take selected argument
                myCalendar.set(Calendar.MONTH, monthOfYear);
                //set Date view and take selected argument
                myCalendar.set(Calendar.DAY_OF_MONTH, dayOfMonth);
                //select the format
                SimpleDateFormat format1 = new SimpleDateFormat("yyyy-MM-dd");
                //get the date into string and pass according to the outbound or inbound
                String date = format1.format(myCalendar.getTime());
                if(out_bound) outboundDate.setText(date);
                else inboundDate.setText(date);
            }
        };

        /*
         * outbound calendar date picker
         * trigger the DatePickerDialog to display the calendar and pick the date
         */
        img_btn1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                out_bound = true;
                new DatePickerDialog(FlightActivity.this, date, myCalendar
                        .get(Calendar.YEAR), myCalendar.get(Calendar.MONTH),
                        myCalendar.get(Calendar.DAY_OF_MONTH)).show();
            }
        });

        /*
         * inbound calendar date picker
         * trigger the DatePickerDialog to display the calendar and pick the date
         */
        img_btn2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                out_bound = false;
                new DatePickerDialog(FlightActivity.this, date, myCalendar
                        .get(Calendar.YEAR), myCalendar.get(Calendar.MONTH),
                        myCalendar.get(Calendar.DAY_OF_MONTH)).show();
            }
        });
    }

    //Calls skyscanner API to get flight result for the selected pair of cities.
    private void validation(final String origin, final String destination, String outbound, String inbound)
    {
        OkHttpClient client = new OkHttpClient();
        //create a request with arguments received from user to filter database
        //each API required a host server ID and unique key to access the database
        Request request = new Request.Builder()
                .url("https://skyscanner-skyscanner-flight-search-v1.p.rapidapi.com/apiservices/browsequotes/v1.0/US/USD/en-US/"+
                        origin+"/"+destination+"/"+outbound+"?inboundPartialDate="+inbound)
                .get().addHeader("x-rapidapi-host", "skyscanner-skyscanner-flight-search-v1.p.rapidapi.com")
                .addHeader("x-rapidapi-key", "a88960d2c3msh12cc97b5caad1e2p1783f4jsn5995f341503e").build();

        //get the response from the database
        try{
            Response response = client.newCall(request).execute();
            System.out.println("Response : "+response);
        }catch (Exception e) { Log.e("ERROR", e.getMessage(), e); }

        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(@NotNull Call call, @NotNull IOException e) { e.printStackTrace(); }

            @Override
            public void onResponse(@NotNull Call call, @NotNull Response response) throws IOException {
                if (response.isSuccessful()) {
                    final String myResponse = response.body().string();
                    FlightActivity.this.runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            System.out.println(myResponse);
                            getQuotesList(myResponse, origin, destination, seekBar.getProgress()*20.0);
                            myListAdapter.notifyDataSetChanged();
                        }
                    });
                }
            }
        });
    }

    //This method parses the json response and creates a list of flightQuote.
    private void getQuotesList(String myResponse, String origin, String dest, Double minPrice) {
        //create a hashmap to match the carrierID with carrierName
        HashMap<Integer, String> carrier_map = new HashMap<>();
        try {
            JSONObject mainObject = new JSONObject(myResponse);
            JSONArray quotesArray = mainObject.getJSONArray("Quotes");
            //create JSON array to store Carriers information
            JSONArray carriersArray = mainObject.getJSONArray("Carriers");
            //match the CarrierName with the CarrierID in the database
            for(int i = 0; i< carriersArray.length(); i++){
                JSONObject tempObj = carriersArray.getJSONObject(i);
                carrier_map.put(tempObj.getInt("CarrierId"),tempObj.getString("Name"));
            }

            Log.e("Total Flights results: ", String.valueOf(quotesArray.length()));

            //Iterates through JSON Array to parse JSON objects and add them to flightArrayList.
            for(int i = 0; i<quotesArray.length(); i++){
                JSONObject tempObject = quotesArray.getJSONObject(i);
                //only need to fetch outbound leg as the inbound will automatically detect later using the min_price comparison
                int carrier_id = tempObject.getJSONObject("OutboundLeg").
                        getJSONArray("CarrierIds").getInt(0);
                String carrier = carrier_map.get(carrier_id);
                String departureDate = tempObject.getJSONObject("OutboundLeg").
                        getString("DepartureDate").replace("00:00:00", "");
                Double min_price = tempObject.getDouble("MinPrice");
                Flight flight = new Flight(min_price, departureDate, origin, dest, carrier_id,
                        carrier, inboundDate.getText().toString());
                if(min_price <= minPrice) flightArrayList.add(flight);
            }

            //If no flights are found.
            if(flightArrayList.size() == 0)   { alert(); }

        } catch (JSONException e) {
            e.printStackTrace();
            alert();
        }
    }


    /**
     * alert method that pop-up when there is no found flight
     */
    private void alert() {
        AlertDialog.Builder alertDialog = new AlertDialog.Builder(FlightActivity.this);
        alertDialog.setTitle("No flight found for the destination.");
        alertDialog.setMessage("Please Try Again with different dates or destination.");
        alertDialog.setNeutralButton("Close", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
            }
        });
        alertDialog.show();
    }
}
