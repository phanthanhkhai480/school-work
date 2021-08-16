import { Component } from '@angular/core';
import { Router } from '@angular/router';
import { AlertController } from '@ionic/angular';

@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage {

  constructor(
    public alertController: AlertController, 
    private route: Router) {}

  async flightSearch(){
    
    const alert = await this.alertController.create({
      header: 'Trip Selection',
      buttons: [
        {
          text: 'One-Way trip',
          handler: () => {
            this.route.navigate(['/one-way']);
          }
        }, {
          text: 'Round trip',
          handler: () => {
            this.route.navigate(['/round-trip']);
          }
        }, {
          text: 'Saved Search',
          handler: () => {
            this.route.navigate(['/saved-search'])
          }
        }
      ]
    });

    await alert.present();
  }

  async hotelSearch(){
    const alert = await this.alertController.create({
      cssClass: 'my-custom-class',
      header: 'This feature is under development',
      subHeader: 'Stay tunes for upcoming updates.',
      message: '',
      buttons: ['OK']
    });

    await alert.present();
  }
}

