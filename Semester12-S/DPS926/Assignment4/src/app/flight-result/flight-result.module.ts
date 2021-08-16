import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';
import { IonicModule } from '@ionic/angular';
import { FlightResultPageRoutingModule } from './flight-result-routing.module';
import { FlightResultPage } from './flight-result.page';
import { HttpClientModule } from '@angular/common/http';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    HttpClientModule,
    FlightResultPageRoutingModule
  ],
  declarations: [FlightResultPage]
})
export class FlightResultPageModule {}
