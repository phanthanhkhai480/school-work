import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { AlertController } from '@ionic/angular';
import { QuoteManager } from '../flight-model/quoteManager.model';
import { StorageService } from '../storage.service';

@Component({
  selector: 'app-saved-search',
  templateUrl: './saved-search.page.html',
  styleUrls: ['./saved-search.page.scss'],
})
export class SavedSearchPage implements OnInit {
  allQuotes: QuoteManager[] = [];
  constructor(private storageService: StorageService,
              private alertController: AlertController) { }

  ngOnInit() {
    this.allQuotes = this.storageService.getAllTasks();
  }

  ionViewWillEnter(){
    this.allQuotes = this.storageService.getAllTasks();
  }


  async delete(quote){
    const alert = await this.alertController.create({
      header: 'Delete Saved',
      message: 'Do you want to delete this search?',
      buttons: ['Cancel', {
        text: 'Agree',
        handler: () => {
          this.storageService.deleteOneTask(quote);          
          this.allQuotes = this.storageService.getAllTasks();
        }
      }]
    }).then(alert => {
      alert.present();
    }); 
  }

  async deleteAll(){  
    const alert = await this.alertController.create({
      header: 'Delete All Saved',
      message: 'Do you want to delete all search?',
      buttons: ['Cancel', {
        text: 'Agree',
        handler: () => {
          this.storageService.deleteAllTasks();
          this.allQuotes = this.storageService.getAllTasks();
        }
      }]
    }).then(alert => {
      alert.present();
    });  
  }
}
