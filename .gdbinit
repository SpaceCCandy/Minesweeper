set arch avr 
set serial baud 115200 
file main.elf 
target remote /dev/cu.usbmodem1101
mon debugwire e
layout src 
focus cmd 