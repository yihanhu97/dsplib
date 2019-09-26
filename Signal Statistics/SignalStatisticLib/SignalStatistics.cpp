//
//  SignalStatistics.cpp
//  SignalStatisticLib
//
//  Created by Yihan Hu on 9/23/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#include "SignalStatistics.hpp"

// Pass values to private variables in the class
SignalStatistics::SignalStatistics(double* _sig_src_arr, uint32_t _blockSize) {
    sig_src_arr = _sig_src_arr;
    blockSize = _blockSize;
}

// Calculate signal mean
double SignalStatistics::mean() {
    double _mean = 0.0;
    
    double *input = sig_src_arr;
    double sum = 0.0;
    uint32_t blkCnt;
    double in1, in2, in3, in4;
    
    blkCnt = blockSize>>2U; // blcCnt = blockSize / 2^2;
    
    // Compute 4 values at a time
    while(blkCnt > 0) {
        
        in1 = *input++;
        in2 = *input++;
        in3 = *input++;
        in4 = *input++;
        
        sum += in1;
        sum += in2;
        sum += in3;
        sum += in4;
        
        blkCnt--;
    }
    blkCnt = blockSize % 0x4; // blkCnt = blockSize % 4;
    while(blkCnt > 0) {
        sum += *input++;
        blkCnt--;
    }
    
    _mean = sum/(double)blockSize;
    
    return _mean;
}

// Calculate signal variance
double SignalStatistics::var() {
    double _variance = 0.0;
    
    // Calculate signal mean first
    double _mean  = mean();

    double *input = sig_src_arr;
    double value;
    uint32_t blkCnt;
    
    double fsum = 0.0;
    
    // If signal array only contains less than or equal to 1 value, variance is 0
    if(blockSize == 1) {
        _variance = 0.0;
        return _variance;
    }
        
    // To calculate the signal variance
    blkCnt = blockSize>>2U;
    
    while(blkCnt > 0) {
        value = *input++ - _mean;
        fsum += value * value;
        value = *input++ - _mean;
        fsum += value * value;
        value = *input++ - _mean;
        fsum += value * value;
        value = *input++ - _mean;
        fsum += value * value;
        
        blkCnt--;
    }
    
    blkCnt = blockSize % 0x4;
    
    while(blkCnt > 0) {
        value = *input++ - _mean;
        fsum += value * value;
        
        blkCnt--;
    }
    
    _variance = fsum/(double(blockSize) - 1.0);
    
    return _variance;
}

// Calculate signal standard deviation
double SignalStatistics::std() {
    double _variance = var();
    double _std = sqrt(_variance);
    return _std;
}

// Calculate signal root mean square
double SignalStatistics::rms() {
    double _rms = 0.0;
    
    double *input = sig_src_arr;
    double sum = 0.0;
    uint32_t blkCnt;
    double value;
    
    blkCnt = blockSize>>2U;
    
    while(blkCnt > 0) {
        value = *input++;
        sum += value * value;
        value = *input++;
        sum += value * value;
        value = *input++;
        sum += value * value;
        value = *input++;
        sum += value * value;
        
        blkCnt--;
    }
    
    blkCnt = blockSize % 0x4;
    
    while(blkCnt > 0) {
        value = *input++;
        sum += value * value;
    
        blkCnt--;
    }
    
    _rms = sqrt(sum/(double)blockSize);
    
    return _rms;
}


