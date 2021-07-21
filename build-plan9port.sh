#!/bin/sh
9c io.c
9c keyboard.c
9c menu.c
9c platoterm.c
9c protocol.c
9c screen.c
9c terminal.c
9c touch.c
9l -o platoterm io.o keyboard.o menu.o platoterm.o protocol.o screen.o terminal.o touch.o

