using SQLite;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;

namespace Assignment2.FlightModel
{
    public class QuoteManager : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        [PrimaryKey, AutoIncrement]
        public string carrier { get; set; }
        public string quote_price { get; set; }
        public string currency_symbol { get; set; }
        public string place_origin { get; set; }
        public string place_destination { get; set; }
        public string time_depart { get; set; }
        public string time_return { get; set; }

        public QuoteManager() { }

        public QuoteManager(string mCarrier, string mPrice, string mSymbol, 
            string mOrigin, string mDeparture, string mDepart, string mReturn) {
            carrier = mCarrier;
            quote_price = mPrice;
            currency_symbol = mSymbol;
            place_origin = mOrigin + " Airport";
            place_destination = mDeparture + " Airport";
            time_depart = mDepart;
            if (mReturn == "")
                time_return = "Unavailable details. Please check back later";
        }
    }
}
