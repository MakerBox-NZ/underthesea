#include <Adafruit_NeoPixel.h>
#define PIN 4
#define LED_COUNT 10
// Parameter 1 = number of pixels in pixels
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.show(); // Initialize all pixels to 'off'
}

// *** CHANGE COLOURS IN VOID LOOP ***
void loop() { 
  FadeInOut(0, 0, 255); //red, green, blue
  delay(500);
  FadeInOut(0, 255, 0);
}













void FadeInOut(byte red, byte green, byte blue){
  float r, g, b;
      
  for(int k = 0; k < 256; k=k+1) { 
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showPixels();
    delay(10);
  }
  

       
  for(int k = 255; k >= 0; k=k-2) {
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showPixels();
    delay(10);
  }

        
  for(int k = 0; k < 256; k=k+1) { 
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showPixels();
    delay(20);
  }
  

       
  for(int k = 255; k >= 0; k=k-2) {
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showPixels();
    delay(5);
  }

}

// *** REPLACE TO HERE ***

void showPixels() {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   pixels.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   pixels.setPixelColor(Pixel, pixels.Color(red, green, blue));
 #endif

}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < LED_COUNT; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showPixels();
}
