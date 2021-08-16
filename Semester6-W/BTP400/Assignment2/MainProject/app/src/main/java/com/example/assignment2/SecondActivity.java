/**
 * Activity to implement the second activity for the user to choose
 * between Flight or Hotel search.
 *
 * @author Carlianz Pura (03/07/2020)
 */

package com.example.assignment2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class SecondActivity extends AppCompatActivity {
    Button flight, hotel,logout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        //assigning all EditText field to local attribute for any later modification
        flight = (Button) findViewById(R.id.flight);
        hotel = (Button) findViewById(R.id.hotel);
        logout = (Button) findViewById(R.id.logout);

        /*
          move to FlightActivity
         */
        flight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(SecondActivity.this, FlightActivity.class));
            }
        });

        /*
          move to HotelActivity
         */
        hotel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(SecondActivity.this, HotelActivity.class));
            }
        });

        /*
          log user out of the program
         */
        logout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {   finish();   }
        });
    }
}
