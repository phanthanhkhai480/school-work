/**
 * Model class for Hotel object.
 *
 * @author Khai Phan (03/17/2020)
 */

package com.example.assignment2;

import org.jetbrains.annotations.NotNull;

public class Hotel {

    private int id;
    private String hotelName;
    private Double price;
    private String address;
    private int person;
    private String date;

    /**
     * constructor that receive the parameter
     * @param id        receive the id of destination
     * @param name      receive the name of the hotel from the corresponding id
     * @param price     receive the price from database
     * @param address   receive the address of hotel registed in database
     * @param adults    receive the number of person want to stay
     * @param date      receive the date of staying
     */
    public Hotel(int id, String name, Double price, String address,
                 int adults, String date) {
        this.id = id;
        this.hotelName = name;
        this.price = price;
        this.address = address;
        this.person = adults;
        this.date = date;
    }

    @NotNull
    @Override
    /*
     * toString() method use to display information when an object is call.
     */
    public String toString() {
        return "Hotel{" +
                "id=" + id +
                ", hotelName='" + hotelName + '\'' +
                ", price=" + price +
                ", address='" + address + '\'' +
                '}';
    }

    //below are getter and setter for corresponding object
    public String getHotelName() {
        return hotelName;
    }

    public void setHotelName(String hotelName) {
        this.hotelName = hotelName;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setPrice(Double price) {
        this.price = price;
    }

    public int getPerson() {
        return person;
    }

    public void setPerson(int mPerson) {
        this.person = mPerson;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }


}