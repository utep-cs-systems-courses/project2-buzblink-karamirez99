COMMON_OBJECTS =
CPU	       = msp430g2553
CFLAGS	       = -mmcu=${CPU} -I../demos/h
LDFLAGS	       = -L/opt/ti/msp430_gcc/include

CC	       = msp430-elf-gcc
AS 	       = msp430-elf-as


all: toy.elf

toy.elf: ${COMMON_OBJECTS} toyMain.o buzzer.o wdInterruptHandler.o song.o led.o switches.o stateMachine.o p2_interrupt_handler.c ../demos/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.elf

buzzer.c: buzzer.h
toyMain.c: buzzer.h switches.h
wdInterruptHandler.o: song.h stateMachine.h buzzer.h
song.c: song.h
led.c: led.h
stateMachine.c: stateMachine.h
