/*
 * 15.	Построить логический вектор, каждый элемент равен истине, если в соответствующей строке числа строго убывают
 */

#include <iostream>
#include<iomanip>

void readDimensions(int *rows, int *cols)
{
    do
    {
        std::cout << "Enter rows number (positive number): ";
        std::cin >> *rows;
    } while (*rows < 1);
    do
    {
        std::cout << "Enter columns number (positive number > 1): ";
        std::cin >> *cols;
    } while (*cols < 2);
}

int ** allocateMatrix(int rows, int cols)
{
    int **matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void deleteMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete matrix[i];
    }
    delete matrix;
}

void fillMatrix(int **matrix, int rows, int cols)
{
    std::cout << "Enter matrix elements:" << std::endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void printMatrix(int **matrix, int rows, int cols)
{
    std::cout << std::endl << "Matrix:" << std::endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << std::left << std::setw(2) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool * findResultVector(int **matrix, int rows, int cols)
{
    bool * result = new bool[rows];
    for (int i = 0; i < rows; i++)
    {
        bool isDescending = true;
        for (int j = 0; j < cols - 1; j++)
        {
            if (matrix[i][j] <= matrix[i][j + 1])
            {
                isDescending = false;
                break;
            }
        }
        result[i] = isDescending;
    }
    return result;
}

void printVector(bool *vector, int rows)
{
    std::cout << std::endl << "Result vector:" << std::endl;
    std::cout << std::boolalpha;
    for (int i = 0; i < rows; i++)
    {
        std::cout << vector[i] << std::endl;
    }
}

int main() {
    int rows, cols;
    readDimensions(&rows, &cols);
    int **matrix = allocateMatrix(rows, cols);
    fillMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);
    bool *result = findResultVector(matrix, rows, cols);
    deleteMatrix(matrix, rows);
    printVector(result, rows);
    delete result;
    return 0;
}
