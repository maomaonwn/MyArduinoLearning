//在LCD1602屏幕上显示Hello World

#include "LiquidCrystal_I2C.h"

// 设置 LCD1602 的地址，列数，行数
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // 初始化 LCD 对象
  lcd.init();
 
  // 打印内容
  lcd.backlight();
  lcd.print("Helloworld!");
}

void loop()
{
}
