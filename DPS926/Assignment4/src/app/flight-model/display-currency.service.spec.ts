import { TestBed } from '@angular/core/testing';
import { DisplayCurrencyService } from './display-currency.service';

describe('DisplayCurrencyService', () => {
  let service: DisplayCurrencyService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(DisplayCurrencyService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
