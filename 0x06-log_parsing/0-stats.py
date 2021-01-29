#!/usr/bin/python3
"""Script that reads stdin line by line and computes metrics"""
import sys


codes = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0,
}

def print_metrics(codes, size):
    """function to print status codes and total file size"""
    print("File size: {}".format(size))
    for k, v in sorted(codes.items()):
        if v > 0:
            print("{}: {}".format(k, v))

count = 1
size = 0
try:
    for line in sys.stdin:
        splited_line = line.strip().split()
        if len(splited_line) < 7:
            continue
        size += int(splited_line[-1])
        status_code = splited_line[-2]
        if status_code in codes:
            codes[status_code] += 1
        if count == 10:
            print_metrics(codes, size)
            count = 1
        else:
            count += 1
    print_metrics(codes, size)
except KeyboardInterrupt:
    print_metrics(codes, size)
    raise