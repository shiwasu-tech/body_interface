#include <M5Unified.h>

float accX  = 0.0F;
float accY  = 0.0F;
float accZ  = 0.0F;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;

float roll  = 0.0F;
float pitch = 0.0F;
float yaw   = 0.0F;

const float pi  = 3.14;

void readGyro(){
  M5.Imu.getAccel(&accX, &accY, &accZ);             // 加速度の取得
  M5.Imu.getGyro(&gyroX, &gyroX, &gyroZ);           // 角速度の取得
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

  M5.Imu.begin();

  M5.Display.setRotation(1);
  M5.Display.setTextSize(2);
  M5.Display.setTextColor(BLUE,BLACK);

}

void loop() {

  readGyro();
  
  M5.Display.setCursor(0,10);
  M5.Display.setTextColor(BLUE,BLACK);
  M5.Display.printf("p=%f\nr=%f\ny=%f",pitch,roll,yaw);
  M5.Display.setTextColor(RED,BLACK);

  delay(100);
}
