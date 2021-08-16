import { pizzaOrder } from "./pizzaOrder.model";

//collection of all order
export class pizzaManager {
    pizzaCollection: pizzaOrder[];

    constructor(){
        this.pizzaCollection = [];
    }
}
    