#include <iostream>
#include <climits> // Para INT_MAX
using namespace std;

int contarBits(int n) {
    return __builtin_popcount(n); // Cuenta los bits en 1
}

int numeroMinBits(int L, int R) {
    int minBits = INT_MAX, resultado = INT_MAX;

    for (int i = L; i <= R; i++) {
        int bits = contarBits(i);
        
        if (bits < minBits || (bits == minBits && i < resultado)) {
            minBits = bits;
            resultado = i;
        }
    }
    
    return resultado;
}
// 123456789 124217728 7000000000000000 70000000000000000


int main() {
    int L = 7000000000000000, R = 70000000000000000;
    cout << "Número con menos bits en [" << L << ", " << R << "]: " << numeroMinBits(L, R) << endl;
    return 0;
}