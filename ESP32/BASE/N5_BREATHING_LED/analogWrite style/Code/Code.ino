//实现呼吸灯(使用analogWrite()函数)

#define LED_PIN 12


void setup() {
  pinMode(LED_PIN,OUTPUT);
}


void loop() {
  //实现渐亮的效果
  for(int i=0;i<256;i++){
    analogWrite(LED_PIN,i);
    delay(10);
  }

  //实现渐灭效果
  for(int i=255;i>=0;i--){
    analogWrite(LED_PIN,i);
    delay(10);
  }
}
