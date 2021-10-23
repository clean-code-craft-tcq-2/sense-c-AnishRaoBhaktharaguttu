#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
extern "C" {
	#include "stats.h"
	#include "alert.h"
}

#include <stdlib.h>
#include <math.h>

TEST_CASE("reports average, minimum and maximum") {
    float numberset[] = {1.5, 8.9, 3.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    struct Stats computedStats = compute_statistics(numberset, setlength);
    float epsilon = 0.001;
    REQUIRE(abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(abs(computedStats.min - 1.5) < epsilon);
}


TEST_CASE("average is NaN for empty array") {
	struct Stats computedStats;
    float numberset[] = {};
	int setlength = sizeof(numberset) / sizeof(numberset[0]);
	computedStats = compute_statistics(numberset, setlength);
   	REQUIRE(isnan(computedStats.average) == true); 
   	REQUIRE(isnan(computedStats.max) == true); 
   	REQUIRE(isnan(computedStats.min) == true); 
}

TEST_CASE("raises alerts when max is greater than threshold") {
    alerter_funcptr alerters[] = {alert_by_email, alert_by_led};

    float numberset[] = {99.8, 34.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    Stats computedStats = compute_statistics(numberset, setlength);

    const float maxThreshold = 10.2;
    check_and_alert(maxThreshold, alerters, computedStats);

    REQUIRE(emailAlertCallCount == 1);
    REQUIRE(ledAlertCallCount == 1);
}
