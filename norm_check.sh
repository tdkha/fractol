#!/bin/bash

NORM="norminette"

echo "+------------------------------------------+"
echo "|   Checking norminette for header files   |"
echo "+------------------------------------------+"
echo ""
$NORM ./includes/*.h

echo ""
echo "+------------------------------------------+"
echo "|   Checking norminette for source files   |"
echo "+------------------------------------------+"
echo ""
$NORM ./srcs/*.c
