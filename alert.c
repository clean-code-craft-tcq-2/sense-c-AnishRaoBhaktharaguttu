#include <stdio.h>
#include "alert.h"

int emailAlertCallCount=0;
int ledAlertCallCount=0;

//When the LED alert is raised, the led alert counter is incremented
void alert_by_led(){
	ledAlertCallCount++;
}
//When the email alert is raised, the email alert counter is incremented
void alert_by_email(){
	emailAlertCallCount++;
}
