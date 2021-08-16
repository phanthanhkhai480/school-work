import { Injectable } from '@angular/core';
import { Size } from './size.model';

@Injectable({
  providedIn: 'root'
})
export class SizeService {

  constructor() { }

  private mSize: Size[] = [
    { id: 'sm',
      size_:'Small'
    },
    { id: 'md',
      size_:'Medium'
    },
    { id: 'lg',
      size_:'Large'
    },
    { id: 'xl',
      size_:'X-Large'
    },
    { id: 'pt',
      size_:'Party'
    }, 
  ];

  getAllSizes() {
    return [...this.mSize];
  }

  getRecipe(sizeID){
    return {...this.mSize.find(
      size => { return size.id === sizeID; }
      )
    }
  }
}
