// 定义 LED 与 按键引脚
int led_pin = 2;
int button_pin = 14;

// 定义 LED 逻辑值
int led_logic = 0;
// 判断 LED 的状态是否改变过
bool status = false;


void setup() {  
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT_PULLDOWN);
}

void loop() {
  // 按键消抖
  if (digitalRead(button_pin)) {
    // 睡眠 10ms，如果依然为高电平，说明抖动已消失。
    delay(10);
    if (digitalRead(button_pin) && !status) {
      led_logic = !led_logic;
      digitalWrite(led_pin, led_logic);
      // led 的状态发生了变化，即使我持续按着按键，LED 的状态也不应该改变。
      status = !status;
      }else if (!digitalRead(button_pin)) {
        status = false;  
      }
    }
}
