//
//  mean.cpp
//  RobustSS
//
//  Created by Yihan Hu on 9/25/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#include "mean.hpp"

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
