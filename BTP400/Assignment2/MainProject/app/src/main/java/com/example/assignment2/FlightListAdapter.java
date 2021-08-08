/**
 * Adapter class for flight result list.
 *
 * @author Khai Phan and Carlianz Pura (03/10/2020)
 */

package com.example.assignment2;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.recyclerview.widget.RecyclerView;

import org.jetbrains.annotations.NotNull;

import java.util.ArrayList;


public class FlightListAdapter extends RecyclerView.Adapter<FlightListAdapter.ViewHolder> {

    //ArrayList that stored the flights found in the database
    private ArrayList<Flight> flightQuotes;

    /**
     * default constructor
     * @param flightQuotes parse the flightQuotes found to the Flight Display
     */
    FlightListAdapter(ArrayList<Flight> flightQuotes) {  this.flightQuotes = flightQuotes;   }

    /**
     * create view type with a prepared format in flight_result_list.xml
     * @param parent hold the view
     * @param viewType declare a type
     * @return vewiHolder display
     */
    @NotNull
    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        LayoutInflater layoutInflater = LayoutInflater.from(parent.getContext());
        View listItem = layoutInflater.inflate(R.layout.flight_result_list, parent, false);
        return new ViewHolder(listItem);
    }

    /**
     * check for nunmber of flight found
     * @return number of flight qoutes
     */
    @Override
    public int getItemCount() {     return flightQuotes.size();     }

    /**
     * connect the view id in .xml with the attribute in .java for modifying
     */
    static class ViewHolder extends RecyclerView.ViewHolder {
        View view;
        TextView airline, source, destination, price, departure_time, return_time;

        ViewHolder(View itemView) {
            super(itemView);
            this.view = itemView;
            this.airline = itemView.findViewById(R.id.airline);
            this.source = itemView.findViewById(R.id.source);
            this.destination = itemView.findViewById(R.id.destination);
            this.price = itemView.findViewById(R.id.price);
            this.departure_time = itemView.findViewById(R.id.time);
            this.return_time = itemView.findViewById(R.id.return_time);
        }
    }

    /**
     * set data for each of the view area
     * @param holder hold the view
     * @param position position in the array
     */
    @Override
    public void onBindViewHolder(final ViewHolder holder, int position) {
        Flight flightQuote = flightQuotes.get(position);
        holder.airline.setText(flightQuote.CarrierName);
        holder.source.setText(flightQuote.origin);
        holder.destination.setText(flightQuote.destination);
        holder.departure_time.setText("Departure: "+ flightQuote.departureDate.replace("T", "  "));
        holder.return_time.setText("Return: "+ flightQuote.returnDate);
        holder.price.setText("$USD " + flightQuote.minPrice);
    }
}
