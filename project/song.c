#include "song.h"
#include "buzzer.h"

#define SONGLEN 28

const short noteCollection[10] = {
  SILENCE, B3, C4, D4, E4,
  F4, G4, A4, B4, C5
};

const unsigned char songPart1[SONGLEN] = {
  0x08, 0x44, 0x54, 0x61, 0x61, 0x61, 0x61, 0x64,
  0x21, 0x41, 0x31, 0x31, 0x31, 0x31, 0x34,
  0x41, 0x31, 0x21, 0x21, 0x21, 0x21, 0x24,
  0x81, 0x91, 0x85, 0x71, 0x48, 0x44
};

unsigned char *song = songPart1;
void next_note()
{
  static char noteLength = 0;
  static char songPos = -1;
  static char notExtending = 1;
  static char extensionCount = 0;

  if (noteLength == 0 && notExtending) {
    char noteInSong;
    
    songPos = (songPos == SONGLEN - 1) ? 0 : songPos + 1;
    noteInSong = song[songPos];

    noteLength = (0x0F & noteInSong);                            // 1st byte is length for the note
    
    buzzer_set_period(noteCollection[(noteInSong >> 4) & 0x0F]); // 2nd byte contains index for the note itself
    // buzzer_set_period(3222);
    if (noteLength % 4 != 0) {
      notExtending = 0;
      extensionCount = noteLength % 4;
    }
    
  }

  if (notExtending ||
    noteLength > 0) {
    noteLength -= 1;
  } else {
    buzzer_set_period(0);
    extensionCount--;
    notExtending = (extensionCount == 0) ? 1 : 0;
  }
  
}
