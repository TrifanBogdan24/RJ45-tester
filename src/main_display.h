#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>


// Rezolutie: 160x128

// Pini pentru display-ul 128x160
#define TFT_CS    10
#define TFT_DC    A3
#define TFT_RST   -1

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);



void init_main_display()
{
    // Init SPI 128x160 display
    tft.initR(INITR_BLACKTAB);      // Initialize display
    tft.setRotation(1);             // Optional: change to 0-3 based on setup
    tft.fillScreen(ST77XX_BLACK);   // Clear screen
}



/*
* In stange - prima varianta de cablare:
*            Sender    <->   Receiver
* Pin 1   white-orange <-> white-orange
* Pin 2   orange       <-> orange
* Pin 3   white-green  <-> white-green
* Pin 4   blue         <-> blue
* Pin 5   white-blue   <-> white-blue
* Pin 6   green        <-> green
* Pin 7   white-brown  <-> white-brown
* Pin 8   brown        <-> brown
*
*
* In dreapta - a doua varianta de cablare:
*            Sender    <->   Receiver
* Pin 1   white-green  <-> white-green
* Pin 2   green        <-> green
* Pin 3   white-orange <-> white-orange
* Pin 4   blue         <-> blue
* Pin 5   white-blue   <-> white-blue
* Pin 6   orange       <-> orange
* Pin 7   white-brown  <-> white-brown
* Pin 8   brown        <-> brown
*

* (x, y) -> upper left corner
* tft.fillRect(x, y, width, height, ST77XX_<color>);
* 
*/
void draw_straight_through_wiring()
{
    // TODO:


    const int BOX_WIDTH = 12;
    const int BOX_HEIGHT = 10;

    const int WIRE_WIDTH = 16;
    const int WIRE_HEIGHT = 2;

    const int Y_OFFSET_BTWN_BOXES = 5;
    const int WIDTH_SEP_LINE = 4;



    const int Y_BASE_OFFSET = (tft.height() - 8 * BOX_HEIGHT - 7 * Y_OFFSET_BTWN_BOXES) / 2;
    
    

    // Prima varianta de cablare:
    const int X_OFFSET_FIRST = (tft.width() / 2 - WIDTH_SEP_LINE / 2 - 4 * BOX_WIDTH - WIRE_WIDTH) / 2;

    // Pin 1   white-orange <-> white-orange
    tft.fillRect(X_OFFSET_FIRST + 0                         , Y_BASE_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_FIRST + BOX_WIDTH                 , Y_BASE_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);
    tft.fillRect(X_OFFSET_FIRST + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_FIRST + 3 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);

    // Pin 2   orange       <-> orange
    tft.fillRect(X_OFFSET_FIRST + 0                         , Y_BASE_OFFSET + BOX_HEIGHT + Y_OFFSET_BTWN_BOXES, BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);
    tft.fillRect(X_OFFSET_FIRST + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + BOX_HEIGHT + Y_OFFSET_BTWN_BOXES, BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);

    // Pin 3   white-green <-> white-green
    tft.fillRect(X_OFFSET_FIRST + 0                         , Y_BASE_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_FIRST + BOX_WIDTH                 , Y_BASE_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_GREEN);
    tft.fillRect(X_OFFSET_FIRST + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_FIRST + 3 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_GREEN);

    // Pin 4   blue         <-> blue
    tft.fillRect(X_OFFSET_FIRST + 0                         , Y_BASE_OFFSET + 3 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_BLUE);
    tft.fillRect(X_OFFSET_FIRST + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 3 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_BLUE);

    // Pin 5   white-blue   <-> white-blue
    tft.fillRect(X_OFFSET_FIRST + 0                         , Y_BASE_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_FIRST + BOX_WIDTH                 , Y_BASE_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_BLUE);
    tft.fillRect(X_OFFSET_FIRST + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_FIRST + 3 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_BLUE);

    // Pin 6   green        <-> green
    tft.fillRect(X_OFFSET_FIRST + 0                         , Y_BASE_OFFSET + 5 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_GREEN);
    tft.fillRect(X_OFFSET_FIRST + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 5 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_GREEN);

    // Pin 7   white-brown  <-> white-brown
    tft.fillRect(X_OFFSET_FIRST + 0                         , Y_BASE_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_FIRST + BOX_WIDTH                 , Y_BASE_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);
    tft.fillRect(X_OFFSET_FIRST + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_FIRST + 3 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);

    // Pin 8   brown        <-> brown
    tft.fillRect(X_OFFSET_FIRST + 0                         , Y_BASE_OFFSET + 7 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);
    tft.fillRect(X_OFFSET_FIRST + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 7 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);




    tft.fillRect((tft.width() - WIDTH_SEP_LINE) / 2, 0, WIDTH_SEP_LINE, tft.height(), ST7735_WHITE);  // Split screen



    // A doua varianta de cablare de cablare:
    const int X_OFFSET_SECOND = tft.width() / 2 + 2 + (tft.width() / 2 - 4 / 2 - 4 * BOX_WIDTH - WIRE_WIDTH) / 2;

    // Pin 1   white-green  <-> white-green
    tft.fillRect(X_OFFSET_SECOND + 0                         , Y_BASE_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_SECOND + BOX_WIDTH                 , Y_BASE_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_GREEN);
    tft.fillRect(X_OFFSET_SECOND + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_SECOND + 3 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_GREEN);

    // Pin 2   green        <-> green
    tft.fillRect(X_OFFSET_SECOND + 0                         , Y_BASE_OFFSET + BOX_HEIGHT + Y_OFFSET_BTWN_BOXES, BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_GREEN);
    tft.fillRect(X_OFFSET_SECOND + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + BOX_HEIGHT + Y_OFFSET_BTWN_BOXES, BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_GREEN);

    // Pin 3   white-orange <-> white-orange
    tft.fillRect(X_OFFSET_SECOND + 0                         , Y_BASE_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_SECOND + BOX_WIDTH                 , Y_BASE_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);
    tft.fillRect(X_OFFSET_SECOND + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_SECOND + 3 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);

    // Pin 4   blue         <-> blue
    tft.fillRect(X_OFFSET_SECOND + 0                         , Y_BASE_OFFSET + 3 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_BLUE);
    tft.fillRect(X_OFFSET_SECOND + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 3 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_BLUE);

    // Pin 5   white-blue   <-> white-blue
    tft.fillRect(X_OFFSET_SECOND + 0                         , Y_BASE_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_SECOND + BOX_WIDTH                 , Y_BASE_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_BLUE);
    tft.fillRect(X_OFFSET_SECOND + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_SECOND + 3 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_BLUE);

    // Pin 6   orange       <-> orange
    tft.fillRect(X_OFFSET_SECOND + 0                         , Y_BASE_OFFSET + 5 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);
    tft.fillRect(X_OFFSET_SECOND + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 5 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);

    // Pin 7   white-brown  <-> white-brown
    tft.fillRect(X_OFFSET_SECOND + 0                         , Y_BASE_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_SECOND + BOX_WIDTH                 , Y_BASE_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);
    tft.fillRect(X_OFFSET_SECOND + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft.fillRect(X_OFFSET_SECOND + 3 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);

    // Pin 8   brown        <-> brown
    tft.fillRect(X_OFFSET_SECOND + 0                         , Y_BASE_OFFSET + 7 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);
    tft.fillRect(X_OFFSET_SECOND + 2 * BOX_WIDTH + WIRE_WIDTH, Y_BASE_OFFSET + 7 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);
}


