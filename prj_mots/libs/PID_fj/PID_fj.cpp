/**********************************************************************************************
 * Arduino PID Library - Version 1.0.1
 * by Brett Beauregard <br3ttb@gmail.com> brettbeauregard.com
 *
 * This Library is licensed under a GPLv3 License
 **********************************************************************************************/

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <PID_fj.h>

/*Constructor (...)*********************************************************
 ***************************************************************************/
PID::PID(double* FD, double* OUT, double* ST,
        double Kp, double Ki, double Kd, int DIR, int* MIN, int*MAX)
{
 iOutput = OUT;
 iInput = FD;
 iSetpoint = ST;
 iOmin = MIN;
 iOmax = MAX;
 RUNNING = false;

 PID::SetTunings(Kp, Ki, Kd, DIR);
}
 
/* Compute() **********************************************************************
 **********************************************************************************/ 
bool PID::Compute()
{
   if(!RUNNING) return false;
   /*Compute all the working error variables*/
   double error = *iSetpoint - *iInput;
   ITerm+= (ki * (error+lastError)/2);
   if (ITerm > *iOmax) { ITerm=*iOmax; } else { if (ITerm < *iOmin) { ITerm=*iOmin; } }
   double dInput = (*iInput - lastInput);
   /*Compute PID Output*/
   double output = kp * error + ITerm - kd * dInput;
   if (output > *iOmax) { output=*iOmax; } else { if (output < *iOmin) { output=*iOmin; } }
   *iOutput = output;
   /*Remember some variables for next time*/
   lastInput = *iInput;
   lastError = error;
   return true;
}

/* SetTunings(...)**********************************************************
 ******************************************************************************/ 
 void PID::SetTunings(double Kp, double Ki, double Kd, int DIR) {
 if (Kp<0 || Ki<0 || Kd<0) return;
  kp = Kp;
  ki = Ki;
  kd = Kd;
 
 if(DIR==REVERSE) {
  kp = (0 - kp);
  ki = (0 - ki);
  kd = (0 - kd);
 }
}
  
/* SetMode(...)****************************************************************
 ******************************************************************************/ 
void PID::Run(int cmd) {
 if(cmd==ON) {
  lastInput = *iInput;
  lastError = 0;
  ITerm = *iOutput;
 }
 else { *iOutput=0; }
 RUNNING = cmd;
}

/* Status Funcions*************************************************************
 ******************************************************************************/
double PID::GetKp(){ return kp;}
double PID::GetKi(){ return ki;}
double PID::GetKd(){ return kd;}
int PID::GetState(){ return RUNNING ? ON : OFF;}