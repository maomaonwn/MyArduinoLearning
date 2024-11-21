//通过PS2摇杆模块，在串口监视器中打印读取到的数值。

#define PS2_X 15
#define PS2_Y 2
#define SW    4


void setup() {
  pinMode(PS2_X,INPUT);
  pinMode(PS2_Y,INPUT);
  pinMode(SW,INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  //读取数值
  Serial.printf("x:%d,y:%d.z:%d\n",analogRead(PS2_X),analogRead(PS2_Y),digitalRead(SW));
  delay(100);

}


/*经过测试可知：y值范围0~4095（上~下）、x值范围0~4095（左~右）、y值范围0~1（按下~未按下）
