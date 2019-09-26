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
#include <cmath>
#include <stdint.h>

class SignalStatistics {
private:
    double *sig_src_arr;
    uint32_t blockSize;
public:
    // Class constructor
    SignalStatistics(double* _sig_src_arr, uint32_t _blockSize);
    
    // Calculate signal mean
    double mean();

    // Calculate signal variance
    double var();

    // Calculate signal standard deviation
    double std();
    
    // Calculate signal standard root mean square
    double rms();
};

#endif /* SIGNALSTATISTICS_H */
