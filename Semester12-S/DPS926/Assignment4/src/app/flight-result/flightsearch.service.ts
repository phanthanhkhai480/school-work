import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Carrier } from '../flight-model/carrier.model';
import { Currency } from '../flight-model/currency.model';
import { Place } from '../flight-model/place.model';
import { Quote } from '@angular/compiler';
import { map } from 'rxjs/operators';
import { QuoteManager } from '../flight-model/quoteManager.model';
import { FlightManager } from '../flight-model/flightManager.model';

@Injectable({
  providedIn: 'root'
})
export class FlightsearchService {
  url:string="";
  flightManager: FlightManager;
  mCarrier: Carrier[] = [];
  quoteManager: QuoteManager;
  temp:number;

  //corsDecode: string;
  host:string;
  key:string;


  constructor(private http:HttpClient) { 
    //this.corsDecode = 'https://cors-bypas.herokuapp.com/';
    this.key = '2c0dfd5706msh1c85a0bcf50792bp1260a5jsn149de2afa234';
    this.host = 'skyscanner-skyscanner-flight-search-v1.p.rapidapi.com';
    //this.flightManager = new FlightManager();
  }

  makeURL(origin:string, destination:string, departureDate:string, returnDate:string, currency:string, returned:boolean){
    this.url = "https://skyscanner-skyscanner-flight-search-v1.p.rapidapi.com/apiservices/browsequotes/v1.0/US/" + 
      currency + "/en-US/" + origin + "/" + destination + "/" + departureDate;
    if(returned){  this.url += "?inboundpartialdate=" + returnDate;  }

    this.setQuote(origin, destination, departureDate, returnDate, currency);
    this.getCarrier(this.url);
  }

  setQuote(origin:string, destination:string, departureDate:string, returnDate:string, currency:string){    
    this.temp = this.randomInteger(100,1000)
    this.quoteManager = new QuoteManager("Air Canada", this.temp.toString(), currency, origin, destination, departureDate, returnDate);
  }
  getQuote(){ return this.quoteManager; }


  getCarrier(url_:string){   
    // let body = "";
    // const httpOptions = {
    //   headers: new HttpHeaders({
    //     'x-rapidapi-key': this.key,
    //     'x-rapidapi-host': this.host
    //   })
    // };

    // let temp = new Array<Carrier>();
    // return this.http.post<Carrier[]>(`${this.corsDecode}${url_}`, body, httpOptions).pipe(
    //   map(res => {
    //     console.log(res);
    //     temp = res;
    //     if(temp.length != 0){
    //       for(let a = 0; a < temp.length; a++){
    //         console.log(temp[a].Carrier);
    //       }
    //     }
    //     return temp;
    //   })
    // )
    
    fetch(url_, {
      "method": "GET",
      "headers": {
        'x-rapidapi-key': this.key,
        'x-rapidapi-host': this.host
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
