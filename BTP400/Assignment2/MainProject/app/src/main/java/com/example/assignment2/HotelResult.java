/**
 * Activity to implement Search Hotel feature.
 *
 * @author Khai Phan and Carlianz Pura (03/17/2020)
 */

package com.example.assignment2;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.DialogInterface;
import android.os.Bundle;
import android.util.Log;

import org.jetbrains.annotations.NotNull;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.util.ArrayList;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class HotelResult extends AppCompatActivity {

    RecyclerView recyclerView;
    HotelListAdapter myHotelListAdapter;
    ArrayList<Hotel> hotels;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_hotel_result);
        recyclerView = findViewById(R.id.recycler_view);
        hotels = new ArrayList<>();

        //receive value from HotelActivity
        String destinationName = getIntent().getStringExtra("des");
        String checkIn = getIntent().getStringExtra("checkIn");
        String checkOut = getIntent().getStringExtra("checkout");
        int adults = getIntent().getIntExtra("person", 1);
        int star = getIntent().getIntExtra("star", 1);
        double max_price = getIntent().getDoubleExtra("max_price",100.00);

        System.out.println("destinationName:"+destinationName);

        myHotelListAdapter = new HotelListAdapter(hotels);
        recyclerView.setLayoutManager(new LinearLayoutManager(HotelResult.this));
        recyclerView.setAdapter(myHotelListAdapter);
        getPlaceId(destinationName,checkIn,checkOut,adults,star, max_price);

    }

    //Get place id from place name.
    private void getPlaceId(final String destinationName, final String checkInDate, final String checkoutDate,
                            final int adults, final int star, final double max_price){

        String url = "https://hotels4.p.rapidapi.com/locations/search?locale=en_US&query="+destinationName;
        //send the request with the url and host with key to the server to find the id of destination
        OkHttpClient client = new OkHttpClient();
        Request request = new Request.Builder()
                .url(url)
                .get()
                .addHeader("x-rapidapi-host", "hotels4.p.rapidapi.com")
                .addHeader("x-rapidapi-key", "c818638c80msh29cee8001e69163p137235jsn863205b7d988")
                .build();

        try{
            //check for the response from server
            Response response = client.newCall(request).execute();
            System.out.println("Response : "+response);
        }catch (Exception e) {
            Log.e("ERROR", e.getMessage(), e);
        }
        //establish a connection with the request string to the server
        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(@NotNull Call call, @NotNull IOException e) {
                e.printStackTrace();
            }

            @Override
            public void onResponse(@NotNull Call call, @NotNull Response response) throws IOException {
                //check the response state
                if (response.isSuccessful()) {
                    final String myResponse = response.body().string();
                    HotelResult.this.runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            System.out.println(myResponse);
                            int destinationId;
                            try {
                                JSONObject mainObject = new JSONObject(myResponse);
                                //get destination id from the server, if destination is not found, it will return 0
                                destinationId =((JSONObject)((JSONObject) mainObject.getJSONArray("suggestions").
                                        get(0)).getJSONArray("entities").get(0)).getInt("destinationId");
                                //Call the hotels4 API to get list of hotels for the required destinationId.
                                findHotels(destinationId, checkInDate,checkoutDate,adults,star, max_price);

                            } catch (JSONException e) {
                                e.printStackTrace();
                            }
                        }
                    });
                }
            }
        });

    }

    //Get list of hotels from hotels4 API. This methods calls the API and parses the JSON response to get list of hotels.
    private void findHotels(int destinationId, final String checkInDate, final String checkoutDate, final int adults, int star, final double max_price)  {
        String url = "https://hotels4.p.rapidapi.com/properties/list?currency=USD&starRatings="+ star + "%252C3&checkIn="+checkInDate+
                "&locale=en_US&checkOut="+checkoutDate+"&sortOrder=PRICE&destinationId="+destinationId+"&type=CITY&pageNumber=1&pageSize=100&adults1="+adults;

        OkHttpClient client = new OkHttpClient();
        Request request = new Request.Builder().url(url).get().addHeader("x-rapidapi-host", "hotels4.p.rapidapi.com")
                .addHeader("x-rapidapi-key", "c818638c80msh29cee8001e69163p137235jsn863205b7d988").build();
        try {
            //check for the response from server
            Response response = client.newCall(request).execute();
            System.out.println("Response : "+response);
        }catch (Exception e) {  Log.e("ERROR", e.getMessage(), e);  }
        //establish a connection with the request string to the server
        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(@NotNull Call call, @NotNull IOException e) {     e.printStackTrace();    }

            @Override
            public void onResponse(@NotNull Call call, @NotNull Response response) throws IOException {
                //check the response state
                if (response.isSuccessful()) {
                    final String myResponse = response.body().string();
                    HotelResult.this.runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            try {
                                //fetch result from server as JSON Object
                                JSONArray searchResults = new JSONObject(myResponse).getJSONObject("data").getJSONObject("body").
                                        getJSONObject("searchResults").getJSONArray("results");
                                //clear the old data if there is any old data
                                hotels.clear();
                                for(int i = 0; i<searchResults.length(); i++){
                                    try {
                                        //get the result from the JSON Object field
                                        JSONObject tempObj = searchResults.getJSONObject(i);
                                        int id = tempObj.getInt("id");
                                        String name = tempObj.getString("name");
                                        String address = tempObj.getJSONObject("address").getString("streetAddress");
                                        Double price = tempObj.getJSONObject("ratePlan").getJSONObject("price").getDouble("exactCurrent");
                                        Hotel hotel = new Hotel(id, name, price, address, adults, "From " + checkInDate + " to " + checkoutDate);
                                        //add hotel found to object hotel
                                        if(price<=max_price) hotels.add(hotel);
                                        myHotelListAdapter.notifyDataSetChanged();
                                    }catch (Exception e){e.printStackTrace();}
                                }
                                if(hotels.size() == 0) { alert(); }
                                System.out.println("###" + hotels.toString());
                            } catch (JSONException e) {
                                e.printStackTrace();
                                alert();
                            }
                        }
                    });
                }
            }
        });
    }

    /**
     * alert method that pop-up when there is no found hotel
     */
    private void alert() {
        AlertDialog.Builder alertDialog = new AlertDialog.Builder(HotelResult.this);
        alertDialog.setTitle("No room found in this city.");
        alertDialog.setMessage("Please Try Again with different dates");
        alertDialog.setNeutralButton("Close", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
            }
        });
        alertDialog.show();
    }
}
