#include <iostream>

using namespace std;

// poner aqui los ejemplos como funciones con el siguiente formato,
// donde 'X' es el numero de ejemplo
int ejemploX(const int n)
{ 
  int suma = 0;  // Θ(1)
  for (int i = 1; i <= n; i++)  // Θ(n)
    for (int j = 1; j <= n; j++)
      for (int z = 1; z <= j; z++)   // Θ(i)
      suma++;  // Θ(1)

  return suma;
}

int main()
{ // pedir el valor de n
  int n;
  cout << "Introducir n: ";
  cin >> n;

  // invocar a cada ejemplo
  cout << "Ejemplo X: " << ejemploX(n) << endl;
  return 0;
}