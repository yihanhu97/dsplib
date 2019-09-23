//
//  dspfunctions.h
//  signal
//
//  Created by Yihan Hu on 9/23/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#ifndef dspfunctions_h
#define dspfunctions_h

#include <stdio.h>

// Calculate signal mean
double calc_signal_mean(double *sig_src_arr, int sig_length);
// Calculate signal variance
double calc_signal_variance(double *sig_src_arr, double sig_mean, int sig_length);


#endif /* dspfunctions_h */
