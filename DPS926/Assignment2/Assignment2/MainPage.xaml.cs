using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace Assignment2
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
        }

        async private void Flight_Booking(object sender, EventArgs e)
        {
            string action = await DisplayActionSheet("Flight Booking", "Cancel", null, "One-way Ticket", "Return Ticket", "Saved History");
            if (action == "One-way Ticket") {
                await Navigation.PushModalAsync(new Flight());
            }
            else if (action == "Return Ticket") {
                await Navigation.PushModalAsync(new FlightReturn());
            }
            else if (action == "Saved History")
            {
                await Navigation.PushModalAsync(new FlightHistory());
            }
        }

        private void Hotel_Booking(object sender, EventArgs e)
        {
            _ = DisplayAlert("Warning", "This features will be available soon. Stay tunes for upcoming updates", "OK");
        }
    }
}
