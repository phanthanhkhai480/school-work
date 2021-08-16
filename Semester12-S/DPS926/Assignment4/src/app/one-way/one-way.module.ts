import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';
import { IonicModule } from '@ionic/angular';
import { OneWayPageRoutingModule } from './one-way-routing.module';
import { OneWayPage } from './one-way.page';
import { ReactiveFormsModule } from '@angular/forms';
import { HttpClientModule } from '@angular/common/http';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    ReactiveFormsModule,
    IonicModule,
    HttpClientModule,
    OneWayPageRoutingModule
  ],
  declarations: [OneWayPage]
})
export class OneWayPageModule {}
