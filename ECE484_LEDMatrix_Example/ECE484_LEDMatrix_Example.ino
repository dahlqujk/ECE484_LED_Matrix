//Mario's Ideas
//MAX7219 - using Led Control library to display 8x8   bitmap
#include <LedControl.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// On a Trinket or Gemma we suggest changing this to 1
#define PIN            13

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      1

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int DIN = 11;
int CS = 10;
int CLK   = 7;
LedControl lc=LedControl(DIN, CLK, CS,0);

int Cat[8] ={B10001000,B11111000,B10101000,B01110001,B00100001,B01111001,B01111101,B10111110   };
byte Apple [8]={B00011000,B00001000,B01110110,B11111111,B11111111,B11111111,B01111010,B00110100};

void   setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,0);
  lc.clearDisplay(0);
  #if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
  pixels.begin(); // This initializes the NeoPixel library.

  pixels.setPixelColor(0, pixels.Color(0,150,0)); // Moderately bright green color.
  digitalWrite(13,LOW);

}
   
void loop(){
  for(int i=0;i<8;i++) lc.setRow(0,i,Apple[i]);
  delay(5000);
  lc.clearDisplay(0);
  for(int i=0;i<8;i++) lc.setRow(0,i,Cat[i]);
  delay(5000);
  lc.clearDisplay(0);
}
