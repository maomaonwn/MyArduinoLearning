//使用PS2摇杆操控舵机(使用第三方库)
#include<ESP32Servo.h>

#define PS2_X      15
#define PS2_Y      2
#define SW         4
#define SERVO      13

#define RESOLUTION 12                 //ADC默认分辨率为12，所以让LEDC分辨率也为外设，就可以直接使用输入的逻辑信号了
#define FREQ       50

Servo my_servo;

//PS2需要的逻辑值
int value;

void setup() {
  pinMode(PS2_X,INPUT);
  pinMode(PS2_Y,INPUT);
  pinMode(SW,INPUT_PULLUP);

  Serial.begin(9600);

  //分配硬件定时器
  ESP32PWM::allocateTimer(0);
  //设置频率
  my_servo.setPeriodHertz(FREQ);
  //关联Servo对象与GPIO引脚，设置脉宽范围
  my_servo.attach(SERVO,500,2500);
}

void loop() {
  value = map(analogRead(PS2_Y),0,pow(2,RESOLUTION),min_width,max_width);                                  //map函数又称为映射函数，主要将范围为a的一个变量，等比例转换到b中
  
  //读取数值
  Serial.printf("x:%d,y:%d,z:%d,映射后的y:%d\n",analogRead(PS2_X),analogRead(PS2_Y),digitalRead(SW),value);
  delay(100);

  //输出PWM
  my_servo.write(value);
  delay(100);
}
