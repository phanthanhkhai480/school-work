import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { AlertController } from '@ionic/angular';
import { QuoteManager } from '../flight-model/quoteManager.model';
import { StorageService } from '../storage.service';
import { FlightsearchService } from './flightsearch.service';

@Component({
  selector: 'app-flight-result',
  templateUrl: './flight-result.page.html',
  styleUrls: ['./flight-result.page.scss'],
})
export class FlightResultPage implements OnInit {
  carrier:string="N/A";
  currency:string=""
  price_quote:string="";
  origin:string="N/A";
  destination:string="N/A";
  departure:string="N/A";
  arrival:string="N/A";

  quoteManager: QuoteManager;

  constructor(private flightsearch: FlightsearchService,
              private storage: StorageService,
              private route: Router,
              private alertController: AlertController) { }

  ngOnInit() {
    this.quoteManager = this.flightsearch.getQuote();
    this.carrier = this.quoteManager.carrier;
    this.currency = this.quoteManager.currency_symbol;
    this.price_quote = this.quoteManager.quote_price;
    this.origin = this.quoteManager.place_origin;
    this.destination = this.quoteManager.place_destintion;
    this.departure = this.quoteManager.time_depart;
    if(this.quoteManager.time_return != "")
      this.arrival = this.quoteManager.time_return;
  }

  async save(){
    const alert = await this.alertController.create({
      header: 'Save Search',
      message: 'Do you want to save this search?',
      buttons: ['Cancel', {
        text: 'Agree',
        handler: () => {
          this.storage.takeData(this.carrier, this.currency, this.price_quote, this.origin, this.destination, this.departure, this.arrival);
          this.route.navigate(['home']);
        }
      }]
    });

    await alert.present();
  }
}
