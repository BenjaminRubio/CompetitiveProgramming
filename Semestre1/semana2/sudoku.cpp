#include <bits/stdc++.h>
using namespace std;

// matriz que guarda valores del sudoku, sólo se ocupa la
// segunda posición de la tercera componente en caso de
// celda doble
int sudoku[6][6][2] {0};

// bitmasks con valores usados por fila, columna y región
int rowMasks[6] {0};
int colMasks[6] {0};
int regMasks[3][2] {0};

// posiciones de sudoku a rellenar
vector<vector<int>> toComplete;

// función para imprimir solución final
void printSudoku() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (sudoku[i][j][1]) {
                cout << sudoku[i][j][0] << '/' << sudoku[i][j][1] << ' ';
            } else {
                cout << sudoku[i][j][0] << ' ';
            }
        }
        cout << '\n';
    }
}

// funcion de solucion por backtracking
// va rellenando el sudoku segun las coordenadas en toComplete
// según el parámetro index
bool solveSudoku(int index) {

    // termina si se rellenaron todos los valores de toComplete
    if (index == toComplete.size()) {
        return true;
    }

    // obtenemos coordenadas
    int row = toComplete[index][0];
    int col = toComplete[index][1];
    int lev = toComplete[index][2];

    // se itera segun los números del 1 al 9
    for (int i = 1, b = 1; i < 10; i++, b <<= 1) {

        // sólo se acepta si no esta en ninguna de las bitmasks de la coordenada
        if (!(b & rowMasks[row]) && !(b & colMasks[col]) && !(b & regMasks[row/2][col/3])) {

            // casos especiales celdas dobles se verifica el de arriba menor
            if (lev && (sudoku[row][col][0] >= i)) {
                continue;
            }
            if (!lev && sudoku[row][col][1]) {
                if (sudoku[row][col][1] <= i) {
                    continue;
                }
            }

            // hacemos los cambios de ingresar el numero
            rowMasks[row] ^= b;
            colMasks[col] ^= b;
            regMasks[row/2][col/3] ^= b;
            sudoku[row][col][lev] = i;

            // si la configuracion sirve terminamos
            if (solveSudoku(index + 1)) {
                return true;
            }

            // en otro caso deshacemos cambios y volvemos a iterar
            rowMasks[row] ^= b;
            colMasks[col] ^= b;
            regMasks[row/2][col/3] ^= b;
            sudoku[row][col][lev] = 0;
        }
    }

    // en caso de no funcionar ningun número volvemos en el backtracking
    return false;
}

int main() {
    // vector que se modificará e insertará a toComplete
    vector<int> coord = {0, 0, 0};
    for (int i = 0; i < 6; i++) {
        coord[0] = i;
        for (int j = 0; j < 6; j++) {
            coord[1] = j;
            string temp;
            cin >> temp;
            coord[2] = 0;

            // ingresamos valor de celda en caso de estar dado
            if (temp[0] != '-') {
                sudoku[i][j][0] = int(temp[0] - '0');
                rowMasks[i] |= 1 << int(temp[0] - '1');
                colMasks[j] |= 1 << int(temp[0] - '1');
                regMasks[i/2][j/3] |= 1 << int(temp[0] - '1');
            } else {
                // en caso de no estar dado ingresamos posicion para completar
                toComplete.push_back(coord);
            }

            // si la celda es doble hacemos lo mismo con la segunda posicion
            if (temp.size() == 3) {
                coord[2] = 1;
                if (temp[2] != '-') {
                    sudoku[i][j][1] = int(temp[2] - '0');
                    rowMasks[i] |= 1 << int(temp[2] - '1');
                    colMasks[j] |= 1 << int(temp[2] - '1');
                    regMasks[i/2][j/3] |= 1 << int(temp[2] - '1');
                } else {
                    toComplete.push_back(coord);
                }
            }
        }
    }

    // resolvemos
    solveSudoku(0);
    printSudoku();
}