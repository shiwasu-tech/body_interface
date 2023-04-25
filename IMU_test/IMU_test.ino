#include <M5Unified.h> // M5Unifiedライブラリをプログラムで使用可能にします。
#include <BleKeyboard.h>  // https://github.com/T-vK/ESP32-BLE-Keyboard

// グローバル変数（プログラム全体で使用する変数の定義をします。）
uint32_t count;


BleKeyboard bleKeyboard("M5StickCPlus");  //デバイス名

const int longPress_ms = 300;  // 長押し判定時間(ms)

int A = 26;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;


// setup関数は起動時に一度だけ実行されます。
// 主に初期化処理を記述します。
void setup() {

  auto cfg = M5.config();       // M5Stack初期設定用の構造体を代入
  // configを設定する場合はここで設定
  // 例
  // cfg.external_spk = true;
  cfg.internal_imu = true;
  M5.begin(cfg);   

  pinMode(A,INPUT_PULLUP);

  M5.Lcd.setRotation(1);                 
  M5.Display.setTextSize(1);               // テキストサイズを変更
  M5.Lcd.setCursor(20, 10);
  M5.Display.print("Presentation-Mode");       // 画面にHello World!!と1行表示
  M5.Lcd.setCursor(20, 45);
  M5.Display.print("Browse-Mode");
  M5.Lcd.setCursor(20, 80);
  M5.Display.print("Codeing-Mode");
  M5.Lcd.drawTriangle(5, 5, 15, 5, 15, 10, RED);

  Serial.begin(115200);
  Serial.println("BLE Begin");
  bleKeyboard.begin();

  M5.Imu.begin();
  
  count = 0;                               // countを初期化

}

// loop関数は起動している間ずっと繰り返し実行されます。
// センサーから値を取得したり、画面を書き換える動作等をおこないます。
void loop() {
  M5.update();

  M5.Imu.getGyro(&gyroX,&gyroY,&gyroZ);
  //M5.Lcd.printf("%6.2f  %6.2f  %6.2f o/s\n", gyroX, gyroY, gyroZ);
  if(bleKeyboard.isConnected()){

    if(digitalRead(A) == 0){
      // ATOMのボタンを押下されているか
      if(gyroY > 200 || gyroX > 200 || gyroZ > 200){

        
        // 短押し時の処理
        //M5.Display.print("Down");
        bleKeyboard.press(KEY_LEFT_ARROW);
        delay(100);
        bleKeyboard.releaseAll();

        delay(1000);

        
      }else if(gyroY < -200 || gyroX < -200 || gyroZ < -200){

        //M5.Display.print("Up");
        bleKeyboard.press(KEY_RIGHT_ARROW);
        delay(100);
        bleKeyboard.releaseAll();

        delay(1000);

      }
      // BLE接続であることを、ATOMのLED（青）を知らせる
      
    }

  }else{
      // BLE未接続であることを、ATOMのLED（赤）を知らせる
      M5.Lcd.setCursor(20, 100);

      M5.Display.print("BLE connecting...");

      delay(500);
    }
    
  delay(10); 
}