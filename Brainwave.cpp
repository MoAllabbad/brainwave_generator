#include "mbed.h"
#include "Brainwave.hpp"
#include "math.h"
#include <iostream>
#define FB Frequency_band

#define DOMINANT_MAGNITUDE 10
#define SECONDARY_MAGNITUDE 4

#define DOMINANT_AMPLITUDE_VARIANCE  2
#define SECONDARY_AMPLITUDE_VARIANCE 1

Brainwave::Brainwave( FB::Bands band ) 
    : dominant_band(band), Delta(DELTA_LWR_LMT, DELTA_UPPR_LMT), Theta(THETA_LWR_LMT, THETA_UPPR_LMT)
    , Alpha(ALPHA_LWR_LMT, ALPHA_UPPR_LMT) , Beta(BETA_LWR_LMT, BETA_UPPR_LMT), Gamma(GAMA_LWR_LMT, GAMA_UPPR_LMT)
{}

void Brainwave::simulation(float stored_val[], bool print_flag)
{
    for(int i=0; i < FULL_CYCLE_LENGTH; i++)
    {
        stored_val[i]=0; // reset previous values, otherwise they keep growing
        float t = (float) i / SIGNAL_RESOLUTION_PER_SECOND;
        for ( int freq =1; freq <= NUM_OF_FREQUENCIES; freq++)
        {
            stored_val[i] += ((i < 20) ? i*0.01 : 1)*  // (i < 20) ? i*0.02 : 1) is a ramp saturating at 20 
                             get_freq_amplitude(freq)* // the amplitude of the sin at freq is determined by the brain state
                             sin(freq*t*2*PI); 
        }
        if (print_flag){
            std::cout << stored_val[i] << std::endl;
        }
    }
}


int Brainwave::get_freq_amplitude(int freq)
{
    if ( (dominant_band.get_lower_limit() <= freq) && (freq <= dominant_band.get_upper_limit()) )
        return  rand() % DOMINANT_AMPLITUDE_VARIANCE  + DOMINANT_MAGNITUDE;
    else
        return  rand() % SECONDARY_AMPLITUDE_VARIANCE + SECONDARY_MAGNITUDE;
}

