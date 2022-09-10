#ifndef PROGRAMSTATES_HPP
#define PROGRAMSTATES_HPP

#include <Arduino.h>
#include <HardwareSerial.h>
#include "irRemoteButtonDefines.hpp"

// The main functions that do the operations for each of the defined states.



// The state machine that holds information about the current and previous state.
// Defines states in its own namespace.
class MainStateMachine
{

public:

  // The state enum.
  enum State 
  {
      INIT_STATE,
      IDLE_STATE,
      DECODE_STATE,
      SLEEP_STATE
  };

  
  MainStateMachine() : 
  currentState( INIT_STATE ), 
  previousState( INIT_STATE ) 
  {}

  // Set state makes it easy to update both the current and previous state.
  void setState( State state )
  {
    previousState = currentState;
    currentState = state;
  }

  // Getters
  State getCurrentState()  { return( currentState );  }
  State getPreviousState() { return( previousState ); }

  // State functions
  void initState();
  void idleState();
  void decodeState();
  void sleepState();
  
private:

  // Holds currentState and previous state in case
  // we have special jumps depending on previous state.
  State currentState;
  State previousState;

};


#endif
