import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { displayCurrency } from './displayCurrency.model';
import { map } from 'rxjs/operators';

@Injectable({
  providedIn: 'root'
})
export class DisplayCurrencyService {
  url:string;
  constructor(private http: HttpClient) { }

  fetchCurrency(){
    this.url = 'https://openexchangerates.org/api/currencies.json';
    //console.log(this.url);  
    return this.http.get<{[key:string]: string}>(this.url).
    pipe(
      map(responseData => {
        const mCurrency_ = [];
        for (const item in responseData){
          mCurrency_.push(new displayCurrency(item, responseData[item]));
        }
        return mCurrency_;
      }) 
    );

    // return this.http.get<{[key:string]: displayCurrency}>(this.url).
    // pipe(
    //   map(responseData => {
    //     const mCurrency_ = [];
    //     for (const item in responseData){
    //       mCurrency_.push(new displayCurrency(responseData[item].id_, responseData[item].currency_));
    //     }
    //     return mCurrency_;
    //   }) 
    // );
  }
}
