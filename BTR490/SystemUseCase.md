Detail about use-case: **User checking information about particular details of an upcoming trip**

# System Use Case
### 1. Brief Description (scope)
  a. This use case describes the process of a user checking the information about their upcoming initerary of flight/living/transportation.

### 2. Actors (users)
  a. Travellers.
  b. Frequent Traveller.

### 3. Pre-Conditions
  a. User must have the app (downloaded from App Store).
  b. User must already have at least one of the bookings in any of the category in order to view.
  c. User must grant the authorization permission to the app so it can search for the data.

### 4. Basic Flow
  a. User download the app from the app store, wait for it to finish the installation
  b. Open the app, login to one of the email and give the app permission to retrieve the initerary information (1)
  c. The app retrieving the information (this process could take up to 10 minutes depends on the amount of emails)
  d. User select on one of the information section (Flights, Hotel, Transportation)
  e. The system will display information from the earliest possible day to the latest information it can retrieves. 
  f. **We have created a view for the app in each of the section**
  f. User can either take a screenshot, share to a friend,

### 5. Alternate and/or exception flows
  a. If travellers failed to login, the app will display an error message said the user is required to give the app permission to view email information to retrieve the information
  b. 

### 6. Post-conditions
  a. Travellers get to understand their upcoming trip
  b. Travellers take an idea of where they will going, where they will stay and how do they go from places to places.
