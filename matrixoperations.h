#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createMatrix(string name) {
    int row, col;
    cout << "Enter row size for " + name + ": ";
    cin >> row;
    cout << "Enter column size for " + name + ": ";
    cin >> col;

    vector<vector<int>> res(row, vector<int>(col));
    cout << "Input the elements of " << name << " (" << row << "x" << col << "):" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
            cin >> res[i][j];
		}
	}

    return res;
}

vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B) {
    int row = A.size(), col = A[0].size();
    vector<vector<int>> res(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = A[i][j] + B[i][j];
        }
    }
    return res;
}

vector<vector<int>> subtract(vector<vector<int>> A, vector<vector<int>> B) {
    int row = A.size(), col = A[0].size();
    vector<vector<int>> res(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = A[i][j] - B[i][j];
        }
    }
    return res;
}

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B) {
    int row = A.size(), col = B[0].size();
    vector<vector<int>> res(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = 0;  
            for (int k = 0; k < col; k++) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return res;
}

void displayMatrix(vector<vector<int>> mx) {	
	for (int i = 0; i < mx.size(); i++) {
		for (int j = 0; j < mx[0].size(); j++) {
            cout << mx[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}