import { Injectable } from '@angular/core';
import { AlertController } from '@ionic/angular';
import { Storage } from '@ionic/Storage-angular';
import { QuoteManager } from './flight-model/quoteManager.model';

@Injectable({
  providedIn: 'root'
})
export class StorageService {
  private _storage: Storage | null = null;

  constructor(private storage: Storage,
              private alertController: AlertController) { 
    this.init();
  }

  async init(){
    const storage = await this.storage.create();
    this._storage = storage;
  }

  public takeData(carrier:string, currency:string, quote:string, 
    origin:string, destination:string, departureDate:string, returnDate:string){
    var temp1 = new QuoteManager(carrier, quote, currency, origin, destination, departureDate, returnDate);
    var key = carrier + quote + currency + origin + destination + departureDate + returnDate;
    this._storage?.set(key, temp1);
    this.logAllTasks();   
  }

  private logAllTasks(){
    console.log("All Tasks : ");
    this._storage.forEach((key, value, index) => {
      console.log(key, value, index);
    });
  }

  public getAllTasks(){
    var allQuotes: QuoteManager[] = [];
    if (this._storage != null){
    this._storage.forEach((value, key, index) => {
      allQuotes.push(value as QuoteManager);
    });
    }
    return allQuotes;
  }

  public async deleteAllTasks(){
    await this._storage.clear();
    this.logAllTasks();
  }

  public async deleteOneTask(task: QuoteManager){
    var key = task.carrier + task.quote_price + task.currency_symbol + task.place_origin + task.place_destintion + task.time_depart + task.time_return;
    await this._storage.remove(key);
    this.logAllTasks();
  }
}
