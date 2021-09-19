#ifndef PARSER_H
#define PARSER_H

#include <array>
#include <iostream>
#include <string>

class Parser
{
public:
   Parser();
   bool check_arguments(int num_arguments, char **arguments);

   std::array<int, 3> request_drinks();

private:
   std::string ErrorMsg = "Erro: ";
   
   bool is_number(const std::string &str);
   bool check_drink_quantity(std::string DrinkQuantity);
};

#endif