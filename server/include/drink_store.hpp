#ifndef DRINK_STORE_HPP
#define DRINK_STORE_HPP

#include <array>
#include <iostream>

#include "terminal_parser.hpp"

class DrinkStore
{
private:
   enum class Drink;
public:
   DrinkStore();

   void send_drink(Drink fDrink, int Quantity);

   bool check_availability(Drink Drink, int Quantity);

private:
   std::array<int, 3> mDrinksArray;
};

#endif