This repository is "Body interface project" by shiwasu_tech since 2023/04/23

**制作過程は[こちら](https://shiwasu-tech.github.io/body_interface.html)**

必要なもの
- M5StickCPlus (時計タイプのものだとよい。)
- 抵抗(自由),タクトスイッチ,ジャンパー線
- ArduinoIDE (versionは問わない)


作成方法
0. このリポジトリをローカルに持ってくる。
1. ArduinoIDEでライブラリ検索から[M5Unified]()と[M5GFX]()をダウンロード
2. このリンクから[BLEmouse.h](https://github.com/T-vK/ESP32-BLE-Mouse),[BLEKeyboard.h](https://github.com/T-vK/ESP32-BLE-Keyboard)ライブラリをzip形式でインストール
3. インストールしたzipファイルをArduinoIDEに取り込む(helpから「zip形式のライブラリをインクルード」)
4. M5~~.inoと書かれたファイルをArduinoIDEで開き、PCとM5StickCPlusを繋いで書き込み

# **使用方法**

## ※使用用語※
電源ボタン= 端末を"M5"の向きで立てた時左側についているボタン<br>
サブボタン= 端末を"M5"の向きで立てた時右側についているボタン<br>
M5ボタン = "M5"と書かれたボタン<br>
26ボタン = 26番ピンと繋いだボタン<br>
25ボタン = 25番ピンと繋いだボタン<br>

## 1. Motion-Key

- ジャンパ線をGPIO26,25それぞれからスイッチ、抵抗介してGroudに1本ずつつなぐ。
- 推しやすい位置にボタンを持ってきて、電源ボタンでM5Stickを起動。
- 画面の向きをサブボタンから選択し"M5"と書かれたボタンで決定。
- 使用端末とBLE接続(Bluetooth端末のように検索をかけると"Motion-key"と出てくるはず)
- サブボタンからモード選択(ディスプレイ上に対応キーが表示される)
- モード4"Selectable"では25ボタン,26ボタン同時押しで送るキーが選択可能(M5ボタンで対応キーを選択)
- 25ボタン,26ボタンのどちらかを押しながら手を左右に振りかざすとUIに表示されたキーとが送られる。25ボタンと26ボタンを同時押しするとUIでオレンジに表示されたキーが送れる。<br><br>
- 電源ボタン長押しで電源オフ。


<br>

## 2. Motion-Mouse
- 1と同様にスイッチ、抵抗を含む回路を作成。
- 電源ボタンで起動。
- 使用端末とBluetooth接続。("Motion-Mouse"と出てくるはず。)
- 25ボタン、26ボタンを押しながら手を振りかざすとカーソル移動やドラッグができる。
- サブボタンから感度、微調整モードに移行できる。(※未実装)<br><br>
- 電源ボタン長押しで電源オフ。

## 3. Motion-Joystick

[作成中]
