#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

const int max_size = 100;

void readMatrix(int matrix[max_size][max_size], int &size, std::ifstream &infile){
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			infile >> matrix[i][j];
		}
	}
}
	
void printMatrix(int matrix[max_size][max_size], int size, std::string matrixName){
	cout << matrixName << ":" << endl;
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void addMatrices(int matrixA[max_size][max_size], int matrixB[max_size][max_size], int result[max_size][max_size], int size){
		for (int i = 0; i < size; ++i){
			for (int j = 0; j < size; ++j){
				result[i][j] = matrixA[i][j] + matrixB[i][j];
			}
		}
}

void subtractMatrices(int matrixA[max_size][max_size], int matrixB[max_size][max_size], int result[max_size][max_size], int size){
		for (int i = 0; i < size; ++i){
			for (int j = 0; j < size; ++j){
				result[i][j] = matrixA[i][j] - matrixB[i][j];
			}
		}
}

int main(){
	int size;
	int matrixA[max_size][max_size];
	int matrixB[max_size][max_size];
	int result[max_size][max_size];

	std::ifstream infile("matrix_input.txt");
	
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
	
	subtractMatrices(matrixA, matrixB, result, size);
	printMatrix(result, size, "Matrix Difference (A - B)");
	
	return 0;
}