import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { AlertController } from '@ionic/angular';
import { Pizza } from '../pizza/pizza.model';
import { PizzaService } from '../pizza/pizza.service';
import { pizzaOrder } from '../pizza/pizzaOrder.model';

@Component({
  selector: 'app-order-manager',
  templateUrl: './order-manager.page.html',
  styleUrls: ['./order-manager.page.scss'],
})
export class OrderManagerPage implements OnInit {

  private mPizzaCollection: pizzaOrder = new pizzaOrder();
  constructor(private route: Router, 
    private pizzasService: PizzaService,
    public alertController: AlertController) { }

  ngOnInit() {
    this.mPizzaCollection = this.pizzasService.takeNewPizzaCollection();
  }

  async checkCurrentOrder(){
    if(this.mPizzaCollection.orderQuantity_ > 0){
      this.route.navigate(['/order-manager/check-current-order']);
    }
    else{
      const alert = await this.alertController.create({
        subHeader: 'Warning',
        message:  'Please add at least 1 pizza to cart',
        buttons: ['OK']
      });
      await alert.present();
    }
  }

  async updateCurrentOrder(){
    if(this.mPizzaCollection.orderQuantity_ > 0){
      this.route.navigate(['/home']);
    }
    else{
      const alert = await this.alertController.create({
        subHeader: 'Warning',
        message:  'Please add at least 1 pizza to cart',
        buttons: ['OK']
      });
      await alert.present();
    }
  }

  previousOrder(){
    this.route.navigate(['/order-manager/previous-order']);
  }

  newOrder(){
    this.pizzasService.clearOrder();
    this.route.navigate(['/home']);
  }
}
