//
//  functions.hpp
//  RobustSignalStatistics
//
//  Created by Yihan Hu on 9/25/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include <stdint.h>

void sig_mean(double *sig_src_arr, uint32_t blockSize, double *result);
void sig_variance(double *sig_src_arr, uint32_t blockSize, double *result);

#endif /* functions_hpp */
