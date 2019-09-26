//
//  main.cpp
//  signal
//
//  Created by Yihan Hu on 9/16/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#include <iostream>
#include "SignalStatistics.hpp"
#include "waveforms.hpp"
#define SIG_LENGTH 320

int main() {

    SignalStatistics *testSignal = new SignalStatistics(&InputSignal_f32_1kHz_15kHz[0], sizeof(InputSignal_f32_1kHz_15kHz)/sizeof(InputSignal_f32_1kHz_15kHz[0]));

    double signal_mean = testSignal->calc_signal_mean();
    double signal_variance = testSignal->calc_signal_variance();
    double signal_std = testSignal->calc_signal_std();

    std::cout<<"Signal mean = "<<signal_mean<<std::endl;
    std::cout<<"Signal variance = "<<signal_variance<<std::endl;
    std::cout<<"Signal std = "<<signal_std<<std::endl;


    return 0;
}

