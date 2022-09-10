
#include "programStates.hpp"


MainStateMachine mainState;


void setup()
{

}

void loop()
{
    switch( mainState.currentState )
    {
        case( MainStateMachine::INIT_STATE  ): mainState.initState();  break;
        case( MainStateMachine::IDLE_STATE  ): mainState.idleState();  break;
        case( MainStateMachine::BLINK_STATE ): mainState.blinkState(); break;
    }
}
