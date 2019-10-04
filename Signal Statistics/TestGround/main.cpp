//
//  main.cpp
//  signal
//
//  Created by Yihan Hu on 9/16/19.
//  Copyright © 2019 Yihan Hu. All rights reserved.
//

//#include "SignalStatistics.hpp"
#include "convolution.hpp"
#include "signals.hpp"
#include <time.h>
#define SIG_LENGTH 320
#define IMP_RSP_LENGTH 29

double output[11];

int main() {

//    double tStart = clock();
//    SignalStatistics *testSignal = new SignalStatistics(&InputSignal_f32_1kHz_15kHz[0], sizeof(InputSignal_f32_1kHz_15kHz)/sizeof(InputSignal_f32_1kHz_15kHz[0]));
//
//    std::cout<<"Signal mean     = "<<testSignal->mean()<<std::endl;
//    std::cout<<"Signal variance = "<<testSignal->var()<<std::endl;
//    std::cout<<"Signal std      = "<<testSignal->std()<<std::endl;
//    std::cout<<"Signal rms      = "<<testSignal->rms()<<std::endl;
//    std::cout<<"Execution time  = "<<((double)(clock()-tStart))/CLOCKS_PER_SEC<<std::endl;
    
//    uint32_t x = 3;
//    uint32_t y = x>>2U;
    conv(test_input, 7, test_response, 5, output);
    for(int i=0; i<(sizeof(output)/sizeof(output[0]));i++) {
        std::cout<<output[i]<<std::endl;
    }

    return 0;
}

