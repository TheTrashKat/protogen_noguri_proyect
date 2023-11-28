
#include <MD_MAX72xx.h>
#include <SPI.h>

#define ANIMATION_DELAY 75	// milliseconds
#define MAX_FRAMES      4   // number of animation frames

#define HARDWARE_TYPE MD_MAX72XX::DR0CR0RR1_HW
#define MAX_DEVICES 4

#define CLK_PIN   10  // or SCK
#define DATA_PIN   8 // or MOSI
#define CS_PIN    9  // or SS

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

uint32_t prevTimeAnim = 0;  // remember the millis() value in animations
int16_t idx;                // display index (column)
uint8_t frame;              // current animation frame
uint8_t deltaFrame;         // the animation frame offset for the next frame

void resetMatrix(void)
{
  mx.control(MD_MAX72XX::INTENSITY, MAX_INTENSITY/2);
  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
  mx.clear();
}

void setup() {
resetMatrix();
prevTimeAnim = millis();
mx.begin();

}

void loop() {
  if (millis()-prevTimeAnim < ANIMATION_DELAY)
    return;
  prevTimeAnim = millis();      // starting point for next time

  char Angry2L[] =    {B00000000, B00000011, B00001111, B00011111, B00111111, B00111111, B00011111, B00000000};
  char Angry1L[] =    {B00000000, B10000000, B11100000, B11111000, B11111100, B11111110, B11111100, B00000000};
  char noseLeft[] =   {B00000000, B00000000, B10000000, B11000000, B11000000, B11111100, B01111110, B00000000};
  for (uint8_t i=0; i<7; i++){
    mx.setRow(0,i, Angry1L[i]);
    mx.setRow(1,i, Angry2L[i]);
     mx.setRow(2,i, 0);
     mx.setRow(3,i, noseLeft[i]);
 
  }
}
