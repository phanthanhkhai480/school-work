import { Injectable } from '@angular/core';
import { Pizza } from './pizza.model';
import { pizzaManager } from './pizzaManager.model';
import { pizzaOrder } from './pizzaOrder.model';

@Injectable({
  providedIn: 'root'
})
export class PizzaService {
  private mPizza: Pizza = new Pizza();
  private mPizzaCollection: pizzaOrder = new pizzaOrder();
  private mOrderCollection: pizzaManager = new pizzaManager();
  
  constructor() { }

  addNewPizza(mPizza_: Pizza) {
    this.mPizza = mPizza_;
    if(this.mPizza != null){
      this.mPizzaCollection.pizzaOrder_.push(this.mPizza);
      this.calculatePizza();
    }
  }

  calculatePizza(){
    this.mPizzaCollection.orderQuantity_ = 0;
    this.mPizzaCollection.orderTotal_ = 0;
    for(let a = 0; a < this.mPizzaCollection.pizzaOrder_.length; a++){
      this.mPizzaCollection.orderQuantity_ += this.mPizzaCollection.pizzaOrder_[a].quantity_;
      this.mPizzaCollection.orderTotal_ += this.mPizzaCollection.pizzaOrder_[a].price_;
    }
  }

  addNewOrder(){
    this.mPizzaCollection.orderTime_ = new Date().toString();
    this.mOrderCollection.pizzaCollection.push(this.mPizzaCollection);
    this.mPizzaCollection = new pizzaOrder();
  }

  removePizza(temp: Pizza){
    for(let a = 0; a < this.mPizzaCollection.pizzaOrder_.length; a++){
      if(temp.topping_ === this.mPizzaCollection.pizzaOrder_[a].topping_ &&
        temp.size_ === this.mPizzaCollection.pizzaOrder_[a].size_ &&
        temp.quantity_ === this.mPizzaCollection.pizzaOrder_[a].quantity_ &&
        temp.price_ === this.mPizzaCollection.pizzaOrder_[a].price_) {
          this.mPizzaCollection.pizzaOrder_.splice(a,1);    
          this.calculatePizza();
        }         
    }
  }

  clearOrder(){
    this.mPizzaCollection = new pizzaOrder();
  }

  takeNewPizza(){
    if(this.mPizza != null)
      return this.mPizza;
  }

  takeNewPizzaCollection(){
    if(this.mPizzaCollection != null)
      return this.mPizzaCollection;
  }

  takeNewOrderCollection(){
    if(this.mOrderCollection != null)
      return this.mOrderCollection;
  }

}
