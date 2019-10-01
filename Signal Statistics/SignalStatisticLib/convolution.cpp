//
//  convolution.cpp
//  dsplib
//
//  Created by Yihan Hu on 9/30/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#include "convolution.hpp"

void conv(double *srcA, uint32_t srcALen, double *srcB, uint32_t srcBLen, double *dst) {
    
    double *in1;         // Input A pointer
    double *in2;         // Input B pointer
    double *out = dst;   // Output pointer
    double *x;           // Intermediate input A pointer
    double *y;           // Intermediate input B pointer
    
    double *src1, *src2; // Intermediate pointers
    double sum, acc0, acc1, acc2, acc3; // Accumulators
    double x0, x1, x2, x3, c0;
    uint32_t j, k, count, blkCnt, blockSize1, blockSize2, blockSize3; // Loop counters
    
    // Always consider in1 is longer than in2
    if(srcALen >= srcBLen) {
        in1 = srcA;
        in2 = srcB;
    }
    else {
        in1 = srcB;
        in2 = srcA;
        j = srcBLen;
        srcBLen = srcALen;
        srcALen = j;
    }
    blockSize1 = srcBLen - 1;
    blockSize2 = srcALen - (srcBLen - 1);
    blockSize3 = blockSize1;
    
}
