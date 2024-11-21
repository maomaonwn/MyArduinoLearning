//单个舵机转动代码

#define FREQ         50
#define CHANNEL      0
#define RESOLUTION   8
#define SERVO        13

int calculatePWM(int degree);

void setup() {
  //建立LEDC通道
  ledcSetup(CHANNEL,FREQ,RESOLUTION);

  //关联GPIO口与LEDC通道
  ledcAttachPin(SERVO,CHANNEL);


}

void loop() {
  ledcWrite(CHANNEL,calculatePWM(0));
  delay(500);
  ledcWrite(CHANNEL,calculatePWM(90));
  delay(500);
 
 
}



int calculatePWM(int degree){
  int min_width = 0.5 / 20 * pow(2,RESOLUTION);
  int max_width = 2.5 / 20 * pow(2,RESOLUTION);

  //50°的逻辑值：（max_width - min_width) * 50 /180 + min_width
  //这里必须先乘度数，再除180，不然这里的转换不能成功
  return (max_width - min_width)*degree /180 +min_width;
}
