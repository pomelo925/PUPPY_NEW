#ifndef _SCRIPT_H_
#define _SCRIPT_H_

#include <state.h>

enum class SCR{
  TEST = 0,  // testing script
  WALK  // walk straight 
};


namespace SCRIPT{
/**
  @brief run script
  @param script select script in enum class SCR 
 **/
  void run(SCR script);  
}

#endif