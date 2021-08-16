import { Quote } from "@angular/compiler";
import { Carrier } from "./carrier.model";
import { Currency } from "./currency.model";
import { Place } from "./place.model";

export interface FlightManager{
    mQuote: Quote[],
    mCarrier: Carrier[],
    mPlace: Place[],
    mCurrency: Currency[]
}