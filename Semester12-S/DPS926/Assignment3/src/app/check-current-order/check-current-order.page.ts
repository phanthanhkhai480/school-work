import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { AlertController } from '@ionic/angular';
import { Pizza } from '../pizza/pizza.model';
import { PizzaService } from '../pizza/pizza.service';
import { pizzaOrder } from '../pizza/pizzaOrder.model';

@Component({
  selector: 'app-check-current-order',
  templateUrl: './check-current-order.page.html',
  styleUrls: ['./check-current-order.page.scss'],
})
export class CheckCurrentOrderPage implements OnInit {

  mPizzaCollection: pizzaOrder;
  mPizza: Pizza = new Pizza();
  mOrderPizza: Pizza[] = [];
  mOrderAmount: number = 0;
  mOrderQuantity: number = 0;
  mTopping: string = "";
  mSize: string = "";
  mPrice: number = 0;
  mQuantity: number = 0;
  constructor(private pizzasService: PizzaService, 
    public alertController: AlertController,
    private route: Router) { }

  ngOnInit() {
    this.mPizzaCollection = this.pizzasService.takeNewPizzaCollection();
    this.mOrderPizza = this.mPizzaCollection.pizzaOrder_;
    this.showData();
  }
  
  showData(){
    if(this.mPizzaCollection.orderQuantity_ > 0){
      this.mOrderAmount = this.mPizzaCollection.orderTotal_;
      this.mOrderQuantity = this.mPizzaCollection.orderQuantity_;
    }
  }

  async delete(a){
    const alert = await this.alertController.create({
      header: 'Modify Order',
      message: 'Do you want to delete this item?',
      buttons: ['Cancel', {
        text: 'Agree',
        handler: () => {  
          this.pizzasService.removePizza(a);
          this.showData();  
          this.route.navigate(['/order-manager/check-current-order']);
        }
      }]
    });

    await alert.present();
  }

  submitOrder(){
    if(this.mOrderQuantity > 0){
      this.pizzasService.addNewOrder();
      this.route.navigate(['/order-manager']);
    }
  }
}
