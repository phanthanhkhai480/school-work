import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { FlightResultPage } from './flight-result.page';

const routes: Routes = [
  {
    path: '',
    component: FlightResultPage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class FlightResultPageRoutingModule {}
