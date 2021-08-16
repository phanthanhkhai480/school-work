/**
 * Activity to implement Search Hotel feature.
 *
 * @author Khai Phan and Carlianz Pura (03/28/2020)
 */

package com.example.assignment2;

import android.app.DatePickerDialog;
import android.content.Intent;
import android.os.Bundle;
import android.os.StrictMode;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import java.text.SimpleDateFormat;
import java.util.Calendar;

public class HotelActivity extends AppCompatActivity {
    EditText destinationPlace, guests, checkIn, checkOut;
    TextView responseView;
    Button searchHotel, hotelLogout, hotelBack;
    ImageView img_btn1, img_btn2;
    EditText price_filter;
    SeekBar seekBar;
    Boolean out_bound;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_hotel);
        if (android.os.Build.VERSION.SDK_INT > 9)
        {
            StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
            StrictMode.setThreadPolicy(policy);
        }

        //assigning all EditText field to local attribute for any later modification
        destinationPlace = (EditText) findViewById(R.id.destinationPlace);
        guests = (EditText) findViewById(R.id.guests);
        checkIn = (EditText) findViewById(R.id.checkIn);
        checkOut = (EditText) findViewById(R.id.checkOut);
        responseView = (TextView) findViewById(R.id.responseView);
        searchHotel = (Button) findViewById(R.id.searchHotel);
        hotelLogout = (Button) findViewById(R.id.hotelLogout);
        hotelBack = (Button) findViewById(R.id.hotelBack);

        img_btn1 = findViewById(R.id.calendar_btn_1);
        img_btn2 = findViewById(R.id.calendar_btn_2);

        seekBar = findViewById(R.id.seekBar);
        price_filter = findViewById(R.id.price_filter);

        /*
          create a horizontal scroll bar to filter the price
         */
        seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                double price = progress*5;
                price_filter.setText(String.format("%.2f"                   , price));
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {            }
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
                myCalendar.set(Calendar.YEAR, year);
                myCalendar.set(Calendar.MONTH, monthOfYear);
                myCalendar.set(Calendar.DAY_OF_MONTH, dayOfMonth);
                SimpleDateFormat format1 = new SimpleDateFormat("yyyy-MM-dd");
                String date = format1.format(myCalendar.getTime());
                //String date = year + "-" + (String.format("%02", ))
                if(out_bound) checkIn.setText(date);
                else checkOut.setText(date);
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
                new DatePickerDialog(HotelActivity.this, date, myCalendar
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
                new DatePickerDialog(HotelActivity.this, date, myCalendar
                        .get(Calendar.YEAR), myCalendar.get(Calendar.MONTH),
                        myCalendar.get(Calendar.DAY_OF_MONTH)).show();
            }
        });

        /*
          log user out of the program
         */
        hotelLogout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(HotelActivity.this, MainActivity.class));
            }
        });

        /*
          move back to the prior activity
         */
        hotelBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });

        //Opens the HotelResult page and passes all inpuit value from user to HotelResult.
        searchHotel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(destinationPlace.getText().toString().equals("")){
                    Toast.makeText(HotelActivity.this, "", Toast.LENGTH_SHORT).show();
                }
                Intent intent = new Intent(HotelActivity.this, HotelResult.class);
                System.out.println("Destination here: "+destinationPlace.getText().toString());
                intent.putExtra("des", destinationPlace.getText().toString());
                intent.putExtra("checkIn", checkIn.getText().toString());
                intent.putExtra("checkout", checkOut.getText().toString());
                intent.putExtra("person", Integer.parseInt(guests.getText().toString()));
                intent.putExtra("star", 2);
                intent.putExtra("max_price", Double.parseDouble(price_filter.getText().toString()));
                startActivity(intent);
            }
        });
    }
}
