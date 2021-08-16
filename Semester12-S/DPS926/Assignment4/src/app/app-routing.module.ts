import { NgModule } from '@angular/core';
import { PreloadAllModules, RouterModule, Routes } from '@angular/router';

const routes: Routes = [
  {
    path: 'home',
    loadChildren: () => import('./home/home.module').then( m => m.HomePageModule)
  },
  {
    path: '',
    redirectTo: 'home',
    pathMatch: 'full'
  },
  {
    path: 'flight-result',
    loadChildren: () => import('./flight-result/flight-result.module').then( m => m.FlightResultPageModule)
  },
  {
    path: 'round-trip',
    loadChildren: () => import('./round-trip/round-trip.module').then( m => m.RoundTripPageModule)
  },
  {
    path: 'one-way',
    loadChildren: () => import('./one-way/one-way.module').then( m => m.OneWayPageModule)
  },
  {
    path: 'saved-search',
    loadChildren: () => import('./saved-search/saved-search.module').then( m => m.SavedSearchPageModule)
  },
];

@NgModule({
  imports: [
    RouterModule.forRoot(routes, { preloadingStrategy: PreloadAllModules })
  ],
  exports: [RouterModule]
})
export class AppRoutingModule { }
