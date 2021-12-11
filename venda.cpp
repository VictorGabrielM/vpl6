#include "venda.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>

void Venda::adicionaCelular(const Celular &celular)
{
  m_celulares.push_back(celular);

  // TODO: Implemente este metodo
}

void Venda::ordena()
{

  m_celulares.sort();

  // TODO: Implemente este metodo

  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular
}

void Venda::recarregaEstoque(int cod, int qtd)
{
  std::list<Celular>::iterator it = m_celulares.begin();
  while (1)
  {
    if (it->cod == cod)
    {
      it->qtd += qtd;
      break;
    }
    else
      it++;
  }

  // TODO: Implemente este metodo
}

void Venda::efetuaVenda(int cod, int qtd)
{
  std::list<Celular>::iterator it = m_celulares.begin();
  while (1)
  {
    if (it->cod == cod && it->qtd >= qtd) //se a quantidade comprada
    {                                     //está em estoque
      it->qtd -= qtd;
      break;
    }
    else if (it->cod == cod && it->qtd < qtd)
    {
      break;
    }
    else
      ;
    it++;
  }

  // TODO: Implemente este metodo
  /**
   * Observe na descricao do enunciado que nao e permita a venda de um modelo
   * cuja quantidade seja maior que a quantidade atual em estoque.
   * Ex: Se existirem apenas 5 celulares Motorola Moto G50 em estoque, vendas a
   * partir de 6 unidades devem ser ignoradas.
   */
}

void Venda::aplicaDesconto(const std::string &fabricante, float desconto)
{
  std::list<Celular>::iterator it;

  for (it = m_celulares.begin(); it != m_celulares.end(); it++)
  {
    if (it->fabricante == fabricante)
    {
      it->valor -= it->valor * (desconto / 100);
    }
  }

  // TODO: Implemente este metodo
}

void Venda::removeModelo(int cod)
{
  std::list<Celular>::iterator it = m_celulares.begin();

  while (1)
  {
    if (it->cod == cod)
    {
      break;
    }
    it++;
  }
  m_celulares.erase(it);

  // TODO: Implemente este metodo
}

void Venda::imprimeEstoque() const
{
  std::list<Celular>::const_iterator it = m_celulares.begin();
  int i = 1;

  for (it = m_celulares.begin(); it != m_celulares.end(); it++)
  {
    if (it->qtd < 1)
    {
      continue;
    }
    std::cout << std::fixed << std::setprecision(0);
    std::cout << it->fabricante << " " << it->modelo << ", " << it->armazenamento << "GB, ";
    std::cout << it->memoria << "GB RAM, " << it->peso << " gramas, ";
    std::cout << (char)toupper(it->cor[0]);
    while (1)
    {
      if (it->cor[i] == *it->cor.begin())
      {
        break;
      }
      std::cout << it->cor[i];
      i++;
    }
    std::cout << ", ";
    std::cout << it->qtd;
    if (it->qtd == 1)
    {
      std::cout << " restante, ";
    }
    if (it->qtd != 1)
    {
      std::cout << " restantes, ";
    }
    std::cout << "R$ " << std::setprecision(2) << it->valor << std::endl;
  }

  // TODO: Implemente este metodo.
  /**
   * Aqui voce tera que imprimir a lista de celulares em estoque com as
   * restricoes descritas no enunciado do problema. Notem no exemplo que a
   * primeira letra da cor do celular fica maiuscula. Outra coisa, se houver
   * apenas um item em estoque de determinado modelo de celular, voce tera que
   * imprimir '1 restante' e nao '1 restantes'. Por ultimo, apenas modelos de
   * celulares com pelo menos um item em estoque deverao ser exibidos.
   */
}