//循环遍历所有LED灯，检查点阵屏的LED是否正常

//定义行引脚数组
  int row_array[8] = {13,25,2,27,23,4,22,18};
  //定义列引脚数组
  int col_array[8] = {26,21,19,12,5,14,33,32};
  
void setup() {
  //配置行引脚，并且初始化为低电平(刚开始使灯熄灭，此处是使用的共阳级点阵屏)
  for(int i=0;i<0;i++){
    pinMode(row_array[i],OUTPUT);
    digitalWrite(row_array[i],LOW);
  }
  //配置列引脚，并且初始化为高电平
  for(int i=0;i<0;i++){
    pinMode(col_array[i],OUTPUT);
    digitalWrite(col_array[i],HIGH);
  }
}

void loop() {
  //遍历所有的LED
  for(int i=0;i<8;i++){
    digitalWrite(row_array[i],HIGH);
    for(int j=0;j<8;j++){
      digitalWrite(col_array[j],LOW);
      delay(100);
      digitalWrite(col_array[j],HIGH);
    }
    digitalWrite(row_array[i],LOW);
  }
  
}
