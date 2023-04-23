#include <M5Unified.h> // M5Unifiedライブラリをプログラムで使用可能にします。
#include <BleKeyboard.h>  // https://github.com/T-vK/ESP32-BLE-Keyboard

// グローバル変数（プログラム全体で使用する変数の定義をします。）
uint32_t count;


BleKeyboard bleKeyboard("M5ATOM KB");  //デバイス名

const int longPress_ms = 300;  // 長押し判定時間(ms)


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
  M5.Lcd.setRotation(3);                        // M5デバイスの初期化

  

  M5.Display.setTextSize(2);               // テキストサイズを変更
  M5.Display.print("Hello World!!");       // 画面にHello World!!と1行表示

  Serial.begin(115200);
  Serial.println("BLEキーボードアプリ開始");
  bleKeyboard.begin();

  M5.Imu.begin();
  
  count = 0;                               // countを初期化

}

// loop関数は起動している間ずっと繰り返し実行されます。
// センサーから値を取得したり、画面を書き換える動作等をおこないます。
void loop() {
  M5.update();

  M5.Imu.getGyro(&gyroX,&gyroY,&gyroZ);
  M5.Lcd.printf("%6.2f  %6.2f  %6.2f o/s\n", gyroX, gyroY, gyroZ);

   if(bleKeyboard.isConnected()){
    // ATOMのボタンを押下されているか
    if(M5.BtnA.wasPressed()){
      // M5ATOMのボタンが押されたら一定時間待つ

      
      // 短押し時の処理
      M5.Display.print("paste");

      Serial.println(" 短押し時は、Ctrl+v を送信 ");
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press('v');
      delay(100);
      bleKeyboard.releaseAll();

      delay(100);
      
    }
    // BLE接続であることを、ATOMのLED（青）を知らせる
    
  }else{
    // BLE未接続であることを、ATOMのLED（赤）を知らせる
   M5.Display.print("BLE no connection");

   delay(5000);
  }
  delay(10);                          // 1秒待つ
}