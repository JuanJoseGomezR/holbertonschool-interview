#!/usr/bin/python3
<<<<<<< HEAD

"""
Main in file for testing
=======
"""
Main file for testing
>>>>>>> 144bb0ca1dffeaf131d3314832e843fe45bbde66
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

<<<<<<< HEAD
	data = [65]
print(validUTF8(data))

	data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))

	data = [229, 65, 127, 256]
print(validUTF8(data))
=======
data = [65]
print(validUTF8(data))

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))

data = [229, 65, 127, 256]
print(validUTF8(data))
>>>>>>> 144bb0ca1dffeaf131d3314832e843fe45bbde66
