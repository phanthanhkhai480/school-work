using System;
using Assignment2.FlightModel;
using System.Collections.ObjectModel;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Assignment2
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class FlightHistory : ContentPage
    {
        DBManager dbModel = new DBManager();
        ObservableCollection<QuoteManager> allQuotes;

        public FlightHistory()
        {
            InitializeComponent();
        }

        protected async override void OnAppearing()
        {
            allQuotes = await dbModel.CreateTable();
            result_history.ItemsSource = allQuotes;
            base.OnAppearing();
        }

        public void deleteFromDB(object sender, EventArgs e)
        {
            var deleteQuote = (sender as MenuItem).CommandParameter as QuoteManager;
            allQuotes.Remove(deleteQuote);
            dbModel.deleteQuote(deleteQuote);
        }

        //public async void updateDB(object sender, EventArgs e)
        //{
        //    var updateQuote = result_history.SelectedItem as QuoteManager;
        //    var updatedTask = await TaskManager.InputBox(this.Navigation, updateQuote);
        //    if (updatedTask != null)
        //    {
        //        dbModel.updateQuote(updatedTask);
        //    }
        //}

        async private void go_back(object sender, EventArgs e)
        {
            _ = await Navigation.PopModalAsync();
        }
    }
}