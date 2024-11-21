//使ESP32连接WIFI，并在串口屏打印相关信息

#include<WiFi.h>

//定义WiFi名与密码
const char * ssid = "要成为摸鱼王";
const char * password = "13456789";

#define LED 2                                                     //板载LED的引脚是2



void setup() {
//连接Wifi以及判断是否连接成功、并返回本地IP地址

  
  Serial.begin(9600);
  
  //连接WIFI
  WiFi.begin(ssid,password);
  Serial.println("正在连接 WiFi");
  
  
  
  //检测是否连接成功
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print("...");
  }
  //串口监视器里的反馈
  Serial.println("连接成功");
  Serial.print("IP地址：");
  Serial.println(WiFi.localIP());
  //板载LED的反馈
  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH);
  delay(100);
  digitalWrite(LED,LOW);
  delay(100);

  digitalWrite(LED,HIGH);
  delay(100);
  digitalWrite(LED,LOW);
  delay(100);

  digitalWrite(LED,HIGH);
  delay(1500);
  digitalWrite(LED,LOW);
}

void loop() {

}
