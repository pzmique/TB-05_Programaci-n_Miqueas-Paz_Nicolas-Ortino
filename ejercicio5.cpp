#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

const int F = 4; 
const int C = 4; 

void M(int matriz[F][C]) {
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    srand(time(0));
    int matriz[F][C];

    // Inicializar la matriz con números enteros aleatorios
    for (int i = 0; i < F; ++i) {
        for (int j = 0; j < C; ++j) {
            matriz[i][j] = rand() % 100 + 1; // Números entre 1 y 100
        }
    }

    cout << "Matriz inicial:" << endl;
    M(matriz);

    // Calcular promedio general
    int sumaTotal = 0;
    for (int i = 0; i < F; ++i) {
        for (int j = 0; j < C; ++j) {
            sumaTotal += matriz[i][j];
        }
    }
    double promedio = static_cast<double>(sumaTotal) / (F * C);
    cout << "Promedio general: " << promedio << endl;

    // Suma de pares de cada columna
    vector<int> sumaParesCol(C, 0);
    for (int j = 0; j < C; ++j) {
        for (int i = 0; i < F; ++i) {
            if (matriz[i][j] % 2 == 0) {
                sumaParesCol[j] += matriz[i][j];
            }
        }
        cout << "Suma de pares de la columna " << j + 1 << ": " << sumaParesCol[j] << endl;
    }

    // Suma de impares de cada fila
    vector<int> sumaImparesFila(F, 0);
    for (int i = 0; i < F; ++i) {
        for (int j = 0; j < C; ++j) {
            if (matriz[i][j] % 2 != 0) {
                sumaImparesFila[i] += matriz[i][j];
            }
        }
        cout << "Suma de impares de la fila " << i + 1 << ": " << sumaImparesFila[i] << endl;
    }

    // Posicion maximo y minimo
    int maxVal = matriz[0][0], minVal = matriz[0][0];
    pair<int, int> posMax(0, 0), posMin(0, 0);
    for (int i = 0; i < F; ++i) {
        for (int j = 0; j < C; ++j) {
            if (matriz[i][j] > maxVal) {
                maxVal = matriz[i][j];
                posMax = {i, j};
            }
            if (matriz[i][j] < minVal) {
                minVal = matriz[i][j];
                posMin = {i, j};
            }
        }
    }
    cout << "Posicion del maximo valor (" << maxVal << "): [" << posMax.first << "][" << posMax.second << "]" << endl;
    cout << "Posicion del minimo valor (" << minVal << "): [" << posMin.first << "][" << posMin.second << "]" << endl;

    // Ordenar de forma ascendente la fila 2
    sort(matriz[1], matriz[1] + C);
    cout << "Fila 2 ordenada de forma ascendente:" << endl;
    M(matriz);

    // Ordenar en forma descendente la columna 3
    vector<int> col3(F);
    for (int i = 0; i < F; ++i) {
        col3[i] = matriz[i][2];
    }
    sort(col3.begin(), col3.end(), greater<int>());
    for (int i = 0; i < F; ++i) {
        matriz[i][2] = col3[i];
    }
    cout << "Columna 3 ordenada de forma descendente:" << endl;
    M(matriz);

    // Intercambiar la columna 2 y la columna 4
    for (int i = 0; i < F; ++i) {
        swap(matriz[i][1], matriz[i][3]);
    }
    cout << "Matriz despues de intercambiar las columnas 2 y 4:" << endl;
    M(matriz);

    return 0;
}

