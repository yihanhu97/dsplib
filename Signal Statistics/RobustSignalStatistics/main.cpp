//
//  main.cpp
//  RobustSignalStatistics
//
//  Created by Yihan Hu on 9/25/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

#include <iostream>
#include "functions.hpp"
#include "waveforms.hpp"
#define BLOCKSIZE 320

using namespace std;

double mean;
double variance;

int main() {
    sig_mean(&InputSignal_f32_1kHz_15kHz[0], BLOCKSIZE, &mean);
    sig_variance(&InputSignal_f32_1kHz_15kHz[0], BLOCKSIZE, &variance);
    cout<<"signal mean      = "<<mean<<endl;
    cout<<"signal variance  = "<<variance<<endl;
    return 0;
}
