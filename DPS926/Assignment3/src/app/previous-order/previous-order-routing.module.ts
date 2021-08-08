import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { PreviousOrderPage } from './previous-order.page';

const routes: Routes = [
  {
    path: '',
    component: PreviousOrderPage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class PreviousOrderPageRoutingModule {}
