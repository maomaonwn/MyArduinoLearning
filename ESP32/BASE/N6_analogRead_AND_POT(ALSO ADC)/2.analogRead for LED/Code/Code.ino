//使用analogRead函数来点亮LED(需要进行analogWrite和analogRead模拟值区间的转换)

#define POT 26
#define LED 12

int pot_value;
int led_value;

void setup() {
  pinMode(POT,INPUT);
  pinMode(LED,OUTPUT);

}

void loop() {
  pot_value = analogRead(POT);                  //读取电位计模拟输入
   //把电位计模拟输入值转换为LED模拟输出
  led_value = pot_value/16; 
                     
  analogWrite(LED,led_value);
  delay(50);
  

}
