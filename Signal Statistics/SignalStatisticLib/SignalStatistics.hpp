//
//  SignalStatistic.cpp
//  SignalStatisticLib
//
//  Created by Yihan Hu on 9/23/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#ifndef SIGNALSTATISTICS_H
#define SIGNALSTATISTICS_H

#include <stdio.h>

class SignalStatistics {
private:
    double *sig_src_arr;
    int sig_length;
public:
    // Class constructor
    SignalStatistics(double* _sig_src_arr, int _sig_length);
    
    // Calculate signal mean
    double calc_signal_mean();

    // Calculate signal variance
    double calc_signal_variance();

    // Calculate signal standard deviation
    double calc_signal_std();
};

#endif /* SIGNALSTATISTICS_H */
