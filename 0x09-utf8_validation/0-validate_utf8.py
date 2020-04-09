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
    for n in data:
        if n > 128:
            return False

    return True


def validUTF8_bytes(data, n):
    """ method that will validate a set of bytes as utf-8"""
