#!/bin/bash
set -xe 

clang -Wall -Wextra -o matrix_test matrix_test.c
#to complie using graph draw:
#clang -Wall -Wextra -o your_app your_app.c -lraylib -lm -lpthread -ldl -lrt 
