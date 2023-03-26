#ifndef _STATE_H_
#define _STATE_H_

#include <Arduino.h>
#include <cstdlib>
#include <iostream>

// see "st_func()" to know what each state actually means 
typedef enum class STATE{
  IDLE = 0,
  FORWARD,
  BACKWARD,
  CLOCKWISE,
  COUNTERCLOCKWISE,
  INITIALIZE
}ST;


class StateMachine{
public:
  StateMachine() : _currentState(ST::IDLE) {}

  void setState(ST state);


private:
  ST _currentState;

  void st_init(void); // initialize the motors to given angles
};

extern StateMachine puppy;

#endif