class SparseMatrix:
    def _init_(self, rows, cols):
        self.rows = rows
        self.cols = cols
        self.matrix = []

    # Function to insert a non-zero element in the sparse matrix
    def insert(self, row, col, value):
        if value != 0:
            self.matrix.append((row, col, value))

    # Function to display the sparse matrix
    def display(self):
        if not self.matrix:
            print("The matrix is empty (no non-zero elements).")
            return
        print("Row\tColumn\tValue")
        for element in self.matrix:
            print(f"{element[0]}\t{element[1]}\t{element[2]}")

    # Function to find the transpose of the matrix
    def transpose(self):
        result = SparseMatrix(self.cols, self.rows)
        for (row, col, value) in self.matrix:
            result.insert(col, row, value)
        return result

    # Function to find the fast transpose of the matrix
    def fast_transpose(self):
        result = SparseMatrix(self.cols, self.rows)
        row_size = [0] * self.cols
        start_pos = [0] * self.cols

        # Counting the number of non-zero elements in each column
        for (row, col, value) in self.matrix:
            row_size[col] += 1

        # Computing the start position of each column in the transposed matrix
        start_pos[0] = 0
        for i in range(1, self.cols):
            start_pos[i] = start_pos[i - 1] + row_size[i - 1]

        # Filling the transposed matrix
        for (row, col, value) in self.matrix:
            result.insert(start_pos[col], col, value)
            start_pos[col] += 1
        return result

    # Function to add two sparse matrices
    def add(self, other):
        if self.rows != other.rows or self.cols != other.cols:
            raise ValueError("Matrix dimensions must be the same for addition.")
        
        result = SparseMatrix(self.rows, self.cols)
        i, j = 0, 0

        # Traverse both matrices and add corresponding elements
        while i < len(self.matrix) and j < len(other.matrix):
            if self.matrix[i][0] == other.matrix[j][0]:
                if self.matrix[i][1] == other.matrix[j][1]:
                    # Same position, add the values
                    result.insert(self.matrix[i][0], self.matrix[i][1], self.matrix[i][2] + other.matrix[j][2])
                    i += 1
                    j += 1
                elif self.matrix[i][1] < other.matrix[j][1]:
                    result.insert(self.matrix[i][0], self.matrix[i][1], self.matrix[i][2])
                    i += 1
                else:
                    result.insert(other.matrix[j][0], other.matrix[j][1], other.matrix[j][2])
                    j += 1
            elif self.matrix[i][0] < other.matrix[j][0]:
                result.insert(self.matrix[i][0], self.matrix[i][1], self.matrix[i][2])
                i += 1
            else:
                result.insert(other.matrix[j][0], other.matrix[j][1], other.matrix[j][2])
                j += 1

        # Insert remaining elements
        while i < len(self.matrix):
            result.insert(self.matrix[i][0], self.matrix[i][1], self.matrix[i][2])
            i += 1
        while j < len(other.matrix):
            result.insert(other.matrix[j][0], other.matrix[j][1], other.matrix[j][2])
            j += 1

        return result


# Main program
if __name__ == "_main_":
    # Creating two sparse matrices
    matrix1 = SparseMatrix(4, 4)
    matrix1.insert(0, 0, 5)
    matrix1.insert(1, 2, 8)
    matrix1.insert(2, 1, 3)
    matrix1.insert(3, 3, 9)

    matrix2 = SparseMatrix(4, 4)
    matrix2.insert(0, 0, 1)
    matrix2.insert(1, 2, 4)
    matrix2.insert(2, 1, 2)
    matrix2.insert(3, 3, 3)

    print("Matrix 1:")
    matrix1.display()
    print("\nMatrix 2:")
    matrix2.display()

    # Transpose operation
    transpose_matrix1 = matrix1.transpose()
    print("\nTranspose of Matrix 1:")
    transpose_matrix1.display()

    # Fast Transpose operation
    fast_transpose_matrix1 = matrix1.fast_transpose()
    print("\nFast Transpose of Matrix 1:")
    fast_transpose_matrix1.display()

    # Addition of two sparse matrices
    print("\nAddition of Matrix 1 and Matrix 2:")
    added_matrix = matrix1.add(matrix2)
    added_matrix.display()