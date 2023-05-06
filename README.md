This repository is "Body interface project" by shiwasu_tech since 2023/04/23

必要なもの
- M5StickCPlus (時計タイプのものだとよい。)
- ArduinoIDE (versionは問わない)
- M5 JoyStickUnit (M5mouse-joyのみ必要)
- M5 IMUUnit (M5mouse-fingerのみ必要j)
- 抵抗(自由),タクトスイッチ,ジャンパー線


作成方法
0. このリポジトリをローカルに持ってくる。
1. ArduinoIDEでライブラリ検索から[M5Unified]()と[M5GFX]()をダウンロード
2. ArduinoIDEで[BLEmouse.h]()のライブラリをzip形式でインストール
3. M5~~.inoと書かれたファイルをArduinoIDEで開き、PCとM5StickCPlusを繋いで書き込み

使用方法
## 1. M5key

- ジャンパ線をGPIO26,25それぞれからスイッチ介してGroudに1本ずつつなぐ。
- 推しやすい位置にボタンを持ってきて、左のボタン(電源ボタン)でM5Stickを起動。
- 画面の向きを右のボタン(モードボタン)から選択し"M5"と書かれたボタンで決定。
- 使用端末とBLE接続(Bluetooth端末のように検索をかけると"M5sitck-keyboard"と出てくるはず)
- モードボタンからモード選択(右のUIからなんのキーが対応しているか見れる)
- モード4"Selectable"では２つのボタン同時押しで送るキーが選択可能(M5ボタンで選択)
- 26番ピンとつないだボタン(青ボタン),26番ピンとつないだボタン(緑ボタン)どちらかを押しながら手を左右に振りかざすとUIに表示されたキーとが送られる。青ボタンと緑ボタンを同時押しするとUIでオレンジになったキーが送れる。
- 電源ボタン長押しで電源オフ

## 2. M5mouse-joy




# Body Interface

1. Facial Play/Pause

**"Have you ever felt annoying to stop the movie and retake a pen again when you watch class videos and need to take some memos?"**
This project help you act so without stress.

When your face is UP, nothing happens. But when your face is DOWN, the video would stop by sending "PLAY_AND_PAUSE key" via BLE.
As same when you up your face, the video restart.


2. Hand Interface (shortcut keys)

**Imagin if you can controll your PCs with your motion.**
This project make you feel in the Sci-Fi World.

You can control 
the **slides** with your **"Handsnap"**
the **screen** with your **"Hand Motion"**

Like these your hands would be Left-Hand-Devices.

3. Handy mouse

4. Handy keyboard
