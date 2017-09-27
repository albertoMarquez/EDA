#include <iostream>

using namespace std;

//Precondicion: 0<=n<=long(v) and Paratodo i : 0<=i<n : v[i] >= 0
//Postcondicion: #k : 0<=k<n : Paratodo j : k < j < n : a[k] > numero(v,j)
//numero(v,k) = max(Paratodo l : k<l<n : v[l])  

void calculaMesetas(int v[], int n, int &inicio, int &fin) {
	inicio = 0;
	fin = 0;
	int inicioAux = v[0];
	int pos = 0;
	int cont = 1, contMax = cont;

	for (int i = 1; i < n; i++) {
		if (inicioAux == v[i]) {
			cont++;
			if (cont > contMax) {
				contMax = cont;
				fin = i;
				inicio = pos;
			}
		}
		else {
			inicioAux = v[i];
			pos = i;
			cont = 1;
		}
	}
}

bool resuelve() {
	int n;
	int v[100000];
	cin >> n;
	if (n == 0)
		return false;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int inicio;
	int fin;
	calculaMesetas(v, n, inicio, fin);

	cout << inicio << " " << fin << endl;

	return true;
}

int main() {

	while (resuelve()) {
		;
	}

	return 0;
}