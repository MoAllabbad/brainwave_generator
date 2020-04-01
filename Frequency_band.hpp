#ifndef FREQUENCY_BAND_HPP
#define FREQUENCY_BAND_HPP

#define DELTA_LWR_LMT  1
#define DELTA_UPPR_LMT 3
#define THETA_LWR_LMT  4
#define THETA_UPPR_LMT 7
#define ALPHA_LWR_LMT  8
#define ALPHA_UPPR_LMT 12
#define BETA_LWR_LMT   13
#define BETA_UPPR_LMT  30
#define GAMA_LWR_LMT   31
#define GAMA_UPPR_LMT  50

class Frequency_band
{
    public:
         typedef enum {
            DELTA, // ~1-3  Hz
            THETA, // ~4-7  Hz
            ALPHA, // ~8-12 Hz
            BETA,  // 13-30 Hz
            GAMMA, // 31-50 Hz
            NUMBRE_OF_BANDS
        } Bands;
        Frequency_band(Bands band);
        Frequency_band (int lower_limit, int upper_limit);
        int get_lower_limit();
        int get_upper_limit();
        void set_lower_limit(int ll);
        void set_upper_limit(int ul);
    private:
        int _lower_limit;
        int _upper_limit;

};

#endif

