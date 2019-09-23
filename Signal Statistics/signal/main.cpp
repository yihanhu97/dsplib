//
//  main.cpp
//  signal
//
//  Created by Yihan Hu on 9/16/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#include <iostream>
#include "dspfunctions.h"
#include "waveforms.h"
#define SIG_LENGTH 320

double signal_mean;
double signal_variance;

int main() {
    
    signal_mean = calc_signal_mean(&InputSignal_f32_1kHz_15kHz[0], SIG_LENGTH);
    signal_variance = calc_signal_variance(&InputSignal_f32_1kHz_15kHz[0], signal_mean, SIG_LENGTH);
    
    std::cout<<"Signal mean = "<<signal_mean<<std::endl;
    std::cout<<"Signal variance = "<<signal_variance<<std::endl;
    
    return 0;
}

