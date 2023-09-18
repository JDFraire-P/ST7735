// JDFraire_ST7735.h

// Custom librarie to control the mini display ST7735S 0.96" 80x160 TFT color display with 4-wire SPI interface

// Creator: JDFraire

// Date: 2023-08-31

// Version: 1.0

// dependences: Adafruit_GFX.h, Adafruit_ST7735.h, SPI.h

#ifndef JDFraire_ST7735_h
#define JDFraire_ST7735_h

// These pins will also work for the 0.96" TFT shield.
#define TFT_CS        10
#define TFT_RST        9 
#define TFT_DC         8
#define TFT_BLK         7 // Display backlight pin

// tradeoff being that performance is not as fast as hardware SPI above.
#define TFT_MOSI 11  // Data out
#define TFT_SCLK 13  // Clock out SCK

#include <Arduino.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h> // SPI library
#include <JDFraire_ColorsUtils.h> // Color utilities library, add color types and conversion functions

// mini display class, Child class of Adafruit_ST7735 class, add custom functions and color type (rgb565_t)
class Mini_Display : public Adafruit_ST7735{
  public:
    // Constructor
    Mini_Display(uint8_t cs, uint8_t rs, uint8_t rst, uint8_t blk);
    // Initialize the display
    void init(uint16_t options = INITR_MINI160x80_PLUGIN);
    // Fill the display with a color
    void fillScreen(rgb565_t color);
    // Draw a rectangle
    void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, rgb565_t color);
    // Draw a filled rectangle
    void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, rgb565_t color);
    // Draw a circle
    void drawCircle(int16_t x0, int16_t y0, int16_t r, rgb565_t color);
    // Draw a filled circle
    void fillCircle(int16_t x0, int16_t y0, int16_t r, rgb565_t color);
    // Draw a triangle
    void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y3, rgb565_t color);
    // Draw a filled triangle
    void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y3, rgb565_t color);
    // Draw a rounded rectangle
    void drawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, rgb565_t color);
    // Draw a filled rounded rectangle
    void fillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, rgb565_t color);
    // Draw a line
    void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, rgb565_t color);
    // Draw a pixel
    void drawPixel(int16_t x, int16_t y, rgb565_t color);
    // Draw a character
    void drawChar(int16_t x, int16_t y, unsigned char c, rgb565_t color, rgb565_t bg, uint8_t size);
    // Draw a string
    void drawString(int16_t x, int16_t y, String s, rgb565_t color, rgb565_t bg, uint8_t size);
    // Draw a centered string
    void drawStringCentered(int16_t x1, int16_t y1, int16_t x2, int16_t y2, String s, rgb565_t color, rgb565_t bg, uint8_t size);
    // enter to sleep mode
    void sleep();
    // exit from sleep mode
    void wakeup();
  private:
    // backlight pin
    uint8_t _blk;
};

// Text box class to draw a text box with a border and a background color, enable update the text without redraw all display content
class Text_Box{
  public:
    // Constructor
    Text_Box(const char* text, Mini_Display *display, int x, int y, int w, int h, rgb565_t border_color, rgb565_t bg_color, rgb565_t text_color);
    // Destructor
    ~Text_Box();

    // Draw the text box
    void draw();
    // Update the text box text
    void update_text(String text);
    // Calculate the text size to fit the text box bounds
    void calculate_text_size();
    // change the text color
    void set_text_color(rgb565_t color, bool update = true);
    // change the border color
    void set_border_color(rgb565_t color, bool update = true);
    // change the background color
    void set_bg_color(rgb565_t color, bool update = true);
    // fit the text size to the text box bounds
    void fit(bool fit = true);


  private:

    Mini_Display *_display;

    int16_t _x;
    int16_t _y;
    int16_t _w;
    int16_t _h;
    rgb565_t _border_color;
    rgb565_t _bg_color;
    rgb565_t _text_color;
    uint8_t _text_size;
    String _text;
    bool _fit; // flag to know if the text size is fitted to the text box bounds
  
};

extern Mini_Display mini_display;

#endif