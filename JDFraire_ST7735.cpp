// JDFraire_ST7735.cpp

// Creator: JDFraire

// Description: Custom librarie to control the mini display ST7735S 0.96" 80x160 TFT color display with 4-wire SPI interface

// Date: 2023-08-31

// Version: 1.0

// dependences: Adafruit_GFX.h, Adafruit_ST7735.h, SPI.h

#include <Arduino.h>
#include <JDFraire_ST7735.h>

// mini display class, Child class of Adafruit_ST7735 class, add custom functions and color type (rgb565_t)
Mini_Display::Mini_Display(uint8_t cs, uint8_t rs, uint8_t rst, uint8_t blk) : Adafruit_ST7735(cs, rs, rst) {
  // constructor body

  // set the backlight pin
  _blk = blk;

}

// Initialize the display
void Mini_Display::init(uint16_t options) {
  Adafruit_ST7735::initR(options);
  // set the backlight pin as output
  pinMode(_blk, OUTPUT);
  // turn on the backlight
  digitalWrite(_blk, HIGH);
  setRotation(3);
  fillScreen(rgb565_t((uint16_t)0x0000));
  // Serial.println("TFT - \tInitialized");
  delay(250);
}

// fill the display with a color
void Mini_Display::fillScreen(rgb565_t color) {
  Adafruit_ST7735::fillScreen(color.value);
}

// Draw a rectangle
void Mini_Display::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, rgb565_t color) {
  Adafruit_ST7735::drawRect(x, y, w, h, color.value);
}

// Draw a filled rectangle
void Mini_Display::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, rgb565_t color) {
  Adafruit_ST7735::fillRect(x, y, w, h, color.value);
}

// Draw a circle
void Mini_Display::drawCircle(int16_t x0, int16_t y0, int16_t r, rgb565_t color) {
  Adafruit_ST7735::drawCircle(x0, y0, r, color.value);
}

// Draw a filled circle
void Mini_Display::fillCircle(int16_t x0, int16_t y0, int16_t r, rgb565_t color) {
  Adafruit_ST7735::fillCircle(x0, y0, r, color.value);
}

// Draw a triangle
void Mini_Display::drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y3, rgb565_t color) {
  Adafruit_ST7735::drawTriangle(x0, y0, x1, y1, x2, y3, color.value);
}

// Draw a filled triangle
void Mini_Display::fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y3, rgb565_t color) {
  Adafruit_ST7735::fillTriangle(x0, y0, x1, y1, x2, y3, color.value);
}

// Draw a rounded rectangle
void Mini_Display::drawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, rgb565_t color) {
  Adafruit_ST7735::drawRoundRect(x, y, w, h, r, color.value);
}

// Draw a filled rounded rectangle
void Mini_Display::fillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, rgb565_t color) {
  Adafruit_ST7735::fillRoundRect(x, y, w, h, r, color.value);
}

// Draw a line
void Mini_Display::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, rgb565_t color) {
  Adafruit_ST7735::drawLine(x0, y0, x1, y1, color.value);
}

// Draw a pixel
void Mini_Display::drawPixel(int16_t x, int16_t y, rgb565_t color) {
  Adafruit_ST7735::drawPixel(x, y, color.value);
}

// Draw a character
void Mini_Display::drawChar(int16_t x, int16_t y, unsigned char c, rgb565_t color, rgb565_t bg, uint8_t size) {
  Adafruit_ST7735::drawChar(x, y, c, color.value, bg.value, size);
}

// Draw a string
void Mini_Display::drawString(int16_t x, int16_t y, String s, rgb565_t color, rgb565_t bg, uint8_t size) {
  Adafruit_ST7735::setTextColor(color.value, bg.value);
  Adafruit_ST7735::setTextSize(size);
  Adafruit_ST7735::setCursor(x, y);
  Adafruit_ST7735::println(s);
}


/* Draw a centered string
  @param x1: x coordinate of the top left corner of the text box
  @param y1: y coordinate of the top left corner of the text box
  @param x2: x coordinate of the bottom right corner of the text box
  @param y2: y coordinate of the bottom right corner of the text box
  @param s: string to draw
  @param color: text color
  @param bg: background color
  @param size: text size
*/
void Mini_Display::drawStringCentered(int16_t x1, int16_t y1, int16_t x2, int16_t y2, String s, rgb565_t color, rgb565_t bg, uint8_t size) {
  
  
  Adafruit_ST7735::setTextColor(color.value, bg.value);
  Adafruit_ST7735::setTextSize(size);

  // Calculate the string width and height
  int16_t x0, y0;
  uint16_t w, h;
  Adafruit_ST7735::getTextBounds(s, 0, 0, &x0, &y0, &w, &h);

  // Calculate the string position
  int16_t x0_new = x1 + (x2 - x1 - w) / 2;
  int16_t y0_new = y1 + (y2 - y1 - h) / 2;

  // Add the offset to the string position
  x0_new += 1;
  y0_new += 1;

  // Draw the string
  Adafruit_ST7735::setCursor(x0_new, y0_new);
  Adafruit_ST7735::println(s);
}

// enter to sleep mode
void Mini_Display::sleep() {
  Adafruit_ST7735::enableDisplay(false);

  // turn off the backlight
  digitalWrite(_blk, LOW);

}

// exit from sleep mode
void Mini_Display::wakeup() {
  Adafruit_ST7735::enableDisplay(true);

  // turn on the backlight
  digitalWrite(_blk, HIGH);
}

// instance of the mini display class
extern Mini_Display mini_display = Mini_Display(TFT_CS, TFT_DC, TFT_RST, TFT_BLK);


/* TEXT BOX CLASS */

// Text box class to draw a text box with a border and a background color, enable update the text without redraw all display content
Text_Box::Text_Box(const char* text, Mini_Display *display, int x, int y, int w, int h, rgb565_t border_color, rgb565_t bg_color, rgb565_t text_color) {
  _display = display;
  _display->setTextWrap(false);
  _x = x;
  _y = y;
  _w = w;
  _h = h;
  _border_color = border_color;
  _bg_color = bg_color;
  _text_color = text_color;
  _text = text;
  _fit = true;
  _text_size = 1; // default text size
}

// Destructor
Text_Box::~Text_Box() {
  // Draw a rectangle with the background color to erase the text box
  _display->fillRect(_x, _y, _w, _h, rgb565_t(0x0000));
  // free memory of the display object
}

// Draw the text box, and update the text if needed (if the text has changed)
void Text_Box::draw() {
  // Draw the border
  _display->drawRect(_x, _y, _w, _h, _border_color);
  // Draw the background
  _display->fillRect(_x + 1, _y + 1, _w - 2, _h - 2, _bg_color);
  // Fit the text size to the text box bounds
  if (_fit) calculate_text_size();
  // Draw the text
  _display->drawStringCentered(_x + 1, _y + 1, _x + _w - 2, _y + _h - 2, _text, _text_color, _bg_color, _text_size);
}

// Calculate the text size to fit the text box bounds
void Text_Box::calculate_text_size() {
  // Calculate the text size to fit the text box bounds
  int16_t x, y;
  uint16_t w, h;
  _text_size = 1;
  _display->setTextSize(_text_size);
  _display->getTextBounds(_text, _x + 1, _y + 1, &x, &y, &w, &h);
  // Calculate the text size to fit the text box bounds
  while (w < _w - 2 && h < _h - 2) {
    _text_size++;
    _display->setTextSize(_text_size);
    _display->getTextBounds(_text, _x + 1, _y + 1, &x, &y, &w, &h);
  }
  _text_size--;
}

// Update the text box text
void Text_Box::update_text(String text) {
  // check if the text has changed
  if (text == _text) return;
  // update the text 
  _text = text;
  // draw the text box
  draw();
}

// change the text color
void Text_Box::set_text_color(rgb565_t color, bool update) {
  _text_color = color;
  // draw the text box
  if (update) draw();
}

// change the border color
void Text_Box::set_border_color(rgb565_t color, bool update) {
  _border_color = color;
  // draw the text box
  if (update) draw();
}

// change the background color
void Text_Box::set_bg_color(rgb565_t color, bool update) {
  _bg_color = color;
  // draw the text box
  if (update) draw();
}

// fit the text size to the text box bounds
void Text_Box::fit(bool fit) {
  _fit = fit;
}





