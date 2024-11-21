//使用Kevin Harrington的“ESP32Servo”库进行舵机实验

#include <ESP32Servo.h>

#define SERVO_PIN 18
#define MAX_WIDTH 2500
#define MIN_WIDTH 500

//定义Servo对象
Servo my_servo;



void setup() {
  //配置：
  //分配硬件定时器
  ESP32PWM::allocateTimer(0);

  //设置频率
  my_servo.setPeriodHertz(50);

  //关联Servo对象与GPIO引脚，设置脉宽范围
  my_servo.attach(SERVO_PIN,MIN_WIDTH,MAX_WIDTH);          //接最小、最大脉宽，单位微妙
}

void loop() {

  my_servo.write(90);
  delay(1000);

  my_servo.write(0);
  delay(1000);
}
