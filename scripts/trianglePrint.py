#!/usr/bin/env python3

# get the number of the base of the triangle and print it with stars
import sys

n = int(sys.argv[1])

for i in range(1, n + 1):
    line = ""
    for j in range(i):
        line += "*"
    print(line)

