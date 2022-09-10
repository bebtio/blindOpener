#include <Arduino.h>
#include <HardwareSerial.h>

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

  State currentState;
  State previousState;
  
  MainStateMachine() : 
  currentState( INIT_STATE ), 
  previousState( INIT_STATE ) 
  {}

  void setState( State state )
  {
    previousState = currentState;
    currentState = state;
  }

  void initState();
  void idleState();
  void decodeState();
  void sleepState();
  
private:

};
