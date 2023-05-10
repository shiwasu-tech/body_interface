This repository is "Body interface project" by shiwasu_tech since 2023/04/23

**制作過程は[こちら](https://shiwasu-tech.github.io/body_interface.html)**

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

## 2. M5mouse-IMU



