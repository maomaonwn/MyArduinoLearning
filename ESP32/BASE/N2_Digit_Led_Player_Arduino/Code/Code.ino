int pin_g = 27;                                                                  //设置引脚
int pin_f = 26;
int pin_a = 25;
int pin_b = 33;
int pin_e = 32;
int pin_d = 15;
int pin_c = 21;
int pin_dp = 23;
int pin_array[8] = {pin_g, pin_f, pin_a, pin_b, pin_e, pin_c, pin_dp};


int number_array[][8] = {                                                       //设置"数字"对应的电平
    {0, 0, 0, 0, 0, 0, 1, 1}, // 0
    {1, 0, 0, 1, 1, 1, 1, 1}, // 1
    {0, 0, 1, 0, 0, 1, 0, 1}, // 2
    {0, 0, 0, 0, 1, 1, 0, 1}, // 3
    {1, 0, 0, 1, 1, 0, 0, 1}, // 4
    {0, 1, 0, 0, 1, 0, 0, 1}, // 5
    {0, 1, 0, 0, 0, 0, 0, 1}, // 6
    {0, 0, 0, 1, 1, 1, 1, 1}, // 7
    {0, 0, 0, 0, 0, 0, 0, 1}, // 8
    {0, 0, 0, 0, 1, 0, 0, 1}, // 9
};
void displayNumber(int num){                                                   //显示"数字"的函数
   for(int i=0;i<8;i++){
    digitalWrite(pin_array[i],number_array[num][i]);
   }
}                                                                     






void setup() {                                     
  for (int i = 0; i < 8; i++) {
    pinMode(pin_array[i], OUTPUT);
    digitalWrite(pin_array[i], HIGH);
  }
}





void loop() {
  for(int i=0;i<10;i++){
    displayNumber(i);
    delay(500);
  }
}
