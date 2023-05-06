#include <M5Unified.h>
#include <BleMouse.h>

const int BTN1 = 26;

float accX  = 0.0F;
float accY  = 0.0F;
float accZ  = 0.0F;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;

float roll  = 0.0F;
float pitch = 0.0F;
float yaw   = 0.0F;

int dir = 0; //-1:左ひねり 0:水平 1:右ひねり
int motion = 0; //

const float pi  = 3.14;

BleMouse BleMouse("M5-IMUmouse");

void readGyro(){
  M5.Imu.getAccel(&accX, &accY, &accZ);             // 加速度の取得
  M5.Imu.getGyro(&gyroX, &gyroY, &gyroZ);           // 角速度の取得
  roll  =  atan(accX / sqrt((accY * accY) + (accZ * accZ))) * 180 / pi; 
  pitch =  atan(accY / sqrt((accX * accX) + (accZ * accZ))) * 180 / pi; 
  yaw   =  atan(sqrt((accX * accX) + (accY * accY)) / accZ) * 180 / pi;
}





void setup() {

  auto cfg = M5.config();       // M5Stack初期設定用の構造体を代入
  // configを設定する場合はここで設定
  // 例
  // cfg.external_spk = true;
  cfg.internal_imu = true;
  M5.begin(cfg);   

  pinMode(BTN1,INPUT_PULLUP);
  //pinMode(BTN2,INPUT_PULLUP);
  //gpio_pullup_dis(GPIO_NUM_36);
  //gpio_pulldown_dis(GPIO_NUM_36);
  

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
  //UIinit(1,0);

  BleMouse.begin();

  M5.Imu.begin();
                               
}

void loop() {
  
  readGyro();

  if(digitalRead(BTN1) == 0){
    if(roll < -30){

      BleMouse.release(MOUSE_LEFT);

      if(gyroX > 20 || gyroX < -20 || gyroZ > 20 || gyroZ < -20){

        BleMouse.move(gyroX/5,-gyroZ/5);

      }

    }else if(roll > 30){

      BleMouse.press(MOUSE_LEFT);

      if(gyroX > 20 || gyroX < -20 || gyroZ > 20 || gyroZ < -20){
        
        BleMouse.move(-gyroX/5,gyroZ/5);

      }

    }else{
      
      BleMouse.release(MOUSE_LEFT);
      BleMouse.release(MOUSE_RIGHT);

    }
  }
  delay(10);
}
