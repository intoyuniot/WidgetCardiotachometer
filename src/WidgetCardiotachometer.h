#ifndef WIDGET_CARDIOTAOMETER_H_
#define WIDGET_CARDIOTAOMETER_H_

#include "application.h"


class WidgetCardiotachometer
{
    public:
        WidgetCardiotachometer(uint8_t ucItem = 0);
        ~WidgetCardiotachometer();
        void begin(void (*UserCallBack)(void) = NULL);
        void displayHeartRate(int heartRate);


    private:
        char pDataHeartRateTopic[64];
        uint8_t _Item=0;
};

#endif
