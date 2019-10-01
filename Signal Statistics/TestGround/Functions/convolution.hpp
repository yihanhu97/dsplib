//
//  convolution.hpp
//  dsplib
//
//  Created by Yihan Hu on 9/30/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#ifndef convolution_hpp
#define convolution_hpp

#include <stdio.h>
#include <cmath>
#include <stdint.h>
#include <iostream>

void conv(double *srcA, uint32_t srcALen, double *srcB, uint32_t srcBLen, double *dst);

#endif /* convolution_hpp */
