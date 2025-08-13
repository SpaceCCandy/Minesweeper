set arch avr 
set serial baud 115200 
file main.elf 
target remote /dev/ttyACM8
layout src 
focus cmd 