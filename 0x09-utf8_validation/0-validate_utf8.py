#!/bin/usr/python3
""" Module for validating utf-8
"""

import sys


def validUTF8(data):
    """ Method for validating utf-8
    @param data: data to test
    @return: True if utf-8 else false
    """
    i = 0
    while i < len(data):
        if data[i] >> 7 & 0:
            i += 1
            continue

    return True


def validUTF8_bytes(data, n):
    """ method that will validate a set of bytes as utf-8"""
