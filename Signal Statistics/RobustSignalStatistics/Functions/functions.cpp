//
//  mean.cpp
//  RobustSignalStatistics
//
//  Created by Yihan Hu on 9/25/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#include "functions.hpp"

void sig_mean(double *sig_src_arr, uint32_t blockSize, double *result) {
 
    double sum = 0.0;
    uint32_t blkCnt;
   
    double in1, in2, in3, in4;
    
    blkCnt = blockSize>>2U; // blcCnt = blockSize / 2^2;
    
    // Compute 4 values at a time
    while(blkCnt > 0) {
        
        in1 = *sig_src_arr++;
        in2 = *sig_src_arr++;
        in3 = *sig_src_arr++;
        in4 = *sig_src_arr++;
        
        sum += in1;
        sum += in2;
        sum += in3;
        sum += in4;
        
        blkCnt--;
    }
    blkCnt = blockSize % 0x4; // blkCnt = blockSize % 4;
    while(blkCnt > 0) {
        sum += *sig_src_arr++;
        blkCnt--;
    }
    
    *result = sum/(double)blockSize;
}

void sig_variance(double *sig_src_arr, uint32_t blockSize, double *result) {
    double mean, value;
    uint32_t blkCnt;
    double *input = sig_src_arr;
    
    double sum = 0.0;
    double fsum = 0.0;
    
    double in1, in2, in3, in4;
    
    // If signal array only contains less than or equal to 1 value, variance is 0
    if(blockSize <= 1) {
        *result = 0;
        return;
    }
    
    // To calculate the signal mean
    blkCnt = blockSize>>2U;
    
    while (blkCnt > 0) {
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
    
    blkCnt = blockSize % 0x4;
    
    while(blkCnt > 0) {
        sum += *input++;
        blkCnt--;
    }
    
    mean = sum/double(blockSize);
    
    // To calculate the signal variance
    blkCnt = blockSize>>2U;
    // Reinitialize the pointer to the beginning of the array
    input = sig_src_arr;
    
    while(blkCnt > 0) {
        value = *input++ - mean;
        fsum += value * value;
        value = *input++ - mean;
        fsum += value * value;
        value = *input++ - mean;
        fsum += value * value;
        value = *input++ - mean;
        fsum += value * value;
        
        blkCnt--;
    }
    
    blkCnt = blockSize % 0x4;
    
    while(blkCnt > 0) {
        value = *input++ - mean;
        fsum += value * value;
        
        blkCnt--;
    }
    
    *result = fsum/double(blockSize - 1.0);
    
}

