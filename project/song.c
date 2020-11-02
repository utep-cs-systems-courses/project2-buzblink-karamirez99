#include "song.h"
#include "buzzer.h"
#include "led.h"

#define SONGP1LEN 28
#define SONGP2LEN 25

char songLen;
char songSectionsLen[] = {SONGP1LEN, SONGP2LEN};
char noteLength;
unsigned char songSection = 0;
unsigned char reset = 0;

const short noteCollection[11] = {
  SILENCE, G3, C4, D4, E4,
  F4, G4, A4, B4, C5, G3
};

const unsigned char songPart1[SONGP1LEN] = {
  0x08, 0x44, 0x54, 0x61, 0x61, 0x61, 0x61, 0x64,
  0x21, 0x41, 0x31, 0x31, 0x31, 0x31, 0x34,
  0x41, 0x31, 0x21, 0x21, 0x21, 0x21, 0x24,
  0x81, 0x91, 0x85, 0x71, 0x48, 0x44
}; 

const unsigned char songPart2[SONGP2LEN] = {
  0x08, 0x44, 0x54, 0x61, 0x61, 0x61, 0x61, 0x64,
  0x21, 0x41, 0x31, 0x31, 0x31, 0x31, 0x34,
  0x41, 0x31, 0x25, 0x11, 0x41, 0x51, 0x31, 0x21,
  0x28, 0x24
};

unsigned char *songSections[] = {songPart1, songPart2};

void next_note()
{
  static char noteLength = 0;             
  static char songPos = -1;
  static char notExtending = 1;           //Instead of writing silence, it will be assumed
  static char extensionCount = 0;         //Length of assumed silence when extending
  static char finishedSection = 0;
  
  if (reset) {
    songPos = -1;
    notExtending = 1;
    extensionCount = 0;
    noteLength = 0;
    reset = 0;
    finishedSection = 0;
    green_on = 0;
  }
  
  if (songPos == songSectionsLen[songSection] - 1){
    finishedSection = 1;
    green_on = 1;
    buzzer_set_period(SILENCE);
  }
  
  if (noteLength == 0 && notExtending && !finishedSection) {
    char noteInSong;
    
    songPos = songPos + 1;
    noteInSong = ((char*) (songSections[songSection]))[songPos];

    // 1st 4 bits is length for the note
    noteLength = (0x0F & noteInSong);
    
    // 2nd 4 bits contains index for the note itself
    buzzer_set_period(noteCollection[(noteInSong >> 4) & 0x0F]);


    //Instead of writing in silence extensionCount is assumed silence
    if (noteLength % 4 != 0) {
      notExtending = 0;
      extensionCount = noteLength % 4;
    }
    
  }

  if (notExtending || noteLength > 0) {
    noteLength -= 1;
  } else {
    buzzer_set_period(0);
    extensionCount--;
    notExtending = (extensionCount == 0) ? 1 : 0;
  }
  
}
