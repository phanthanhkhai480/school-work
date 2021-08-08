import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { SavedSearchPageRoutingModule } from './saved-search-routing.module';

import { SavedSearchPage } from './saved-search.page';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    SavedSearchPageRoutingModule
  ],
  declarations: [SavedSearchPage]
})
export class SavedSearchPageModule {}
