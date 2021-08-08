using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace Assignment2
{
    public class FlightSearchObject
    {
        public string mOrigin { get; set; }
        public string mDestination { get; set; }
        public DatePicker mDepart { get; set; }
        public string mCurrency { get; set; }


        public FlightSearchObject() { }

        public FlightSearchObject(string origin_, string destination_, DatePicker depart_, string currency_) {
            mOrigin = origin_;
            mDestination = destination_;
            mDepart = depart_;
            mCurrency = currency_;
        }
    }
}
