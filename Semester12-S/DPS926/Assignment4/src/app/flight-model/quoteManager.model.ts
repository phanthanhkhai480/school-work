export class QuoteManager{
    carrier: string;
    quote_price: string;
    currency_symbol: string;
    place_origin: string;
    place_destintion: string;
    time_depart: string;
    time_return: string;

    constructor(mCarrier:string, mQuote:string, mCurrency:string, mOrigin:string, mDestination:string, mDepart:string, mReturn:string){
        this.carrier = mCarrier;
        this.quote_price = mQuote;
        this.currency_symbol = mCurrency;
        this.place_origin = mOrigin;
        this.place_destintion = mDestination;
        this.time_depart = mDepart;
        this.time_return = mReturn;
    }
}