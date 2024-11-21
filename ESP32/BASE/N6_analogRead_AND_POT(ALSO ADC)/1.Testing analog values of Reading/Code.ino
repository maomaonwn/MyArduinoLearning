//在串口屏中打印电位计的模拟输入信号

#define POT 26
#define LED 13

int pot_value;                                         //初始化电位计输入信号



void setup() {
  //设置串口通信的波特率(设置好一次后就可以建立通信，所以放在setup函数中）
  Serial.begin(9600);
  pinMode(POT,INPUT); 

}



void loop() {
  pot_value = analogRead(POT);                         //读取电位计模拟输入值
  Serial.println(pot_value);                           //打印这个值在串口屏上
  delay(50);
}
