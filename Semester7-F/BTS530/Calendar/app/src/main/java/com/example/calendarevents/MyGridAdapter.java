package com.example.calendarevents;

import android.content.Context;
import android.graphics.Color;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.Calendar;
import java.util.List;
import java.util.Locale;
import java.util.SimpleTimeZone;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

public class MyGridAdapter extends ArrayAdapter {

    List<Date> dates;
    Calendar currentDate;
    List<Events> events;
    LayoutInflater inflater;

    public MyGridAdapter(@NonNull Context context, List<Date> dates, Calendar currentDate, List<Events> events){
        super(context, R.layout.single_cell_layout);

        this.dates= dates;
        this.currentDate = currentDate;
        this.events = events;
        inflater = LayoutInflater.from(context);
    }

    @Nullable
    @Override
    public Object getItem(int position) {
        return dates.get(position);
    }

    @Override
    public int getPosition(@Nullable Object item) {
        return dates.indexOf(item);
    }

    @Override
    public int getCount() {
        return dates.size();
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        Date monthDate = dates.get(position);
        Calendar dateCalendar = Calendar.getInstance();
        dateCalendar.setTime(monthDate);
        int dayNo = dateCalendar.get(Calendar.DAY_OF_MONTH);
        int displayMonth = dateCalendar.get(Calendar.MONTH)+1;
        int displayYear = dateCalendar.get(Calendar.YEAR);
        int currentMonth = currentDate.get(Calendar.MONTH)+1;
        int currentYear = currentDate.get(Calendar.YEAR);


        View view = convertView;
        if(view == null)
        {
            view = inflater.inflate(R.layout.single_cell_layout, parent, false);
        }

        if(displayMonth == currentMonth && displayYear == currentYear)
        {
            view.setBackgroundColor(getContext().getResources().getColor(R.color.green));
        }
        else
        {
            view.setBackgroundColor(Color.parseColor("#cccccc"));
        }

        TextView dayNumber = view.findViewById(R.id.calendar_day);
        TextView EventNumber = view.findViewById(R.id.events_id);
        dayNumber.setText(String.valueOf(dayNo));
        Calendar eventCalendar = Calendar.getInstance();
        ArrayList<String> arrayList = new ArrayList<>();
        for (int i  = 0; i < events.size(); i++)
        {
            eventCalendar.setTime(convertStringToDate(events.get(i).getDATE()));
            if(dayNo == eventCalendar.get(Calendar.DAY_OF_MONTH) && displayMonth == eventCalendar.get(Calendar.MONTH) +1
            && displayYear == eventCalendar.get(Calendar.YEAR))
            {
                arrayList.add(events.get(i).getEVENT());
                EventNumber.setText(arrayList.size()+ " Events");
            }

        }

        return view;
    }

    private Date convertStringToDate(String eventDate)
    {
        SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd", Locale.ENGLISH);
        Date date = null;
        try
        {
            date = format.parse(eventDate);
        }catch (ParseException e)
        {
            e.printStackTrace();
        }
        return date;
    }

}
