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
    public partial class Flight : ContentPage
    {
        FlightSearchObject fso = new FlightSearchObject();
        string currency_ = "";

        public Flight() {
            InitializeComponent();
            setDate();
        }

        private void setDate() {
            //set selection range for dates
            depart_date.MinimumDate = DateTime.Now;
            depart_date.MaximumDate = DateTime.Now.AddYears(2);
        }

        async private void go_back(object sender, EventArgs e) {
            await Navigation.PopModalAsync();
        }

        async private void flight_search(object sender, EventArgs e)
        {
            if (origin.Text == null || destination.Text == null || depart_date.Date.ToString() == null) {
                _ = DisplayAlert("Warning", "Field is missing or airport code is wrong", "OK");
            }
            else {
                fso = new FlightSearchObject(origin.Text, destination.Text, depart_date, currency_);
                await Navigation.PushModalAsync(new FlightSearch(fso));
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