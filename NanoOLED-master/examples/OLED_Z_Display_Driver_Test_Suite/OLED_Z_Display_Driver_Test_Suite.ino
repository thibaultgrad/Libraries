#include <Wire.h>
#include <NanoOLED.h>

static const uint8_t SeeedLogo[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x60, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0xff, 0xfc, 0x00, 0x00, 0x00, 0x80, 0xf0, 0x20, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0x60, 0xe0, 0xc0,
    0xc0, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x60, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x80, 0xc0,
    0xc0, 0xe0, 0x60, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x60, 0xe0, 0xc0, 0xc0,
    0x80, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xc0, 0xc0, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xc0, 0xc0, 0xe0, 0x60, 0xc0, 0xc0, 0x80, 0x00, 0xc0, 0xf0, 0xf0, 0xf0, 0xc0, 0x00, 0xc0,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xc0, 0xc0,
    0xf8, 0xf8, 0x00, 0xd8, 0xd8, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0x60, 0xc0, 0xc0, 0x80, 0x00,
    0x00, 0x03, 0x0f, 0x1e, 0x3c, 0x70, 0xe3, 0xcf, 0x9f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x70, 0xbf,
    0xcf, 0xe3, 0x70, 0x78, 0x3e, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x33, 0x77, 0x66, 0x66, 0x66, 0x6c,
    0x7d, 0x18, 0x00, 0x1f, 0x3f, 0x76, 0x66, 0x66, 0x66, 0x76, 0x37, 0x07, 0x00, 0x0f, 0x3f, 0x7f,
    0x66, 0x66, 0x66, 0x66, 0x77, 0x27, 0x07, 0x00, 0x1f, 0x3f, 0x76, 0x66, 0x66, 0x66, 0x76, 0x37,
    0x07, 0x00, 0x0f, 0x3f, 0x71, 0x60, 0x60, 0x60, 0x60, 0x31, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00,
    0x11, 0x37, 0x67, 0x66, 0x66, 0x6c, 0x7d, 0x38, 0x00, 0x00, 0x3f, 0x7f, 0x3f, 0x00, 0x00, 0x1f,
    0x3f, 0x70, 0x60, 0x60, 0x70, 0x7f, 0x7f, 0x00, 0x0f, 0x3f, 0x71, 0x60, 0x60, 0x60, 0x60, 0x31,
    0x7f, 0x7f, 0x00, 0x7f, 0x7f, 0x00, 0x06, 0x1f, 0x3b, 0x60, 0x60, 0x60, 0x60, 0x71, 0x3f, 0x1f,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x48, 0x48, 0x48, 0xb0, 0x00, 0xc0, 0x20,
    0x20, 0x20, 0xc0, 0x00, 0xc0, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x40, 0xa0, 0xa0, 0xa0, 0x20, 0x00,
    0x00, 0x20, 0xf0, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0xf8, 0x08,
    0x08, 0x00, 0xc0, 0x20, 0x20, 0x20, 0xf8, 0x00, 0xc0, 0xa0, 0xa0, 0xa0, 0xc0, 0x00, 0x20, 0xa0,
    0xa0, 0xa0, 0xc0, 0x00, 0x40, 0xa0, 0xa0, 0xa0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x48, 0x48, 0x48, 0x08, 0x00, 0x20, 0x40, 0x80, 0x40,
    0x20, 0x00, 0x00, 0x20, 0xf0, 0x20, 0x20, 0x00, 0xc0, 0xa0, 0xa0, 0xa0, 0xc0, 0x00, 0xe0, 0x00,
    0x20, 0x20, 0xc0, 0x00, 0xc0, 0x20, 0x20, 0x20, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x01, 0x00, 0x01, 0x02,
    0x02, 0x02, 0x01, 0x00, 0x01, 0x02, 0x02, 0x02, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x01, 0x00,
    0x00, 0x00, 0x01, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x03, 0x02,
    0x02, 0x00, 0x01, 0x02, 0x02, 0x02, 0x03, 0x00, 0x01, 0x02, 0x02, 0x02, 0x00, 0x00, 0x01, 0x02,
    0x02, 0x02, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x00, 0x00, 0x08, 0x06, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x82, 0x02, 0x00, 0x02, 0x01, 0x01, 0x01,
    0x02, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x00, 0x01, 0x02, 0x02, 0x02, 0x00, 0x00, 0x03, 0x00,
    0x00, 0x00, 0x03, 0x00, 0x01, 0x02, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x82, 0x8c, 0x60, 0x1c, 0x02, 0x00, 0x1c, 0x22, 0x22, 0x22, 0x1c, 0x00, 0x1e,
    0x20, 0x20, 0x00, 0x3e, 0x00, 0x00, 0x3e, 0x04, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3e, 0x04, 0x02, 0x02, 0x00, 0x1c, 0x2a, 0x2a, 0x2a, 0x0c, 0x00, 0x12, 0x2a, 0x2a,
    0x2a, 0x1c, 0x20, 0x1c, 0x22, 0x22, 0x22, 0x14, 0x00, 0x3f, 0x00, 0x02, 0x02, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

NanoOLED NanoOled;

void setup()
{
  Wire.begin();
  NanoOled.init(); //initialze SEEED OLED display
}

void setDisplayToOriginalState(int testCase)

{
  delay(5000);
  NanoOled.init();             //initialze SEEED OLED display
  NanoOled.clearDisplay();     // clear the screen and set start position to top left corner
  NanoOled.deactivateScroll(); // deactivete Scroll (might be activated by previous test case)
  NanoOled.setNormalDisplay(); // Non-inverted Display
  NanoOled.setPageMode();      // Page mode to start with
  NanoOled.setCursor(2, 0);    // 0 Page, 0th Column
  NanoOled.print("Test Case ");
  NanoOled.print(testCase);
  NanoOled.setCursor(3, 0);
  NanoOled.print("Test Case ");
  NanoOled.print(testCase);
  NanoOled.setCursor(4, 0);
  NanoOled.print("Test Case ");
  NanoOled.print(testCase);
  NanoOled.setCursor(5, 0);
  NanoOled.print("Test Case ");
  NanoOled.print(testCase);
  delay(2000);
}

void loop()
{

  setDisplayToOriginalState(1);

  NanoOled.clearDisplay();        //clear the screen and set start position to top left corner
  NanoOled.setNormalDisplay();    //Set display to normal mode (i.e non-inverse mode)
  NanoOled.setPageMode();         //Set addressing mode to Page Mode
  NanoOled.setCursor(0, 0);       //Set the cursor to Xth Page, Yth Column
  NanoOled.print("Hello World!"); //Print the String

  setDisplayToOriginalState(2);

  NanoOled.clearDisplay();     //clear the screen and set start position to top left corner
  NanoOled.setNormalDisplay(); //Set display to Normal mode
  NanoOled.setPageMode();      //Set addressing mode to Page Mode
  NanoOled.setCursor(0, 0);    //Set the cursor to 0th Page, 0th Column
  NanoOled.print(123);         //Print number
  NanoOled.setCursor(1, 0);    //Set the cursor to 1st Page, 0th Column
  NanoOled.print(0xFFFF);      //Print number
  NanoOled.setCursor(2, 0);    //Set the cursor to 2nd Page, 0th Column
  NanoOled.print(0xFFFFFFFF);  //Print number
  NanoOled.setCursor(3, 0);    //Set the cursor to 3rd Page, 0th Column
  NanoOled.print(-12345);      //Print number

  setDisplayToOriginalState(3);

  NanoOled.clearDisplay();                                                                                            //clear the screen and set start position to top left corner
  NanoOled.setNormalDisplay();                                                                                        //Set display to Normal mode
  NanoOled.setHorizontalMode();                                                                                       //Set addressing mode to Horizontal Mode
  NanoOled.print("!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"); //Print String (ASCII 32 - 126 )

  setDisplayToOriginalState(4);

  NanoOled.clearDisplay();                      // clear the screen and set start position to top left corner
  NanoOled.drawBitmap(SeeedLogo, 0, 0, 8, 128); // 1024 = 128 Pixels * 64 Pixels / 8

  setDisplayToOriginalState(5);

  NanoOled.setInverseDisplay();                 // Set Display to inverse mode
  NanoOled.clearDisplay();                      // clear the screen and set start position to top left corner
  NanoOled.drawBitmap(SeeedLogo, 0, 0, 8, 128); // 1024 = 128 Pixels * 64 Pixels / 8

  setDisplayToOriginalState(6);

  NanoOled.clearDisplay();                                                   // clear the screen and set start position to top left corner
  NanoOled.drawBitmap(SeeedLogo, 0, 0, 8, 128);                              // 1024 = 128 Pixels * 64 Pixels / 8
  NanoOled.setHorizontalScrollProperties(Scroll_Left, 4, 7, Scroll_5Frames); //Set Scrolling properties to Scroll Left
  NanoOled.activateScroll();                                                 // Activate Scrolling
  delay(5000);

  setDisplayToOriginalState(7);

  NanoOled.clearDisplay();                                                    // clear the screen and set start position to top left corner
  NanoOled.drawBitmap(SeeedLogo, 0, 0, 8, 128);                               // 1024 = 128 Pixels * 64 Pixels / 8
  NanoOled.setHorizontalScrollProperties(Scroll_Right, 4, 7, Scroll_5Frames); //Set the properties of Horizontal Scrool
  NanoOled.activateScroll();                                                  // Activate Scroll
  delay(5000);
}
