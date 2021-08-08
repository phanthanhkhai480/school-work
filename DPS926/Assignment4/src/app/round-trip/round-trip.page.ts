import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { FormGroup, FormControl, Validators } from '@angular/forms';
import { AlertController } from '@ionic/angular';
import { DisplayCurrencyService } from '../flight-model/display-currency.service';
import { displayCurrency } from '../flight-model/displayCurrency.model';
import { FlightsearchService } from '../flight-result/flightsearch.service';

@Component({
  selector: 'app-round-trip',
  templateUrl: './round-trip.page.html',
  styleUrls: ['./round-trip.page.scss'],
})
export class RoundTripPage implements OnInit {
  form: FormGroup;
  depart_:string="";
  arrive_:string="";
  departDate_:string = new Date().toISOString();
  returnDate_:string="";
  currency_:string="";
  currencies: displayCurrency[];

  constructor(
    private route: Router, 
    private alertController: AlertController,
    private flightSearch: FlightsearchService,
    private currencyService: DisplayCurrencyService ) { }
  
  ngOnInit(){
    this.currencyService.fetchCurrency().subscribe((temp) => {this.currencies = temp;})
    this.form = new FormGroup({
      departure : new FormControl(null, {
        updateOn: 'blur',
        validators: [Validators.required, Validators.minLength(3)]
      }),
      arrival : new FormControl(null, {
        updateOn : 'blur',
        validators: [Validators.required, Validators.minLength(3)]
      }),
      from : new FormControl(null, {
        updateOn: 'blur',
        validators : [Validators.required]
      }) ,
      to : new FormControl(null, {
        updateOn: 'blur',
        validators : [Validators.required]
      }),
      dollar : new FormControl(null, {
        updateOn: 'blur',
        validators : [Validators.required]
      })
    });
  }

  async onSubmitFlight(){
    console.log(this.form);
    if (this.form.invalid){
      const alert = await this.alertController.create({
        header: 'Error',
        message: 'Please check information details.',
        buttons: ['OK']
      });
      await alert.present();
    }
    else{
      this.departDate_ = this.formatDate(this.departDate_);
      this.returnDate_ = this.formatDate(this.returnDate_);
      this.flightSearch.makeURL(this.depart_, this.arrive_, this.departDate_, this.returnDate_, this.currency_, true);
      this.route.navigate(['/flight-result']);
    }
  }
  
  formatDate(date) {
    var d = new Date(date),
        month = '' + (d.getMonth() + 1),
        day = '' + d.getDate(),
        year = d.getFullYear();

    if (month.length < 2) month = '0' + month;
    if (day.length < 2) day = '0' + day;

    return [year, month, day].join('-');
  }

  selectChanged(selectedCurrency) { this.currency_ = selectedCurrency;  };
}
