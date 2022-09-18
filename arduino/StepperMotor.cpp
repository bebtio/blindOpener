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

}

//************************************************************//
// setDirection - Sets the rotation of the motor to either be
// clockwise or coutner clockwise.
//************************************************************//
void 
StepperMotor::setDirection( StepDirection direction )
{
    switch (direction)
    {
        case CLOCKWISE:          /* setClockwise() */      break;
        case COUNTER_CLOCKWISE: /* setCounterClockwise()*/ break;
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
        case FULL_STEP:    /* setFullStep();   */ break;
        case HALF_STEP:    /* setQuarterStep();*/ break;
        case QUARTER_STEP: /* setQuarterStep();*/ break;
        case EIGHTH_STEP:  /* setEighthStep(); */ break;
    }
}

//************************************************************//
// step - Steps the stepper motor by 1 step in the specified 
// direction at the specified speed.
//************************************************************//
void 
StepperMotor::step()
{

}
