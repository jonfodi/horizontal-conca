// horizontal concatenation of 2 matricies
// create 2 1-d matricies by looping through rows of 2 2-matricies (for vertical conca, use COLUMNS)
// fill the 2-d concatenated matrix by inputting the beginnning of the 2nd 1-d matrix to the end of the 1st 1-d



#include<iostream>
#include<array>
#include"pch.h"
#include<iomanip>

using namespace std; 

const size_t row{ 4 }, col{ 3 };

void conca(array<int, col>&, array<int, col>&, array<int, col + col>&);

void print(array<array<int, col>, row>&);

void printC(array<array<int, col + col>, row>&);

int main() {

	array<array<int, col>, row> M1{ 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23 };
	array<array<int, col>, row> M2{ 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 };
	array<array<int, col + col>, row> Mc{};

	//display matricies pre-concatenation

	print(M1);

	cout << endl << endl;

	print(M2);

	cout << endl << endl;
	
	// create 3 new 1-d array with size of columns
	array<int, col>r1; 
	array<int, col>r2;
	array<int, col + col>rc{}; // double column size for concatenated matrix

	//loop through each row of M1 and M2 
	// concatenate them with conca function
    
	for (int r = 0; r < row; r++) { 

		for (int i = 0; i < col; i++)
			r1[i] = M1[r][i]; // fill r1 with the rows of m1

		for (int i = 0; i < col; i++) // fill r2 with the rows of m2
			r2[i] = M2[r][i];

		conca(r1, r2, rc); // concatenate r1 and r2
		
		for (int j = 0; j < row + row; j++)
			Mc[r][j] = rc[j]; // fill concatenated matrix with concatenated row
	}

	printC(Mc);
	
}

void print(array<array<int, col>, row>& a) { //print 2-d matrix

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
    
}
void printC(array<array<int, col + col>, row>& a) { //print 2-d concatenated matrix
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col + col; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
    
}

void conca(array<int, col>& r1, array<int, col>& r2, array<int, col + col>& rc) {

	for (int i = 0; i < col; i++)
		rc[i] = r1[i]; // add row values into 2-d conca matrix

	for (int i = col; i < col + col; i++)
		rc[i] = r2[i - col]; // add row values starting from the last input of the first loop
	
	// process repeats for each row of M1 and M2 to concatenate them
	// see the outer for loop controlled by size 'row'
}
