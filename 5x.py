# Function to add two matrices
def add_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)
    return result

# Function to subtract two matrices
def subtract_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] - matrix2[i][j])
        result.append(row)
    return result

# Function to multiply two matrices
def multiply_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix2[0])):
            sum = 0
            for k in range(len(matrix2)):
                sum += matrix1[i][k] * matrix2[k][j]
            row.append(sum)
        result.append(row)
    return result

# Function to transpose a matrix
def transpose_matrix(matrix):
    result = []
    for j in range(len(matrix[0])):
        row = []
        for i in range(len(matrix)):
            row.append(matrix[i][j])
        result.append(row)
    return result

# Example matrices
matrix1 = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

matrix2 = [
    [9, 8, 7],
    [6, 5, 4],
    [3, 2, 1]
]

# Perform operations and print results
print("Matrix 1:")
for row in matrix1:
    print(row)

print("\nMatrix 2:")
for row in matrix2:
    print(row)

# Addition
print("\nAddition of matrices:")
result_add = add_matrices(matrix1, matrix2)
for row in result_add:
    print(row)

# Subtraction
print("\nSubtraction of matrices:")
result_sub = subtract_matrices(matrix1, matrix2)
for row in result_sub:
    print(row)

# Multiplication
print("\nMultiplication of matrices:")
result_mult = multiply_matrices(matrix1, matrix2)
for row in result_mult:
    print(row)

# Transpose of Matrix 1
print("\nTranspose of Matrix 1:")
result_transpose = transpose_matrix(matrix1)
for row in result_transpose:
    print(row)
