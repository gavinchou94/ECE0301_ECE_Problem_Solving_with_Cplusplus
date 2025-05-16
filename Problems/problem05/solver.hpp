#ifndef _SOLVER_HPP
#define _SOLVER_HPP

#include <cstdlib>

#include "constants.hpp"


void matrix_vector_product(const double matrix[][CAP], 
                        const double vector[], 
                        double result[], const int dim) {
    // loop over rows of matrix
    for (int i=0; i<dim; i++) {
        // initialize product element for this row
        result[i] = 0;
        // loop over columns of matrix
        for (int j=0; j<dim; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}


void submatrix(const double matrix[][CAP], 
            int row, int col,
            double result[][CAP], const int dim) {

}


double determinant(const double matrix[][CAP], const int dim) {
    
    return 0;
}


void replace_column(const double matrix[][CAP],
                    int col, const double vector[],
                    double result[][CAP], const int dim) {
    
    
}

void cramers_rule(const double matrix[][CAP],
                    const double vector[],
                    double result[], const int dim) {
    
}


int parse_file_input(std::string filename,
                double matrix[][CAP],
                double vector[]) {
    // BONUS
    return 0;
}

#endif