# BTR490 Group12

## 1. Team Member
| **Team Member**      | **Student Number** | **Skype**        | **GitHub**       | **Roles**                 |
| :--------------------| :------------------| :--------------- | :----------------| :-------------------------|
| Khai Thanh Phan      | 100901164          | phanthanh.khai   | phanthanhkhai480 |Lead Programmer            |
| Karanpreet Tatla     | 149251167          | karanpreet.tatla | ksinght15        |Database Programmer        |
| Karan Ubhi           | 132796160          | karandeep26      | KaranU26         |App UI Designer/programmer |


## 2. Software Requirement
- An *intermediate* level of **Java** for **UI/Layout designing**
- An *intermediate* level of **C++** for **Data Algorithms and Sorting**
- An *expert* level of **Database (SQL Oracle)** for **Information and Data Searching**


## 3. Business Description
When you are preparing for an upcoming vacation, there are so many things you have to take care of: flights booking, hotel reservation, method of transportation, and even the little things like what you need to bring in order to fit with the current weather and how to fit in with the culture. For years, the convenient thing to do was to buy travel packages from travel agencies, but those are often riddled with hidden fees and do not have much flexibilty. There have been many attempts made to simplify travelling. For example, agencies send out email confirmations but using just emails can be messy and time consuming. There are apps for travel agencies and airlines but those do not provide information about tickets or bookings purchased elsewhere. The solution to this is simple, a one stop app that provides information on everything you need for your next adventure.

We have a travel app (Android/IOS platform available and in the near future a website/computer app) that support travellers on their way to work/school/vacation by storing all the information and the itineraries in **ONE PLACE**. This app will be linked to your email, allowing it to get information from your email confirmations. This way, users do not have to be frustrated looking for confirmation emails or bookings. All they need to do is login in the app with the email they use for booking/reservation and it will extract the information from the email. In addition, we provide users with features such as:

  1. **Flight Information**: Stores all the flight(s) and automatically send a reminder 24 hours (or custom time) prior to departure time. This reminder will also notify the user if they have more than one flight occur in the next 48 hours so they can be prepare. The system will connect with Google to check the flight information in case of a delay or flight cancellation (this will occur 24 hours prior to the **check-in time**. During the 18 hours before the flight, it will check regularly every 2 hours and during the last 6 hours, it will check every 30 minutes). This way, users can trust the app and expect to be notified if anything changes. 
  
  2. **Hotel/Motel Information**: Similar to the flight information, the app stores all the bookings for hotel/motel and reminds the customer 24 hours prior to the check-in time (usually after 12 PM). The app will remind the customer 24 hours (or custom time) before booking. Since the check-in time for hotel/motel can be flexible, this features won't require much algorithms and coding steps. The app will also send another reminder to users 24 hours before their check-out time to kindly remind them the time they need to check-out without penalty.
  
  3. **Car/Transportation Rental**: The app will store all the information that customer will required in order to get their car at the destination such as the start and end date of the rental, the type of car, booking confirmation, etc., The app will also send another reminder to users 24 hours before their return time to kindly remind them the time they need to return the vehical without penalty (in situation where user rental any vehicle, if the user travel using another method of transportation, this will not work).

## 4. Additional Features
  - In addition to providing all the information you would need for travel, users would also be allowed to book flights, hotels, and rentals. By connecting with a third-party partner, we are allowed to direct our users to their website, and give them the best booking experience ever. With the list of the partners below, users can always trust us and make their booking with confidence: 

  1. **Flight Booking**: Kayak, Google Flights FlightHub and Expedia
  
  2. **Hotel/Motel Reservation**: Booking.com and Agoda
  
  3. **Car/Transportation Rental**: Kayak and Expedia
  
  - To enhance the customer's experience with their trip, we are looking to implement a rating system (a rating from 0 to 10) and a blog/review written by travellers, for travellers. Only travellers who have travelled to a certain destination are able to leave a review, this is monitored simply by checking the travellers history and location. For the rating, this feature is only available to users who have the app and have  at least one of their bookings in the app. For example, after a customer's trip, the app will ask for a rating and how they feel about the service as well as the experience in the trip. After that, we can ask if the users wouldn't mind spend a few minutes to write a short paragraph about their initerary. As more and more users use the rating system we will have a strong database which will attract potential users to download the app and use it to check out the rating system as well as the blog so they know where to go, what to avoid, what they need to do and how they can prepared ahead to match with the culture.
  
  - Another feature we provide to our users is to give you advice on what you need to bring based on weather, cultural standards and expectations, previous customer recommendations and reviews. For example, if you are travelling to India, the app may suggest to bring sunscreen, shorts (due to hot weather) and bug spray. 

## 5. Future Features
These are some of the features we are looking to implement in the future: 
  1. **Travel Package**: It is very common for users to book a complete travel package so they can enjoy a discount and to get everything prepared so they do not need to stress about specifics. However, when users book the packages, only one email with all the required information for the flight, hotel, transportation is sent. Our system is not yet ready to extract part of the information and know exactly where it should put to (ex: flights details to flight section).

## 6. UI Display
The main purpose of the app is to store every booking and reservation the user has in one place. It has to be easy, user friendly and usable to smartphone novices. In order to achieve that, we will sort the category in section (Flight, Hotel/Motel, Transportation,...) and when the user click on one of the section, it will display the information of that section only in details. What we will have is:

  1. **Flight**: *FlightInfo.pdf*
  
  2. **Hotel/Motel**: *HotelInfo.pdf*
  
  3. **Car/Transportation Rental**: *RentalInfo.pdf*

## Ignore for now
  - **Sim card/Wifi Router rental**: Most of the work we do requires an internet connection or even a phone call and it will be very inconvenient to not have access to that. To fulfill this demand, many companies have a package containing a portable router and a sim-card ready to be used anywhere. The router devices allows users to access unlimited high speed internet in the area and automatically switches to another provider when out of service/no coverage. However, this idea is newly introduced and not so many people seem to know about it. Because of this, we will contract with these companies to allow our users to obtain routers and the sim cards in advance (instead of taking time waiting) and give us the opportunity to offer the users a special price (cheaper than the companies, or with a special offer). This will save user lots of time since all the pre-filled information will be send to the contracted company and they will prepared everything and users just need to pick it up at the destination airport. **_Details about the procedure will be describe later_** <br/>
  
  - **Famous Attraction/Places**: When you travel to any destination, chances are you want to visit the attractions in that area. Many attractions give you a discounted price if you can take the advantage of online booking and get the ticket beforehand. We will work with the companies so we can give our users an opportunity to purchase tickets to every attraction all on one site and to also give us an opportunity to offer our users the exclusive price compared to at location ticket purchasing. **_Details about the procedure will be describe later_** <br/>
