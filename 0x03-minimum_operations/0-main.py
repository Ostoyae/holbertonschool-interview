#!/usr/bin/python3
"""
Main file for testing
"""

_minOperations = __import__('0-minoperations')._minOperations

for n in range(0, 122):
        print("Min number of operations to reach {} characters: {}".format(n, _minOperations(n)))


