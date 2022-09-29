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
    IrReceiver.begin(IRremoteStates::IR_PIN);

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

    // Do nothing until we receive a signal to decode.
    if( IrReceiver.decode() )
    {
        // Move to the decode state to get do something
        // with the signal.
        setState( MainStateMachine::DECODE_STATE );
    }
}

//************************************************************//
// decodeState - 
//
//
//************************************************************//
void MainStateMachine::decodeState()
{   
    Serial.println( "DECODE_STATE" );

    uint32_t irSignal( IrReceiver.decodedIRData.decodedRawData ); 
    IrReceiver.resume();

    IRremoteStates::RemoteStates state = IRremoteStates::decodeIRSignal( irSignal );

    // Define a state for every possible input. Could just fall through to IDLE_STATE
    // if not UP_BUTTON or DOWN_BUTTON instead.
    switch( state )
    {
        case( IRremoteStates::POWER_BUTTON ):  setState( SLEEP_STATE );                  break;
        case( IRremoteStates::A_BUTTON ):      setState( IDLE_STATE );                   break;
        case( IRremoteStates::B_BUTTON ):      setState( IDLE_STATE );                   break;
        case( IRremoteStates::C_BUTTON ):      setState( IDLE_STATE );                   break;
        case( IRremoteStates::UP_BUTTON ):     setState( MOTOR_CLOCKWISE_STATE );        break;
        case( IRremoteStates::RIGHT_BUTTON ):  setState( IDLE_STATE );                   break;
        case( IRremoteStates::DOWN_BUTTON ):   setState( MOTOR_COUNTERCLOCKWISE_STATE ); break;
        case( IRremoteStates::LEFT_BUTTON ):   setState( IDLE_STATE );                   break;
        case( IRremoteStates::CENTER_BUTTON ): setState( IDLE_STATE );                   break;
        case( IRremoteStates::NONE ):          setState( IDLE_STATE );                   break;
    }
}

//************************************************************//
// motorClockwiseState() - 
//
//
//************************************************************//
void MainStateMachine::motorClockwiseState()
{
    Serial.println( "MOTOR_CLOCKWISE_STATE" );

    // Tell the stepper motor what to do.
    stepper.setStepDirection( StepperMotor::CLOCKWISE );
    stepper.step(400);

    // Return to IDLE_STATE for next command.
    setState( MainStateMachine::IDLE_STATE );
}

//************************************************************//
// motorCounterClockwiseState() - 
//
//
//************************************************************//
void MainStateMachine::motorCounterClockwiseState()
{
    Serial.println( "MOTOR_COUNTERCLOCKWISE_STATE" );

    // Tell stepper motor what to do.
    stepper.setStepDirection( StepperMotor::COUNTER_CLOCKWISE );
    stepper.step(400);

    // Return to IDLE_STATE for next command.
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
    Serial.println( "SLEEP_STATE" );

    // Set the motor sleep mode to on.
    if( stepper.isSleepModeSet() == true )
    {
      stepper.setSleepMode( false );    
    }
    else
    {
      stepper.setSleepMode( true );
    }
    // Enable an interrupt on the IR pin to wake it back up on 
    // receive.

    // Enable sleep mode.

    // Set state to IDLE_STATE
    setState( MainStateMachine::IDLE_STATE );
}



////**************************************************************//
//// Private functions from here, just used to make the code look
//// prettier.
////**************************************************************//
