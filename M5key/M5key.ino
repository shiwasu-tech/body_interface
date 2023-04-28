/*
  mode1 = presentation
  mode2 = browsing
  mode3 = media
  mode4 = individual-keys

  mode1>Btn1>IMU = arrow        <141~144>   "slide <-/->"
       >Btn2>IMU = alt+tab      <151~154>   "window cange"
       >Btn1>Btn2= play/pause   <131>       "media play/pause"
  
  mode2>Btn1>IMU = arrow*5      <241~244>   "scroll"
       >Btn2>IMU = alt+arrow    <251~254>   "go/back"
       >Btn1>Btn2= F5           <231>       "reload"
  
  mode3>Btn1>IMU = media-<>⋀⋁   <341~344>   "next/previouse/Fullscreen/unFullscreen"
       >Btu2>IMU = volume-Dn/Up <351~354> 
       >Btn1>Btn2= play/pause   <331>

  mode4>Btn1     = arrow
       >Btn1>Btn2= anykey       <431>       "you can choose from assets"

    assets = "arrow","PgUp/PgDn","Enter","F5","Play/Pause","next/previous","alt + arrow","alt + tab","ctrl + z/ctrl + shift + z","Fullscreen/unFullscreen"
*/
/*
  mode0 = Phone

  mode0>Btn1>IMU = 
       >Btn2>IMU = 
       >Btn1>Btn2= shutter
*/

#include <M5Unified.h> // M5Unifiedライブラリをプログラムで使用可能にします。
#include <BleKeyboard.h>  // https://github.com/T-vK/ESP32-BLE-Keyboard

// グローバル変数（プログラム全体で使用する変数の定義をします。）
uint32_t count;

int BTN1 = 26;

int mode = 1;

int keytemp = 0;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;


BleKeyboard bleKeyboard("M5StickCPlus");  //デバイス名

const int longPress_ms = 300;  // 長押し判定時間(ms)

void KeySend(int mode,int com){
  com = mode * 100 + com;
  if(com == 141){
    blekeyboard.press(KEY_RIGHT_ARROW);
  }else if(com == 142){
    blekeyboard.press(KEY_LEFT_ARROW);
  }else if(com == 143){
    blekeyboard.press(KEY_DOWN_ARROW);
  }else if(com == 144){
    blekeyboard.press(KEY_UP_ARROW);
  }else if(com == 151){
    blekeyboard.press(KEY_);
  }else if(com == 152){
    blekeyboard.press(KEY_);
  }else if(com == 153){
    blekeyboard.press(KEY_);
  }else if(com == 154){
    blekeyboard.press(KEY_);
  }else if(com == 130){
    blekeyboard.press(KEY_);
  }else if(com == ){
    blekeyboard.press(KEY_);
  }else if(com == ){
    blekeyboard.press(KEY_);
  }else if(com == ){
    blekeyboard.press(KEY_);
  }else if(com == ){
    blekeyboard.press(KEY_);
  }else if(com == ){
    blekeyboard.press(KEY_);
  }else if(com == ){
    blekeyboard.press(KEY_);
  }
  delay(100);
  blekeyboard.releaseAll();
  delay(100);
}

void Mode1to3(int mode){
  M5.Display.drawTriangle(); // mode select UI
  M5.Display.drawTriangle(); //keyboard UI etc...

  keytemp = 0;

  if(blekeyboard.isConnected()){
    M5.Display.print("BLE connected");
    //BLE status

    M5.Imu.getGyro(&gyroX,&gyroY,&gyroZ);

    if(digitalRead(BTN1) == 0){

      if(digitalRead(BTN2) == 1){
        
        // This scope is " Btn1 ∧ IMU "
        keytemp =+ 40;

        if(gyroX > 200 || gyroY < -200 || gyroZ > 200){
          keytemp =+ 1;
        }else if(gyroX < -200 || gyroY > 200 || gyroZ < -200){
          keytemp =+ 2;
        }

      }else{

        //This scope is " Btn1 ∧ Btn2 "

        keytemp =+ 30;
        keysend(mode,keytemp);
      }

    }else if(digitalRead(BTN2) == 0){

      // This scope is " Btn2 ∧ IMU　"
      keytemp =+ 50;

      if(gyroX > 200 || gyroY < -200 || gyroZ > 200){
          keytemp =+ 1;
        }else if(gyroX < -200 || gyroY > 200 || gyroZ < -200){
          keytemp =+ 2;
        }

    }

    KeySend(mode,keytemp);
  }else{
    M5.Display.print("BLE connecting...");
  }
}

void mode4(){

}



void setup() {

  auto cfg = M5.config();       // M5Stack初期設定用の構造体を代入
  // configを設定する場合はここで設定
  // 例
  // cfg.external_spk = true;
  cfg.internal_imu = true;
  M5.begin(cfg);   

  pinMode(A,INPUT_PULLUP);

  M5.Lcd.setRotation(1);                 
  M5.Display.setTextSize(1);           
  M5.Lcd.setCursor(20, 10);
  M5.Display.print("Presentation-Mode");      
  M5.Lcd.setCursor(20, 45);
  M5.Display.print("Browse-Mode");
  M5.Lcd.setCursor(20, 80);
  M5.Display.print("Codeing-Mode");
  M5.Lcd.drawTriangle(5, 5, 15, 5, 15, 10, RED);

  Serial.begin(115200);
  Serial.println("BLE Begin");
  bleKeyboard.begin();

  M5.Imu.begin();
  
  count = 0;                               
}

void loop() {
  M5.update();

  if(M5.BtnA.isPressed()){
    mode += 1;
    if(mode > 4){
      mode = 1;
    }
  }
  

}




/*
if(bleKeyboard.isConnected()){

      if(digitalRead(BTN1) == 0){

        M5.Imu.getGyro(&gyroX,&gyroY,&gyroZ);

        if(gyroY > 200 || gyroX > 200 || gyroZ > 200){


          bleKeyboard.press(KEY_LEFT_ARROW);
          delay(100);
          bleKeyboard.releaseAll();

          delay(1000);

          
        }else if(gyroY < -200 || gyroX < -200 || gyroZ < -200){

          bleKeyboard.press(KEY_RIGHT_ARROW);
          delay(100);
          bleKeyboard.releaseAll();

          delay(1000);

        }

        
      }

    }else{
  
        M5.Lcd.setCursor(20, 100);

        M5.Display.print("BLE connecting...");

        delay(500);
      }
      */