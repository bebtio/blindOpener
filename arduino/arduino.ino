
//***************************************//
// Author:  Alberto Heras
// Date:    10 September 2022
// Purpose: 
//***************************************//

#include "mainStateMachine.hpp"


//***************************************//
// Declare the MainStateMachine variable.
// This controls everything that happens.
//***************************************//
MainStateMachine mainState;

//***************************************//
// Don't use set up. We are going to handle all the setup in the
// INIT_STATE in the loop.
//***************************************//
void setup()
{

}

//***************************************//
// The main loop where everything happens.
//***************************************//
void loop()
{
    // Main state machine goes here.
    switch( mainState.getCurrentState() )
    {
        case( MainStateMachine::INIT_STATE                   ): mainState.initState();                  break;
        case( MainStateMachine::IDLE_STATE                   ): mainState.idleState();                  break;
        case( MainStateMachine::DECODE_STATE                 ): mainState.decodeState();                break;
        case( MainStateMachine::MOTOR_CLOCKWISE_STATE        ): mainState.motorClockwiseState();        break;
        case( MainStateMachine::MOTOR_COUNTERCLOCKWISE_STATE ): mainState.motorCounterClockwiseState(); break;
        case( MainStateMachine::SLEEP_STATE                  ): mainState.sleepState();                 break;
    }
}

//***************************************//
