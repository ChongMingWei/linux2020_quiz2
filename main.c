#include <stdio.h>
#include <stdlib.h>
#include "quiz2_3.h"
#include <time.h>
int main(){
    // Timer 
    struct timespec time1 = {0, 0};
    struct timespec time2 = {0, 0};
    // Division 
    uint32_t q,d,n;
    srand(time(NULL));
    for (d = 2;d < 5000;++d){

        long fast=0;
        long normal=0;
        for (int i=0; i<5;++i){
            n = rand() % 4294967296;
            
            clock_gettime(CLOCK_REALTIME, &time1);
            q = n / d;
            clock_gettime(CLOCK_REALTIME, &time2);
            
            long diff = time2.tv_nsec - time1.tv_nsec;
            normal += diff;
 
            // fast division part
            uint64_t two_to_k = ((uint64_t)1 << 32);
            uint32_t magic = (uint32_t)(two_to_k / d);
            if (two_to_k % d != 0) {
	            magic++;
            }
            
            clock_gettime(CLOCK_REALTIME, &time1);
            q = ((uint64_t)n * (uint64_t)magic) >> 32;
            clock_gettime(CLOCK_REALTIME, &time2);

            diff = time2.tv_nsec - time1.tv_nsec;
            fast += diff;
        }
        printf("fast = %ld ns normal = %ld ns\n",fast/5,normal/5);
    }
    return 0;
}
