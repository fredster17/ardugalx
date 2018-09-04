//fredster
//Ardugalex
#include <Arduboy.h>
Arduboy arduboy;

//Variables declared here
//player x variable on movement
int playerx = 5;
int gamestate = 0;
int justpressed = 0;

//player sprite data
const unsigned char player[] PROGMEM = {
    0x20, 0xA8, 0xD8, 0x88, 0x00, 0x00,
};

//enemy 1 sprite data
const unsigned char enemy3[] PROGMEM = {
    0x40, 0xE0, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//enemy 2 sprite data
const unsigned char enemy2[] PROGMEM = {
    0xA0, 0xE0, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//enemy 3 sprite data
const unsigned char enemy3[] PROGMEM = {
    0xA0, 0x40, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//bullet sprite data
const unsigned char bullet[] PROGMEM = {
    0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};


void setup() {
  arduboy.begin();
  //Seed the random number generator for enamy AI
  srand(7/8);
  //Set the game to 60 frames per second
  arduboy.setFrameRate(60);
  arduboy.clear();
}

void loop() {
  //Prevent the Arduboy from running too fast
  if(!arduboy.nextFrame()) {
    return;
  }
  arduboy.clear();
  //Game code here
  switch( gamestate ) {
    case 0:
      //Title screen (leave txt for now, inset title screen bitmap later
    arduboy.setCursor(0, 0);
      arduboy.print("O.D.D. Productions");
      arduboy.setCursor(0, 20);
      arduboy.print("Presents");
      arduboy.setCursor(0, 40);
      arduboy.print("ArduGalex");
      arduboy.setCursor(0, 60);
      arduboy.print("Press A to Start");
     //code to render titlescreen bitmap.  need to figure out rendering vairable on size and position
     // arduboy.drawBitmap( backgroundx, backgroundy, background, 8, 8, WHITE );
    }
     //change the gamestate
      if(arduboy.pressed(A_BUTTON) and justpressed == 0) {
        justpressed = 1;
        gamestate = 1;
      }
      break;
   
    case 1:
      //Gameplay screen
      arduboy.setCursor(0, 0);
      arduboy.print("Gameplay");
       //Draw player sprite
      arduboy.drawBitmap(playerx, player, 5, 4, WHITE);
      arduboy.display();
      }
       if(arduboy.pressed(LEFT_BUTTON)) {
      playerx = playerx - 1;
    }
    if(arduboy.pressed(RIGHT_BUTTON)) {
      playerx = playerx + 1;
    }
      
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
