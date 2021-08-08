import { Component, OnInit } from '@angular/core';
import { PizzaService } from '../pizza/pizza.service';
import { pizzaManager } from '../pizza/pizzaManager.model';
import { pizzaOrder } from '../pizza/pizzaOrder.model';

@Component({
  selector: 'app-previous-order',
  templateUrl: './previous-order.page.html',
  styleUrls: ['./previous-order.page.scss'],
})
export class PreviousOrderPage implements OnInit {

  private mOrderCollection: pizzaManager = new pizzaManager();
  private mPizzaCollection: pizzaOrder[] = [];
  constructor(private pizzasService: PizzaService) { }

  ngOnInit() {
    this.mOrderCollection = this.pizzasService.takeNewOrderCollection();
    this.mPizzaCollection = this.mOrderCollection.pizzaCollection;
  }

}
