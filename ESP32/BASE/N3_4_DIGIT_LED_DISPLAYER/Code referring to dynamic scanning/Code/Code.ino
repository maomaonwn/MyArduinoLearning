//加入动态扫描，让一同显示一个四位数字

int seg_1 = 5;
int seg_2 = 18;
int seg_3 = 19;
int seg_4 = 21;
int seg_array[4] = {seg_1, seg_2, seg_3, seg_4};

int a = 32;
int b = 25;
int c = 27;
int d = 12;
int e = 13;
int f = 33;
int g = 26;
int dp = 14;
int led_array[8] = {a, b, c, d, e, f, g, dp};

int logic_array[10][8] = {                                              //这里的4位数码管是共阴极的，与共阳极时的电平相反，即共阳时为1，共阴时应该为0.
 //a, b, c, d, e, f, g, dp
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 1, 0, 1, 1, 0}, // 9
  };
  
void clear();
void display_number(int order,int number);
void display_4_number(int number);

//请输入显示的四位数：
int number = 2024;

void setup() {
  for(int i=0;i<8;i++){                                                  //如果要让线路导通，应有电势差，即需要让段选线高电平，位选线低电平。但初始化时不让导通，所以这里相反。
    pinMode(led_array[i],OUTPUT);
    digitalWrite(led_array[i],LOW);
  }
  for(int i=0;i<4;i++){
    pinMode(seg_array[i],OUTPUT);
    digitalWrite(seg_array[i],HIGH);
  }
}





void loop() {
  

  
}





void display_4_number(int number){
  if(number<10000){
    int arr3[4] = {0};
    for(int i=0;i<4;i++){
      arr3[i] = number%10;
      number/=10;
    }

    for(int i=0;i<4;i++){
      display_number(i,arr3[3-i]);
      delay(50);
    }
  } 
}
void display_number(int order,int number){
  clear();                                                              //清屏函数：要把之前设为低电平的位选线给重置掉，否则两个数码管会同时显示（且是一样的数字：因为段选线是统一控制的）
  
  digitalWrite(seg_array[order],LOW);
  for(int i=0;i<8;i++){
    digitalWrite(led_array[i],logic_array[number][i]);
  }
}
void clear(){                                                           //之前的初始化代码
  for(int i=0;i<8;i++){                                                  
    pinMode(led_array[i],OUTPUT);
    digitalWrite(led_array[i],LOW);
  }
  for(int i=0;i<4;i++){
    pinMode(seg_array[i],OUTPUT);
    digitalWrite(seg_array[i],HIGH);
  }
}
