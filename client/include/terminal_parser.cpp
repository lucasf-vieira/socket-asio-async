#include "terminal_parser.hpp"

Parser::Parser() {}

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
      std::cerr << ErrorMsg << "Digite apenas numeros inteiros positivos." << std::endl;
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

bool Parser::check_drink_quantity_array(std::array<std::string, 3> DrinksStrArray)
{
   for (auto it = DrinksStrArray.begin(); it != DrinksStrArray.end(); it++)
   {
      if (!check_drink_quantity_string(*it))
      {
         return false;
      }
   }

   return true;
}

// Pede a entrada de quantidade de cada bebida para o usuário
std::array<int, 3> Parser::request_drinks()
{
   std::fflush(stdin);
   std::array<int, 3> DrinksArray;
   DrinksArray.fill(0);

   std::array<std::string, 3> DrinksStrArray;

   std::cout << "Entre a quantidade desejada de bebidas no seguinte formato:" << std::endl
             << "'[Qtd. cervejas] [Qtd. aguas] [Qtd. refrigerantes]' (separado por espaços)" << std::endl;
   std::cout << "Quantia bebidas: ";

   std::cin >> DrinksStrArray.at(0);
   std::cin >> DrinksStrArray.at(1);
   std::cin >> DrinksStrArray.at(2);

   while (!check_drink_quantity_array(DrinksStrArray))
   {
      std::cout << "Quantia bebidas: ";
      std::cin >> DrinksStrArray.at(0);
      std::cin >> DrinksStrArray.at(1);
      std::cin >> DrinksStrArray.at(2);
   }

   // Convertendo Strings para inteiros
   DrinksArray.at(0) = std::atoi(DrinksStrArray.at(0).c_str());
   DrinksArray.at(1) = std::atoi(DrinksStrArray.at(1).c_str());
   DrinksArray.at(2) = std::atoi(DrinksStrArray.at(2).c_str());

   return DrinksArray;
}

void Parser::tokenize(std::string const &str, const char Delim, std::vector<std::string> &SeparatedString)
{
   // construct a stream from the string
   std::stringstream ss(str);

   std::string Buffer;
   while (std::getline(ss, Buffer, Delim))
   {
      SeparatedString.push_back(Buffer);
   }
}

std::array<int, 3> Parser::convert_drinks_string(std::string DrinksStr)
{
   std::vector<std::string> SeparatedString;
   const char Delimiter = ' ';
   tokenize(DrinksStr, Delimiter, SeparatedString);

   std::array<int, 3> DrinksArray;
   
   DrinksArray.at(0) = std::atoi(SeparatedString.at(0).c_str());
   DrinksArray.at(1) = std::atoi(SeparatedString.at(1).c_str());
   DrinksArray.at(2) = std::atoi(SeparatedString.at(2).c_str());

   return DrinksArray;
}
