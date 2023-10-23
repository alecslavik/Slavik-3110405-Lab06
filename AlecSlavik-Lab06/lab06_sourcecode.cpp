#include <iostream>
#include <fstream>

//using the using operation we can skip typing std:: everytime we want to change the input or output (or end a line)
using std::cout;
using std::cin;
using std::endl;

//The max size of our matrix, 100 is defined
const int max_size = 100;

//Our read matrix function, where it uses the numbers from our file to fill in the matrix
void readMatrix(int matrix[max_size][max_size], int &size, std::ifstream &infile){
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			infile >> matrix[i][j];
		}
	}
}

//The print matrix function, used for every operation and is the visual for the user
void printMatrix(int matrix[max_size][max_size], int size, std::string matrixName){
	cout << matrixName << ":" << endl;
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			cout << matrix[i][j] << ' ';
		}
		cout << endl;//some extra endl where I needed whitespace in the output
	}
	cout << endl;
}

//Add matrices, taking the values from each cell, adding them, and inserting them to the corresponding spot in the result matrix
void addMatrices(int matrixA[max_size][max_size], int matrixB[max_size][max_size], int result[max_size][max_size], int size){
		for (int i = 0; i < size; ++i){
			for (int j = 0; j < size; ++j){
				result[i][j] = matrixA[i][j] + matrixB[i][j];
			}
		}
}

//subtracting the values from each cell, and inserting them to the corresponding spot in the result matrix
void subtractMatrices(int matrixA[max_size][max_size], int matrixB[max_size][max_size], int result[max_size][max_size], int size){
		for (int i = 0; i < size; ++i){
			for (int j = 0; j < size; ++j){
				result[i][j] = matrixA[i][j] - matrixB[i][j];
			}
		}
}

//Finally, our matrix multiplication which uses a new letter to denote a cell, k in order to get the product of the two numbers and add them to the results
void multiplyMatrices(int matrixA[max_size][max_size], int matrixB[max_size][max_size], int result[max_size][max_size], int size){
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            result[i][j] = 0;
            for (int k = 0; k < size; ++k){
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

//Our main function where we declare our variables, get the input file and data from it, and call all of our functions
int main(){
	int size;
	int matrixA[max_size][max_size];
	int matrixB[max_size][max_size];
	int result[max_size][max_size];

	std::ifstream infile("matrix_input.txt");
	
	//Just in case the file is unable to be read
	if (!infile){
		cout << "Error with opening the file";
		return 1;
	}
	
	infile >> size;
	
	readMatrix(matrixA, size, infile);
	readMatrix(matrixB, size, infile);
	
	cout << "Alec Slavik" << endl;
	cout << "Lab #6: Matrix manipulation\n" << endl;
	
	printMatrix(matrixA, size, "Matrix A");
	printMatrix(matrixB, size, "Matrix B");
	
	addMatrices(matrixA, matrixB, result, size);
	printMatrix(result, size, "Matrix Sum (A + B)");
	
	multiplyMatrices(matrixA, matrixB, result, size);
	printMatrix(result, size, "Matrix Product (A * B)");
	
	subtractMatrices(matrixA, matrixB, result, size);
	printMatrix(result, size, "Matrix Difference (A - B)");
	
	return 0;
}