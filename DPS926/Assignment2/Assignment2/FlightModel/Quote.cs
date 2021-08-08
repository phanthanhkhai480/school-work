using System;
using System.Collections.Generic;
using System.Text;

namespace Assignment2.FlightModel
{
    public class OutboundLeg
    {
        public List<int> CarrierIds { get; set; }
        public int OriginId { get; set; }
        public int DestinationId { get; set; }
        public DateTime DepartureDate { get; set; }
    }

    public class InboundLeg
    {
        public List<int> CarrierIds { get; set; }
        public int OriginId { get; set; }
        public int DestinationId { get; set; }
        public DateTime DepartureDate { get; set; }
    }
    public class Quote
    {
        public int QuoteId { get; set; }
        public int MinPrice { get; set; }
        public bool Direct { get; set; }
        public OutboundLeg OutboundLeg { get; set; }
        public InboundLeg InboundLeg { get; set; }
        public DateTime QuoteDateTime { get; set; }

        public Quote() { }
    }
}
