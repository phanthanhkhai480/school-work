import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { SavedSearchPage } from './saved-search.page';

const routes: Routes = [
  {
    path: '',
    component: SavedSearchPage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class SavedSearchPageRoutingModule {}
