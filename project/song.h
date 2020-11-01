#ifndef song_included
#define song_included


#define SILENCE 0
#define B3 0
#define C4 7644
#define D4 6811
#define E4 6067
#define F4 5727
#define G4 5102
#define A4 4545
#define B4 0

extern const short noteCollection[9]; 
extern char noteLength;

void next_note();

#endif
