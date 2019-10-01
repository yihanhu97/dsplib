//
//  signalstatistic.cpp
//  dsplib
//
//  Created by Yihan Hu on 9/23/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#ifndef signalstatistic_hpp
#define signalstatistic_hpp

#include "importlibs.hpp"

class signalstatistic {
private:
    double *sig_src_arr;
    uint32_t blockSize;
public:
    // Class constructor
    signalstatistic(double* _sig_src_arr, uint32_t _blockSize);
    
    // Calculate signal mean
    double mean();

    // Calculate signal variance
    double var();

    // Calculate signal standard deviation
    double std();
    
    // Calculate signal standard root mean square
    double rms();
};

#endif /* signalstatistic_hpp */
