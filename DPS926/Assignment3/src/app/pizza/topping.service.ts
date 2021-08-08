import { Injectable } from '@angular/core';
import { Topping } from './topping.model';

@Injectable({
  providedIn: 'root'
})
export class ToppingService {

  constructor() { }

  private mTopping: Topping[] = [
    { id: 'vegetable',
      topping_:'Vegetable'
    },
    { id: 'pepperoni',
      topping_:'Pepperoni'
    },
    { id: 'mushroom',
      topping_:'Mushroom'
    },
    { id: 'sausage',
      topping_:'Sausage'
    }, 
    { id: 'extracheese',
      topping_:'Extra Cheese'
    },  
  ];

  getAllTopping(){
    return[...this.mTopping];
  }
  
  getSizes(toppingID){
    return {...this.mTopping.find(
      topping => { return topping.id === toppingID; }
      )
    }
  }
}
