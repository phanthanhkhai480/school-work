# Part 2: Reflection
### 1. Why is it important not to deallocate the Observer when detaching from this application? Does this apply in general? Why or Why not? 
- When an Observer is detaching from the application, it doesn’t mean the Observer is no longer wanting to be notified from the application. There might be a chance that Observer function are temporally detached to avoid any unwanted notification that it can manually update and synchronize itself later. Deallocate the Observer could remove the Observer entirely from the application which could cause some trouble to it when trying to re-attach or synchronize itself.  

### 2. GOF discusses how the Memento has a wide/narrow interface. Explain what is meant by this and how your implementation of the Memento pattern accomplishes this.
- Narrow Interface: the CareTaker class, which is UndoStack, can only pass the object of Memento into the Originator class, which is Timer to perform the restoration.
- UndoStack Code: ![alt text](https://github.com/seneca-btp600-w21/a4-a4-mhdiallo-kphan6-tunser/blob/main/images/UndoStack%20(CareTaker).PNG)
- Wide Interface: the Originator class, which is the Timer get the object from CareTaker class, extract the information and replace the current data to restore it into the previous state. 
- Timer Code: ![alt text](https://github.com/seneca-btp600-w21/a4-a4-mhdiallo-kphan6-tunser/blob/main/images/Timer%20(Originator).PNG)

### 3. Does your Memento store the same information as the Timer? Explain why each value stored was necessary for the restoration of the Timer to its former state.
- The Memento class only has the storedTime_ and the pausedStatus_ in place. Reason for using those is the most important information would be to retrieve the state of pausing and the time has been elapsed and replace what is currently in Timer. For starting time and stopping time, it is not as simple as taking the starting time and stopping and putting back as it will caused an error (because class Timer is using the current system time). 

### 4.Does our Timer being a Singleton prevent other Subjects/Observers from being created? Explain your answer.
- Yes. Right now, the default constructor has been moved into protected state and regards to Singleton definition, a method of Instance has been created to return the instance of Timer. 
