PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
SIZE=$(PREFIX)size
CFLAGS = -mcpu=cortex-m3 -mthumb -std=c11 -O1 -g -c 
LDFLAGS = -nolibc -nostartfiles -T linker.ld -Wl,-Map=blink.map
all:main.o crt.o lcd.o init.o gpio.o systick.o  blink.elf

%.o:%.c 
	$(CC) $(CFLAGS) -c $^ -o $@
blink.elf:main.o crt.o lcd.o init.o gpio.o systick.o
	$(CC) $(LDFLAGS) $^ -o $@
	$(SIZE) $@
.PHONY:clean
clean:
	rm *.o 
	rm blink.elf 
	rm blink.map 
	
