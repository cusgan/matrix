#include <iostream>
#include <vector>
#include "matrixoperations.h"
using namespace std;

int main() {
	vector<vector<int>> A, B, res;

    string name1, name2;
    char ans;
    cout << "--- MATRIX OPERATIONS ---" << endl;

    // do {
    //     cout << "Would you like to give your matrices custom names? [1-Yes/0-No]: ";
    //     cin >> ans;
    //     cin.ignore();
    // } while (!isdigit(ans));

    if (ans == '1') {
        cout << "Name of first matrix: ";
        cin.ignore();
        getline(cin, name1);
        cout << "Name of second matrix: ";
        cin.ignore(-1);
        getline(cin, name2);
    } else {
        name1 = "Matrix A";
        name2 = "Matrix B";
    }

    A = createMatrix(name1);
    B = createMatrix(name2);
	
	cout << endl << name1 << endl;
	displayMatrix(A);
	cout << name2 << endl;
	displayMatrix(B);
	
    if (A.size() == B.size() && A[0].size() == B[0].size()) {
        cout << name1 << " + " << name2 << " (Addition)" << endl;
        res = add(A, B);
        displayMatrix(res);
        cout << name1 << " - " << name2 << " (Subtraction)" << endl;
        res = subtract(A, B);
        displayMatrix(res);	
    } else {
        cout << "Addition and Subtraction cannot be performed." << endl << endl;
    }
	cout << name1 << " * " << name2 << " (Multiplication)" << endl;
	res = multiply(A, B);
	displayMatrix(res);

    //add functionalities: user menu for operations, exception handling

    return 0;
}