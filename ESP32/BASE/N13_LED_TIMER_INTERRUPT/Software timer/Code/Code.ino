//定时器与LED闪烁

#include <Ticker.h>

#define LED 2
#define LED_ONCE 4

//定义定时器对象
Ticker timer;
Ticker timer_once;



void setup() {
  pinMode(LED,OUTPUT);
  pinMode(LED_ONCE,OUTPUT);

  //配置定时器
  timer.attach(0.5,);
  timer_once.once(3,

}

void loop() {
  // put your main code here, to run repeatedly:

}
