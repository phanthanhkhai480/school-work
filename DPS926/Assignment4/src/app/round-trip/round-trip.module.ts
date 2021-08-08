import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';
import { IonicModule } from '@ionic/angular';
import { RoundTripPageRoutingModule } from './round-trip-routing.module';
import { RoundTripPage } from './round-trip.page';
import { ReactiveFormsModule } from '@angular/forms';
import { HttpClientModule } from '@angular/common/http';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    ReactiveFormsModule,
    IonicModule,
    HttpClientModule,
    RoundTripPageRoutingModule
  ],
  declarations: [RoundTripPage]
})
export class RoundTripPageModule {}
