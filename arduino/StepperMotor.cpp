#include "StepperMotor.hpp"


//************************************************************//
// StepperMotor constructor - Doesn't do anything. We are going
// to follow state machine model and just do the construction
// in the init call instead.
//************************************************************//
StepperMotor::StepperMotor()
{

}


//************************************************************//
// init - Initialize all the pins we require as either inputs
// or outputs.
//************************************************************//
void 
StepperMotor::init()
{
    // The reason these aren't defined as inputs is because
    // these are outputs in the eyes of the arduino NANO.
    // This class CONTROLS the EasyDriver board instead of 
    // being the EasyDriver board... Hope that makes sense later.
    pinMode(STEP_PIN,  OUTPUT);
    pinMode(DIR_PIN,   OUTPUT);
    pinMode(MS1_PIN,   OUTPUT);
    pinMode(MS2_PIN,   OUTPUT);

    // Give it some initial settings.
    setStepDirection( CLOCKWISE );
    setStepSpeed( FULL_STEP );
}

//************************************************************//
// setDirection - Sets the rotation of the motor to either be
// clockwise or coutner clockwise.
//************************************************************//
void 
StepperMotor::setStepDirection( StepDirection direction )
{
    switch (direction)
    {
        case CLOCKWISE:         setClockwise();        break;
        case COUNTER_CLOCKWISE: setCounterClockwise(); break;
    }
}

//************************************************************//
// setStepSpeed - Sets the speed of the stepper motor to one of
// the four defined leves in the hpp file.
//************************************************************//
void 
StepperMotor::setStepSpeed( StepSpeed speed )
{
    switch (speed)
    {
        case FULL_STEP:    setFullStep();    break;
        case HALF_STEP:    setQuarterStep(); break;
        case QUARTER_STEP: setQuarterStep(); break;
        case EIGHTH_STEP:  setEighthStep();  break;
    }
}
    
//************************************************************//
// step - Steps the stepper motor by 1 step in the specified 
// direction at the specified speed.
//************************************************************//
void 
StepperMotor::step()
{
    // Steps the motor whenever there is a change from
    // LOW to HIGH on the pin. 
    // digitalWrite(STEP_PIN, HIGH);
    // digitalWrite(STEP_PIN, LOW );
}


//*************************//
// Private functions below //
//*************************//


//************************************************************//
// setClockwise() - the direction of HIGH and low depend on how
// you plug in the motor. Going to need to experiment to figure
// which LOGIC value sets what direction.
//************************************************************//
void 
StepperMotor::setClockwise()
{
    digitalWrite(DIR_PIN, HIGH);
}

//************************************************************//
// setCounterClockwise() - the direction of HIGH and low depend on how
// you plug in the motor. Going to need to experiment to figure
// which LOGIC value sets what direction.
//************************************************************//
void 
StepperMotor::setCounterClockwise()
{
    digitalWrite(DIR_PIN, LOW);
}

//************************************************************//
// setFullStep - Sets MS1 and MS2 to use FULL_STEP
//************************************************************//
void 
StepperMotor::setFullStep()
{
    digitalWrite( MS1_PIN, LOW );
    digitalWrite( MS2_PIN, LOW );
}

//************************************************************//
// setHalfStep - Sets MS1 and MS2 to use HALF_STEP
//************************************************************//
void 
StepperMotor::setHalfStep()
{
    digitalWrite( MS1_PIN, HIGH );
    digitalWrite( MS2_PIN, LOW );
}

//************************************************************//
// setQuarterStep - Sets MS1 and MS2 to use QUARTER_STEP
//************************************************************//
void 
StepperMotor::setQuarterStep()
{
    digitalWrite( MS1_PIN, LOW );
    digitalWrite( MS2_PIN, HIGH );
}

//************************************************************//
// setEighthStep - Sets MS1 and MS2 to use EIGHTH_STEP
//************************************************************//
void 
StepperMotor::setEighthStep()
{
    digitalWrite( MS1_PIN, HIGH );
    digitalWrite( MS2_PIN, HIGH );
}
