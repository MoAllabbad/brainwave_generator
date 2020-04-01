
#include "Brainwave.hpp"
#define PRINT_FLAG 1 // whether or not to enable the option to print to the screen/serial-monitor/plotter

#define DEEP_SLEEP  Frequency_band::DELTA   // ~1-3  Hz
#define ASLEEP      Frequency_band::THETA   // ~4-7  Hz
#define DROWSY      Frequency_band::ALPHA   // ~8-12 Hz
#define RELAXED     Frequency_band::BETA    // 13-30 Hz
#define EXCITED     Frequency_band::GAMMA   // 31-50 Hz

int main()
{   
    float stored_val[FULL_CYCLE_LENGTH]; // this array has the values to pass to the FFT. FULL_CYCLE_LENGTH is defined in Braineave.cpp
    Brainwave drowsy_signal(DROWSY);
    //Brainwave deep_sleep_signal(DEEP_SLEEP);
    //Brainwave excited_signal(EXCITED);
    while(1){
        drowsy_signal.simulation(stored_val, PRINT_FLAG);
        //deep_sleep_signal.simulation(NUM_OF_CYCLES_PER_RUN, stored_val, PRINT_FLAG);
        //excited_signal.simulation(NUM_OF_CYCLES_PER_RUN, stored_val, PRINT_FLAG);
    }
}