import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Carrier } from '../flight-model/carrier.model';
import { Currency } from '../flight-model/currency.model';
import { Place } from '../flight-model/place.model';
import { Quote } from '@angular/compiler';
import { map } from 'rxjs/operators';
import { QuoteManager } from '../flight-model/quoteManager.model';

@Injectable({
  providedIn: 'root'
})
export class FlightsearchService {
  url:string="";
  mQuote_: Quote[] = [];
  mCarrier_: Carrier[] = [];
  mPlace_: Place[] = [];
  mCurrency_: Currency[] = [];
  quoteManager: QuoteManager;
  temp:number;;

  constructor(private http:HttpClient) { }

  makeURL(origin:string, destination:string, departureDate:string, returnDate:string, currency:string, returned:boolean){
    this.url = "https://skyscanner-skyscanner-flight-search-v1.p.rapidapi.com/apiservices/browsequotes/v1.0/US/" + 
      currency + "/en-US/" + origin + "/" + destination + "/" + departureDate;
    if(returned){  this.url += "?inboundpartialdate=" + returnDate;  }
    console.log(this.url);
    this.setQuote(origin, destination, departureDate, returnDate, currency);
    this.getCarrier(this.url);
  }

  setQuote(origin:string, destination:string, departureDate:string, returnDate:string, currency:string){    
    this.temp = this.randomInteger(100,1000)
    this.quoteManager = new QuoteManager("Air Canada", this.temp.toString(), currency, origin, destination, departureDate, returnDate);
  }
  getQuote(){ return this.quoteManager; }


  getCarrier(url_:string){   
    fetch(url_, {
      "method": "GET",
      "headers": {
        'x-rapidapi-key': '2c0dfd5706msh1c85a0bcf50792bp1260a5jsn149de2afa234',
        'x-rapidapi-host': 'skyscanner-skyscanner-flight-search-v1.p.rapidapi.com'
	  }
    }).then(response => {
      console.log(response);
    })
    .catch(err => {
      console.error(err);
    });
  }

  randomInteger(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
  }
}
