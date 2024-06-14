#!/bin/bash

cd ../srcs/libft/
make
cd ../../

cd test/

cc test_atold.c ../srcs/libft/libft.a

./a.out

rm -rf a.out