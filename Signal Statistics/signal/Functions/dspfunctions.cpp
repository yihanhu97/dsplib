//
//  dspfunctions.cpp
//  signal
//
//  Created by Yihan Hu on 9/23/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#include "dspfunctions.h"
#include <cmath>

double calc_signal_mean(double *sig_src_arr, int sig_length) {
    
    double _mean = 0.0;
    
    for(int i=0;i<sig_length;i++) {
        _mean = _mean + sig_src_arr[i];
    }
    _mean = _mean/double(sig_length);
    
    return _mean;
}

double calc_signal_variance(double *sig_src_arr, double sig_mean, int sig_length) {
    
    double _variance = 0.0;
    
    for(int i=0;i<sig_length;i++) {
        _variance = _variance + pow((sig_src_arr[i] - sig_mean),2);
    }
    
    _variance = _variance / (sig_length - 1);
    
    return _variance;
}
