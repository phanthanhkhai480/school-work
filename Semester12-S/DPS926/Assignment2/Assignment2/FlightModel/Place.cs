using System;
using System.Collections.Generic;
using System.Text;

namespace Assignment2.FlightModel
{
    public class Place
    {
        public string Name { get; set; }
        public string Type { get; set; }
        public int PlaceId { get; set; }
        public string IataCode { get; set; }
        public string SkyscannerCode { get; set; }
        public string CityName { get; set; }
        public string CityId { get; set; }
        public string CountryName { get; set; }

        public Place() { }
    }
}
