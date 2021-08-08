import { NgModule } from '@angular/core';
import { PreloadAllModules, RouterModule, Routes } from '@angular/router';

const routes: Routes = [
  {
    path: '',
    redirectTo: 'home',
    pathMatch: 'full'
  },
  {
    path: 'home',
    loadChildren: () => import('./home/home.module').then( m => m.HomePageModule)
  },
  {
    path: 'order-manager',
    children:[
      {
        path: '',
        loadChildren: () => import('./order-manager/order-manager.module').then( m => m.OrderManagerPageModule)
      },
      {
        path: 'check-current-order',
        loadChildren: () => import('./check-current-order/check-current-order.module').then( m => m.CheckCurrentOrderPageModule)
      },
      {
        path: 'previous-order',
        loadChildren: () => import('./previous-order/previous-order.module').then( m => m.PreviousOrderPageModule)
      },
    ]
  },
];

@NgModule({
  imports: [
    RouterModule.forRoot(routes, { preloadingStrategy: PreloadAllModules })
  ],
  exports: [RouterModule]
})
export class AppRoutingModule { }
