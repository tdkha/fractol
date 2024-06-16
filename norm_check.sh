#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color
NORM="norminette"

printf	"\n+------------------------------------------+\n"
printf	"|                                          |\n"
printf	"|   Checking norminette for ${GREEN}header files${NC}   |\n"
printf	"|                                          |\n"
printf	"+------------------------------------------+\n"

$NORM ./includes/*.h

printf	"\n+------------------------------------------+\n"
printf	"|                                          |\n"
printf	"|   Checking norminette for ${GREEN}source files${NC}   |\n"
printf	"|                                          |\n"
printf	"+------------------------------------------+\n"
$NORM ./srcs/*.c
