
#include "programStates.hpp"


MainStateMachine mainState;

// Don't use set up. We are going to handle all the setup in the
// INIT_STATE in the loop.
void setup()
{

}


void loop()
{
    // Main state machine goes here.
    switch( mainState.getCurrentState() )
    {
        case( MainStateMachine::INIT_STATE  ) : mainState.initState();   break;
        case( MainStateMachine::IDLE_STATE  ) : mainState.idleState();   break;
        case( MainStateMachine::DECODE_STATE ): mainState.decodeState(); break;
    }
}
