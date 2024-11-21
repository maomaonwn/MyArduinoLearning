//通过PS2摇杆模块控制舵机转动

#define PS2_X      15
#define PS2_Y      2
#define SW         4
#define SERVO      13

#define RESOLUTION 12                 //ADC默认分辨率为12，所以让LEDC分辨率也为外设，就可以直接使用输入的逻辑信号了
#define CHANNEL    0
#define FREQ       50

//设置舵机需要的最大/最小脉宽值(转换成逻辑值)
int min_width = 0.5 / 20 *pow(2,RESOLUTION);
int max_width = 2.5 / 20 *pow(2,RESOLUTION);
//PS2需要的逻辑值
int value;

void setup() {
  pinMode(PS2_X,INPUT);
  pinMode(PS2_Y,INPUT);
  pinMode(SW,INPUT_PULLUP);

  Serial.begin(9600);

  //设置LEDC通道的频率和分辨率
  ledcSetup(CHANNEL,FREQ,RESOLUTION);
  //关联通道与GPIO
  ledcAttachPin(SERVO,CHANNEL);
}

void loop() {
  value = map(analogRead(PS2_Y),0,pow(2,RESOLUTION),min_width,max_width);                                  //map函数又称为映射函数，主要将范围为a的一个变量，等比例转换到b中
  
  //读取数值
  Serial.printf("x:%d,y:%d,z:%d,映射后的y:%d\n",analogRead(PS2_X),analogRead(PS2_Y),digitalRead(SW),value);
  delay(100);

  //输出PWM
  ledcWrite(CHANNEL,value);
}
