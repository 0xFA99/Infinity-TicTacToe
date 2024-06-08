#!/bin/bash

CC=cc
CFLAGS="-Wall -Wextra -pedantic"
LDFLAGS="-Iinclude -lraylib"

$CC main.c -o InfinityTicTacToe $CFLAGS $LDFLAGS
