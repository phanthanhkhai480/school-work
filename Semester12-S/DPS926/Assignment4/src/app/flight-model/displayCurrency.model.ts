export class displayCurrency{
    code_:string;
    fullName_: string;

    constructor (public id_: string,public currency_: string){
        this.code_ = id_;
        this.fullName_ = this.currency_;
    }
}