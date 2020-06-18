#include "display.h"

#define DEBUG_LEVEL 5
#define INFO_LEVEL  1

#define LOG_LEVEL 5 //1 INFO, 5 DEBUG
#define LOG_TO_SERIAL true
#define LOG_TO_LCD true



void logDebug(String message, float value) {
   
    if (LOG_LEVEL >= DEBUG_LEVEL) {
        if(LOG_TO_SERIAL == true){
            Serial.print(message);
            Serial.println(value);
        }
        if(LOG_TO_LCD == true){
            display_print(0,message);
            display_print(1,String(value));
        }
    }
}

void logDebug(String message) {
    
    if (LOG_LEVEL >= DEBUG_LEVEL) {
        if(LOG_TO_SERIAL == true){
            Serial.print(message);
        }
        if(LOG_TO_LCD == true){
            display_print(0,message);
        }
    }
}


void logInfo(String message) {
    if (LOG_LEVEL >= INFO_LEVEL) {
        if(LOG_TO_SERIAL == true){
            Serial.print(message);
        }
        if(LOG_TO_LCD == true){
            display_print(0,message);
        }
    }
}
void logInfo(String message, float value){
    if (LOG_LEVEL >= INFO_LEVEL) {
        if(LOG_TO_SERIAL == true){
            Serial.print(message);
            Serial.println(value);
        }
        if(LOG_TO_LCD == true){
            display_print(0,message);
            display_print(1,String(value));
        }
    }
}

