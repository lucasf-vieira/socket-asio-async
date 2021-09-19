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

private:
   std::string ErrorMsg = "Erro: ";

   bool is_number(const std::string &str);
   bool check_drink_quantity_string(std::string DrinkQuantity);
};

#endif