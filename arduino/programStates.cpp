
#include "programStates.hpp"

//************************************************************//
// initState- initializes the digital inputs for the IR receiver.
//
//
//************************************************************//
void MainStateMachine::initState()
{
    // Set serial output for debugging.
    Serial.begin(9600);

    // Set pin labeled D2 as an input.
    pinMode( 2 ,INPUT );

    pinMode( LED_BUILTIN, OUTPUT );
    setState( MainStateMachine::IDLE_STATE );
    Serial.println("In INIT_STATE");
}

//************************************************************//
// idleState - waits for IR receiver to receive an input signal.
//
//
//************************************************************//
void MainStateMachine::idleState()
{
    Serial.println("In IDLE_STATE");
    int pinRead = digitalRead(2);
    Serial.println(pinRead);

    // Pin gets pulled low by the IR receiver?
    // Yes the IR sensor is active low, meaning it outputs 5V
    // when it detects nothing and drops when it detects something.
    if( pinRead == LOW )
    {
        setState( MainStateMachine::BLINK_STATE );
    }
}

//************************************************************//
// blinkState - Turns on the built in led. Does this when the IR
// receiver detects any kind of input.
//
//
//************************************************************//
void MainStateMachine::blinkState()
{
    Serial.println("In BLINK_STATE");

    for( int i = 0; i < 5; ++i )
    {
      digitalWrite(LED_BUILTIN, HIGH);
      delay( 500 );
      digitalWrite(LED_BUILTIN, LOW);
      delay( 500 );
    }
    
    setState( MainStateMachine::IDLE_STATE );
}
