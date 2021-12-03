
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>

#ifndef MATLAB_MEX_FILE
#include <Arduino.h>
#include <EMGFilters.h>
#include <EMGFilters.cpp>

EMGFilters myFilter1;
EMGFilters myFilter2;
EMGFilters myFilter3;

SAMPLE_FREQUENCY sampleRate = SAMPLE_FREQ_500HZ;
unsigned long long interval = 1000000ul / sampleRate;
NOTCH_FREQUENCY humFreq = NOTCH_FREQ_60HZ;

//emg1
int dato1;
int datoFiltro1;

//emg1
int dato2;
int datoFiltro2;

//emg1
int dato3;
int datoFiltro3;

#define sq(x) ((x)*(x));

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
extern "C" void EMG_T_Outputs_wrapper(real_T *FSR,
			real_T *EMG1,
			real_T *EMG2,
			real_T *EMG3,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0] == 1){
# ifndef MATLAB_MEX_FILE
    unsigned long long timeStamp = micros();

    analogReadResolution(12);
    
    FSR[0] = analogRead(A7);
    
    //EMG1
    dato1 = analogRead(A0);
    datoFiltro1 = myFilter1.update(dato1);
    EMG1[0] = sq(datoFiltro1);

    //EMG2
    dato2 = analogRead(A2);
    datoFiltro2 = myFilter2.update(dato2);
    EMG2[0] = sq(datoFiltro2);
    
    //EMG3
    dato3 = analogRead(A3);
    datoFiltro3 = myFilter3.update(dato3);
    EMG3[0] = sq(datoFiltro3);
    
# endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C" void EMG_T_Update_wrapper(real_T *FSR,
			real_T *EMG1,
			real_T *EMG2,
			real_T *EMG3,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1){     
        # ifndef MATLAB_MEX_FILE         
                myFilter1.init(sampleRate, humFreq, true, true, true);
                myFilter2.init(sampleRate, humFreq, true, true, true);
                myFilter3.init(sampleRate, humFreq, true, true, true);
        # endif        
                xD[0]=1;}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

