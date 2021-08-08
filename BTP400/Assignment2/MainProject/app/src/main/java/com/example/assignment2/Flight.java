/**
 * Model class for Flight object.
 *
 * @author Khai Phan (03/10/2020)
 */

package com.example.assignment2;

import org.jetbrains.annotations.NotNull;

//create a temporary template to display the information
public class Flight {
    double minPrice;
    String departureDate;
    String origin;
    String destination;
    private int carrierId;
    String CarrierName;
    String returnDate;

    /**
     * constructor that receive the parameter
     * @param minPrice      receive the price from database
     * @param departureDate receive the departure date entered by the user
     * @param origin        receive the origin place enter by user
     * @param destination   receive the destination place entered by user
     * @param carrierId     receive the airline ID from the database
     * @param carrierName   receive the airlines name from the database
     * @param returnDate    receive the return date entered by user
     */
    Flight(double minPrice, String departureDate, String origin, String destination,
           int carrierId, String carrierName, String returnDate) {
        this.minPrice = minPrice;
        this.departureDate = departureDate;
        this.origin = origin;
        this.destination = destination;
        this.carrierId = carrierId;
        CarrierName = carrierName;
        this.returnDate = returnDate;
    }

    @NotNull
    @Override
    /*
     * toString() method use to display information when an object is call.
     */
    public String toString() {
        return "Flight{" +
                "minPrice=" + minPrice +
                ", departureDate='" + departureDate + '\'' +
                ", returnDate='" + returnDate + '\'' +
                ", origin='" + origin + '\'' +
                ", destination='" + destination + '\'' +
                ", carrierId=" + carrierId +
                ", CarrierName='" + CarrierName + '\'' +
                '}';
    }
}
