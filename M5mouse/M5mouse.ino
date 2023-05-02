
#include <M5Unified.h>
#include <BleMouse.h>

const int BTN1 = 26;
const int BTN2 = 25;

int mode = 1;
int msdir = 1;

int mstemp = 0;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;

BleMouse BleMouse("M5StickCPlus-mouse");


void MsSend(int mode,int com){
  com = mode * 100 + com;
  if(com == 141){
    BleKeyboard.press(KEY_RIGHT_ARROW);
  }else if(com == 142){
    BleKeyboard.press(KEY_LEFT_ARROW);
  }
}

void UIinit(int mode,int key){

  //mode UI arrow init
  M5.Lcd.fillTriangle(36,30,36,38,43,34,DARKGREY);
  M5.Lcd.fillTriangle(36,50,36,58,43,54,DARKGREY);
  M5.Lcd.fillTriangle(36,70,36,78,43,74,DARKGREY);
  M5.Lcd.fillTriangle(36,90,36,98,43,94,DARKGREY);

  if(mode == 1){
    M5.Lcd.fillTriangle(36,30,36,38,43,34,RED);
  }

  if(mode == 2){
    M5.Lcd.fillTriangle(36,50,36,58,43,54,RED);
  }

  if(mode == 3){
  M5.Lcd.fillTriangle(36,70,36,78,43,74,RED);
  }

  if(mode == 4){
    M5.Lcd.fillTriangle(36,90,36,98,43,94,RED);
  }

}

void setup() {

  auto cfg = M5.config();       // M5Stack初期設定用の構造体を代入
  // configを設定する場合はここで設定
  // 例
  // cfg.external_spk = true;
  cfg.internal_imu = true;
  M5.begin(cfg);   

  pinMode(BTN1,INPUT_PULLUP);
  pinMode(BTN2,INPUT_PULLUP);
  gpio_pullup_dis(GPIO_NUM_36);
  gpio_pulldown_dis(GPIO_NUM_36);
  

  //hand select
  M5.Lcd.setRotation(1); 
  M5.Lcd.setCursor(110,5);
  M5.Display.setTextSize(1);
  M5.Display.print("^ select hand/mode ");
  M5.Lcd.setCursor(30,120);
  M5.Display.print("enter/keyselect(selectable mode) >");
  M5.Lcd.setCursor(20,30);
  M5.Display.setTextSize(2);
  M5.Display.println("Which hand?");

  int hand = 1;
  while(1){

    M5.update();

    if(M5.BtnB.isPressed()){
      hand += 1;
      if(hand > 2){
        hand = 1;
      }
    }

    if(hand == 1){
      M5.Lcd.setCursor(20,50);
      M5.Lcd.setTextColor(BLUE, WHITE);
      M5.Display.print("1.RIGHT");
      M5.Lcd.setCursor(20,70);
      M5.Lcd.setTextColor(WHITE, BLACK);
      M5.Display.print("2.LEFT");
    }else{
      M5.Lcd.setCursor(20,50);
      M5.Lcd.setTextColor(WHITE, BLACK);
      M5.Display.print("1.RIGHT");
      M5.Lcd.setCursor(20,70);
      M5.Lcd.setTextColor(BLUE, WHITE);
      M5.Display.print("2.LEFT");
    }

    if(M5.BtnA.isPressed()){
      break;
    }

    delay(100);
  }

  M5.Display.clear();


  if(hand == 1){
    M5.Lcd.setRotation(1);                 
  }else{
    M5.Lcd.setRotation(3);
  }

  M5.Display.setTextSize(1); 

  //BLE print
  M5.Display.setCursor(7,6);
  M5.Display.setTextColor(BLUE,BLACK);
  M5.Display.print("BLE");

  //draw niC logo
  M5.Lcd.setCursor(155,6);
  M5.Lcd.setTextColor(YELLOW, NAVY);
  M5.Lcd.print("nitechCreate");
  M5.Lcd.setTextColor(WHITE,BLACK);

  //mode UI draw
  M5.Lcd.setCursor(10, 30);
  M5.Display.print("Mode");
  M5.Lcd.setCursor(50, 30);
  M5.Display.print("Presentation");
  M5.Lcd.setCursor(50, 50);
  M5.Display.print("Browsing");
  M5.Lcd.setCursor(50, 70);
  M5.Display.print("Media");
  M5.Lcd.setCursor(50, 90);
  M5.Display.print("Selectable");
  //M5.Lcd.setCursor(50, 85);
  //M5.Display.print("Phone");
  //M5.Lcd.setCursor(50, 100);
  //M5.Display.print("Mouse");

  //Manual
  M5.Lcd.fillRect(32,106,8,8,BLUE);
  M5.Lcd.setCursor(41,106);
  M5.Display.print("...Blue -Button + Motion.");
  M5.Lcd.fillRect(32,116,8,8,GREEN);
  M5.Lcd.setCursor(41,116);
  M5.Display.print("...Green-Button + Motion.");
  M5.Lcd.fillRect(32,126,8,8,RED);
  M5.Lcd.setCursor(41,126);
  M5.Display.print("...Blue -Button + Green-Button.");
  

  //pertition draw
  M5.Lcd.drawLine(0,21,240,21,WHITE);
  M5.Lcd.drawLine(135,22,135,102,DARKGREY);
  M5.Lcd.drawLine(0,103,240,103,DARKGREY);

  //UI initialize
  UIinit(1,0);

  BleKeyboard.begin();

  M5.Imu.begin();
                               
}

void loop() {
  
}
