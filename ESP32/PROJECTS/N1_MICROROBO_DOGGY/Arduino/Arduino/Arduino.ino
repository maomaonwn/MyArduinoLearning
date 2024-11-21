#define FREQ       40
#define RESOLUTION 12                                 //ADC默认分辨率为12，所以让LEDC分辨率也为外设，就可以直接使用输入的逻辑信号了
#define SERVO_PIN_1 34
#define SERVO_PIN_2 33
#define SERVO_PIN_3 14
#define SERVO_PIN_4 13

int last_1 = 90;
int last_2 = 90;
int last_3 = 90;
int last_4 = 90;

#define PS2_X 15
#define PS2_Y 2
#define SW    4
int val_PS2_X;
int val_PS2_Y;
int min_width = 0.5 / 20 *pow(2,RESOLUTION);         //是舵机的最小/最大脉宽
int max_width = 2.5 / 20 *pow(2,RESOLUTION);

int calculatePWM(int degree);
void servos(int now_1,int now_2,int now_3,int now_4);





void setup() {
//N1_配置PWM信号
  //建立LEDC通道
  ledcSetup(0,FREQ,RESOLUTION);
  ledcSetup(1,FREQ,RESOLUTION);
  ledcSetup(2,FREQ,RESOLUTION);
  ledcSetup(3,FREQ,RESOLUTION);

  //关联GPIO口与LEDC通道
  ledcAttachPin(SERVO_PIN_1,0);
  ledcAttachPin(SERVO_PIN_2,1);
  ledcAttachPin(SERVO_PIN_3,2);
  ledcAttachPin(SERVO_PIN_4,3);

//N2_配置PS2摇杆模块
  pinMode(PS2_X,INPUT);
  pinMode(PS2_Y,INPUT);
  pinMode(SW,INPUT_PULLUP);

//N3_舵机初始化
  ledcWrite(0,last_1);
  ledcWrite(1,last_2);
  ledcWrite(2,last_3);
  ledcWrite(3,last_4);
  delay(1000);
}





void loop() {
//N1_映射摇杆的逻辑值并测试
  val_PS2_X = map(analogRead(PS2_X),0,pow(2,RESOLUTION),min_width,max_width);
  val_PS2_Y = map(analogRead(PS2_Y),0,pow(2,RESOLUTION),min_width,max_width);
  Serial.begin(9600);
  Serial.printf("x%d,y%d,z%d,映射后的xy%d和%d\n",analogRead(PS2_X),analogRead(PS2_Y),digitalRead(SW),val_PS2_X,val_PS2_Y);
  delay(100);

//N2_使用摇杆控制机器人执行不同的步态或姿态
  if(val_PS2_Y <200){
    go();
  }
  if(val_PS2_Y >300){
    back();
  }
  if(val_PS2_X <200){
    turnleft();
  }
  if(val_PS2_X >300){
    turnright();
  }
  if(digitalRead(SW)!=1){
    posture1();
  }
}




//Func1_计算舵机转动角度对应的PWM逻辑值的函数
int calculatePWM(int degree){
  int min_width = 0.5 / 20 * pow(2,RESOLUTION);
  int max_width = 2.5 / 20 * pow(2,RESOLUTION);

  //50°的逻辑值：（max_width - min_width) * 50 /180 + min_width
  //这里必须先乘度数，再除180，不然这里的转换不能成功
  return (max_width - min_width)*degree /180 +min_width;
}

//Func2_根据当前位置和目标位置并通过延时来分发控制舵机的函数
void servos(int now_1,int now_2,int now_3,int now_4){
  int val_1;
  int val_2;
  int val_3;
  int val_4;

  val_2 = (now_2 - last_2)/30;
  val_4 = (now_4 - last_4)/30;
  val_1 = (now_1 - last_1)/30;
  val_3 = (now_3 - last_3)/30;

  for(int i=0;i<30;i++){
    last_2 = last_2 + val_2;
    last_4 = last_4 + val_4;
    last_1 = last_1 + val_1;
    last_3 = last_3 + val_3;

    ledcWrite(0,calculatePWM(last_1));
    ledcWrite(1,calculatePWM(last_2));
    ledcWrite(2,calculatePWM(last_3));
    ledcWrite(3,calculatePWM(last_4));
    delay(5);
  }
}

//Func3_前进步态函数
void go(void){
//N1_先出右腿的第一个周期
  servos(90,50,50,90);
  servos(130,50,50,130);
  servos(130,90,90,130);
  servos(90,90,90,90);
//N2_先出左腿的第二个周期
  servos(50,90,90,50);
  servos(50,130,130,50);
  servos(90,130,130,90);
  servos(90,90,90,90);
}

//Func4_后退步态函数_是前进步态的倒序
void back(void){
//N1_先出右腿的第一个周期
  servos(90,130,130,90);
  servos(50,130,130,50);
  servos(50,90,90,50);
  servos(90,90,90,90);
//N2_先出左腿的第二个周期
  servos(130,90,90,130);
  servos(130,50,50,130);
  servos(90,50,50,90);
  servos(90,90,90,90);
}

//Func5_右转步态函数
void turnright(void){
  servos(90,130,50,90);
  servos(130,130,50,50);
  servos(130,90,90,50);
  servos(90,90,90,90);
}

//Func6_左转步态函数
void turnleft(void){
  servos(130,90,90,50);
  servos(130,130,50,50);
  servos(90,130,50,90);
  servos(90,90,90,90);
}

//Func6_右前招手姿态函数
void posture1(void){
  servos(90,100,90,90);
  servos(90,145,90,90);
  servos(90,180,90,90);
  servos(90,145,90,90);
}
