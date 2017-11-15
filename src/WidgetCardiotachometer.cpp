
#include "WidgetCardiotachometer.h"


WidgetCardiotachometer::WidgetCardiotachometer(uint8_t ucItem)
{
    _Item = ucItem;
    memset(pDataHeartRateTopic,0,sizeof(pDataHeartRateTopic));
    sprintf(pDataHeartRateTopic,"channel/cardiotachometer_%d/data/heartRate",_Item);
}

WidgetCardiotachometer::~WidgetCardiotachometer()
{

}

void WidgetCardiotachometer::begin(void (*UserCallBack)(void))
{

}

void WidgetCardiotachometer::displayHeartRate(int heartRate)
{
    IntoRobot.publish(pDataHeartRateTopic,heartRate);
}









