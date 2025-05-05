PREFIX =arm-none-eabi-
CC =$(PREFIX)gcc 
SIZE =$(PREFIX)size
CFLAGS = -mcpu=cortex-m3 -mthumb -std=c11 -g -O1 -c 

PROJECT = final.elf 

SRC += main.c  
  SRC +=    boot.c 
  SRC+=init.c
  SRC+=rcc.c 
  SRC+=gpio.c
OBJ = $(SRC:.c=.o)

$(PROJECT):$(OBJ)
	$(CC) -nolibc -nostartfiles -nostdlib   $^  -T linker.ld  -o  $@
	$(SIZE) $@



%.o:%.c 
	$(CC) $(CFLAGS) $< -o $@ 

clean:
	rm *.o 
	rm $(PROJECT)