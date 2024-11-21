//使用按键实现开关灯


int led_pin = 2;
int button_pin = 14;

int led_logic = 0;

//定义记录LED状态是否更改过的值
bool status = false;                                                            

void setup() {
  pinMode(led_pin,OUTPUT);
  pinMode(button_pin,INPUT_PULLDOWN);                        //注意这里是INPUT模式并且设置下拉电阻(具体原因:略)
 
}

void loop() {
  //按键消抖
  if(digitalRead(button_pin)==1){
    delay(10);                                              //这里如果是10ms的话可能会有状态切换不灵敏的问题，适当延长就好
    
    if(digitalRead(button_pin)==1 && status==true){
      led_logic = !led_logic;                         
      digitalWrite(led_pin,led_logic);

      status = true;
    }
    else if(digitalRead(button_pin)== 0){
      status = false;
    }
  }

}



//代码可能有点问题，因为在做实验的时候，小灯没有亮。可以考虑修改下小灯的代码什么的。
