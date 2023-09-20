#include <JDFraire_ST7735.h>
#include <Arduino.h>

// Define the pins for the ST7735 display
#define TFT_CS 10
#define TFT_RST 9
#define TFT_DC 8
#define TFT_BLK 7

// Create an instance of the Mini_Display class
Mini_Display mini_display(TFT_CS, TFT_DC, TFT_RST, TFT_BLK);

// Create a Text_Box instance
Text_Box textBox("Hello, World!", &mini_display, 20, 50, 100, 40, rgb565_t(0xFFFF), rgb565_t(0x0000), rgb565_t(0xFFFF));

void setup() {
  // Initialize the Arduino and display
  mini_display.init();
}

void loop() {
  // Clear the screen with a background color
  mini_display.fillScreen(rgb565_t(0x0000));

  // Draw a red rectangle
  mini_display.fillRect(10, 10, 50, 30, rgb565_t(0xF800));  // Red color

  // Draw a blue circle
  mini_display.fillCircle(70, 40, 20, rgb565_t(0x001F));  // Blue color

  // Update the text in the text box
  static int count = 0;
  count++;
  String newText = "Count: " + String(count);
  textBox.update_text(newText);

  // Draw the text box
  textBox.draw();

  // Delay for a moment to see the display
  delay(1000);
}
