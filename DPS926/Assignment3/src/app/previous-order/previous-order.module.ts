import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { PreviousOrderPageRoutingModule } from './previous-order-routing.module';

import { PreviousOrderPage } from './previous-order.page';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    PreviousOrderPageRoutingModule
  ],
  declarations: [PreviousOrderPage]
})
export class PreviousOrderPageModule {}
