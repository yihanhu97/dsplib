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
    // Setting up all the variables that will be used later
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
    
    
    // Setting pointer location
    count = 1;
    x = in1;
    y = in2;
    
    /* The main idea
       input array x = [x0, x1, x2, ..., x(srcALen-1)]
       input array y = [y0, y1, y2, ..., y(srcBLen-1)]
       Flip y across the origin and implement multiply and sum.
                              x0 x1 x2 ... x(srcALen-1)
       y(srcBLen-1) ... y2 y1 y0
     */
    
    /* Stage 1
       out[0] = x[0] * y[0]
       out[1] = x[0] * y[1] + x[1] * y[0]
       ....
       two arrays are now in the position of the following:
                              x0 x1 x2 ... x(srcALen-1)
       y(srcBLen-1) y(srcBLen-2) ... y2 y1 y0
       out[0], out[1], ... , out[srcBLen-2] are now calculated
    */
    while(blockSize1 > 0) {
        sum = 0.0;
        k = count >> 2U;
        while(k > 0) {
            /* x[0] * y[srcBLen-1] */
            sum += *x++ * *y--;
            /* x[1] * y[srcBLen-2] */
            sum += *x++ * *y--;
            /* x[2] * y[srcBLen-3] */
            sum += *x++ * *y--;
            /* x[3] * y[srcBLen-4] */
            sum += *x++ * *y--;
            /* Decrement the loop counter*/
            k--;
        }
        k = count % 0x4;
        while(k > 0) {
            sum += *x++ * *y--;
            k--;
        }
        *out++ = sum;
        y = in2 + count;
        x = in1;
        
        count++;
        blockSize1--;
    }
    
    /* Stage 2
       Keep shifting array y to the right
       ...
       two arrays are now in the position of the following:
                x0 x1 x2 ... x(srcALen-2) x(srcALen-1)
                             y(srcBLen-1) ... y2 y1 y0
       out[0], out[1], ... , out[srcALen-1] are now calculated
    */
    
    // Setting pointer location
    x = in1;
    src2 = in2 + (srcBLen - 1);
    y = src2;
    count = 0;
    
    if(srcBLen >= 4) {
        blkCnt = blockSize2 >> 2U;
        while(blkCnt > 0) {
            acc0 = 0.0;
            acc1 = 0.0;
            acc2 = 0.0;
            acc3 = 0.0;
            
            x0 = *(x++);
            x1 = *(x++);
            x2 = *(x++);
            
            k = srcBLen >> 2U;
            do {
                c0 = *(y--);
                x3 = *x;
                
                acc0 += x0 * c0;
                acc1 += x1 * c0;
                acc2 += x2 * c0;
                acc3 += x3 * c0;
                
                c0 = *(y--);
                x0 = *(x+1);
                acc0 += x1 * c0;
                acc1 += x2 * c0;
                acc2 += x3 * c0;
                acc3 += x0 * c0;
                
                c0 = *(y--);
                x1 = *(x+2);
                acc0 += x2 * c0;
                acc1 += x3 * c0;
                acc2 += x0 * c0;
                acc3 += x1 * c0;
                
                c0 = *(y--);
                x2 = *(x+3);
                x += 4;
                acc0 += x3 * c0;
                acc1 += x0 * c0;
                acc2 += x1 * c0;
                acc3 += x2 * c0;
            } while(--k);
            
            k = srcBLen % 0x4;
            while(k > 0) {
                c0 = *(y--);
                x3 = *(x++);
                
                acc0 += x0 * c0;
                acc1 += x1 * c0;
                acc2 += x2 * c0;
                acc3 += x3 * c0;
                
                x0 = x1;
                x1 = x2;
                x2 = x3;
                
                k--;
            }
            *out++ = acc0;
            *out++ = acc1;
            *out++ = acc2;
            *out++ = acc3;
            
            count += 4;
            x = in1 + count;
            y = src2;
            blkCnt--;
        }
        
        blkCnt = blockSize2 % 0x4;
        while(blkCnt > 0) {
            sum = 0.0;
            k = srcBLen >> 2U;
            while(k > 0) {
                sum += *x++ * *y--;
                sum += *x++ * *y--;
                sum += *x++ * *y--;
                sum += *x++ * *y--;
                k--;
            }
            k = srcBLen % 0x4;
            while(k > 0) {
                sum += *x++ * *y--;
                k--;
            }
            *out++ = sum;
            count++;
            x = in1 + count;
            y = src2;
            blkCnt--;
        }
    }
    else {
        blkCnt = blockSize2;
        while(blkCnt > 0) {
            sum = 0.0;
            k = srcBLen;
            while(k > 0) {
                sum += *x++ * *y--;
                k--;
            }
            *out++ = sum;
            count++;
            x = in1 + count;
            y = src2;
            blkCnt--;
        }
    }
    
    /* Stage 3
       Keep shifting array y to the right
       ...
       two arrays are in the final position of the following:
       x0 x1 x2 ... x(srcALen-2) x(srcALen-1)
                                              y(srcBLen-1) ... y2 y1 y0
       out[0], out[1], ... , out[srcALen+srcBLen-2] are now calculated
    */
    
    // Setting pointer location
    src1 = (in1 + srcALen) - (srcBLen - 1);
    x = src1;
    src2 = in2 + (srcBLen - 1);
    y = src2;
    
    while(blockSize3 > 0) {
        sum = 0.0;
        k = blockSize3 >> 2U;
        while(k > 0) {
            sum += *x++ * *y--;
            sum += *x++ * *y--;
            sum += *x++ * *y--;
            sum += *x++ * *y--;
            k--;
        }
        k = blockSize3 % 0x4;
        while(k > 0) {
            sum += *x++ * *y--;
            k--;
        }
        *out++ = sum;
        x = ++src1;
        y = src2;
        blockSize3--;
    }
}
