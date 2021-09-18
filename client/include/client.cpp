#include "client.hpp"

enum class Client::Drink
{
   Beer,
   Water,
   Soda
};

Client::Client()
{
   mDrinksArray.fill(0);                 // initialize drink array with 0 for each drink
   bool Result = initialize_client_id(); // initialize client ID
}

bool Client::initialize_client_id()
{
   bool Result = false;
   // mClientID = 0;
   return Result;
}

int Client::get_client_id() const
{
   return mClientID;
}

int Client::get_beer_quantity() const
{
   return mDrinksArray.at(static_cast<int>(Drink::Beer));
}
int Client::get_water_quantity() const
{
   return mDrinksArray.at(static_cast<int>(Drink::Water));
}
int Client::get_soda_quantity() const
{
   return mDrinksArray.at(static_cast<int>(Drink::Soda));
}

void Client::make_order()
{
}

void Client::make_order(int BeerQuantity, int WaterQuantity, int SodaQuantity)
{
}

bool Client::check_availability(Drink Drink, int DrinkQuantity)
{
   bool DrinkAvailable = false;

   return DrinkAvailable;
}

void Client::add_drink(Drink fDrink, int DrinkQuantity)
{
   bool DrinkAvailable = check_availability(fDrink, DrinkQuantity);

   if (DrinkAvailable == false)
   {
      std::cout << "Drink quantity unavailable." << std::endl;
      return;
   }

   switch (fDrink)
   {
   case Drink::Beer:
      mDrinksArray.at(static_cast<int>(Drink::Beer)) += DrinkQuantity;
      break;

   case Drink::Water:
      mDrinksArray.at(static_cast<int>(Drink::Water)) += DrinkQuantity;
      break;

   case Drink::Soda:
      mDrinksArray.at(static_cast<int>(Drink::Soda)) += DrinkQuantity;
      break;

   default:
      std::cout << "Wrong drink type" << std::endl;
      break;
   }
}

Client::Drink Client::beer_type()
{
   return Drink::Beer;
}
Client::Drink Client::water_type()
{
   return Drink::Water;
}
Client::Drink Client::soda_type()
{
   return Drink::Soda;
}

std::ostream &operator<<(std::ostream &output, const Client &client)
{
   output << "Drink quantity in client " << client.get_client_id() << std::endl;
   output << "Beer : " << client.get_beer_quantity() << std::endl;
   output << "Water: " << client.get_water_quantity() << std::endl;
   output << "Soda : " << client.get_soda_quantity() << std::endl;

   return output;
}