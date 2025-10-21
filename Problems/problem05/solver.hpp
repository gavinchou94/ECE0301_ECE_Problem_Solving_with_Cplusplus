#ifndef _SOLVER_HPP
#define _SOLVER_HPP

#include <cstdlib>

#include "constants.hpp"

void matrix_vector_product(const double matrix[][CAP],
                           const double vector[],
                           double result[], const int dim)
{
    // loop over rows of matrix
    for (int i = 0; i < dim; i++)
    {
        // initialize product element for this row
        result[i] = 0;
        // loop over columns of matrix
        for (int j = 0; j < dim; j++)
        {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

void submatrix(const double matrix[][CAP],
               int row, int col,
               double result[][CAP], const int dim)
{
    // TODO
    int subrow = 0;
    for (int i = 0; i < dim; i++)
    {
        if (i != row)
        {
            int subcol = 0;
            for (int j = 0; j < dim; j++)
            {
                if (j != col)
                {
                    result[subrow][subcol] = matrix[i][j];
                    subcol++;
                }
            }
            subrow++;
        }
    }
}
// I've used // I used https://matrix.reshish.com/ to find det
double determinant(const double matrix[][CAP], const int dim)
{
    // TODO
    if (dim == 0)
    { // Check invalid matrix
        return 0;
    }
    if (dim == 1)
    { // 1x1 matrix
        return matrix[0][0];
    }
    double det = 0;
    double sub[dim][CAP]; // Temp submatrix
    int sign = 1;         // Sign alternator

    for (int j = 0; j < dim; j++)
    {
        submatrix(matrix, 0, j, sub, dim);
        double subdet = determinant(sub, dim - 1);
        det += sign * matrix[0][j] * subdet;
        sign = -sign; // Flip sign for the next integer
    }
    return det;
}

void replace_column(const double matrix[][CAP],
                    int col, const double vector[],
                    double result[][CAP], const int dim)
{
    // TODO
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (j == col)
            {
                result[i][j] = vector[i];
            }
            else
            {
                result[i][j] = matrix[i][j];
            }
        }
    }
}
void cramers_rule(const double matrix[][CAP],
                  const double vector[],
                  double result[], const int dim)
{
    // TODO
    double det = determinant(matrix, dim);
    if (det == 0)
    { // Crammer's rule cannot be applied
        return;
    }
    double modmat[dim][CAP]; // Modified matrix
    for (int j = 0; j < dim; j++)
    {
        replace_column(matrix, j, vector, modmat, dim);
        result[j] = determinant(modmat, dim) / det;
    }
}

int parse_file_input(std::string filename,
                     double matrix[][CAP],
                     double vector[])
{
    // BONUS TODO
    return 0;
}

#endif