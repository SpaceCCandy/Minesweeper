CC      = avr-gcc
CFLAGS += \
    -DF_CPU=16000000ULL \
    -O1 \
    -Wall \
    -Wextra \
    -Wpedantic \
    -g \
    -mmcu=atmega328p \
<<<<<<< HEAD
    -std=gnu11 \
=======
    -std=gnu17
>>>>>>> d119d16dc30ab7f81ddd59845d96a27c6aaa501b

.PHONY: all
all: main.elf

.PHONY: clean
clean:
	@rm -rvf *.d *.elf *.o

main.elf: main.o mapping.o move.o checkDig.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.S
	$(CC) $(CFLAGS) -MM -MF $*.d $<
	$(CC) $(CFLAGS) -c $<
<<<<<<< HEAD

=======
>>>>>>> d119d16dc30ab7f81ddd59845d96a27c6aaa501b

%.o: %.c
	$(CC) $(CFLAGS) -MM -MF $*.d $<
	$(CC) $(CFLAGS) -c $<

-include $(wildcard *.d)
