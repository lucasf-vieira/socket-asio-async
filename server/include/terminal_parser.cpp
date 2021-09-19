#include "terminal_parser.hpp"

Parser::Parser(){}

bool Parser::is_number(const std::string &fString)
{
   return fString.find_first_not_of("0123456789") == std::string::npos;
}

bool Parser::check_drink_quantity_string(std::string QuantityString)
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

std::array<int, 3> Parser::initialize_drinks()
{
   std::array<int, 3> DrinkArray;
   DrinkArray.fill(0);

   std::string QuantityString;

   std::cout << "Entre com um numero de 0 a 10.000 para a quantidade inicial de bebidas:" << std::endl
             << "Quantidade de cervejas: ";

   // Quantidade de cervejas
   std::cin >> QuantityString;

   while (!check_drink_quantity_string(QuantityString))
   {
      std::cout << "Quantidade de cervejas: ";
      std::cin >> QuantityString;
   }
   DrinkArray.at(0) = std::stoi(QuantityString);

   // Quantidade de águas
   std::cout << "Quantidade de águas: ";
   std::cin >> QuantityString;

   while (!check_drink_quantity_string(QuantityString))
   {
      std::cout << "Quantidade de águas: ";
      std::cin >> QuantityString;
   }
   DrinkArray.at(1) = std::stoi(QuantityString);

   // Quantidade de refrigerantes
   std::cout << "Quantidade de refrigerantes: ";
   std::cin >> QuantityString;

   while (!check_drink_quantity_string(QuantityString))
   {
      std::cout << "Quantidade de refrigerantes: ";
      std::cin >> QuantityString;
   }
   DrinkArray.at(2) = std::stoi(QuantityString);

   return DrinkArray;
}
