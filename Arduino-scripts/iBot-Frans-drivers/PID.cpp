#include "PID.h"

PID::PID(double Kp, double Ki, double Kd, double tau, double limMin, double limMax, double T)
{
    //sets gains
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;

    //sets filter time
    this->tau = tau;

    //sets limits
    this->limMin = limMin;
    this->limMax = limMax;
    
    //sets sampling time
    this->T = T;
    
    //asigns emptu memory so we dont get "not defined" value error bs
    double integrator = 0.0;
    double preverror = 0.0;
    double differentiator = 0.0;
    double prevMeassurement = 0.0;
};

double PID::update(double setPoint, double meassurement)
{
    /*gets error. the error is always posetively setpoint - meassurement so that when you do the feedback loop in state space you do negative gain for stability.*/
    double error = setPoint - meassurement; //the error between the set value and the meassurment




    /* gets the proportional part of the output value */
    double proportional = this->Kp * error; //the proportional part of the output value




    /* accumulates the integrator */
    this->integrator += 0.5 * this->Ki * this->T * (error + this->prevError); //the discretly accumulated integrator


    /*making sure the integrator doesnt saturate the output value */
    float limMinInt; // mimimum value for the integrator
    float limMaxInt; // maximum value for the integrator

    if (this->limMax > proportional)
    {
        limMaxInt = this->limMax - proportional;
    }
    else
    {
        limMaxInt = 0.0;
    }
    
    if (this->limMin < proportional)
    {
        limMinInt = this->limMin - proportional;
    }
    else
    {
        limMinInt = 0.0;
    }
    
    if (this->integrator > limMaxInt)
    {
        this->integrator = limMaxInt;
    }
    else if (this->integrator < limMinInt)
    {
        this->integrator = limMinInt;
    }




    /* sets the differentiator */
    this->differentiator = ( 2.0 * this->Kd * (meassurement - this->prevMeassurement)   /*note we are deriving on meassurement and not error.*/ 
                            + ( 2.0 * this->tau - this->T ) * this->differentiator )    /*this is mostly because we can, but also some bart due to*/
                            / ( 2.0 *this->tau + this->T );                             /*beneficial behavior of the system*/
    /*also note that we are using a low pass filter on ther differentiator, this is to have a way of dealing with noise*/




    /*summing shit together*/
    this->Out = proportional + this->integrator + this->differentiator;


    /*limiting the output value*/
    if (this->Out > this->limMax)
    {
        this->Out = this->limMax;
    }
    else if (this->Out < this->limMin)
    {
        this->Out=this->limMin;
    }
    
    /*keeping error*/
    this->prevError = error;

    /*keeping the meassurement*/
    this->prevMeassurement = meassurement;


    /*FINALLY we can return the one thing we actually wanted.... the output*/
    return this->Out;
};