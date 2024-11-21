#include<Arduino.h>
#include<ESP32Servo.h>

            
int last_1;                     //1左前、2右前、3左后、4右后
int last_2;
int last_3;
int last_4;

#define SERVO_PIN_1 13
#define SERVO_PIN_2 25
#define SERVO_PIN_3 34
#define SERVO_PIN_4 18

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;



void setup() {
//N1_配置舵机
  //分配硬件定时器
ESP32PWM::allocateTimer(0);
ESP32PWM::allocateTimer(1);
ESP32PWM::allocateTimer(2);
ESP32PWM::allocateTimer(3);
  //设置频率
servo1.setPeriodHertz(50);
servo2.setPeriodHertz(50);
servo3.setPeriodHertz(50);
servo4.setPeriodHertz(50);
  //关联Servo对象与GPIO引脚，设置脉宽范围
servo1.attach(SERVO_PIN_1,500,2500);
servo2.attach(SERVO_PIN_2,500,2500);
servo3.attach(SERVO_PIN_3,500,2500);
servo4.attach(SERVO_PIN_4,500,2500);

//N2_初始化舵机
servo1.write(90);
last_1 = 90;
servo2.write(90);
last_2 = 90;
servo3.write(90);
last_3 = 90;
servo4.write(90);
last_4 = 90;
delay(1000);
}

void loop() {
  

}

