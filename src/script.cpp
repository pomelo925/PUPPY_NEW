#include <script.h>
#include <state.h>

void SCRIPT::run(SCR script){
  switch(script){
  // [SCRIPT] TEST
    case SCR::TEST:
      Serial.println("= [SCRIPT] TEST =");

      puppy.setState(ST::IDLE);
      puppy.setState(ST::INITIALIZE);
      break;

  // [SCRIPT] WALK
    case SCR::WALK:
      Serial.println("= [SCRIPT] WALK =");

      break;
  }
}



