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

double _mean;
double _variance;
double _std;
double _rms;

int main() {

    sig_mean(&InputSignal_f32_1kHz_15kHz[0], BLOCKSIZE, &_mean);
    sig_variance(&InputSignal_f32_1kHz_15kHz[0], BLOCKSIZE, &_variance);
    sig_std(&InputSignal_f32_1kHz_15kHz[0], BLOCKSIZE, &_std);
    sig_rms(&InputSignal_f32_1kHz_15kHz[0], BLOCKSIZE, &_rms);
    cout<<"signal mean      = "<<_mean<<endl;
    cout<<"signal variance  = "<<_variance<<endl;
    cout<<"signal std       = "<<_std<<endl;
    cout<<"signal rms       = "<<_rms<<endl;
    return 0;
}

//Measure execuation time
//#include <time.h>
//clock_t tStart = clock();
//cout<<"Execution time   = "<<((double)(clock()-tStart))/CLOCKS_PER_SEC<<endl;
