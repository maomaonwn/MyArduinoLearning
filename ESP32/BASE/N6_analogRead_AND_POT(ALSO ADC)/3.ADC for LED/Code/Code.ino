//使用ADC来控制LED亮度(而不是analogWrite来输出模拟值)

#define POT     26
#define LED     12
#define CHANNEL 0
#define FREQ    1000

int pot_value;

void setup() {
  analogReadResolution(12);                 //设置ADC分辨率，可以不写，用默认的12.
  analogSetAttenuation(ADC_11db);           //设置输入衰减，可以不写，默认11db

  ledcSetup(CHANNEL,FREQ,12);               //都是12，可以直接使用模拟输入值
  ledcAttachPin(LED,CHANNEL);
}

void loop() {
  //获取模拟信号输入值
  pot_value = analogRead(POT);
  //输出PWM
  ledcWrite(CHANNEL,pot_value);
  delay(50);
}
