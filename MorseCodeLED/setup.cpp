const int ledPin = 13;  // 板上LED
const int dotDuration = 200; // 點的時間（毫秒）

// 摩斯碼對照表
const char* morseCodeTable[26] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",  // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         // S-Z
};

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sendMorse("HI");
  delay(3000); // 每句之間停頓
}

void sendMorse(const char* text) {
  for (int i = 0; text[i] != '\0'; i++) {
    char ch = toupper(text[i]);
    if (ch >= 'A' && ch <= 'Z') {
      const char* code = morseCodeTable[ch - 'A'];
      for (int j = 0; code[j] != '\0'; j++) {
        if (code[j] == '.') {
          flashDot();
        } else if (code[j] == '-') {
          flashDash();
        }
        delay(dotDuration); // 符號間隔
      }
      delay(dotDuration * 2); // 字母間隔（3 個 dot 時間）
    } else if (ch == ' ') {
      delay(dotDuration * 6); // 單字間隔
    }
  }
}

void flashDot() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration);
  digitalWrite(ledPin, LOW);
}

void flashDash() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration * 3);
  digitalWrite(ledPin, LOW);
}