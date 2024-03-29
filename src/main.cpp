#include <Arduino.h>
#include <WiFi.h>
#include "Adafruit_ThinkInk.h"
#include "test.h"

// ESP32-C3 SS=7,SCL(SCK)=4,SDA(MOSI)=6,BUSY=3,RST=2,DC=1
// 250 x 122 = 30.500 pixel

#define EPD_DC 1
#define EPD_CS 7
#define EPD_BUSY 3 // can set to -1 to not use a pin (will wait a fixed delay)
#define SRAM_CS -1
#define EPD_RESET 2  // can set to -1 and share with microcontroller Reset!
#define EPD_SPI &SPI // primary SPI

// 2.13" Tricolor EPD with SSD1680 chipset
ThinkInk_213_Tricolor_RW display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY,
                                 EPD_SPI);

void setup()
{
  WiFi.mode(WIFI_MODE_NULL);
  btStop();
  Serial.begin(115200);
  delay(2000);
  Serial.println("Initialized!");
  pinMode(8, OUTPUT);
  display.begin(THINKINK_TRICOLOR);

  display.clearBuffer();

  for (int y = 0; y < Garfield_Fat.height; y++)
  {
    for (int x = 0; x < Garfield_Fat.width / 4; x++) // 212 / 4 = 53 bits
    {
      uint8_t value = Garfield_Fat.data[y * 53 + x];
      uint8_t one = (value & 0xC0) >> 6;
      uint8_t two = (value & 0x30) >> 4;
      uint8_t three = (value & 0xC) >> 2;
      uint8_t four = value & 0x3;

      uint8_t base_x = x * 4;
      display.drawPixel(base_x, y, one);
      display.drawPixel(base_x + 1, y, two);
      display.drawPixel(base_x + 2, y, three);
      display.drawPixel(base_x + 3, y, four);
    }
  }
  display.display();
}

void testdrawtext(const char *text, uint16_t color)
{
  display.setCursor(0, 0);
  display.setTextColor(color);
  display.setTextWrap(true);
  display.print(text);
}

void loop()
{ /*
 Serial.println("Banner demo");
   display.clearBuffer();
   display.setTextSize(3);
   display.setCursor((display.width() - 144) / 2, (display.height() - 24) / 2);
   display.setTextColor(EPD_BLACK);
   display.print("Tri");
   display.setTextColor(EPD_RED);
   display.print("Color");
   display.display();

   delay(15000);

   Serial.println("Color rectangle demo");
   display.clearBuffer();
   display.fillRect(display.width() / 3, 0, display.width() / 3,
                    display.height(), EPD_BLACK);
   display.fillRect((display.width() * 2) / 3, 0, display.width() / 3,
                    display.height(), EPD_RED);
   display.display();

   delay(15000);

   Serial.println("Text demo");
   // large block of text
   display.clearBuffer();
   display.setTextSize(1);
   testdrawtext(
       "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur "
       "adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, "
       "fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor "
       "neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet "
       "ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a "
       "tortor imperdiet posuere. ",
       EPD_BLACK);
   display.display();

   delay(15000);

   display.clearBuffer();
   for (int16_t i = 0; i < display.width(); i += 4) {
     display.drawLine(0, 0, i, display.height() - 1, EPD_BLACK);
   }

   for (int16_t i = 0; i < display.height(); i += 4) {
     display.drawLine(display.width() - 1, 0, 0, i, EPD_RED);
   }
   display.display();

   delay(15000);
   */
}
