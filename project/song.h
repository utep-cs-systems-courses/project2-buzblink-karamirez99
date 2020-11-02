#ifndef song_included
#define song_included


#define SILENCE 0
#define G3 10205
#define C4 7644
#define D4 6811
#define E4 6067
#define F4 5727
#define G4 5102
#define A4 4545
#define B4 4050
#define C5 3822

extern const short noteCollection[11];
extern unsigned char songSection;
extern unsigned char reset;

void next_note();
void change_section(char section);

#endif
