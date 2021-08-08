using Assignment2.FlightModel;
using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Threading.Tasks;
using Newtonsoft.Json;
using System.Linq;
using System.Collections.ObjectModel;

namespace Assignment2
{
    public class FlightManager
    {
        QuoteManager qm = new QuoteManager();
        public ObservableCollection<QuoteManager> quoteManager = new ObservableCollection<QuoteManager>();
        public List<Quote> mQuote { get; set; }
        public List<Carrier> mCarrier { get; set; }
        public List<Place> mPlace { get; set; }
        public List<Currency> mCurrency { get; set; }

        public FlightManager() { }
       
        public async Task<List<Carrier>> GetCarrier(string url_)
        {
            HttpClient clientCarrier = new HttpClient();
            HttpRequestMessage requestCarrier = new HttpRequestMessage
            {
                Method = HttpMethod.Get,
                RequestUri = new Uri(url_),
                Headers =
                {
                    { "x-rapidapi-key", "2c0dfd5706msh1c85a0bcf50792bp1260a5jsn149de2afa234" },
                    { "x-rapidapi-host", "skyscanner-skyscanner-flight-search-v1.p.rapidapi.com" },
                },
            };
            using (var response = await clientCarrier.SendAsync(requestCarrier))
            {
                if (response.IsSuccessStatusCode)
                {
                    //fetch json object response
                    var body = await response.Content.ReadAsStringAsync();
                    //make json object more human readable
                    var dic = JsonConvert.DeserializeObject<Dictionary<string, object>>(body);
                    //extract json object at certain location
                    var carriers_ = dic.ElementAt(1).Value;
                    //return result as function required.
                    mCarrier = JsonConvert.DeserializeObject<List<Carrier>>(carriers_.ToString());
                }
                else
                    mCarrier = new List<Carrier>();
            }
            return mCarrier;
        }
        public async Task<List<Place>> GetPlace(string url_)
        {
            HttpClient clientPlace = new HttpClient();
            HttpRequestMessage requestPlace = new HttpRequestMessage
            {
                Method = HttpMethod.Get,
                RequestUri = new Uri(url_),
                Headers =
                {
                    { "x-rapidapi-key", "2c0dfd5706msh1c85a0bcf50792bp1260a5jsn149de2afa234" },
                    { "x-rapidapi-host", "skyscanner-skyscanner-flight-search-v1.p.rapidapi.com" },
                },
            };
            using (var response = await clientPlace.SendAsync(requestPlace))
            {
                if (response.IsSuccessStatusCode)
                {
                    //fetch json object response
                    var body = await response.Content.ReadAsStringAsync();
                    //make json object more human readable
                    var dic = JsonConvert.DeserializeObject<Dictionary<string, object>>(body);
                    //extract json object at certain location
                    var places_ = dic.ElementAt(2).Value;
                    //return result as function required.
                    mPlace = JsonConvert.DeserializeObject<List<Place>>(places_.ToString());
                }
                else
                    mPlace = new List<Place>();
            }
            return mPlace;
        }
        public async Task<List<Currency>> GetCurrency(string url_)
        {
            HttpClient clientCurrency = new HttpClient();
            HttpRequestMessage requestCurrency = new HttpRequestMessage
            {
                Method = HttpMethod.Get,
                RequestUri = new Uri(url_),
                Headers =
                {
                    { "x-rapidapi-key", "2c0dfd5706msh1c85a0bcf50792bp1260a5jsn149de2afa234" },
                    { "x-rapidapi-host", "skyscanner-skyscanner-flight-search-v1.p.rapidapi.com" },
                },
            };
            using (var response = await clientCurrency.SendAsync(requestCurrency))
            {
                if (response.IsSuccessStatusCode)
                {
                    //fetch json object response
                    var body = await response.Content.ReadAsStringAsync();
                    //make json object more human readable
                    var dic = JsonConvert.DeserializeObject<Dictionary<string, object>>(body);
                    //extract json object at certain location
                    var currencies_ = dic.ElementAt(3).Value;
                    //return result as function required.
                    mCurrency = JsonConvert.DeserializeObject<List<Currency>>(currencies_.ToString());
                }
                else
                    mCurrency = new List<Currency>();
            }
            return mCurrency;
        }
        public async Task<List<Quote>> GetQuote(string url_)
        {
            HttpClient clientQuote = new HttpClient();
            HttpRequestMessage requestQuote = new HttpRequestMessage
            {
                Method = HttpMethod.Get,
                RequestUri = new Uri(url_),
                Headers =
                {
                    { "x-rapidapi-key", "2c0dfd5706msh1c85a0bcf50792bp1260a5jsn149de2afa234" },
                    { "x-rapidapi-host", "skyscanner-skyscanner-flight-search-v1.p.rapidapi.com" },
                },
            };
            using (var response = await clientQuote.SendAsync(requestQuote))
            {
                if (response.IsSuccessStatusCode)
                {
                    //fetch json object response
                    var body = await response.Content.ReadAsStringAsync();
                    //make json object more human readable
                    var dic = JsonConvert.DeserializeObject<Dictionary<string, object>>(body);
                    //extract json object at certain location
                    var quotes = dic.ElementAt(0).Value;
                    //return result as function required.
                    mQuote = JsonConvert.DeserializeObject<List<Quote>>(quotes.ToString());
                }
                else
                    mQuote = new List<Quote>();
            }
            return mQuote;
        }

        public ObservableCollection<QuoteManager> Matching() {
            if (mQuote.Count() > 0)
            {
                string carrier_ = "", origin_ = "", departure_ = "", depart_time = "", return_time = "";
                for (int a = 0; a < mQuote.Count(); a++)
                {
                    for (int b = 0; b < mPlace.Count(); b++)
                    {
                        if (mQuote[a].OutboundLeg.OriginId == mPlace[b].PlaceId)
                        {
                            origin_ = mPlace[b].Name.ToString();
                        }
                        if (mQuote[a].OutboundLeg.DestinationId == mPlace[b].PlaceId)
                        {
                            departure_ = mPlace[b].Name.ToString();
                        }
                    }
                    for (int c = 0; c < mCarrier.Count(); c++)
                    {
                        for (int d = 0; d < mQuote[a].OutboundLeg.CarrierIds.Count(); d++)
                        {
                            if (mQuote[a].OutboundLeg.CarrierIds[d] == mCarrier[c].CarrierId)
                            {
                                carrier_ = mCarrier[c].Name.ToString();
                            }
                        }
                    }
                    if (mQuote[a].OutboundLeg != null)
                    {
                        string temp_time = String.Format("{0:dddd, MMM dd yyyy, hh:mm tt}", mQuote[a].OutboundLeg.DepartureDate);
                        depart_time = temp_time;
                    }
                    if (mQuote[a].InboundLeg != null)
                    {
                        string temp_time = String.Format("{0:dddd, MMM dd yyyy, hh:mm tt}", mQuote[a].InboundLeg.DepartureDate);
                        return_time = temp_time;
                    }

                    string price_ = mQuote[a].MinPrice.ToString();
                    string currrency_symbol = mCurrency[0].Symbol.ToString();
                    qm = new QuoteManager(carrier_, price_, currrency_symbol, origin_, departure_, depart_time, return_time);
                    quoteManager.Add(qm);
                }
            }
            else
                quoteManager = new ObservableCollection<QuoteManager>();
            return quoteManager;
        }
    }
}
