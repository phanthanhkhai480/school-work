import { InboundLeg } from "./inbound.model";
import { OutboundLeg } from "./outbound.model";

export interface Quote{
    QuoteId: number,
    MinPrice: number,
    Direct: boolean,
    OutboundLeg: OutboundLeg,
    InboundLeg: InboundLeg,
    QuoteDateTime: Date
}