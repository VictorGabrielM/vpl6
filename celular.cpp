#include "celular.hpp"

int Celular::id = 1;
// TODO: Inicialize aqui sua variavel estatica. Caso tenha optado por essa
// solucao.

Celular::Celular(std::string modelo,
                 std::string fabricante,
                 int armazenamento,
                 int memoria,
                 double peso,
                 std::string cor,
                 int qtd,
                 float valor) {
                
    this->modelo = modelo;
    this->fabricante = fabricante;
    this->armazenamento = armazenamento;
    this->memoria = memoria;
    this->peso = peso;
    this->cor = cor;
    this->qtd = qtd;
    this->valor = valor;
    this->cod = id;
    id++;              
  // TODO: Implemente este metodo
}

bool Celular::operator<(const Celular& other) {
  if(this->fabricante == other.fabricante)
    return this->modelo < other.modelo;
  return this->fabricante < other.fabricante;  
  // TODO: Implemente este metodo. 
  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular
  
  return false;
}