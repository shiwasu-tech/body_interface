#include <M5Unified.h>
#include <BleMouse.h>
#include <Wire.h>
#define JOY_ADDR 0x52

static int x,y,btn;

const int BTN1 = 26;
const int BTN2 = 25;

int mode = 1;
int msdir = 1;

int mstemp = 0;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;

BleMouse BleMouse("M5-joymouse");


void MsSend(int mode,int com){
  com = mode * 100 + com;
  
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
  /*
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
    */

  //manual
  

  //pertition draw
  M5.Lcd.drawLine(0,21,240,21,WHITE);
  M5.Lcd.drawLine(135,22,135,102,DARKGREY);
  M5.Lcd.drawLine(0,103,240,103,DARKGREY);

  //UI initialize
  UIinit(1,0);

  BleMouse.begin();
  Wire.begin(32, 33);  
  M5.Imu.begin();
                               
}

void loop() {
  Wire.requestFrom(JOY_ADDR, 3);
  if(Wire.available()) { //If data is received.
    
    x = Wire.read();
    y = Wire.read();
    btn = Wire.read();

    x -= 130;
    y -= 130;

  }

  
  if(btn == 0){
    BleMouse.release(MOUSE_MIDDLE);
    if(x>10||x<-10||y>10||y<-10){
      BleMouse.move(-x/10,y/10);

    }
  }else{
    if(x>10||x<-10||y>10||y<-10){
      BleMouse.press(MOUSE_MIDDLE);
      BleMouse.move(-x/10,y/10);

    }
  }
  delay(10);
}
