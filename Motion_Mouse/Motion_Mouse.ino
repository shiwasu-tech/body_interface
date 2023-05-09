#include <M5Unified.h>
#include <BleMouse.h>

const int BTN1 = 26;
const int BTN2 = 25;

float accX  = 0.0F;
float accY  = 0.0F;
float accZ  = 0.0F;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;

float roll  = 0.0F;
float pitch = 0.0F;
float yaw   = 0.0F;
float roll_2= 0.0F;

float x = 0.0F;
float y = 0.0F;
float z = 0.0F;

BleMouse BleMouse("Motion-Mouse");

void drawUI(int x,int y,int left,int right,int middle,int dir,int twist){

  //finger
  M5.Lcd.drawCircle(x,y+35,5,WHITE);
  M5.Lcd.drawRect(x-5,y+35,11,16,WHITE);
  M5.Lcd.fillRect(x-4,y+35,9,16,BLACK);
  //finger button
  M5.Lcd.drawCircle(x,y+38,3,WHITE);
  M5.Lcd.drawCircle(x,y+47,3,WHITE);

  //mouse body
  if(left == 1){
    M5.Lcd.fillCircle(x,y,7,RED);
    M5.Lcd.fillRect(x,y-7,8,15,BLACK);
    M5.Lcd.fillCircle(x,y+38,2,RED);
  }else if(right == 1){
    M5.Lcd.fillCircle(x,y,7,RED);
    M5.Lcd.fillRect(x-7,y-7,8,15,BLACK);
    M5.Lcd.fillCircle(x,y+38,2,RED);
  }
  M5.Lcd.drawCircle(x,y,7,WHITE);

  M5.Lcd.drawCircle(x,y+10,7,WHITE);

  M5.Lcd.fillRect(x-7,y,15,11,BLACK);
  M5.Lcd.drawRect(x-7,y,15,11,WHITE);
  M5.Lcd.drawLine(x-6,y+10,x+6,y+10,BLACK);

  //middle button
  if(middle == 1){
    M5.Lcd.fillRect(x-2,y-3,5,6,RED);
    M5.Lcd.fillCircle(x,y+47,2,RED);
  }else{
    M5.Lcd.fillRect(x-2,y-3,5,6,BLACK);
  }
  M5.Lcd.drawRect(x-2,y-3,5,6,WHITE);
  
  if(dir == 1){
    //↑
    M5.Lcd.fillTriangle(x,y-15,x-2,y-10,x+2,y-10,RED);
    M5.Lcd.fillTriangle(x,y-15,x-2,y-10,x+2,y-10,RED);
    //↓
    M5.Lcd.fillTriangle(x,y+25,x-2,y+20,x+2,y+20,RED);
    M5.Lcd.fillTriangle(x,y+25,x-2,y+20,x+2,y+20,RED);
    //←
    M5.Lcd.fillTriangle(x-15,y+5,x-10,y+3,x-10,y+7,RED);
    M5.Lcd.fillTriangle(x-15,y+5,x-10,y+3,x-10,y+7,RED);
    //→
    M5.Lcd.fillTriangle(x+15,y+5,x+10,y+3,x+10,y+7,RED);
    M5.Lcd.fillTriangle(x+15,y+5,x+10,y+3,x+10,y+7,RED);
    

    //finger
    M5.Lcd.fillCircle(x,y+47,2,RED);

    M5.Lcd.fillTriangle(x,y+73,x-7,y+81,x+7,y+81,WHITE);
    M5.Lcd.fillTriangle(x,y+89,x-7,y+81,x+7,y+81,WHITE);
    M5.Lcd.fillRect(x-4,y+76,9,11,BLACK);
    M5.Lcd.drawLine(x-5,y+81,x+5,y+81,WHITE);
    M5.Lcd.drawLine(x,y+76,x,y+86,WHITE);

  }

  if(twist == 1){
    //arm twist
    M5.Lcd.drawCircle(x,y+61,6,WHITE);
    M5.Lcd.fillRect(x-4,y+61,8,7,BLACK);
    M5.Lcd.fillTriangle(x+2,y+64,x+4,y+68,x,y+67,WHITE);
  }
}

void readGyro(){
  M5.Imu.getAccel(&accX, &accY, &accZ);             // 加速度の取得
  M5.Imu.getGyro(&gyroX, &gyroY, &gyroZ);           // 角速度の取得
  roll  =  atan(accX / sqrt((accY * accY) + (accZ * accZ))) * 180 / 3.14; 
  pitch =  atan(accY / sqrt((accX * accX) + (accZ * accZ))) * 180 / 3.14; 
  yaw   =  atan(sqrt((accX * accX) + (accY * accY)) / accZ) * 180 / 3.14;

  if(roll < 0){
    roll_2 = -roll;
  }else{
    roll_2 = roll;
  }

  //if(yaw < 0){
  //  yaw = -yaw;
  //}

  roll_2  = roll_2    *2*3.14/360;
  yaw     = yaw       *2*3.14/360;
  y = (-gyroX * (1- roll_2 * roll_2 /2) - gyroZ * (roll_2 - roll_2 * roll_2 * roll_2/6))/10;
  x = (-gyroZ * (1- roll_2 * roll_2 /2) - gyroX * (roll_2 - roll_2 * roll_2 * roll_2/6))/10;
}


void setup(){

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
  //M5.Lcd.setCursor(110,5);
  //M5.Display.setTextSize(1);
  //M5.Display.print("^ select hand");
  //M5.Lcd.setCursor(130,120);
  //M5.Display.print("enter >");
  //M5.Lcd.setCursor(20,30);
  //M5.Display.setTextSize(2);
  //M5.Display.println("Which hand?");

  //int hand = 1;
  //while(1){
  //
  //  M5.update();
  //
  //  if(M5.BtnB.isPressed()){
  //    hand += 1;
  //    if(hand > 2){
  //      hand = 1;
  //    }
  //  }
  //
  //  if(hand == 1){
  //    M5.Lcd.setCursor(20,50);
  //    M5.Lcd.setTextColor(BLUE, WHITE);
  //    M5.Display.print("1.RIGHT");
  //    M5.Lcd.setCursor(20,70);
  //    M5.Lcd.setTextColor(WHITE, BLACK);
  //    M5.Display.print("2.LEFT");
  //  }else{
  //    M5.Lcd.setCursor(20,50);
  //    M5.Lcd.setTextColor(WHITE, BLACK);
  //    M5.Display.print("1.RIGHT");
  //    M5.Lcd.setCursor(20,70);
  //    M5.Lcd.setTextColor(BLUE, WHITE);
  //    M5.Display.print("2.LEFT");
  //  }
  //
  //  if(M5.BtnA.isPressed()){
  //    break;
  //  }
  //
  //  delay(100);
  //}
  //
  //M5.Display.clear();
  //
  //  
  //if(hand == 1){
  //  M5.Lcd.setRotation(1);                 
  //}else{
  //  M5.Lcd.setRotation(3);
  //}

  M5.Display.setTextSize(1); 

  //BLE print
  M5.Display.setCursor(7,6);
  M5.Display.setTextColor(BLUE,BLACK);
  M5.Display.print("BLE");

  //draw machine name
  M5.Lcd.setCursor(155,6);
  M5.Lcd.setTextColor(YELLOW, NAVY);
  M5.Lcd.print("Motion-Mouse");
  M5.Lcd.setTextColor(WHITE,BLACK);       

  //pertition draw
  M5.Lcd.drawLine(0,21,240,21,WHITE);

  //list
  M5.Lcd.setCursor(7,41);
  M5.Lcd.print("Ms");
  M5.Lcd.setCursor(7,80);
  M5.Lcd.print("Thumb");
  M5.Lcd.setCursor(7,110);
  M5.Lcd.print("Arm");

  //UI draw (x,y,left,right,middle,dir,twist)
  drawUI(50,40,0,0,0,1,0);
  drawUI(85,40,1,0,0,1,0);
  drawUI(120,40,1,0,0,0,0);
  drawUI(155,40,0,1,0,0,1);
  drawUI(190,40,0,0,1,1,1);
  drawUI(225,40,0,0,1,0,1);
  //scroll ui draw

  
  BleMouse.begin();

  M5.Imu.begin();
                               
}

void loop() {
  
  M5.Display.setCursor(30,7);

  if(BleMouse.isConnected()){
    M5.Lcd.setTextColor(BLUE, BLACK);
    M5.Display.print("Online ");

    readGyro();

    if(digitalRead(BTN1) == 0 && digitalRead(BTN2) == 1){

      //move / wheel scroll

      if(roll > 0 || yaw > 0){
        BleMouse.release(MOUSE_LEFT);
        BleMouse.release(MOUSE_RIGHT);
        BleMouse.release(MOUSE_MIDDLE);
        
        BleMouse.move(x,y);
      }else{
        BleMouse.release(MOUSE_LEFT);
        BleMouse.release(MOUSE_RIGHT);
        BleMouse.release(MOUSE_MIDDLE);
        
        BleMouse.move(0,0,x,0);
      }

    }else if(digitalRead(BTN1) == 1 && digitalRead(BTN2) == 0){
      
      // just click

      if(roll > 0 || yaw > 0){
        BleMouse.press(MOUSE_LEFT);
        BleMouse.release(MOUSE_RIGHT);
        BleMouse.release(MOUSE_MIDDLE);

      }else{
        BleMouse.release(MOUSE_LEFT);
        BleMouse.press(MOUSE_RIGHT);
        BleMouse.release(MOUSE_MIDDLE);
      }

    }else if(digitalRead(BTN1) == 0 && digitalRead(BTN2) == 0){

      //drag / middle drag

      if(roll > 0 || yaw > 0){
        BleMouse.press(MOUSE_LEFT);
        BleMouse.release(MOUSE_RIGHT);
        BleMouse.release(MOUSE_MIDDLE);

        BleMouse.move(x,y);
      }else{
        BleMouse.release(MOUSE_LEFT);
        BleMouse.release(MOUSE_RIGHT);
        BleMouse.press(MOUSE_MIDDLE);

        BleMouse.move(x,y);
      }

    }else{    
      //delay(50);
      BleMouse.release(MOUSE_LEFT);
      BleMouse.release(MOUSE_RIGHT);
      BleMouse.release(MOUSE_MIDDLE);
    }
  

  }else{
    M5.Lcd.setTextColor(DARKGREY, BLACK);
    M5.Display.print("Offline");
    delay(500);
  }

  delay(10);
  
}


