import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { FormGroup, FormControl, Validators } from '@angular/forms';
import { AlertController, PickerColumnOption, PickerController, PickerOptions } from '@ionic/angular';
import { DisplayCurrencyService } from '../flight-model/display-currency.service';
import { displayCurrency } from '../flight-model/displayCurrency.model';
import { FlightsearchService } from '../flight-result/flightsearch.service';

@Component({
  selector: 'app-one-way',
  templateUrl: './one-way.page.html',
  styleUrls: ['./one-way.page.scss'],
})
export class OneWayPage implements OnInit {
  form: FormGroup;
  depart_:string="";
  arrive_:string="";
  departDate_:string = new Date().toISOString();
  currency_:string="";
  currencies: displayCurrency[];

  constructor(
    private route: Router, 
    private alertController: AlertController,
    private flightSearch: FlightsearchService,
    private currencyService: DisplayCurrencyService) { }
  
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
      this.flightSearch.makeURL(this.depart_, this.arrive_, this.departDate_, "", this.currency_, false);
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
