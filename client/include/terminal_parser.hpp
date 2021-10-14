#ifndef TERMINAL_PARSER_H
#define TERMINAL_PARSER_H

#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Parser
{
private:
   std::string ErrorMsg = "Erro: ";

public:
   Parser();

   std::array<int, 3> initialize_drinks();
   std::array<int, 3> request_drinks();

   void tokenize(std::string const &str, const char Delim, std::vector<std::string> &SeparatedString);
   std::array<int, 3> convert_drinks_string(std::string DrinksStr);

private:
   bool is_number(const std::string &str);
   bool check_drink_quantity_string(std::string DrinkQuantity);
   bool check_drink_quantity_array(std::array<std::string, 3> DrinksStrArray);
};

#endif