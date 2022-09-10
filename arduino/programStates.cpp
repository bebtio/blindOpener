
#include <IRremote.h>
#include "programStates.hpp"


//************************************************************//
// initState- initializes the digital inputs for the IR receiver.
//
//
//************************************************************//
void MainStateMachine::initState()
{

    // Initialize the receiver library to read from pin 2.
    IrReceiver.begin(2);

    // Set serial output for debugging.
    Serial.begin(9600);

    Serial.println("In INIT_STATE");

    // Since we are done initializing. Move onto the idle state.
    setState( MainStateMachine::IDLE_STATE );
}

//************************************************************//
// idleState - waits for IR receiver to receive an input signal.
// 
// Will put arduino to sleep after it receives no inputs for 
// 30 seconds.
//
//************************************************************//
void MainStateMachine::idleState()
{
    Serial.println("In IDLE_STATE");

    // Do nothing until we receive a singal to decode.
    if( IrReceiver.decode() )
    {
        // Move to the decode state to get do something
        // with the signal.
        setState( MainStateMachine::DECODE_STATE );
    }
}

//************************************************************//
// blinkState - Turns on the built in led. Does this when the IR
// receiver detects any kind of input.
//
//
//************************************************************//
void MainStateMachine::decodeState()
{   
    Serial.println( "DECODE_STATE" );

    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    setState( MainStateMachine::IDLE_STATE );  
    delay(2000);
    IrReceiver.resume();
}

//************************************************************//
// sleepState() - Puts the arduino asleep after some time of
// inactivity.
// 
// Wakes upon receiving IR signal.
//************************************************************//
void SleepState()
{
  
}
