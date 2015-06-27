#!/bin/bash

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib:/usr/local/lib ; export LD_LIBRARY_PATH

ttransform -input $1 -output $2 -func $3 -histeq $4 -color $5

