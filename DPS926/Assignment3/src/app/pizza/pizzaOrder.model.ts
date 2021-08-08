import { Pizza } from "./pizza.model";
import { pizzaManager } from "./pizzaManager.model";

//collection of pizzas in 1 order
export class pizzaOrder{
    pizzaOrder_: Pizza[];
    orderQuantity_: number;
    orderTotal_: number;
    orderTime_: string;

    constructor(){
        this.pizzaOrder_ = [];
        this.orderQuantity_ = 0;
        this.orderTotal_ = 0;
        this.orderTime_ = "";
    }
}