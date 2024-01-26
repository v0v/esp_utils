#ifndef VB_F_H
    #define VB_F_H

    #include "time.h"
    #include <Arduino.h>
    #include <ElegantOTA.h>
    #include "display_config.h"

    extern int timeCurrentHourOfTheDay;
    
    extern String printLocalTime();
    extern void onOTAStart();
    extern void onOTAProgress(size_t current, size_t final);
    extern void onOTAEnd(bool success);

#endif
