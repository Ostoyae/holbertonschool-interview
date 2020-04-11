#!/usr/bin/python3
""" Module for validating utf-8
"""

import sys


# def _validUTF8(data):
#     """ Method for validating utf-8
#     @param data: data to test
#     @return: True if utf-8 else false
#     """
#     i = 0
#     for n in data:
#         if n > 128:
#             return False

#     return True

def validUTF8(data):
    """ Method for validating utf-8
    @param data: data to test
    @return: True if utf-8 else false
    """

    i = 0

    while i < len(data):
        if (data[i] > 255):
            return False 
        try:
            if data[i] & (1 << 7) == 0 << 7:
                i += 1
                continue
            if data[i] & (1 << 5) == 0 << 5:
                if (not validUTF8_bytes(data[i:i+2],2)):
                    return False
                i += 2
            elif data[i] & (1 << 4) == 0 << 4:

                if (not validUTF8_bytes(data[i:i+3],3)):
                    return False
                i += 3
            elif data[i] & (1 << 3) == 0 << 3:
                if (not validUTF8_bytes(data[i:i+4],4)):
                    return False
                i += 4
            else:
                return False
        except IndexError:
            return False


    return True


def validUTF8_bytes(data, n):
    """ method that will validate a set of bytes as utf-8"""
    
    if (len(data) != n):
        return False
    for b in data[1:]:
        if b & (1 << 6) != 0 << 6:
            return False

    return True


if __name__ == "__main__":
    pass
