//
//  main.cpp
//  signal
//
//  Created by Yihan Hu on 9/16/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#include <iostream>
#include "waveforms.h"
#define SIG_LENGTH 320



double calc_signal_mean(double *sig_src_arr, int sig_length);

double signal_mean;
int main() {
    
    signal_mean = calc_signal_mean(&InputSignal_f32_1kHz_15kHz[0], SIG_LENGTH);
    
    std::cout<<"\n\nMean = "<<signal_mean<<std::endl;
    
    return 0;
}

double calc_signal_mean(double *sig_src_arr, int sig_length) {
    double _mean = 0.0;
    
    for(int i=0;i<sig_length;i++){
        _mean = _mean + sig_src_arr[i];
    }
    _mean = _mean/double(sig_length);
    
    return _mean;
}
