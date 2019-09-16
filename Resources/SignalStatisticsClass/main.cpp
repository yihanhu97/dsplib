#include <iostream>
#include "SignalStatistics.hpp"

using namespace std;

extern double InputSignal_f32_1kHz_15kHz[320];

int main()
{
     double std;
     SignalStatistics *testSignal = new SignalStatistics(&InputSignal_f32_1kHz_15kHz[0],(sizeof(InputSignal_f32_1kHz_15kHz)/sizeof(InputSignal_f32_1kHz_15kHz[0])));

      std = testSignal->calc_signal_std();
    cout << std << endl;
    return 0;
}
