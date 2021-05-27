#!/usr/bin/python3
"""
Given an n x n 2D matrix, rotate it 90 degrees clockwise
"""


def rotate_2d_matrix(matrix):
    matrix.reverse()
    for i in range(len(matrix)):
        for j in range(i):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    return matrix
