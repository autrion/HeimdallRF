#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Uncomment to use SH1106-based displays
// #define USE_SH1106

#ifdef USE_SH1106
#include <Adafruit_SH110X.h>
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
#define OLED_WHITE SH110X_WHITE
#else
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
#define OLED_WHITE SSD1306_WHITE
#endif

// Pin configuration
constexpr uint8_t BUZZER_PIN = 4;
constexpr uint8_t BUTTON1_PIN = 5;
constexpr uint8_t BUTTON2_PIN = 6;
constexpr uint8_t BUTTON3_PIN = 7;

struct Page {
  const char *title;
  int rssi;
};

Page pages[] = {
    {"868/915 MHz", 0},
    {"2.4 GHz", 0},
    {"5.8 GHz", 0},
};

uint8_t currentPage = 0;
unsigned long lastUpdate = 0;

int generateRSSI() {
  return random(-120, -30); // Dummy RSSI values
}

void beepStartup() {
  tone(BUZZER_PIN, 2000, 200);
  delay(200);
  noTone(BUZZER_PIN);
}

void showInitScreen() {
  display.clearDisplay();
  display.setTextColor(OLED_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("HeimdallRF INIT"));
  display.display();
}

void renderPage(const Page &page) {
  display.clearDisplay();
  display.setTextColor(OLED_WHITE);
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.println(page.title);
  display.setTextSize(1);
  display.setCursor(0, 40);
  display.print(F("RSSI: "));
  display.print(page.rssi);
  display.display();
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);

  Wire.begin();
#ifdef USE_SH1106
  if (!display.begin(0x3C, true)) {
    for (;;) {
      delay(100);
    }
  }
#else
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for (;;) {
      delay(100);
    }
  }
#endif

  randomSeed(micros());

  showInitScreen();
  beepStartup();
  delay(3000);

  pages[0].rssi = generateRSSI();
  renderPage(pages[0]);
}

void loop() {
  if (digitalRead(BUTTON1_PIN) == LOW) {
    currentPage = 0;
    pages[currentPage].rssi = generateRSSI();
    renderPage(pages[currentPage]);
    delay(200);
  } else if (digitalRead(BUTTON2_PIN) == LOW) {
    currentPage = 1;
    pages[currentPage].rssi = generateRSSI();
    renderPage(pages[currentPage]);
    delay(200);
  } else if (digitalRead(BUTTON3_PIN) == LOW) {
    currentPage = 2;
    pages[currentPage].rssi = generateRSSI();
    renderPage(pages[currentPage]);
    delay(200);
  }

  if (millis() - lastUpdate > 1000) {
    lastUpdate = millis();
    pages[currentPage].rssi = generateRSSI();
    renderPage(pages[currentPage]);
  }
}

