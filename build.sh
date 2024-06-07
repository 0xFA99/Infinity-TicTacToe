#!/bin/bash

CC=cc
CFLAGS="-Wall -Wextra -pedantic"
LDFLAGS="-lraylib"

$CC main.c -o InfinityTicTacToe $CFLAGS $LDFLAGS
