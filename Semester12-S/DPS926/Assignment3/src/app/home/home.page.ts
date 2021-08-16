import { Component, OnInit } from '@angular/core';
import { Size } from '../pizza/size.model';
import { SizeService } from '../pizza/size.service';
import { Topping } from '../pizza/topping.model';
import { ToppingService } from '../pizza/topping.service';
import { AlertController } from '@ionic/angular';
import { Router } from '@angular/router';
import { Pizza } from '../pizza/pizza.model';
import { PizzaService } from '../pizza/pizza.service';

@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage implements OnInit{
  sizes : Size[];
  toppings : Topping[];
  //selectedQuantity : number = 0;

  mPizza: Pizza = null;
  mTopping: string = "";
  mSize: string = "";
  mQuantity: number = 0;
  mPrice: number = 0;
  mTotalPrice: number = 0;
  mOrderQuantity: number = 0;
  mTemp: Pizza = null;

  constructor(private sizesService: SizeService, 
    private toppingsService: ToppingService, 
    private pizzasService: PizzaService, 
    public alertController: AlertController, 
    private route: Router) {}

  ngOnInit(){
    this.sizes = this.sizesService.getAllSizes();
    this.toppings = this.toppingsService.getAllTopping();
  }

  quantity(value){
    this.mQuantity = value;
  }
  reset(){  
    this.mQuantity = 0;
    this.mSize = "";
    this.mTopping = "";
  }

  async add(){
    if(this.mQuantity > 0  && this.mTopping != "" && this.mSize != ""){    
      this.mTotalPrice = this.mQuantity * this.mPrice;
      this.mPizza = {
        topping_: this.mTopping,
        size_: this.mSize,
        price_: this.mTotalPrice,
        quantity_: this.mQuantity
      }
      this.pizzasService.addNewPizza(this.mPizza);
      this.mTemp = this.pizzasService.takeNewPizza();

      const alert = await this.alertController.create({
        subHeader: 'Total Price',
        message:  'Add successfully!!',
        buttons: ['OK']
      });
      await alert.present();
      this.reset();   
    }
    else{
      if(this.mTopping == ""){
        const alert = await this.alertController.create({
          subHeader: 'Warning',
          message:  'Please select your Topping',
          buttons: ['OK']
        });
        await alert.present();
      }
      if(this.mSize == ""){
        const alert = await this.alertController.create({
          subHeader: 'Warning',
          message:  'Please select your Size',
          buttons: ['OK']
        });
        await alert.present();
      }
      if(this.mQuantity == 0){
        const alert = await this.alertController.create({
          subHeader: 'Warning',
          message:  'Please choose a Quantity',
          buttons: ['OK']
        });
        await alert.present();
      }     
    }
  }

  OrderManager(){    this.route.navigate(['/order-manager']);  }
  toppingClicked(a){    this.mTopping = a.topping_;  }
  sizeClicked(b){
    this.mSize = b.size_;
    if(this.mSize.match('Small')){
      this.mPrice = 9.99;
    }
    else if(this.mSize.match('Medium')){
      this.mPrice = 11.99;
    }
    else if(this.mSize.match('Large')){
      this.mPrice = 13.99;
    }
    else if(this.mSize.match('X-Large')){
      this.mPrice = 15.99;
    }
    else if(this.mSize.match('Party')){
      this.mPrice = 17.99;
    }
  }
}
  
