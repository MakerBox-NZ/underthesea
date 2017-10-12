#include <Adafruit_NeoPixel.h>


#define PIN 4  //pin number
#define LED_COUNT 176 //number of LEDs in strip 48

//(Number of pixels attached to Arduino, pin connected to NeoPixels, third parameter may need changed on older NeoPixel strips)
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
 pixels.begin();//Initalise NeoPixel library
 pixels.show(); // Initialise all pixels to 'off'
}

// *** CHANGE COLOURS IN VOID LOOP ***
void loop() { 
  int randNumber = random(5, 30); //randomises delay



  






  //fade takes RGB values, from (0,0,0) up to (255,255,255)
  //ADD TO CODE BELOW
  fade(0, 150, 150, randNumber); //red, green, blue, random fade
  fade(100, 0, 0, randNumber);








  
}//THIS GOES AT END OF FADE CODE
























//*** DO NOT CHANGE CODE BELOW***
//Increase colour values by +1
void fade(byte red, byte green, byte blue, int randNumber){
  float r, g, b;
      
  for(int k = 0; k < 256; k=k+1) { 
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    pixels.show();
    delay(randNumber); //randomise duration of fade
  }

//Decrease colour values by -2
  for(int k = 255; k >= 0; k=k-2) {
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    pixels.show();
    delay(randNumber); //randomise duration of fade
  }
}



//Sets all NewPixels to on
void setAll(byte red, byte green, byte blue) {
  //First NeoPixel is 0, second is 1, and so on)
  for(int i = 0; i < LED_COUNT; i++ ) {
   pixels.setPixelColor (i, pixels.Color(red, green, blue)); 
  }
 pixels.show();
}


