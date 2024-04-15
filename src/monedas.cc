// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia // Curso: 2o
// Practica 11: Greedy
// Autor: Javier Garcia Santana
// Correo: alu0101391663@ull.edu.es
// Fecha: 16/12/2022
//
// Archivo cya-monedas: Programa cliente
//
// Historial de revisiones
// 20/11/2022 - Creacion (primera version) del codigo

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>


void print(std::vector<double> input) {
  std::cout << "Resultado: ";

  for(auto it = input.begin(); it != input.end();) {  
    int dups = std::count(it, input.end(), *it);
    if (dups > 1) {
      if (*it > 0.5) {
        std::cout << dups << "x" << *it << "€ ";
      }
      if (*it <= 0.5) {
        std::cout << dups << "x" << *it * 100 << "¢ ";
      }
    } else {
      if (*it > 0.5 ) {
        std::cout << *it << "€ ";
      }
      if (*it <= 0.5 ) {
        std::cout << *it * 100 << "¢ ";
      }
    }
    for(auto last = *it; *++it == last;);
  }
  std::cout << std::endl << "Total monedas: " << input.size() << std::endl;
}

std::vector<double> returnChange(const double quantity, bool bills) {
  std::vector<double> result;//S
  int indicator = 0;
  int coin_type = 1;
  double sum = 0;//sum
  if (bills) {
    std::vector<double> array_of_coins = {500,200,100,50,20,10,5,2,1,0.5,0.2,0.1,0.05,0.02,0.01};//M

    while (sum != quantity) {
      if (indicator < array_of_coins.size()) {
        if (array_of_coins[indicator] + sum <= quantity) {
          result.push_back(array_of_coins[indicator]);
          sum += array_of_coins[indicator];
          //std::cout << sum << " " << quantity << std::endl;
        } else {
          ++indicator;
        }
      } else {
        break;
      }
    }

  } else {
    std::vector<double> array_of_coins = {2,1,0.5,0.2,0.1,0.05,0.02,0.01};//M
    while (sum != quantity) {
      if (indicator < array_of_coins.size()) {
        if (array_of_coins[indicator] + sum <= quantity) {
          result.push_back(array_of_coins[indicator]);
          sum += array_of_coins[indicator];
        } else {
          ++indicator;
        }
      } else {
        break;
      }
    }
 
    for (int i = 1; i < result.size(); ++i) {
      if (result[i] != result[i - 1]) {
        ++coin_type;
      }
    }
    std::cout << "Tipos de monedas: " << coin_type << std::endl;
  }
  return result;
}

std::vector<double> optimizedReturnChange(const double quantity, bool bills) {
  std::vector<double> result; //S
  int coin_type = 1;
  std::vector<double> array_of_coins;//M
  if (bills) {
    array_of_coins = {500,200,100,50,20,10,5,2,1,0.5,0.2,0.1,0.05,0.02,0.01};
  } else {
    array_of_coins = {2,1,0.5,0.2,0.1,0.05,0.02,0.01};
  }
  double sum = 0;//sum
  int integer_division;//c
  for (int v = 0; v < array_of_coins.size(); ++v) {
    integer_division = (quantity - sum) / array_of_coins[v];
    if (integer_division > 0) {
      for (int i = 0; i < integer_division; ++i) {
        result.push_back(array_of_coins[v]);
      }  
      sum += integer_division * array_of_coins[v];
    }
  }
  if (!bills) {
    for (int i = 1; i < result.size(); ++i) {
      if (result[i] != result[i - 1]) {
        ++coin_type;
      }
    }
    std::cout << "Tipos de monedas: " << coin_type << std::endl;
  }
  return result;
}


int main(int argc, char* argv[]) {

  if (argc == 2) {
    std::string intermediate = argv[1];
    const double numeric_input = stod(intermediate);
    print(returnChange(numeric_input, false));
    
  } else if (argc == 3 && std::string(argv[1]) == "-b") {
    std::string intermediate = argv[2];
    const double numeric_input = stod(intermediate);
    print(returnChange(numeric_input, true));
    
  } else if (argc == 3 && std::string(argv[1]) == "-o") {
    std::string intermediate = argv[2];
    const double numeric_input = stod(intermediate);
    print(optimizedReturnChange(numeric_input, false));

  } else if (argc == 4) {
    std::string intermediate = argv[3];
    const double numeric_input = stod(intermediate);
    print(optimizedReturnChange(numeric_input, true));

  } else {
    std::cerr << "Numero incorrecto de parametros u opcion seleccionada no valida" << std::endl;
    exit(EXIT_SUCCESS);
  }
  return 0;
}