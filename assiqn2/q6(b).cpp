#include <iostream>
using namespace std;

// 6) Write a program to implement the following operations on a Sparse Matrix,
// assuming the matrix is represented using a triplet.
// (a) Transpose of a matrix.
// (b) Addition of two matrices.
// (c) Multiplication of two matrices

int main(){
    // (b) Addition of two matrices //
    int sp1[10][3] = {
        {3, 3, 4},   
        {0, 0, 5},
        {1, 1, 8},
        {2, 1, 3},
        {2, 2, 9}
    };

    int sp2[10][3] = {
        {3, 3, 3},
        {0, 0, 2},
        {1, 0, 7},
        {2, 2, 6}
    };

    int row_count1 = sp1[0][2] + 1; 
    int row_count2 = sp2[0][2] + 1;

    int add_sp[20][3];
    add_sp[0][0] = sp1[0][0]; 
    add_sp[0][1] = sp1[0][1]; 
    int k = 1;

    int i = 1, j = 1;
    while (i < row_count1 && j < row_count2) {
        if (sp1[i][0] == sp2[j][0] && sp1[i][1] == sp2[j][1]) {
            add_sp[k][0] = sp1[i][0];
            add_sp[k][1] = sp1[i][1];
            add_sp[k][2] = sp1[i][2] + sp2[j][2];
            i++;
            j++;
        }
        else if (sp1[i][0] < sp2[j][0] || 
                 (sp1[i][0] == sp2[j][0] && sp1[i][1] < sp2[j][1])) {
            add_sp[k][0] = sp1[i][0];
            add_sp[k][1] = sp1[i][1];
            add_sp[k][2] = sp1[i][2];
            i++;
        } 
        else {
           
            add_sp[k][0] = sp2[j][0];
            add_sp[k][1] = sp2[j][1];
            add_sp[k][2] = sp2[j][2];
            j++;
        }
        k++;
    }

    
    while (i < row_count1) {
        add_sp[k][0] = sp1[i][0];
        add_sp[k][1] = sp1[i][1];
        add_sp[k][2] = sp1[i][2];
        i++;
        k++;
    }
    while (j < row_count2) {
        add_sp[k][0] = sp2[j][0];
        add_sp[k][1] = sp2[j][1];
        add_sp[k][2] = sp2[j][2];
        j++;
        k++;
    }

    
    add_sp[0][2] = k - 1;

    
    for (int x = 0; x < k; x++) {
        for (int y = 0; y < 3; y++) {
            cout << add_sp[x][y] << " ";
        }
        cout << endl;
    }
}
