#include <Adafruit_NeoPixel.h>

#define LEDCOUNT (9)

Adafruit_NeoPixel pixel(LEDCOUNT, 2, NEO_GRB + NEO_KHZ800);
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  pixel.begin(); // This initializes the NeoPixel library.
  pixel.setBrightness(40);
  pixel.clear();
  pixel.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < LEDCOUNT; ++i){
    int now = (counter + i * 256/9) % 256;
    pixel.setPixelColor(i, pixel.Color(0,now,255));
  }
  counter = (counter + 3) % 256;
  updateButtons();

  if (digitalRead(13)){
    tone(12, 523);
  }
  else{
    noTone(12);
  }
  pixel.show();
  delay(14);
}

void updateButtons(){
  int index = 0;
  for(int i = 3; i <= 11; ++i){
    if (digitalRead(i)){
      pixel.setPixelColor(index, pixel.Color(255,0,255)); 
    }
    ++index;
  }
}
