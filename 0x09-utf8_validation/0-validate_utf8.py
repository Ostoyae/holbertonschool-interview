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
        try:
            if data[i] & (1<<7) == 0:
                i+=1
                continue
            if data[i] & (1 << 6) == 0:
                if (not validUTF8_bytes(data[i:i+1])):
                    return False
                i += 1
            elif data[i] & (1 << 5) == 0:
                if (not validUTF8_bytes(data[i:i+2])):
                    return False
                i += 2
            elif data[i] & (1 << 4) == 0:
                if (not validUTF8_bytes(data[i:i+3])):
                    return False
                i += 3
            else:
                return False
        except IndexError:
            return False
        
        i+=1

    return True


def validUTF8_bytes(data):
    """ method that will validate a set of bytes as utf-8"""
    for b in data[1:]:
        if b & (1 << 7) != 1:
            return False
    

    return True

if __name__ == "__main__":
    pass
