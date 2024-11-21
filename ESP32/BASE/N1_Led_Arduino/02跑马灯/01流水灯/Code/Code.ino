/*@Code 跑马灯——01单方向流动流水灯
  @Principle  让一组引脚逐渐变为高电平，然后再逐渐变为低电平
  @Author 毛毛maomaonwn
  @Date 2023/12/1        */


  int Pin_List[4] = {13,14,26,33};
  int num = sizeof(Pin_List)/sizeof(Pin_List[0]);

void setup() {
  for(int i=0;i<num;i++){
    pinMode(Pin_List[i],OUTPUT);
  }
}

void loop() {
  for(int i=0;i<num;i++){
    digitalWrite(Pin_List[i],HIGH);
    delay(100);
  }
  delay(100);
  for(int i=0;i<num;i++){
    digitalWrite(Pin_List[i],LOW);
    delay(100);
  }

}
