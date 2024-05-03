1.  **Vector of Vectors (2D array-like structure)**:

    ````cpp
    #include <iostream>
    #include <vector>

    int main() {
    // Creating a 3x3 matrix using vector of vectors
    std::vector<std::vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    };

        // Accessing elements of the matrix
        std::cout << "Element at row 1, column 2: " << matrix[1][2] << std::endl; // Output: 6

        return 0;

    }```

    ````

2.  **Nested Vectors (Arbitrary hierarchical structure)**:

    ````cpp
    #include <iostream>
    #include <vector>

    int main() {
    // Creating nested vectors
    std::vector<std::vector<int>> nestedVectors = {
    {1, 2, 3},
    {4, 5},
    {6, 7, 8, 9}
    };

        // Accessing elements of the nested vectors
        std::cout << "Element at row 2, index 1: " << nestedVectors[2][1] << std::endl; // Output: 7

        return 0;

    }```
    ````

In the first example, `matrix` represents a 3x3 matrix where each element is a row vector. In the second example, `nestedVectors` represents a collection of vectors, where each vector can have a different size, and the structure is not necessarily a regular grid.
