#include "drink_store.hpp"

enum class DrinkStore::Drink
{
   Beer,
   Water,
   Soda
};

DrinkStore::DrinkStore()
{
   Parser mParser;
   mDrinksArray = mParser.request_drinks();
}

void DrinkStore::send_drink(Drink fDrink, int DrinkQuantity)
{
   if (check_availability(fDrink, DrinkQuantity) == false)
   {
      std::cout << "Drink quantity unavailable." << std::endl;
      return;
   }

   mDrinksArray.at(static_cast<int>(fDrink)) -= DrinkQuantity;
}

bool DrinkStore::check_availability(Drink fDrink, int DrinkQuantity)
{
   if (mDrinksArray.at(static_cast<int>(fDrink)) >= DrinkQuantity)
   {
      return true;
   }
   else
   {
      return false;
   }
}
