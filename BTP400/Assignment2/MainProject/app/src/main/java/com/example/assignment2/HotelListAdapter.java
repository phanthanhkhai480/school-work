/**
 * Adapter class for hotel result list.
 *
 * @author Khai Phan and Carlianz Pura (03/24/2020)
 */

package com.example.assignment2;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class HotelListAdapter extends RecyclerView.Adapter<HotelListAdapter.ViewHolder> {
    //ArrayList that stored the hotel found in the database
    ArrayList<Hotel> hotels;

    /**
     * default constructor
     * @param hotels parse the hotel found to the Hotel Display
     */
    HotelListAdapter(ArrayList<Hotel> hotels) {
        this.hotels = hotels;
    }

    /**
     * create view type with a prepared format in hotel_result_list.xml
     * @param parent hold the view
     * @param viewType declare a view type
     * @return viewHolder display
     */
    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        LayoutInflater layoutInflater = LayoutInflater.from(parent.getContext());
        View listItem = layoutInflater.inflate(R.layout.hotel_result_list, parent, false);
        ViewHolder viewHolder = new ViewHolder(listItem);
        return viewHolder;
    }

    /**
     * check for number of hotel found
     * @return size of hotel found
     */
    @Override
    public int getItemCount() {
        return hotels.size();
    }

    /**
     * connect the view id in .xml with the attribute in .java for modifying
     */
    static class ViewHolder extends RecyclerView.ViewHolder {
        View view;
        TextView hotelName, address, date, price, adults;

        ViewHolder(View itemView) {
            super(itemView);
            this.view = itemView;
            this.hotelName = itemView.findViewById(R.id.hotelName);
            this.address = itemView.findViewById(R.id.address);
            this.date = itemView.findViewById(R.id.time);
            this.price = itemView.findViewById(R.id.price);
            this.adults = itemView.findViewById(R.id.adults);
        }
    }

    /**
     * set data for each of the view area
     * @param holder hold the view
     * @param position position in the array
     */
    @Override
    public void onBindViewHolder(final ViewHolder holder, int position) {
        Hotel hotel = hotels.get(position);
        holder.hotelName.setText(hotel.getHotelName());
        holder.address.setText(hotel.getAddress());
        holder.date.setText(hotel.getDate());
        holder.price.setText(" Starting $" + String.format("%.2f", hotel.getPrice()) + "/night");
        holder.adults.setText("For "+ hotel.getPerson()+" person");
    }

}