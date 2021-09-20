#ifndef DRINK_STORE_HPP
#define DRINK_STORE_HPP

#include <array>
#include <iostream>

#include "terminal_parser.hpp"

class DrinkStore
{
private:
   enum class Drink;
   std::array<int, 3> mDrinksArray;

public:
   DrinkStore();

   void send_drink(Drink fDrink, int Quantity);

   bool is_drink_available(Drink Drink, int Quantity);
   std::string check_drink_list_availability(std::array<int, 3> RequestedDrinksArray);
   std::string get_drink_name(Drink fDrink) const;

   friend std::ostream &operator<<(std::ostream &output, const DrinkStore &Store);
};

std::ostream &operator<<(std::ostream &output, const DrinkStore &Store);

#endif