#include <Arduino.h>
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

// 視覚的に数字を定義（12x8マス）
// 1 = 点灯, 0 = 消灯
uint8_t num_visual[10][96] = {
  { // 0
    0,0,0,1,1,1,1,0,0,0,0,0,
    0,0,1,0,0,0,0,1,0,0,0,0,
    0,0,1,0,0,0,0,1,0,0,0,0,
    0,0,1,0,0,0,0,1,0,0,0,0,
    0,0,1,0,0,0,0,1,0,0,0,0,
    0,0,1,0,0,0,0,1,0,0,0,0,
    0,0,1,0,0,0,0,1,0,0,0,0,
    0,0,0,1,1,1,1,0,0,0,0,0
  },
  { // 1
    0,0,0,0,1,0,0,0,0,0,0,0,
    0,0,0,1,1,0,0,0,0,0,0,0,
    0,0,0,0,1,0,0,0,0,0,0,0,
    0,0,0,0,1,0,0,0,0,0,0,0,
    0,0,0,0,1,0,0,0,0,0,0,0,
    0,0,0,0,1,0,0,0,0,0,0,0,
    0,0,0,0,1,0,0,0,0,0,0,0,
    0,0,0,1,1,1,0,0,0,0,0,0
  }
  // ※他の数字も同様に0/1で描画可能
};

void setup() {
  Serial.begin(115200);
  matrix.begin();
  Serial.println("Visual Map Ready");
}

void loop() {
  if (Serial.available() > 0) {
    int n = Serial.parseInt();
    if (n >= 0 && n <= 1) { // 今は0と1だけ定義
      // loadPixels関数を使って、96バイトの配列を流し込む
      matrix.loadPixels(num_visual[n], 96);
      Serial.print("Draw Number: ");
      Serial.println(n);
    }
  }
}