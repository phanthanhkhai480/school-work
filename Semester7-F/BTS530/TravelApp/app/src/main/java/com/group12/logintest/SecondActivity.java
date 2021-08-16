package com.group12.logintest;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class SecondActivity extends AppCompatActivity {
    Button flight, hotel, trip, setting, logout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        flight = (Button) findViewById(R.id.flight);
        hotel = (Button) findViewById(R.id.hotel);
        trip = (Button) findViewById(R.id.trip);
        setting = (Button) findViewById(R.id.setting);
        logout = (Button) findViewById(R.id.logout);

        //trigger flight search screen
        flight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(SecondActivity.this, FlightActivity.class));
            }
        });

        //trigger Hotel search screen
        hotel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(SecondActivity.this, HotelActivity.class));
            }
        });

        //trigger Trip search screen
        trip.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(SecondActivity.this, TripActivity.class));
            }
        });

        //trigger Setting search screen
        setting.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(SecondActivity.this, SettingActivity.class));
            }
        });

        //trigger logout function to exit to login page
        logout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {   finish();   }
        });

    }

}
