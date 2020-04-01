
#include "Frequency_band.hpp"

#ifndef BRAINWAVE_HPP
#define BRAINWAVE_HPP

#define PI 3.14159265
#define NUM_OF_FREQUENCIES 50   // considering from 1 to 50Hz
#define FULL_CYCLE_LENGTH  256
#define SIGNAL_RESOLUTION_PER_SECOND  512 // = (fundamental_frq * number_of_samples)*k where k is an integer bigger than zero



class Brainwave
{
    public:
        Brainwave( Frequency_band::Bands band );   // create brainwave according to the selected state/band
        void simulation(float stored_val[], bool print_flag); // 
        int get_freq_amplitude(int freq);
    private:
        Frequency_band dominant_band;
        Frequency_band Delta;
        Frequency_band Theta;
        Frequency_band Alpha;
        Frequency_band Beta;
        Frequency_band Gamma;
        
};


#endif

