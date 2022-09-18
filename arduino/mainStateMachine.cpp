//***************************************//
// Author:  Alberto Heras
// Date:    10 September 2022
// Purpose: 
//***************************************//

// This library comes from the git repository at: https://github.com/Arduino-IRremote/Arduino-IRremote
// Make sure to install this before running.
#include <IRremote.h>

#include "mainStateMachine.hpp"



//************************************************************//
// initState - initializes the digital inputs for the IR receiver.
//
//
//************************************************************//
void MainStateMachine::initState()
{

    // Initialize the receiver library to read from pin 2.
    IrReceiver.begin(IRremote::IR_PIN);
    

    // Initialize motor.
    stepper.init();

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

    // Pull the raw IR signal from the IrReceiver.
    uint32_t irSignal( IrReceiver.decodedIRData.decodedRawData ); 

    // Turn that signal into an enum for easier handling.
    IRremote::RemoteStates state = IRremote::decodeIRSignal( irSignal );
    Serial.println( IRremote::buttonStringMap[state] );

    // TODO: set the motor state variable to the current state.
    
    setState( MainStateMachine::MOTOR_CONTROL_STATE );  
    delay(2000);

    // Reset the IrReceiver contents to ready for a new signal.
    IrReceiver.resume();
}


void MainStateMachine::motorControlState()
{
  Serial.println( "MOTOR_CONTROL_STATE" );
  
  setState( MainStateMachine::IDLE_STATE );
}
//************************************************************//
// sleepState() - Puts the arduino asleep after some time of
// inactivity.
// 
// Wakes upon receiving IR signal.
//************************************************************//
void MainStateMachine::sleepState()
{
  
}



////**************************************************************//
//// Private functions from here, just used to make the code look
//// prettier.
////**************************************************************//
