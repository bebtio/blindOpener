
#include "programStates.hpp"


enum State 
{
    _initState,
    _blinkState,
    _waitState,
    rotateCounterClockWiseState,
    roateClockwiseState
};

State currentState = _blinkState;

void setup()
{
  initState();
}

void loop()
{
    switch( currentState )
    {
        case( _initState ):
            // Do initialization stuff.
        break;

        case( _blinkState ):
          blinkState();
          currentState = _waitState;
        break;

        case( _waitState ):
          waitState();
          currentState = _blinkState;
        break;
    }
}
