//
//  Convolution.hpp
//  TestGround
//
//  Created by Yihan Hu on 9/29/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#ifndef Convolution_hpp
#define Convolution_hpp

#include <stdio.h>

void conv(double *sig_src_arr,
          double *sig_dest_arr,
          double *imp_response_arr,
          int sig_src_length,
          int imp_reponse_arr);

#endif /* Convolution_hpp */
