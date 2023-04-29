#include <M5Unified.h>
int a = 0;


void setup() {

  auto cfg = M5.config();       // M5Stack初期設定用の構造体を代入
  // configを設定する場合はここで設定
  // 例
  // cfg.external_spk = true;
  cfg.internal_imu = true;
  M5.begin(cfg);   


  M5.Lcd.setRotation(1);                 
  M5.Display.setTextSize(1);       

  M5.Lcd.setCursor(5,15);

  //BLE mark draws
  M5.Lcd.drawTriangle(9,6,13,10,9,14,BLUE);
  M5.Lcd.drawTriangle(13,4,13,10,16,7,BLUE);
  M5.Lcd.drawTriangle(13,10,13,16,16,13,BLUE);
  M5.Lcd.drawLine(9,7,9,13,BLACK);

  //draw niC logo
  M5.Lcd.setCursor(155,6);
  M5.Lcd.setTextColor(YELLOW, NAVY);
  M5.Lcd.print("nitechCreate");
  M5.Lcd.setTextColor(WHITE,BLACK);

  //pertition
  M5.Lcd.drawLine(0,21,240,21,WHITE);
  M5.Lcd.drawLine(135,22,135,135,RED);

  //mode UI draw
  M5.Lcd.setCursor(8, 25);
  M5.Display.print("Mode");
  M5.Lcd.setCursor(50, 25);
  M5.Display.print("Presentation");
  M5.Lcd.setCursor(50, 40);
  M5.Display.print("Browsing");
  M5.Lcd.setCursor(50, 55);
  M5.Display.print("Media");
  M5.Lcd.setCursor(50, 70);
  M5.Display.print("Selectable");
  M5.Lcd.setCursor(50, 85);
  M5.Display.print("Phone");
  M5.Lcd.setCursor(50, 100);
  M5.Display.print("Mouse");
  M5.Lcd.fillTriangle(36,25,36,33,43,29,RED);
  M5.Lcd.fillTriangle(36,40,36,48,43,44,RED);
  M5.Lcd.fillTriangle(36,55,36,63,43,59,RED);
  M5.Lcd.fillTriangle(36,70,36,78,43,74,RED);

  //keyUI init

  //arrow
  M5.Lcd.fillTriangle(145,48,155,43,155,53,RED);
  M5.Lcd.fillTriangle(165,30,160,40,170,40,RED);
  M5.Lcd.fillTriangle(160,43,170,43,165,53,RED);
  M5.Lcd.fillTriangle(175,43,175,53,185,48,RED);
  //play/pause
  M5.Lcd.fillTriangle(200,33,200,37,204,35,RED);
  M5.Lcd.drawLine(207,32,205,38,RED);
  M5.Lcd.fillRect(209,34,2,4,RED);
  M5.Lcd.fillRect(213,34,2,4,RED);
  //next
  M5.Lcd.drawLine(193,45,193,51,RED);
  M5.Lcd.fillTriangle(199,45,199,51,193,48,RED);
  M5.Lcd.fillTriangle(205,45,205,51,199,48,RED);
  //previous
  M5.Lcd.fillTriangle(209,45,209,51,215,48,RED);
  M5.Lcd.fillTriangle(215,45,215,51,221,48,RED);
  M5.Lcd.drawLine(221,45,221,51,RED);
  //

  Serial.begin(115200);
  Serial.println("BLE Begin");

  M5.Lcd.fillRect(194,63,4,4,RED);
  M5.Lcd.fillTriangle(194,65,200,61,200,68,RED);
  M5.Lcd.drawLine(202,64,202,66,RED);
  M5.Lcd.fillRect(209,63,4,4,RED);
  M5.Lcd.fillTriangle(209,65,213,61,213,68,RED);
  M5.Lcd.drawLine(215,64,215,66,RED); 
  M5.Lcd.drawLine(217,63,217,67,RED);
  M5.Lcd.drawLine(219,62,219,68,RED);


  M5.Imu.begin();
                            
}

void loop() {
 
}
