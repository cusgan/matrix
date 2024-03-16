#include <iostream>
#include <vector>
#include <cmath>
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

//integer
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

//double
vector<vector<double>> multiply(vector<vector<double>> A, vector<vector<double>> B) {
    int row = A.size(), col = B[0].size();
    vector<vector<double>> res(row, vector<double>(col));
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

int determinantSquare(vector<vector<int>> mx) {
    int sz = mx.size();
    if (sz == 2) {
        return mx[0][0] * mx[1][1] - mx[0][1] * mx[1][0];
    }
    
    int det = 0;
    for (int i = 0; i < sz; i++) {
        vector<vector<int>> inner(sz-1, vector<int>(0));
        for (int j = 1; j < sz; j++) { //rows
            int k = 0;
            while (inner[j-1].size() < sz-1) { //columns
                if (k == i) {
                    k++;
                    continue;
                }
                inner[j-1].push_back(mx[j][k]);
                k++;
            }
        }
        det += mx[0][i] * pow(-1, i) * determinantSquare(inner);
    }

    return det;
}