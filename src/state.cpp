#include <cstdlib>
#include <iostream>

#include <state.h>
#include <pwm_server.h>
#include <global.h>
#include <kinematics.h>

StateMachine puppy;

void StateMachine::setState(ST state){
  switch(state){
    case ST::IDLE:
      Serial.println("(IDLE) Waiting ...\n");
      break;

    case ST::FORWARD:
      Serial.println("(FORWARD) Start Going Forward ...\n");
      break;

    case ST::BACKWARD:
      Serial.println("(BACKWARD) Start Going Backward ...\n");
      break;

    case ST::CLOCKWISE:
      Serial.println("(CLOCKWISE) Start Rotating Clockwise  ...\n");
      break;

    case ST::COUNTERCLOCKWISE:
      Serial.println("(COUNTERCLOCKWISE) Start Rotating Counterclockwise ...\n");
      break;
    
    case ST::INITIALIZE:
      Serial.println("(INITIALIZE) Start Initializing ...\n");
      st_init();
      break;
  }
};


void StateMachine::st_init(void){
  GLOB::init(); // update_Q_pos() 
  KINE::get_init(); // update_Ixyz() & update_EE()
  PWM::all_motor_init();
}


