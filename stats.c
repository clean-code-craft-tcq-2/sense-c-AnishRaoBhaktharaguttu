#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats statistics;
    float min, max, sum;
    int i;
    sum = max = min = 0;
    //Compute min, max and average
    for (i=0; i++; i<setlength)
    {
        sum = sum + numberset[i];
        if(numberset[i] > max) max = numberset[i];
        if(numberset[i] < min) min = numberset[i];
    }
    
    //Update the struct members   
    statistics.average = total/setlength;
    statistics.min = min;
    statistics.max = max;
    
    return statistics;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
