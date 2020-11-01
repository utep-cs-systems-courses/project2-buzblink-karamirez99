#include "song.h"
#include "buzzer.h"

#define SONGLEN 3

const short noteCollection[9] = {
  SILENCE, B3, C4, D4, E4,
  F4, G4, A4, B4
};

const unsigned char song[SONGLEN] = {
  0x04, 0x42, 0x52
};

void next_note()
{
  static char noteLength = 0;
  static char songPos = -1;

  if (noteLength == 0) {
    char noteInSong;
    
    songPos = (songPos == SONGLEN - 1) ? 0 : songPos + 1;
    noteInSong = song[songPos];

    noteLength = (0x0F & noteInSong);                            // 1st byte is length for the note
    
    buzzer_set_period(noteCollection[(noteInSong >> 4) & 0x0F]); // 2nd byte is length for the note
  }

  noteLength -= 1;;
  
}
