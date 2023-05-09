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


const int BTN1 = 26;
const int BTN2 = 25;

int mode = 1;
int keynum = 1;

int keytemp = 0;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;


BleKeyboard BleKeyboard("Motion-Key");  //デバイス名


void KeySend(int mode,int com){
  com = mode * 100 + com;
  if(com == 141){
    BleKeyboard.press(KEY_RIGHT_ARROW);
  }else if(com == 142){
    BleKeyboard.press(KEY_LEFT_ARROW);
  }else if(com == 143){
    BleKeyboard.press(KEY_DOWN_ARROW);
  }else if(com == 144){
    BleKeyboard.press(KEY_UP_ARROW);
  }else if(com == 151){
    BleKeyboard.press(KEY_LEFT_ALT);
    BleKeyboard.press(KEY_TAB);
  }else if(com == 152){
    //BleKeyboard.press(KEY_);
  }else if(com == 153){
    //BleKeyboard.press(KEY_);
  }else if(com == 154){
    //BleKeyboard.press(KEY_);
  }else if(com == 131){
    BleKeyboard.press(KEY_MEDIA_PLAY_PAUSE);
  }else if(com == 241){
    BleKeyboard.press(KEY_DOWN_ARROW);
    delay(900);
  }else if(com == 242){
    BleKeyboard.press(KEY_UP_ARROW);
    delay(900);
  }else if(com == 243){
    BleKeyboard.press(KEY_LEFT_ARROW);
    delay(900);
  }else if(com == 244){
    BleKeyboard.press(KEY_RIGHT_ARROW);
    delay(900);
  }else if(com == 251){
    BleKeyboard.press(KEY_LEFT_ALT);
    BleKeyboard.press(KEY_RIGHT_ARROW);
  }else if(com == 252){
    BleKeyboard.press(KEY_LEFT_ALT);
    BleKeyboard.press(KEY_LEFT_ARROW);
  }else if(com == 253){
    //BleKeyboard.press(KEY_)
  }else if(com == 254){
    //BleKeyboard.press(KEY_)
  }else if(com == 231){
    BleKeyboard.write(KEY_F5);
  }else if(com == 341){
    BleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
  }else if(com == 342){
    BleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
  }else if(com == 343){
    BleKeyboard.press(KEY_LEFT_SHIFT);
    BleKeyboard.print("f");
    BleKeyboard.release(KEY_LEFT_SHIFT);
    BleKeyboard.press(KEY_ESC);
    BleKeyboard.release(KEY_ESC);
  }else if(com == 344){
    BleKeyboard.print("f");
    BleKeyboard.press(KEY_F11);
  }else if(com == 351){
    BleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
  }else if(com == 352){
    BleKeyboard.write(KEY_MEDIA_VOLUME_UP);
  }else if(com == 353){
    //BleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
  }else if(com == 354){
    //BleKeyboard.write(KEY_MEDIA_VOLUME_UP);
  }else if(com == 331){
    BleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
  }else if(com == 441){
    BleKeyboard.write(KEY_RIGHT_ARROW);
  }else if(com == 442){
    BleKeyboard.write(KEY_LEFT_ARROW);
  }else if(com == 443){
    BleKeyboard.write(KEY_DOWN_ARROW);
  }else if(com == 444){
    BleKeyboard.write(KEY_UP_ARROW);
  }else if(com == 451){
    BleKeyboard.press(KEY_LEFT_ALT);
    BleKeyboard.press(KEY_RIGHT_ARROW);
  }else if(com == 452){
    BleKeyboard.press(KEY_LEFT_ALT);
    BleKeyboard.press(KEY_LEFT_ARROW);
  }else if(com == 453){
    //BleKeyboard.write(KEY_);
  }else if(com == 454){
    //BleKeyboard.write(KEY_);
  }else if(com == 401){
    BleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
  }else if(com == 402){
    BleKeyboard.print("f");
  }else if(com == 403){
    BleKeyboard.write(KEY_RETURN);
  }else if(com == 404){
    BleKeyboard.write(KEY_F5);
  }else if(com == 405){
    BleKeyboard.press(KEY_LEFT_ALT);
    BleKeyboard.press(KEY_TAB);
  }else if(com == 406){
    //BleKeyboard.write(KEY_);
  }else if(com == 407){
    //BleKeyboard.write(KEY_);
  }else if(com == 408){
    //BleKeyboard.write(KEY_);
  }else if(com == 409){
    //BleKeyboard.write(KEY_);
  }else if(com == 410){
    //BleKeyboard.write(KEY_);
  }           


  delay(100);
  BleKeyboard.releaseAll();
  delay(300);
}

void UIinit(int mode,int key){

  //mode UI arrow init
  M5.Lcd.fillTriangle(36,30,36,38,43,34,DARKGREY);
  M5.Lcd.fillTriangle(36,50,36,58,43,54,DARKGREY);
  M5.Lcd.fillTriangle(36,70,36,78,43,74,DARKGREY);
  M5.Lcd.fillTriangle(36,90,36,98,43,94,DARKGREY);

  ////keyUI init

  //arrow
  M5.Lcd.fillTriangle(145,48,155,43,155,53,DARKGREY);
  M5.Lcd.fillTriangle(165,30,160,40,170,40,DARKGREY);
  M5.Lcd.fillTriangle(160,43,170,43,165,53,DARKGREY);
  M5.Lcd.fillTriangle(175,43,175,53,185,48,DARKGREY);
  //play/pause
  M5.Lcd.fillTriangle(200,33,200,37,204,35,DARKGREY);
  M5.Lcd.drawLine(207,32,205,38,DARKGREY);
  M5.Lcd.fillRect(209,34,2,4,DARKGREY);
  M5.Lcd.fillRect(213,34,2,4,DARKGREY);
  //next
  M5.Lcd.drawLine(193,45,193,51,DARKGREY);
  M5.Lcd.fillTriangle(199,45,199,51,193,48,DARKGREY);
  M5.Lcd.fillTriangle(205,45,205,51,199,48,DARKGREY);
  //previous
  M5.Lcd.fillTriangle(209,45,209,51,215,48,DARKGREY);
  M5.Lcd.fillTriangle(215,45,215,51,221,48,DARKGREY);
  M5.Lcd.drawLine(221,45,221,51,DARKGREY);
  //go / back : browse-mode
  M5.Lcd.drawCircle(156,65,7,DARKGREY);
  M5.Lcd.drawLine(152,65,160,65,DARKGREY);
  M5.Lcd.drawLine(156,69,152,65,DARKGREY);
  M5.Lcd.drawLine(156,61,152,65,DARKGREY);
  M5.Lcd.drawCircle(174,65,7,DARKGREY);
  M5.Lcd.drawLine(170,65,178,65,DARKGREY);
  M5.Lcd.drawLine(174,69,178,65,DARKGREY);
  M5.Lcd.drawLine(174,61,178,65,DARKGREY);
  //volume up / down
  M5.Lcd.fillRect(194,63,4,4,DARKGREY);
  M5.Lcd.fillTriangle(194,65,200,61,200,68,DARKGREY);
  M5.Lcd.drawLine(202,64,202,66,DARKGREY);
  M5.Lcd.fillRect(209,63,4,4,DARKGREY);
  M5.Lcd.fillTriangle(209,65,213,61,213,68,DARKGREY);
  M5.Lcd.drawLine(215,64,215,66,DARKGREY); 
  M5.Lcd.drawLine(217,63,217,67,DARKGREY);
  M5.Lcd.drawLine(219,62,219,68,DARKGREY);
  //fullscreen
  M5.Lcd.fillRect(156,76,15,10,DARKGREY);
  M5.Lcd.fillRect(159,78,9,6,BLACK);
  M5.Lcd.fillRect(156,79,15,4,BLACK);
  M5.Lcd.fillRect(161,76,5,10,BLACK);
  //F5
  M5.Lcd.setTextColor(DARKGREY,BLACK);
  M5.Lcd.setCursor(145,92);
  M5.Display.print("F5");
  //Enter
  M5.Lcd.setTextColor(DARKGREY,BLACK);
  M5.Lcd.setCursor(188,77);
  M5.Display.print("Enter");
  //alt + tab
  M5.Lcd.setTextColor(DARKGREY,BLACK);
  M5.Lcd.setCursor(170,92);
  M5.Display.print("Alt + Tab");

  if(mode == 1){
    M5.Lcd.fillTriangle(36,30,36,38,43,34,RED);
    //arrow
    M5.Lcd.fillTriangle(145,48,155,43,155,53,BLUE);
    M5.Lcd.fillTriangle(175,43,175,53,185,48,BLUE);
    //play/pause
    M5.Lcd.fillTriangle(200,33,200,37,204,35,RED);
    M5.Lcd.drawLine(207,32,205,38,RED);
    M5.Lcd.fillRect(209,34,2,4,RED);
    M5.Lcd.fillRect(213,34,2,4,RED);
    //alt + tab
    M5.Lcd.setTextColor(GREEN,BLACK);
    M5.Lcd.setCursor(170,92);
    M5.Display.print("Alt + Tab");
  }

  if(mode == 2){
    M5.Lcd.fillTriangle(36,50,36,58,43,54,RED);
    //arrow
    M5.Lcd.fillTriangle(165,30,160,40,170,40,BLUE);
    M5.Lcd.fillTriangle(160,43,170,43,165,53,BLUE);
    //go / back : browse-mode
    M5.Lcd.drawCircle(156,65,7,GREEN);
    M5.Lcd.drawLine(152,65,160,65,GREEN);
    M5.Lcd.drawLine(156,69,152,65,GREEN);
    M5.Lcd.drawLine(156,61,152,65,GREEN);
    M5.Lcd.drawCircle(174,65,7,GREEN);
    M5.Lcd.drawLine(170,65,178,65,GREEN);
    M5.Lcd.drawLine(174,69,178,65,GREEN);
    M5.Lcd.drawLine(174,61,178,65,GREEN);
    //F5
    M5.Lcd.setTextColor(RED,BLACK);
    M5.Lcd.setCursor(145,92);
    M5.Display.print("F5");
  }

  if(mode == 3){
    M5.Lcd.fillTriangle(36,70,36,78,43,74,RED);
    //play/pause
    M5.Lcd.fillTriangle(200,33,200,37,204,35,RED);
    M5.Lcd.drawLine(207,32,205,38,RED);
    M5.Lcd.fillRect(209,34,2,4,RED);
    M5.Lcd.fillRect(213,34,2,4,RED);
    //next
    M5.Lcd.drawLine(193,45,193,51,BLUE);
    M5.Lcd.fillTriangle(199,45,199,51,193,48,BLUE);
    M5.Lcd.fillTriangle(205,45,205,51,199,48,BLUE);
    //previous
    M5.Lcd.fillTriangle(209,45,209,51,215,48,BLUE);
    M5.Lcd.fillTriangle(215,45,215,51,221,48,BLUE);
    M5.Lcd.drawLine(221,45,221,51,BLUE);
    //volume up / down
    M5.Lcd.fillRect(194,63,4,4,GREEN);
    M5.Lcd.fillTriangle(194,65,200,61,200,68,GREEN);
    M5.Lcd.drawLine(202,64,202,66,GREEN);
    M5.Lcd.fillRect(209,63,4,4,GREEN);
    M5.Lcd.fillTriangle(209,65,213,61,213,68,GREEN);
    M5.Lcd.drawLine(215,64,215,66,GREEN); 
    M5.Lcd.drawLine(217,63,217,67,GREEN);
    M5.Lcd.drawLine(219,62,219,68,GREEN);
  }

  if(mode == 4){
    M5.Lcd.fillTriangle(36,90,36,98,43,94,RED);

    //arrow
    M5.Lcd.fillTriangle(145,48,155,43,155,53,BLUE);
    M5.Lcd.fillTriangle(165,30,160,40,170,40,BLUE);
    M5.Lcd.fillTriangle(160,43,170,43,165,53,BLUE);
    M5.Lcd.fillTriangle(175,43,175,53,185,48,BLUE);

    //go / back : browse-mode
    M5.Lcd.drawCircle(156,65,7,GREEN);
    M5.Lcd.drawLine(152,65,160,65,GREEN);
    M5.Lcd.drawLine(156,69,152,65,GREEN);
    M5.Lcd.drawLine(156,61,152,65,GREEN);
    M5.Lcd.drawCircle(174,65,7,GREEN);
    M5.Lcd.drawLine(170,65,178,65,GREEN);
    M5.Lcd.drawLine(174,69,178,65,GREEN);
    M5.Lcd.drawLine(174,61,178,65,GREEN);

    if(key == 1){
      //play/pause
      M5.Lcd.fillTriangle(200,33,200,37,204,35,RED);
      M5.Lcd.drawLine(207,32,205,38,RED);
      M5.Lcd.fillRect(209,34,2,4,RED);
      M5.Lcd.fillRect(213,34,2,4,RED);
    }else if(key == 2){
      //fullscreen
      M5.Lcd.fillRect(156,76,15,10,RED);
      M5.Lcd.fillRect(159,78,9,6,BLACK);
      M5.Lcd.fillRect(156,79,15,4,BLACK);
      M5.Lcd.fillRect(161,76,5,10,BLACK);
    }else if(key == 3){
      //Enter
      M5.Lcd.setTextColor(RED,BLACK);
      M5.Lcd.setCursor(188,77);
      M5.Display.print("Enter");
    }else if(key == 4){
      //F5
      M5.Lcd.setTextColor(RED,BLACK);
      M5.Lcd.setCursor(145,92);
      M5.Display.print("F5");
    }else if(key == 5){
      //alt + tab
      M5.Lcd.setTextColor(RED,BLACK);
      M5.Lcd.setCursor(170,92);
      M5.Display.print("Alt + Tab");
    }
  }

}

void Mode1to34(int mode,int keynumber){
  
  keytemp = 0;

  //ble on/off-line status text cursor
  M5.Display.setCursor(30,7);

  if(BleKeyboard.isConnected()){
    
    //BLE status
    M5.Lcd.setTextColor(BLUE, BLACK);
    M5.Display.print("Online ");

    while(digitalRead(BTN1) == 0 && digitalRead(BTN2) == 1){
      
      M5.Imu.getGyro(&gyroX,&gyroY,&gyroZ);
 
      // This scope is " Btn1 ∧ IMU "
      if(gyroX > 200 || gyroY < -200 || gyroZ > 200){
        keytemp += 40;
        keytemp += 1;
        break;
      }else if(gyroX < -200 || gyroY > 200 || gyroZ < -200){
        keytemp += 40;
        keytemp += 2;
        break;
      }

    }

    
    while(digitalRead(BTN1) == 1 && digitalRead(BTN2) == 0){

      M5.Imu.getGyro(&gyroX,&gyroY,&gyroZ);

      // This scope is " Btn2 ∧ IMU　"
      if(gyroX > 200 || gyroY < -200 || gyroZ > 200){
          keytemp += 50;
          keytemp += 1;
          break;
      }else if(gyroX < -200 || gyroY > 200 || gyroZ < -200){
          keytemp += 50;
          keytemp += 2;
          break;
      }

    }

    if(digitalRead(BTN1) == 0 && digitalRead(BTN2) == 0){

      //This scope is " Btn1 ∧ Btn2 "
      if(mode != 4){
        keytemp += 30;
        keytemp += 1;
      }else{
        keytemp += keynumber;
      }

    }

    KeySend(mode,keytemp);

  }else{
    M5.Lcd.setTextColor(DARKGREY, BLACK);
    M5.Display.print("Offline");
    delay(500);
  }

}

//void Mode4(){

//}

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
  M5.Display.setCursor(7,7);
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
  M5.update();

  if(M5.BtnB.isPressed()){
    mode += 1;
    if(mode > 4){
      mode = 1;
    }

    keynum = 0;
    UIinit(mode,1);
    delay(100);

  }
  
  if(mode == 4){
    if(M5.BtnA.isPressed()){
      keynum += 1;
      if(keynum > 5){
        keynum = 1;
      }
      UIinit(mode,keynum);
      delay(100);
    }
  }

  Mode1to34(mode,keynum);

}

