#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>


// Rezolutie: 160x128

// Pini pentru display-ul 160x128
#define TFT_DC     9
#define TFT_CS    10
#define TFT_RST   -1


Adafruit_ST7735 tft_lcd = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

#define COLOR_BROWN   tft_lcd.color565(112, 55, 14)
#define COLOR_GREY    tft_lcd.color565(137, 128, 156)


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
    tft_lcd.fillScreen(ST77XX_BLACK);   // Clear screen


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
    tft_lcd.fillScreen(ST77XX_BLACK);   // Clear screen

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
    tft_lcd.fillScreen(ST77XX_BLACK);   // Clear screen

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




void draw_straight_through_rj45_socket()
{
    tft_lcd.fillScreen(ST77XX_BLACK);   // Clear screen

    const int WIDTH_UPPER_RECT = 70;
    const int HEIGHT_UPPER_RECT = 25;

    const int WIDTH_LOWER_RECT = 50;
    const int HEIGHT_LOWER_RECT = 20;

    const int WIDTH_SEP_LINE = 2;



    const int X_OFFSET_UPPER_RECT_OF_LEFT_SOCKET = (tft_lcd.width()/2 - WIDTH_SEP_LINE / 2 - WIDTH_UPPER_RECT) / 2;
    const int Y_OFFSET_UPPER_RECT = (tft_lcd.height() - HEIGHT_UPPER_RECT - HEIGHT_LOWER_RECT) / 2;

    const int X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET = X_OFFSET_UPPER_RECT_OF_LEFT_SOCKET + (WIDTH_UPPER_RECT - WIDTH_LOWER_RECT) / 2;
    const int Y_OFFSET_LOWER_RECT = Y_OFFSET_UPPER_RECT + HEIGHT_UPPER_RECT;


    // Draw left socket
    tft_lcd.fillRect(X_OFFSET_UPPER_RECT_OF_LEFT_SOCKET, Y_OFFSET_UPPER_RECT, WIDTH_UPPER_RECT, HEIGHT_UPPER_RECT, COLOR_GREY);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET, Y_OFFSET_LOWER_RECT, WIDTH_LOWER_RECT, HEIGHT_LOWER_RECT, COLOR_GREY);


    const int X_OFFSET_UPPER_RECT_OF_RIGHT_SOCKET = tft_lcd.width()/2 + WIDTH_SEP_LINE/2 + X_OFFSET_UPPER_RECT_OF_LEFT_SOCKET;
    const int X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET = X_OFFSET_UPPER_RECT_OF_RIGHT_SOCKET + (WIDTH_UPPER_RECT - WIDTH_LOWER_RECT) / 2;

    // Draw right socket
    tft_lcd.fillRect(X_OFFSET_UPPER_RECT_OF_RIGHT_SOCKET, Y_OFFSET_UPPER_RECT, WIDTH_UPPER_RECT, HEIGHT_UPPER_RECT, COLOR_GREY);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET, Y_OFFSET_LOWER_RECT, WIDTH_LOWER_RECT, HEIGHT_LOWER_RECT, COLOR_GREY);




    tft_lcd.fillRect((tft_lcd.width() - WIDTH_SEP_LINE) / 2, 0, WIDTH_SEP_LINE, tft_lcd.height(), ST7735_WHITE);  // Split screen

    // Draw sender pins:

    // Draw pin 1 sender: white-orange
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_ORANGE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_ORANGE);
    // Draw pin 2 sender: orange
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 1 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_ORANGE);
    // Draw pin 3 sender: white-green
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_GREEN);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_GREEN);
    // Draw pin 4 sender: blue
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 3 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_BLUE);
    // Draw pin 5 sender: white-blue
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_BLUE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_BLUE);
    // Draw pin 6 sender: green
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 5 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_GREEN);
    // Draw pin 7 sender: white-brown
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, COLOR_BROWN);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, COLOR_BROWN);
    // Draw pin 8 sender: brown
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 7 * 6, Y_OFFSET_UPPER_RECT, 4, 30, COLOR_BROWN);



    // Draw receinver pins:
    // Draw pin 1 receiver: white-orange
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_ORANGE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_ORANGE);
    // Draw pin 2 receiver: orange
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 1 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_ORANGE);
    // Draw pin 3 receiver: white-green
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_GREEN);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_GREEN);
    // Draw pin 4 receiver: blue
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 3 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_BLUE);
    // Draw pin 5 receiver: white-blue
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_BLUE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_BLUE);
    // Draw pin 6 receiver: green
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 5 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_GREEN);
    // Draw pin 7 receiver: white-brown
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, COLOR_BROWN);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, COLOR_BROWN);
    // Draw pin 8 receiver: brown
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 7 * 6, Y_OFFSET_UPPER_RECT, 4, 30, COLOR_BROWN);
}



void draw_crossover_rj45_socket()
{
    tft_lcd.fillScreen(ST77XX_BLACK);   // Clear screen

    const int WIDTH_UPPER_RECT = 70;
    const int HEIGHT_UPPER_RECT = 25;

    const int WIDTH_LOWER_RECT = 50;
    const int HEIGHT_LOWER_RECT = 20;

    const int WIDTH_SEP_LINE = 2;



    const int X_OFFSET_UPPER_RECT_OF_LEFT_SOCKET = (tft_lcd.width()/2 - WIDTH_SEP_LINE / 2 - WIDTH_UPPER_RECT) / 2;
    const int Y_OFFSET_UPPER_RECT = (tft_lcd.height() - HEIGHT_UPPER_RECT - HEIGHT_LOWER_RECT) / 2;

    const int X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET = X_OFFSET_UPPER_RECT_OF_LEFT_SOCKET + (WIDTH_UPPER_RECT - WIDTH_LOWER_RECT) / 2;
    const int Y_OFFSET_LOWER_RECT = Y_OFFSET_UPPER_RECT + HEIGHT_UPPER_RECT;


    // Draw left socket
    tft_lcd.fillRect(X_OFFSET_UPPER_RECT_OF_LEFT_SOCKET, Y_OFFSET_UPPER_RECT, WIDTH_UPPER_RECT, HEIGHT_UPPER_RECT, COLOR_GREY);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET, Y_OFFSET_LOWER_RECT, WIDTH_LOWER_RECT, HEIGHT_LOWER_RECT, COLOR_GREY);


    const int X_OFFSET_UPPER_RECT_OF_RIGHT_SOCKET = tft_lcd.width()/2 + WIDTH_SEP_LINE/2 + X_OFFSET_UPPER_RECT_OF_LEFT_SOCKET;
    const int X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET = X_OFFSET_UPPER_RECT_OF_RIGHT_SOCKET + (WIDTH_UPPER_RECT - WIDTH_LOWER_RECT) / 2;

    // Draw right socket
    tft_lcd.fillRect(X_OFFSET_UPPER_RECT_OF_RIGHT_SOCKET, Y_OFFSET_UPPER_RECT, WIDTH_UPPER_RECT, HEIGHT_UPPER_RECT, COLOR_GREY);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET, Y_OFFSET_LOWER_RECT, WIDTH_LOWER_RECT, HEIGHT_LOWER_RECT, COLOR_GREY);




    tft_lcd.fillRect((tft_lcd.width() - WIDTH_SEP_LINE) / 2, 0, WIDTH_SEP_LINE, tft_lcd.height(), ST7735_WHITE);  // Split screen

    // Draw sender pins:
    // Draw pin 1 sender: white-orange
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_ORANGE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_ORANGE);
    // Draw pin 2 sender: orange
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 1 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_ORANGE);
    // Draw pin 3 sender: white-green
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_GREEN);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_GREEN);
    // Draw pin 4 sender: blue
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 3 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_BLUE);
    // Draw pin 5 sender: white-blue
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_BLUE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_BLUE);
    // Draw pin 6 sender: green
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 5 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_GREEN);
    // Draw pin 7 sender: white-brown
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, COLOR_BROWN);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, COLOR_BROWN);
    // Draw pin 8 sender: brown
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 7 * 6, Y_OFFSET_UPPER_RECT, 4, 30, COLOR_BROWN);


    // Draw receiver pins:
    // Draw pin 1 receiver: white-green
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_GREEN);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_GREEN);
    // Draw pin 2 receiver: green
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 1 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_GREEN);
    // Draw pin 3 receiver: white-orange
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_ORANGE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_ORANGE);
    // Draw pin 4 receiver: blue
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 3 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_BLUE);
    // Draw pin 5 receiver: white-blue
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_BLUE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_BLUE);
    // Draw pin 6 receiver: orange
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 5 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_ORANGE);
    // Draw pin 7 receiver: white-brown
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, COLOR_BROWN);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, COLOR_BROWN);
    // Draw pin 8 receiver: brown
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 7 * 6, Y_OFFSET_UPPER_RECT, 4, 30, COLOR_BROWN);
}




void draw_rollover_rj45_socket()
{
    tft_lcd.fillScreen(ST77XX_BLACK);   // Clear screen

    const int WIDTH_UPPER_RECT = 70;
    const int HEIGHT_UPPER_RECT = 25;

    const int WIDTH_LOWER_RECT = 50;
    const int HEIGHT_LOWER_RECT = 20;

    const int WIDTH_SEP_LINE = 2;



    const int X_OFFSET_UPPER_RECT_OF_LEFT_SOCKET = (tft_lcd.width()/2 - WIDTH_SEP_LINE / 2 - WIDTH_UPPER_RECT) / 2;
    const int Y_OFFSET_UPPER_RECT = (tft_lcd.height() - HEIGHT_UPPER_RECT - HEIGHT_LOWER_RECT) / 2;

    const int X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET = X_OFFSET_UPPER_RECT_OF_LEFT_SOCKET + (WIDTH_UPPER_RECT - WIDTH_LOWER_RECT) / 2;
    const int Y_OFFSET_LOWER_RECT = Y_OFFSET_UPPER_RECT + HEIGHT_UPPER_RECT;


    // Draw left socket
    tft_lcd.fillRect(X_OFFSET_UPPER_RECT_OF_LEFT_SOCKET, Y_OFFSET_UPPER_RECT, WIDTH_UPPER_RECT, HEIGHT_UPPER_RECT, COLOR_GREY);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET, Y_OFFSET_LOWER_RECT, WIDTH_LOWER_RECT, HEIGHT_LOWER_RECT, COLOR_GREY);


    const int X_OFFSET_UPPER_RECT_OF_RIGHT_SOCKET = tft_lcd.width()/2 + WIDTH_SEP_LINE/2 + X_OFFSET_UPPER_RECT_OF_LEFT_SOCKET;
    const int X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET = X_OFFSET_UPPER_RECT_OF_RIGHT_SOCKET + (WIDTH_UPPER_RECT - WIDTH_LOWER_RECT) / 2;

    // Draw right socket
    tft_lcd.fillRect(X_OFFSET_UPPER_RECT_OF_RIGHT_SOCKET, Y_OFFSET_UPPER_RECT, WIDTH_UPPER_RECT, HEIGHT_UPPER_RECT, COLOR_GREY);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET, Y_OFFSET_LOWER_RECT, WIDTH_LOWER_RECT, HEIGHT_LOWER_RECT, COLOR_GREY);




    tft_lcd.fillRect((tft_lcd.width() - WIDTH_SEP_LINE) / 2, 0, WIDTH_SEP_LINE, tft_lcd.height(), ST7735_WHITE);  // Split screen

    // Draw sender pins:
    // Draw pin 1 sender: white-orange
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_ORANGE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_ORANGE);
    // Draw pin 2 sender: orange
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 1 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_ORANGE);
    // Draw pin 3 sender: white-green
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_GREEN);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_GREEN);
    // Draw pin 4 sender: blue
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 3 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_BLUE);
    // Draw pin 5 sender: white-blue
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_BLUE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_BLUE);
    // Draw pin 6 sender: green
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 5 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_GREEN);
    // Draw pin 7 sender: white-brown
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, COLOR_BROWN);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, COLOR_BROWN);
    // Draw pin 8 sender: brown
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_LEFT_SOCKET + 2 + 7 * 6, Y_OFFSET_UPPER_RECT, 4, 30, COLOR_BROWN);


    // Draw receiver pins:
    // Draw pin 1 receiver: brown
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2, Y_OFFSET_UPPER_RECT, 4, 30, COLOR_BROWN);
    // Draw pin 2 receiver: white-brown
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 1 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, COLOR_BROWN);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 1 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 1 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, COLOR_BROWN);
    // Draw pin 3 receiver: green
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 2 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_GREEN);
    // Draw pin 4 receiver: white-blue
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 3 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_BLUE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 3 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 3 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_BLUE);
    // Draw pin 5 receiver: blue
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 4 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_BLUE);
    // Draw pin 6 receiver: white-green
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 5 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_GREEN);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 5 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 5 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_GREEN);
    // Draw pin 7 receiver: orange
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 6 * 6, Y_OFFSET_UPPER_RECT, 4, 30, ST7735_ORANGE);
    // Draw pin 8 receiver: white-orange
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 7 * 6, Y_OFFSET_UPPER_RECT     , 4, 10, ST7735_ORANGE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 7 * 6, Y_OFFSET_UPPER_RECT + 10, 4, 10, ST7735_WHITE);
    tft_lcd.fillRect(X_OFFSET_LOWER_RECT_OF_RIGHT_SOCKET + 2 + 7 * 6, Y_OFFSET_UPPER_RECT + 20, 4, 10, ST7735_ORANGE);
}