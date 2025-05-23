#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>


// Rezolutie: 160x128

// Pini pentru display-ul 160x128
#define TFT_CS    10
#define TFT_DC    A3
#define TFT_RST   -1


Adafruit_ST7735 tft_lcd = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

#define COLOR_BROWN   tft_lcd.color565(112, 55, 14)



void init_tft_lcd()
{
    // Init SPI 128x160 display
    tft_lcd.initR(INITR_BLACKTAB);      // Initialize display
    tft_lcd.setRotation(1);             // Optional: change to 0-3 based on setup
    tft_lcd.fillScreen(ST77XX_BLACK);   // Clear screen
}



/*
* In stanga - prima varianta de cablare:
*           Sender     <->   Receiver
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
*           Sender     <->   Receiver
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
* tft_lcd.fillRect(x, y, width, height, <color>);
* 
*/
void draw_straight_through_wiring()
{
    init_tft_lcd();

    const int BOX_WIDTH = 12;
    const int BOX_HEIGHT = 10;

    const int WIRE_WIDTH = 17;
    const int WIRE_HEIGHT = 2;

    const int Y_OFFSET_BTWN_BOXES = 5;
    const int WIDTH_SEP_LINE = 4;



    const int Y_OFFSET = (tft_lcd.height() - 8 * BOX_HEIGHT - 7 * Y_OFFSET_BTWN_BOXES) / 2;

    
    // Prima varianta de cablare:
    const int X_OFFSET_1 = (tft_lcd.width() / 2 - WIDTH_SEP_LINE / 2 - 4 * BOX_WIDTH - WIRE_WIDTH) / 2;

    // Pin 1   white-orange <-> white-orange
    tft_lcd.fillRect(X_OFFSET_1                             , Y_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_1 + BOX_WIDTH                 , Y_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH, Y_OFFSET + 0 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_1 + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);

    // Pin 2   orange       <-> orange
    tft_lcd.fillRect(X_OFFSET_1                             , Y_OFFSET + BOX_HEIGHT + Y_OFFSET_BTWN_BOXES, BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH, Y_OFFSET + (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + BOX_HEIGHT + Y_OFFSET_BTWN_BOXES, BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);

    // Pin 3   white-green <-> white-green
    tft_lcd.fillRect(X_OFFSET_1                             , Y_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_1 + BOX_WIDTH                 , Y_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_GREEN);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH, Y_OFFSET + 2 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_1 + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_GREEN);

    // Pin 4   blue         <-> blue
    tft_lcd.fillRect(X_OFFSET_1                             , Y_OFFSET + 3 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_BLUE);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH, Y_OFFSET + 3 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 3 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_BLUE);

    // Pin 5   white-blue   <-> white-blue
    tft_lcd.fillRect(X_OFFSET_1                             , Y_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_1 + BOX_WIDTH                 , Y_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_BLUE);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH, Y_OFFSET + 4 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_1 + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_BLUE);

    // Pin 6   green        <-> green
    tft_lcd.fillRect(X_OFFSET_1                             , Y_OFFSET + 5 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_GREEN);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH, Y_OFFSET + 5 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 5 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_GREEN);

    // Pin 7   white-brown  <-> white-brown
    tft_lcd.fillRect(X_OFFSET_1                             , Y_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_1 + BOX_WIDTH                 , Y_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, COLOR_BROWN);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH, Y_OFFSET + 6 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_1 + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, COLOR_BROWN);

    // Pin 8   brown        <-> brown
    tft_lcd.fillRect(X_OFFSET_1                             , Y_OFFSET + 7 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, COLOR_BROWN);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH, Y_OFFSET + 7 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_1 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 7 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, COLOR_BROWN);




    tft_lcd.fillRect((tft_lcd.width() - WIDTH_SEP_LINE) / 2, 0, WIDTH_SEP_LINE, tft_lcd.height(), ST7735_WHITE);  // Split screen



    // A doua varianta de cablare de cablare:
    const int X_OFFSET_2 = tft_lcd.width() / 2 + 2 + (tft_lcd.width() / 2 - 4 / 2 - 4 * BOX_WIDTH - WIRE_WIDTH) / 2;

    // Pin 1   white-green  <-> white-green
    tft_lcd.fillRect(X_OFFSET_2                             , Y_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_2 + BOX_WIDTH                 , Y_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_GREEN);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH, Y_OFFSET + 0 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_2 + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_GREEN);

    // Pin 2   green        <-> green
    tft_lcd.fillRect(X_OFFSET_2                             , Y_OFFSET + BOX_HEIGHT + Y_OFFSET_BTWN_BOXES, BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_GREEN);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH, Y_OFFSET + 1 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + BOX_HEIGHT + Y_OFFSET_BTWN_BOXES, BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_GREEN);

    // Pin 3   white-orange <-> white-orange
    tft_lcd.fillRect(X_OFFSET_2                             , Y_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_2 + BOX_WIDTH                 , Y_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH, Y_OFFSET + 2 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_2 + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);

    // Pin 4   blue         <-> blue
    tft_lcd.fillRect(X_OFFSET_2                             , Y_OFFSET + 3 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_BLUE);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH, Y_OFFSET + 3 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 3 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_BLUE);

    // Pin 5   white-blue   <-> white-blue
    tft_lcd.fillRect(X_OFFSET_2                             , Y_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_2 + BOX_WIDTH                 , Y_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_BLUE);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH, Y_OFFSET + 4 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_2 + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_BLUE);

    // Pin 6   orange       <-> orange
    tft_lcd.fillRect(X_OFFSET_2                             , Y_OFFSET + 5 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH, Y_OFFSET + 5 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 5 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);

    // Pin 7   white-brown  <-> white-brown
    tft_lcd.fillRect(X_OFFSET_2                             , Y_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_2 + BOX_WIDTH                 , Y_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, COLOR_BROWN);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH, Y_OFFSET + 6 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET_2 + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, COLOR_BROWN);

    // Pin 8   brown        <-> brown
    tft_lcd.fillRect(X_OFFSET_2                             , Y_OFFSET + 7 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, COLOR_BROWN);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH, Y_OFFSET + 7 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET_2 + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 7 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, COLOR_BROWN);
}




/*
*           Sender     <->   Receiver
* Pin 1   white-orange <-> white-green
* Pin 2   orange       <-> green
* Pin 3   white-green  <-> white-orange
* Pin 4   blue         <-> blue
* Pin 5   white-blue   <-> white-blue
* Pin 6   green        <-> orange
* Pin 7   white-brown  <-> white-brown
* Pin 8   brown        <-> brown
*/
void draw_crossover_wiring()
{
    init_tft_lcd();

    const int BOX_WIDTH = 12;
    const int BOX_HEIGHT = 10;

    const int WIRE_WIDTH = 17;
    const int WIRE_HEIGHT = 2;

    const int Y_OFFSET_BTWN_BOXES = 5;

    const int X_OFFSET = (tft_lcd.width() - 4 * BOX_WIDTH - WIRE_WIDTH) / 2;
    const int Y_OFFSET = (tft_lcd.height() - 8 * BOX_HEIGHT - 7 * Y_OFFSET_BTWN_BOXES) / 2;



    // Pin 1   white-orange <-> white-green
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + BOX_WIDTH                 , Y_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + 0 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_GREEN);

    // Pin 2   orange       <-> green
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET + BOX_HEIGHT + Y_OFFSET_BTWN_BOXES, BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + BOX_HEIGHT + Y_OFFSET_BTWN_BOXES, BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_GREEN);

    // Pin 3   white-green <-> white-orange
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + BOX_WIDTH                 , Y_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_GREEN);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + 2 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);

    // Pin 4   blue         <-> blue
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET + 3 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_BLUE);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + 3 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 3 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_BLUE);

    // Pin 5   white-blue   <-> white-blue
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + BOX_WIDTH                 , Y_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_BLUE);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + 4 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_BLUE);

    // Pin 6   green        <-> orange
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET + 5 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_GREEN);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + 5 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 5 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);

    // Pin 7   white-brown  <-> white-brown
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + BOX_WIDTH                 , Y_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, COLOR_BROWN);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + 6 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, COLOR_BROWN);

    // Pin 8   brown        <-> brown
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET + 7 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, COLOR_BROWN);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + 7 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 7 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, COLOR_BROWN);
}



/*
*           Sender     <->   Receiver
* Pin 1   white-orange <-> brown
* Pin 2   orange       <-> white-brown
* Pin 3   white-green  <-> green
* Pin 4   blue         <-> white-blue
* Pin 5   white-blue   <-> blue
* Pin 6   green        <-> white-green
* Pin 7   white-brown  <-> orange
* Pin 8   brown        <-> white-orange
*/
void draw_rollover_wiring()
{
    init_tft_lcd();

    const int BOX_WIDTH = 12;
    const int BOX_HEIGHT = 10;

    const int WIRE_WIDTH = 17;
    const int WIRE_HEIGHT = 2;

    const int Y_OFFSET_BTWN_BOXES = 5;

    const int X_OFFSET = (tft_lcd.width() - 4 * BOX_WIDTH - WIRE_WIDTH) / 2;
    const int Y_OFFSET = (tft_lcd.height() - 8 * BOX_HEIGHT - 7 * Y_OFFSET_BTWN_BOXES) / 2;


    // Pin 1   white-orange <-> brown
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + BOX_WIDTH                 , Y_OFFSET, BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + 0 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 0 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, COLOR_BROWN);

    // Pin 2   orange       <-> white-brown
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET + BOX_HEIGHT + Y_OFFSET_BTWN_BOXES, BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 1 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 1 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, COLOR_BROWN);

    // Pin 3   white-green <-> green
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + BOX_WIDTH                 , Y_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_GREEN);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + 2 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 2 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_GREEN);

    // Pin 4   blue         <-> white-blue
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET + 3 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_BLUE);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + 3 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 3 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 3 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_BLUE);

    // Pin 5   white-blue   <-> blue
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + BOX_WIDTH                 , Y_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_BLUE);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + 4 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 4 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_BLUE);

    // Pin 6   green        <-> white-green
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET + 5 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_GREEN);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + 5 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 5 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 5 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_GREEN);

    // Pin 7   white-brown  <-> orange
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + BOX_WIDTH                 , Y_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, COLOR_BROWN);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + 6 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 6 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, ST77XX_ORANGE);

    // Pin 8   brown        <-> white-orange
    tft_lcd.fillRect(X_OFFSET                             , Y_OFFSET + 7 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH * 2, BOX_HEIGHT, COLOR_BROWN);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH, Y_OFFSET + 7 * (Y_OFFSET_BTWN_BOXES + BOX_HEIGHT) + (BOX_HEIGHT - WIRE_HEIGHT) / 2, WIRE_WIDTH, WIRE_HEIGHT, ST77XX_YELLOW);
    tft_lcd.fillRect(X_OFFSET + 2 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 7 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_WHITE);
    tft_lcd.fillRect(X_OFFSET + 3 * BOX_WIDTH + WIRE_WIDTH, Y_OFFSET + 7 * (BOX_HEIGHT + Y_OFFSET_BTWN_BOXES), BOX_WIDTH, BOX_HEIGHT, ST77XX_ORANGE);
}