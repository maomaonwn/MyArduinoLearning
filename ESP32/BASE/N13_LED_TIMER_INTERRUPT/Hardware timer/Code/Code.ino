//定时器中断与LED闪烁

#define LED      2
#define LED_ONCE 4

hw_timer_t *timer = NULL;
hw_timer_t *timer_once = NULL;

void timer_interrupt();
void timer_interrupt_once();

void setup(){
  pinMode(LED,OUTPUT);
  pinMode(LED_ONCE,OUTPUT);

  //初始化定时器
  timer = timerBegin(0,80,true);
  timer_once = timerBegin(1,80,true);

  //配置定时器
  timerAttachInterrupt(timer,timer_interrupt,true);
  timerAttachInterrupt(timer_once,timer_interrupt_once,true);

  //设置定时器模式
  timerAlarmWrite(timer,1000*1000,true);                     //1s=1000*1000 μs
  timerAlarmWrite(timer_once,3000*1000,false);

  //启动定时器
  timerAlarmEnable(timer);
  timerAlarmEnable(timer_once);
}


void loop(){
  
}


void timer_interrupt(){
  digitalWrite(LED,!digitalRead(LED));
}
void timer_interrupt_once(){
  digitalWrite(LED_ONCE,!digitalRead(LED_ONCE));
}
