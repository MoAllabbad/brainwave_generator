
#include "Frequency_band.hpp"

Frequency_band::Frequency_band(Bands band)
{
    if ( band == DELTA ){
        set_upper_limit(DELTA_UPPR_LMT);
        set_lower_limit(DELTA_LWR_LMT);
    }
    else if (band == THETA){
        set_upper_limit(THETA_UPPR_LMT);
        set_lower_limit(THETA_LWR_LMT);
    }
    else if (band == ALPHA){
        set_upper_limit(ALPHA_UPPR_LMT);
        set_lower_limit(ALPHA_LWR_LMT);
    }
    else if (band == BETA){
        set_upper_limit(BETA_UPPR_LMT);
        set_lower_limit(BETA_LWR_LMT);
    }
    else{
        set_upper_limit(GAMA_UPPR_LMT);
        set_lower_limit(GAMA_LWR_LMT);
    }
}

Frequency_band::Frequency_band( int lower_limit, int upper_limit) 
                    : _lower_limit(lower_limit), _upper_limit(upper_limit)
{}


int Frequency_band::get_lower_limit()
{
    return _lower_limit;
}

int Frequency_band::get_upper_limit()
{
    return _upper_limit;
}

void Frequency_band::set_lower_limit(int ll)
{
    _lower_limit = ll;
}
void Frequency_band::set_upper_limit(int ul)
{
    _upper_limit = ul;
}
