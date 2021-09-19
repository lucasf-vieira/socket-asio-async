#include "terminal_parser.hpp"

Parser::Parser(){}

bool Parser::is_number(const std::string &fString)
{
   return fString.find_first_not_of("0123456789") == std::string::npos;
}

bool Parser::check_drink_quantity(std::string QuantityString)
{
   if (QuantityString.empty())
   {
      std::cerr << ErrorMsg << "Insira uma quantia de 0 a 10.000." << std::endl;
      return false;
   }

   if (!is_number(QuantityString))
   {
      std::cerr << ErrorMsg << "Digite apenas numeros." << std::endl;
      return false;
   }

   int DrinkQuantity = std::stoi(QuantityString);

   if (DrinkQuantity < 0)
   {
      std::cerr << ErrorMsg << "Nao pode ser uma quantia negativa." << std::endl;
      return false;
   }
   if (DrinkQuantity > 10000)
   {
      std::cerr << ErrorMsg << "Insira uma quantia de 0 a 10.000." << std::endl;
      return false;
   }

   return true;
}

std::array<int, 3> Parser::request_drinks()
{
   std::array<int, 3> DrinkArray;
   DrinkArray.fill(0);

   std::string QuantityString;

   std::cout << "Entre com um numero de 0 a 10.000 para a quantidade inicial de bebidas:" << std::endl
             << "Quantidade de cervejas: ";

   // Quantidade de cervejas
   std::cin >> QuantityString;

   while (!check_drink_quantity(QuantityString))
   {
      std::cout << "Quantidade de cervejas: ";
      std::cin >> QuantityString;
   }
   DrinkArray.at(0) = std::stoi(QuantityString);

   // Quantidade de águas
   std::cout << "Quantidade de águas: ";
   std::cin >> QuantityString;

   while (!check_drink_quantity(QuantityString))
   {
      std::cout << "Quantidade de águas: ";
      std::cin >> QuantityString;
   }
   DrinkArray.at(1) = std::stoi(QuantityString);

   // Quantidade de refrigerantes
   std::cout << "Quantidade de refrigerantes: ";
   std::cin >> QuantityString;

   while (!check_drink_quantity(QuantityString))
   {
      std::cout << "Quantidade de refrigerantes: ";
      std::cin >> QuantityString;
   }
   DrinkArray.at(2) = std::stoi(QuantityString);

   return DrinkArray;
}

bool Parser::check_arguments(int num_arguments, char **arguments)
{
   switch (num_arguments)
   {
   case 1:
      std::cout << "Erro: Numero de quadros nao especificado. Utilizacao: ./bin/paging-simulation.o [numero de quadros da simulacao]" << std::endl;
      return false;

   case 2:
      break;

   default:
      std::cout << "Erro: Numero de argumentos excedeu o limite (Limite de 1 argumento)" << std::endl;
      return false;
   }

   std::string argument = arguments[1];

   if (!is_number(argument))
   {
      std::cout << "Erro: Argumento nao e um inteiro positivo. Utilizacao: ./bin/paging-simulation.o [numero de quadros da simulacao]" << std::endl;
      return false;
   }

   if (std::stoi(argument) == 0)
   {
      std::cout << "Erro: Argumento nao pode ser zero. Utilizacao: ./bin/paging-simulation.o [numero de quadros da simulacao]" << std::endl;
      return false;
   }

   return true;
}