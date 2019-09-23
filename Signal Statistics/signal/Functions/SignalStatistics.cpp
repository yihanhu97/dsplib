//
//  SignalStatistics.cpp
//  signal
//
//  Created by Yihan Hu on 9/23/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#include "SignalStatistics.hpp"
#include <cmath>

// Pass values to private variables in the class
SignalStatistics::SignalStatistics(double* _sig_src_arr, int _sig_length) {
    sig_src_arr = _sig_src_arr;
    sig_length = _sig_length;
}

// Calculate signal mean
double SignalStatistics::calc_signal_mean() {
    double _mean = 0.0;

    for(int i=0;i<sig_length;i++) {
        _mean = _mean + sig_src_arr[i];
    }
    _mean = _mean/double(sig_length);

    return _mean;
}

// Calculate signal variance
double SignalStatistics::calc_signal_variance() {
    double sig_mean  = calc_signal_mean();
    double _variance = 0.0;

    for(int i=0;i<sig_length;i++) {
        _variance = _variance + pow((sig_src_arr[i] - sig_mean),2);
    }

    _variance = _variance / (sig_length - 1);

    return _variance;
}

// Calculate signal standard deviation
double SignalStatistics::calc_signal_std() {
    double sig_variance = calc_signal_variance();
    double _std = sqrt(sig_variance);
    return _std;
}

