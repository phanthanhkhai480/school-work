using Assignment2.FlightModel;
using System;
using System.Collections.ObjectModel;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Assignment2
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class FlightSearch : ContentPage
    {     
        public DatePicker mReturn { get; set; }
        public bool return_ { get; set; }
        public string url_ { get; set; }
        string departDate, returnDate;
        FlightManager flightManager_ = new FlightManager();
        FlightSearchObject fso = new FlightSearchObject();
        //DBManager dbModel = new DBManager();
        public ObservableCollection<QuoteManager> quoteManagers = new ObservableCollection<QuoteManager>();

        public FlightSearch() {
            InitializeComponent();
        }
        public FlightSearch(FlightSearchObject mFso) {
            InitializeComponent();
            fso = mFso;
            mReturn = null;
            return_ = false;
            makeURL();
        }
        public FlightSearch(FlightSearchObject mFso, DatePicker mReturn_) {
            InitializeComponent();
            fso = mFso;
            mReturn = mReturn_;
            return_ = true;
            makeURL();
        }
        public void makeURL(){
            departDate = String.Format("{0:yyyy-MM-dd}", fso.mDepart.Date);
            url_ = "https://skyscanner-skyscanner-flight-search-v1.p.rapidapi.com/apiservices/browsequotes/v1.0/US/" +
                        fso.mCurrency + "/en-US/" + fso.mOrigin + "/" + fso.mDestination + "/" + departDate;
            if (return_) {
                returnDate = String.Format("{0:yyyy-MM-dd}", mReturn.Date);
                url_ += "?inboundpartialdate=" + returnDate;
            }
            _ = warning1.Text = "Please Note: This is only mock data with an average estimated price only.";
            _ = warning2.Text = "Due to COVID-19. some flight are not available, therefore data will not be shown. If it takes more than 10 seconds to load result, consider doing another search.";
        }

        protected async override void OnAppearing() {
            _ = await flightManager_.GetCarrier(url_);
            _ = await flightManager_.GetPlace(url_);
            _ = await flightManager_.GetCurrency(url_);
            _ = await flightManager_.GetQuote(url_);
            quoteManagers = flightManager_.Matching();
            _ = result_display.ItemsSource = quoteManagers;
            result_display.BackgroundColor = Color.Orange;
            base.OnAppearing();
        }

        private void Add_DB(object sender, EventArgs e)
        {
            var mQuote = (sender as MenuItem).CommandParameter as QuoteManager;
            if (mQuote != null)
            {
                //dbModel.insertQuote(mQuote);
            }
        }

        async private void go_back(object sender, EventArgs e) {
            _ = await Navigation.PopModalAsync();
        }
    }
}