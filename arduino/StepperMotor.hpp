#ifndef _STEPPERMOTOR_HPP_
#define _STEPPERMOTOR_HPP_

#include "arduinoPinDefines.hpp"

// Make these all defines to save on memory.
// TODO: figure out what these will be set to on the board.
#define STEP_PIN   D3  
#define DIR_PIN    D4
#define MS1_PIN    D5 
#define MS2_PIN    D6 
#define ENABLE_PIN D7
class StepperMotor
{
public:

    // Enumeration to define the directions the motor can spin.
    enum StepDirection
    {
        COUNTER_CLOCKWISE,
        CLOCKWISE,
    };

    // Based on values on pins MS1 and MS2 of Easy stepper motor board.
    // |-------------------------------------------------------------------------------|
    // | MS1  | MS2   | Microstep Resolution  |                                        |
    // |-------------------------------------------------------------------------------|
    // | LOW  | LOW   | FULL_STEP             |  Fastest rotation                      |
    // | HIGH | LOW   | HALF_STEP             |  ...                                   |
    // | LOW  | HIGH  | QUARTER_STEP          |  ...                                   |
    // | HIGH | HIGH  | EIGTH_STEP            |  Slowest: This is the default setting. |
    // |-------------------------------------------------------------------------------|
    enum StepSpeed
    {
        FULL_STEP,
        HALF_STEP,
        QUARTER_STEP,
        EIGHTH_STEP
    };

    StepperMotor();

    void init();
    void setStepDirection( StepDirection direction );
    void setStepSpeed( StepSpeed speed );
    void step( size_t numSteps = 50 );

private:

    void setClockwise();
    void setCounterClockwise();

    void setFullStep();
    void setHalfStep();
    void setQuarterStep();
    void setEighthStep();
};

#endif // _STEPPERMOTOR_HPP_