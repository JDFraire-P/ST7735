# JDFraire ST7735 Library

**Version**: 1.0  
**Release Date**: August 31, 2023  
**Creator**: JDFraire

![ST7735 Mini Display]

## Overview

The JDFraire ST7735 Library is a custom Arduino library designed for controlling the ST7735S 0.96" 80x160 TFT color display with a 4-wire SPI interface. This library provides an easy-to-use interface to control and display graphics on this mini display.

## Features

- **Custom Mini Display Class**: Extends the Adafruit ST7735 library and adds custom functions for drawing shapes, text, and more on the ST7735S display.
- **Color Utilities**: Includes a color utilities library for managing colors with rgb565_t type and conversion functions.
- **Text Box Class**: Allows you to create and manage text boxes with customizable border, background, and text colors. You can update the text within a text box without redrawing the entire display.

## Dependencies

This library depends on the following Arduino libraries:
- `Adafruit_GFX.h`: Core graphics library.
- `Adafruit_ST7735.h`: Hardware-specific library for ST7735.
- `SPI.h`: SPI library.

## Installation

1. Download the library files.
2. Place the `JDFraire_ST7735` folder into the `libraries` directory in your Arduino sketchbook directory.
3. Restart the Arduino IDE if it's open.

## Usage

To use the JDFraire ST7735 Library in your Arduino project, follow these steps:

1. Include the library at the beginning of your Arduino sketch:

   ```cpp
   #include <JDFraire_ST7735.h>

2. Initialize the Mini Display object with the appropriate pins:

   ```cpp
   Mini_Display mini_display(TFT_CS, TFT_DC, TFT_RST, TFT_BLK);

3. Initialize the display and set its options:
   
   ```cpp
   mini_display.init();

4. Use the library's functions to draw shapes, text, and manage text boxes on the display. Example:

   ```cpp
   // Fill the screen with a color
   mini_display.fillScreen(rgb565_t(0x1234));
   
   // Draw a rectangle
   mini_display.drawRect(10, 10, 30, 20, rgb565_t(0xFFFF));

   // Create a text box
   Text_Box textBox("Hello, World!", &mini_display, 20, 50, 80, 30, rgb565_t(0xFFFF), rgb565_t(0x0000), rgb565_t(0xFFFF));

   // Update the text within the text box
   textBox.update_text("New Text");

5. Customize the library's functions and classes as needed for your project.

## Documentation

For detailed information on available functions and how to use them, please refer to the code comments in the library source files: `JDFraire_ST7735.h` and `JDFraire_ST7735.cpp`.

## License

This library is open-source software released under the [MIT License](LICENSE).

## Contributing

If you'd like to contribute to this library or report issues, please visit the [GitHub repository](link_to_repository).

## Credits

- JDFraire: Creator and maintainer of the library.

## Support

If you encounter any issues or have questions about using this library, feel free to contact the creator or open an issue on the GitHub repository.

---

**Enjoy using the JDFraire ST7735 Library for your projects!**
