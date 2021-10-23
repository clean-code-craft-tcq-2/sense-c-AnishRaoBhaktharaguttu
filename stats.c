#include <stdio.h>
#include "stats.h"
#include "alert.h"
#include <math.h>

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats statistics;
    int i;
    float sum = 0.0, max = numberset[0], min = numberset[0];
    //Compute min, max and average
	
if(setlength!=0){
    for (i=0; i<setlength; i++)
    {
        sum += numberset[i];
        if(numberset[i] > max){
		max = numberset[i];
	}
        if(numberset[i] < min){
		min = numberset[i];
	}
    }
    
    //Update the struct members   
    statistics.average = sum/setlength;
    statistics.min = min;
    statistics.max = max;
    } else{
    statistics.average = NAN;
    statistics.min = NAN;
    statistics.max = NAN;
    }
    return statistics;  
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats){
    //If the maximum value exceeded threshold, raise an alert
	if(computedStats.max >  maxThreshold){
		alerters[0]();
		alerters[1]();
	}
}
