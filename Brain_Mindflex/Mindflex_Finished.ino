    /*Written by Rob Edwards and Donnie Plumly. This code was created for the MoonShot Series at Team One USA.
      Feel free to use this code for your project. 
      
      Circuit setup:
      MindFlex- GND to GND of Arduino/Breadboard
                TX to RX of Arduino/Breadboard /// Make sure when uploading you disconnect this pin!!! 
                                                   If not the you will get an error.
      WS2811- GND to GND of Arduino/Breadboard
              5V to 5V of Arduino/Breadboard
              Signal pin (white wire on this module) to pin 3
      */

  #include <Brain.h>
  #include <FastFader.h>
  #include <FastLED.h>
  
  #define DATA_PIN     3
  #define NUM_LEDS     40
  
  #define LEVEL_ONE     3
  #define LEVEL_TWO     10
  #define LEVEL_THREE   18
  #define LEVEL_FOUR    25
  #define LEVEL_FIVE    30
  #define LEVEL_SIX     35
  #define LEVEL_SEVEN   40
  
  int brainVal;
  
  #define Brightness   64
  #define LED_TYPE    WS2811
  #define COLOR_ORDER  RGB
  #define colorTemp OvercastSky
  CRGB leds[NUM_LEDS];


  Brain brain(Serial);
  
  void setup() {
     Serial.begin(9600);
     
     FastLED.addLeds<WS2811, DATA_PIN,RGB>(leds, NUM_LEDS);
     FastLED.setBrightness( Brightness );
     FastLED.setTemperature(colorTemp);
  }
  
  void loop() {
     if (brain.update()) {
       
        delay(10000); // Give the user time to concentrate
        brainVal = brain.readAttention() / 2.5;
        Serial.println(brainVal); 
        
         for( int i = 0; i < brainVal; i++) {
            leds[i] = CRGB::Red;
            FastLED.show();
            delay(100);
          }
          
          delay(4000);
          
         for( int i = brainVal-1; i >= 0; i--) {
            leds[i] = CRGB::Black;
            FastLED.show();
            delay(100);
          }
        turnOffAll();
     }
   }
   
  
///////////////////////////////////////////////////////////
void turnOffAll() {
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  leds[5] = CRGB::Black;
  leds[6] = CRGB::Black;
  leds[7] = CRGB::Black;
  leds[8] = CRGB::Black;
  leds[9] = CRGB::Black;
  
  leds[10] = CRGB::Black;
  leds[11] = CRGB::Black;
  leds[12] = CRGB::Black;
  leds[13] = CRGB::Black;
  leds[14] = CRGB::Black;
  leds[15] = CRGB::Black;
  leds[16] = CRGB::Black;
  leds[17] = CRGB::Black;
  leds[18] = CRGB::Black;
  leds[19] = CRGB::Black;
  
  leds[20] = CRGB::Black;
  leds[21] = CRGB::Black;
  leds[22] = CRGB::Black;
  leds[23] = CRGB::Black;
  leds[24] = CRGB::Black;
  leds[25] = CRGB::Black;
  leds[26] = CRGB::Black;
  leds[27] = CRGB::Black;
  leds[28] = CRGB::Black;
  leds[29] = CRGB::Black;
  
  leds[30] = CRGB::Black;
  leds[31] = CRGB::Black;
  leds[32] = CRGB::Black;
  leds[33] = CRGB::Black;
  leds[34] = CRGB::Black;
  leds[35] = CRGB::Black;
  leds[36] = CRGB::Black;
  leds[37] = CRGB::Black;
  leds[38] = CRGB::Black;
  leds[39] = CRGB::Black; 
  FastLED.show(); //turn on the LEDs 
}

void turnOnAll() {
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  leds[2] = CRGB::Red;
  leds[3] = CRGB::Red;
  leds[4] = CRGB::Red;
  leds[5] = CRGB::Red;
  leds[6] = CRGB::Red;
  leds[7] = CRGB::Red;
  leds[8] = CRGB::Red;  /*Written by Donnie Plumly. Feel free to take this code to the monn and back if your heart desires */
  /*Written by Donnie Plumly. Feel free to take this code to the monn and back if your heart desires */
  /*Written by Donnie Plumly. Feel free to take this code to the monn and back if your heart desires */

  leds[9] = CRGB::Red;

  leds[10] = CRGB::Red;
  leds[11] = CRGB::Red;
  leds[12] = CRGB::Red;
  leds[13] = CRGB::Red;
  leds[14] = CRGB::Red;
  leds[15] = CRGB::Red;
  leds[16] = CRGB::Red;
  leds[17] = CRGB::Red;
  leds[18] = CRGB::Red;
  leds[19] = CRGB::Red;

  leds[20] = CRGB::Red;
  leds[21] = CRGB::Red;
  leds[22] = CRGB::Red;
  leds[23] = CRGB::Red;
  leds[24] = CRGB::Red;
  leds[25] = CRGB::Red;
  leds[26] = CRGB::Red;
  leds[27] = CRGB::Red;
  leds[28] = CRGB::Red;
  leds[29] = CRGB::Red;

  leds[30] = CRGB::Red;
  leds[31] = CRGB::Red;
  leds[32] = CRGB::Red;
  leds[33] = CRGB::Red;
  leds[34] = CRGB::Red;
  leds[35] = CRGB::Red;
  leds[36] = CRGB::Red;
  leds[37] = CRGB::Red;
  leds[38] = CRGB::Red;
  leds[39] = CRGB::Red;  
  FastLED.show(); //turn on the LEDs 
}
