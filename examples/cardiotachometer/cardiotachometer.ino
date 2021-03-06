/*
 ************************************************************************
 * 作者:  IntoRobot Team
 * 版本:  V1.0.0
 * 日期:  03-30-15
 ************************************************************************
 功能描述：
 心率计：检测人体心率

 所需器件:
 1.心率传感器模块

 接线说明:
 心率传感器模块                核心板
 1.+                          +3.3V
 2.-                           GND
 3.S                           A0

 说明：带有“D”的为数字管脚，带有“A”的为模拟管脚，接线时请确认核心板引脚，避免接线错误。

 此例程只支持Atom核心板，但是此应用库不受限制
 */

#include <PulseSensor.h>
#include <WidgetCardiotachometer.h>

#define SENSOR_PIN    A0

PulseSensor pulseSensor(SENSOR_PIN);  // 脉冲输入信号管脚A0
IntoRobotIntervalTimer pulseTimer;

WidgetCardiotachometer cardio = WidgetCardiotachometer();

void pulseISRFun(void)
{
    pulseSensor.PulseISR();
}

void setup()
{
    pulseSensor.begin();
    pulseTimer.begin(pulseISRFun, 2000, uSec); //设定中断程序并闪烁LED灯，2ms一次
}

void loop()
{
    cardio.displayHeartRate(pulseSensor.GetBPM()); //上送心率值
    delay(3000);
}

