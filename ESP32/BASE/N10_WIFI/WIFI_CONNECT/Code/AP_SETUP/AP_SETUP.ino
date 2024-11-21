//创建ESP32的热点

#include<WiFi.h>

//设置名称密码
const char * ssid = "ESP32_AP";
const char * password = "13456789";

void setup() {
 Serial.begin(9600);

 //创建热点
 WiFi.softAP(ssid,password);

 Serial.print("WIFI 接入的IP：");
 Serial.println(WiFi.softAPIP());

}

void loop() {
}
