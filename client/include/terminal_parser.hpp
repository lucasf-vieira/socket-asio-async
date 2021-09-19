#ifndef PARSER_H
#define PARSER_H

#include <array>
#include <iostream>
#include <string>

class Parser
{
public:
   Parser();

   std::array<int, 3> initialize_drinks();
   std::array<int, 3> request_drinks();

private:
   std::string ErrorMsg = "Erro: ";

   bool is_number(const std::string &str);
   bool check_drink_quantity_string(std::string DrinkQuantity);
   bool check_drink_quantity_array(std::array<std::string, 3> DrinksStrArray);
};

#endif