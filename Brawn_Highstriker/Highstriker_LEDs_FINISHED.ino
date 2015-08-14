 /*Written by Donnie Plumly. This code was created for the MoonShot Series at Team One USA.
      Feel free to use this code for your project. 
      
      Circuit setup:
      Force Sensor- left pin to 5V
                    right pin to 8200 Ohm resisitor to GND and A0
      
      WS2811- GND to GND of Arduino/Breadboard
              5V to 5V of Arduino/Breadboard
              Signal pin (white wire on this module) to pin 3
      */

#include <FastFader.h>
#include <FastLED.h>

//strip info
#define DATA_PIN     3
#define NUM_LEDS     40

#define LEVEL_ONE     3
#define LEVEL_TWO     10
#define LEVEL_THREE   20
#define LEVEL_FOUR    25
#define LEVEL_FIVE    29
#define LEVEL_SIX     32
#define LEVEL_SEVEN   36


#define Brightness   64
//#define CHIPSET      TM1803
#define LED_TYPE    WS2811
#define COLOR_ORDER  RGB
CRGB leds[NUM_LEDS];
int pixel_buffer[NUM_LEDS][3];
FastFader pixel_fader;


#define colorTemp OvercastSky

const int FSR_Pin = A0;

void setup() {
  // power-up safety delay
  Serial.begin(9600);
  Serial.print("Start-up test");
  
  delay(2000);
  // It's important to set the color correction for your LED strip here,
  // so that colors can be more accurately rendered through the 'temperature' profiles
  FastLED.addLeds<WS2811, DATA_PIN,RGB>(leds, NUM_LEDS);
  FastLED.setBrightness( Brightness );
  FastLED.setTemperature(colorTemp);
  
  // Bind the pixel fader to the LED interface
  pixel_fader.bind(pixel_buffer, leds, NUM_LEDS, FastLED);
  
  // turn on LEDs as a test, for 2 seconds. This is mostly for effect
  turnOnAll();
  delay(2000);
  turnOffAll();
  delay(2000);
  turnOnAll();
  delay(500);
  turnOffAll();
  delay(250);
  turnOnAll();
  delay(250);
  turnOffAll();
  delay(1000);
  
  Serial.println("  End startup test");
}

void loop() {
  checkFSR();
  delay(50);
}

void checkFSR() {
  //get the temperature sensor's value
  int sensorVal = analogRead(FSR_Pin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  
  
  if (sensorVal <= 10){ 
      turnOffAll();
  }
  //One   
  if (sensorVal >= 11 && sensorVal <= 145) {
      
      // growing/receeding bars
      for(int j = 0; j < 1; j++) { 
        memset(leds, 0, LEVEL_ONE * 3);
        for(int i = 0 ; i < LEVEL_ONE; i++ ) {
          switch(j) { 
            case 0: leds[i].r = 255; break;
          }
          Serial.print(" Level One, 3 leds "); 
          FastLED.show();
          delay(100);
        }
        
        delay(4000);
        
        
        for(int i = LEVEL_ONE-1 ; i >= 0; i-- ) {
          switch(j) { 
            case 0: leds[i].r = 0; break;
          }
          FastSPI_LED.show();
          delay(100);
        }
      }
      turnOffAll(); 
   
   
    //Two   
  } else if (sensorVal >= 146 && sensorVal <= 292) {
    
      // growing/receeding bars
      for(int j = 0; j < 1; j++) { 
        memset(leds, 0, LEVEL_TWO * 3);
        for(int i = 0 ; i < LEVEL_TWO; i++ ) {
          switch(j) { 
            case 0: leds[i].r = 255; break;
          }
          Serial.print(" Level Two, 10 leds "); 
          FastLED.show();
          delay(100);
        }
        
        delay(4000);
        
        for(int i = LEVEL_TWO-1 ; i >= 0; i-- ) {
          switch(j) { 
            case 0: leds[i].r = 0; break;
          }
          FastSPI_LED.show();
          delay(100);
        }
      }
      turnOffAll(); 
  }
  
  //Three 
  else if (sensorVal >= 293 && sensorVal <= 439) {
    
      // growing/receeding bars
      for(int j = 0; j < 1; j++) { 
        memset(leds, 0, LEVEL_THREE * 3);
        for(int i = 0 ; i < LEVEL_THREE; i++ ) {
          switch(j) { 
            case 0: leds[i].r = 255; break;
          }
          Serial.print(" Level Three, 18 leds "); 
          FastLED.show();
          delay(100);
        }
        
        delay(4000);
        
        for(int i = LEVEL_THREE-1 ; i >= 0; i-- ) {
          switch(j) { 
            case 0: leds[i].r = 0; break;
          }
          FastSPI_LED.show();
          delay(100);
        }
      }
      turnOffAll(); 
  }
  ///// Four ///// 
  else if (sensorVal >= 440 && sensorVal <= 586) {
       // growing/receeding bars
      for(int j = 0; j < 1; j++) { 
        memset(leds, 0, LEVEL_FOUR * 3);
        for(int i = 0 ; i < LEVEL_FOUR; i++ ) {
          switch(j) { 
            case 0: leds[i].r = 255; break;
          }
          Serial.print(" Level Four, 25 leds "); 
          FastLED.show();
          delay(50);
        }
        
        delay(4000);
        
        for(int i = LEVEL_FOUR-1 ; i >= 0; i-- ) {
          switch(j) { 
            case 0: leds[i].r = 0; break;
          }
          FastSPI_LED.show();
          delay(50);
        }
      }
      turnOffAll(); 
  }
    ///// Five /////
    else if (sensorVal >= 487 && sensorVal <= 733) {
      // growing/receeding bars
      for(int j = 0; j < 1; j++) { 
        memset(leds, 0, LEVEL_FIVE * 3);
        for(int i = 0 ; i < LEVEL_FIVE; i++ ) {
          switch(j) { 
            case 0: leds[i].r = 255; break;
          }
          Serial.print(" Level Five, 30 leds "); 
          FastLED.show();
          delay(40);
        }
        
        delay(4000);
        
        for(int i = LEVEL_FIVE-1 ; i >= 0; i-- ) {
          switch(j) { 
            case 0: leds[i].r = 0; break;
          }
          FastSPI_LED.show();
          delay(40);
        }
      }
      turnOffAll(); 
  }
  ///// Six ///// 
  else if (sensorVal >= 734 && sensorVal <= 880) {
    
      // growing/receeding bars
      for(int j = 0; j < 1; j++) { 
        memset(leds, 0, LEVEL_SIX * 3);
        for(int i = 0 ; i < LEVEL_SIX; i++ ) {
          switch(j) { 
            case 0: leds[i].r = 255; break;
          }
          Serial.print(" Level Six, 35 leds "); 
          FastLED.show();
          delay(20);
        }
        
        delay(4000);
        
        for(int i = LEVEL_SIX-1 ; i >= 0; i-- ) {
          switch(j) { 
            case 0: leds[i].r = 0; break;
          }
          FastSPI_LED.show();
          delay(20);
        }
      }
      turnOffAll(); 
  }
  ///// Seven /////
   else if (sensorVal >= 881 && sensorVal <= 1023) {
     
      // growing/receeding bars
      for(int j = 0; j < 1; j++) { 
        memset(leds, 0, LEVEL_SEVEN * 3);
        for(int i = 0 ; i < LEVEL_SEVEN; i++ ) {
          switch(j) { 
            case 0: leds[i].r = 255; break;
          }
          Serial.print(" Level Seven, 40 leds "); 
          FastLED.show();
          delay(20);
        }
        
        delay(4000);
        
        for(int i = LEVEL_SEVEN-1 ; i >= 0; i-- ) {
          switch(j) { 
            case 0: leds[i].r = 0; break;
          }
          FastSPI_LED.show();
          delay(20);
        }
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
  leds[8] = CRGB::Red;
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
