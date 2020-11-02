Project 2: buzblink
====================
# Compiling the program:

Typing "make load" into this project directory will create 'toy.elf' and load it into
the MSP430

# Running lab2:

When loaded, the user will be able to perform the following actions:
1. Press SW1 to play section one of the song
2. Press SW2 to play section two of the song
3. Press SW3 to turn off the leds as a section is being played 
4. Press SW4 to pause a section as it is being played

# Notes/Limitations:
A couple of notes for the lab:
- Pausing a section will continute to play the note if one was playing before it is paused
- The green led turns on when a section is finished and the red led continues to blink anyway 
