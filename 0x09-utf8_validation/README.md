# 0x09. UTF-8 Validation

**Table Of Context**
- [0. UTF-8 Validation](#0-UTF-8-Validation)

## Tasks


### 0. UTF-8 Validation
File: **[0-validate_utf8.py](0-validate_utf8.py)**


```
martin@ubuntu:~/0x09-utf8_validation$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

data = [65]
print(validUTF8(data))

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))

data = [229, 65, 127, 256]
print(validUTF8(data))

martin@ubuntu:~/0x09-utf8_validation$

```

```
martin@ubuntu:~/0x09-utf8_validation$ ./0-main.py
True
True
False
martin@ubuntu:~/0x09-utf8_validation$

```



*[top](#0x09-UTF-8-Validation)*

---

