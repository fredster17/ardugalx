//fredster
//Ardugalex
#include <Arduboy.h>
Arduboy arduboy;

//Variables declared here
int gamestate = 0;

void setup() {
  arduboy.begin();
  //Seed the random number generator
  srand(7/8);
  //Set the game to 60 frames per second
  arduboy.setFrameRate(60);
  arduboy.clear();
//bitmap for tilte screen bitmap
//const unsigned char background[] PROGMEM = {
  //  {//hexcode goes here for image};
void loop() {
  //Prevent the Arduboy from running too fast
  if(!arduboy.nextFrame()) {
    return;
  }
  arduboy.clear();
  //Game code here
  switch( gamestate ) {
    case 0:
      //Title screen
      arduboy.setCursor(0, 0);
      arduboy.print("Title Screen");
     //code to render titlescreen bitmap.  need to figure out rendering vairable on size and position
       arduboy.drawBitmap( backgroundx, backgroundy, background, 8, 8, WHITE );
    }
      break;
    case 1:
      //Gameplay screen
      arduboy.setCursor(0, 0);
      arduboy.print("Gameplay");
      break;
    case 2:
      //Win screen
      arduboy.setCursor(0, 0);
      arduboy.print("Win Screen");
      break;
    case 3:
      //Game over screen
      arduboy.setCursor(0, 0);
      arduboy.print("Game Over Screen");
      break;
  }
  arduboy.display();
}
