using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Assignment2
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class FlightReturn : ContentPage
    {
        FlightSearchObject fso = new FlightSearchObject();
        string currency_ = "";
        public FlightReturn()
        {
            InitializeComponent();
            setDate();
        }

        private void setDate()
        {
            //set selection range for dates
            depart_date.MinimumDate = DateTime.Now;
            depart_date.MaximumDate = DateTime.Now.AddYears(2);

            //set selection range for dates
            return_date.MinimumDate = DateTime.Now;
            return_date.MaximumDate = DateTime.Now.AddYears(2);
        }

        async private void go_back(object sender, EventArgs e)
        {
            await Navigation.PopModalAsync();
        }

        async private void flight_search(object sender, EventArgs e)
        {
            if (origin.Text == null || destination.Text == null ||
                depart_date.Date.ToString() == null || return_date.Date.ToString() == null ||
                currency_ == null) {
                _ = DisplayAlert("Warning", "Field is missing or airport code is wrong", "OK");
            }
            else {
                if (DateTime.Compare(depart_date.Date, return_date.Date) > 0)
                    _ = DisplayAlert("Warning", "Return Date cannot be behind Departure Date", "OK");
                else {
                    fso = new FlightSearchObject(origin.Text, destination.Text, depart_date, currency_);
                    await Navigation.PushModalAsync(new FlightSearch(fso, return_date));
                }
            }
        }

        private void currency_SelectedIndexChanged(object sender, EventArgs e)
        {
            Picker picker = sender as Picker;
            var selectedItem = picker.SelectedItem;
            currency_ = selectedItem.ToString();
        }
    }
}