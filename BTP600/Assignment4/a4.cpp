#include "a4.h"
#include <stdio.h>
#include <algorithm>
#include <iostream>

//Observer
Subject::Subject(){}
void Subject::attach(Observer* o){
    observers_.push_back(o);
}
void Subject::detach(const Observer* o){
    auto iterator = std::find(observers_.begin(), observers_.end(), o);
    
    if(iterator != observers_.end()){
        observers_.erase(iterator);
    }
}
void Subject::notify(){
    for(Observer* o:observers_){
        o->update();
    }
}

Stars::Stars(){
    time_ = 0;
}
void Stars::update(){
    time_ = (Timer::getInstance()->currtime() * 10)/10;
}
void Stars::print() const{
    for(int i = 0; i < time_; i++){
        printf("*");
    }
}

Seconds::Seconds(){
    time_ = 0;
}
void Seconds::update(){
    time_ = (Timer::getInstance()->currtime() * 10)/10;
}
void Seconds::print() const{
    printf("%d",time_);
}

Status::Status(){
    paused_ = true;
}
void Status::update(){
    paused_ = Timer::getInstance()->isPaused();
}
void Status::print() const{
    if(paused_)
        printf("paused");
    else
        printf("unpaused");
}



//Memento
Memento::Memento() {
    //elapsed time
    storedTime_ = (Timer::getInstance()->currtime() * 10) / 10;
    //paused status
    pausedStatus_ = Timer::getInstance()->isPaused();
}
Memento::~Memento() {}

void Memento::setPaused(bool paused) {  this->pausedStatus_ = paused;   }
bool Memento::getPaused()            {  return this->pausedStatus_;     }
void Memento::setTime(int time)      {  this->storedTime_ = time;       }
int Memento::getTime()               {  return this->storedTime_;       }



UndoStack::UndoStack(){}
void UndoStack::save(Memento* m){
    if (myStack.size() == 5)
    {
        myStack.pop_back();
        myStack.push_front(m);
    }
    else {
        myStack.push_front(m); 
    }
}
Memento* UndoStack::getMemento(){
    Memento* temp;
    temp = myStack.front();  
    myStack.pop_front();
    return temp;
}

Memento* Timer::createMemento(){
    createdMemento_ = new Memento();
    return createdMemento_;
}

void Timer::restoreFromMemento(Memento* m){

    /*this block of code gets the current time depending on platform
    .. you will need this to restore your timer */
    #if PLATFORM == WINDOWS
        clock_t curr=clock();
    #else
        struct timespec curr;
        clock_gettime(CLOCK_MONOTONIC_RAW, &curr);
    #endif
   
    createdMemento_ = m;

    this->starttime_ = curr;
    this->stoptime_ = curr;
    this->isstop_ = createdMemento_->getPaused();
    this->elapsedTime_ = createdMemento_->getTime();
}



//Singleton
Timer* Timer::getInstance(){
    if(instance_ == nullptr){
        instance_ = new Timer;
    }
    return instance_;
}
Timer* Timer::instance_ = nullptr;


/**************************************************************/
/*   Nothing below this comment should be modified            */
/**************************************************************/

/* Timer class functions.
  start();  starts the clock running from the current time
  currtime();  returns the current time
  stop();  stops the clock without reseting its value
  reset();  stops the clock and resets the timer to 0
  isPaused(); returns true if the timer is stopped, false otherwise
*/

Timer::Timer(){
    elapsedTime_=0;
    isstop_=true;

#if PLATFORM == WINDOWS
    starttime_=0;
    stoptime_=0;    
#else
    clock_gettime(CLOCK_MONOTONIC_RAW, &starttime_);
    stoptime_=starttime_;
#endif


}
void Timer::reset(){
#if PLATFORM == WINDOWS
    starttime_=0;
    stoptime_=0;    
#else
    clock_gettime(CLOCK_MONOTONIC_RAW, &starttime_);
    stoptime_=starttime_;
#endif
    elapsedTime_=0;
    isstop_=true;
}
void Timer::start(){
#if PLATFORM == WINDOWS
    clock_t curr=clock();
    if(isstop_){
        starttime_=(stoptime_==0)?curr:starttime_+(curr-stoptime_);
        isstop_=false;
    }
    else{
        starttime_=curr;   //its like hitting reset and start
    }
#else
    struct timespec curr;
    clock_gettime(CLOCK_MONOTONIC_RAW, &curr);
    if(isstop_){
        starttime_=curr;
        isstop_=false;
    }
    else{
        clock_gettime(CLOCK_MONOTONIC_RAW, &starttime_);
        stoptime_=starttime_;
        elapsedTime_=0;
    }
#endif

}
void Timer::stop(){
#if PLATFORM == WINDOWS
    stoptime_=clock();
#else
    clock_gettime(CLOCK_MONOTONIC_RAW, &stoptime_);
    elapsedTime_ += (stoptime_.tv_nsec - starttime_.tv_nsec) / 1000000000.0 + 
            (stoptime_.tv_sec  - starttime_.tv_sec);
#endif
    isstop_=true;
}
double Timer::currtime(){
    double rc;
#if PLATFORM == WINDOWS
    clock_t curr=clock();
    clock_t elapse=(isstop_)?stoptime_-starttime_:curr-starttime_;
    rc= double(elapse)/CLOCKS_PER_SEC;
#else
    struct timespec curr;
    clock_gettime(CLOCK_MONOTONIC_RAW,&curr);
    if(isstop_){
        rc=elapsedTime_;
    }
    else{
        rc=elapsedTime_ + (curr.tv_nsec - starttime_.tv_nsec) / 1000000000.0 + 
            (curr.tv_sec  - starttime_.tv_sec);
    }    
#endif
    return rc;
}
double Timer::starttime(){
#if PLATFORM == WINDOWS
    return (double)starttime_;
#else
    return starttime_.tv_nsec/ 1000000000.0 + starttime_.tv_sec;
#endif
}
bool Timer::isPaused(){
    return isstop_;
}
