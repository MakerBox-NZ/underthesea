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
  int randNumber = random(5, 20); //randomises delay



  






  //fade takes RGB values, from (0,0,0) up to (255,255,255)
  //ADD TO CODE BELOW
  //fade(0, 150, 150, randNumber); //red, green, blue, random fade
  //fade(200,50,255, randNumber) ; //purple
  //fade(5,5,60, randNumber); //faint blue
  fade(0,0,255,randNumber); //darker blue
  fade(0,255,255,randNumber); //sea green
  //fade(210,200,150,randNumber); //yellow-y orange

  //fade(196,56,236,randNumber);//white/yellow/orange
  //fade(255,0,255,randNumber); //pinky purple
  //fade(200, 170, 150, randNumber); //yellow?
  //fade(150, 300, 100, randnumber); 
  //fade(255, 255, 255,randNumber);//turqoise.
  //fade(234, 123, 211,randNumber);//yellowy orange.
  //fade(20, 99, 101, randNumber);
  //fade(10,100,240,randNumber);


  fade(1, 2, 3, randNumber);
  fade(255,240,1,randNumber);
  fade(0,244,244, randNumber);

  fade(255,0,255,randNumber );
  fade(6,6,6,randNumber);
  fade(156,247,0,randNumber);
   






  










  








  
}//THIS GOES AT END OF FADE CODE

















YEET LOL 666






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

