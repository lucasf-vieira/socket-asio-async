#include "drink_client.hpp"

enum class DrinkClient::Drink
{
   Beer,
   Water,
   Soda
};

DrinkClient::DrinkClient()
{
   mDrinksArray.fill(0); // initialize drink array with 0 for each drink
}

void DrinkClient::connect(asio::io_context &io_context, char *HostIPv4, char *Port)
{
   mClient = std::make_shared<Client>(io_context, HostIPv4, Port);
}

void DrinkClient::request_drinks()
{
   Parser fParser;
   mDrinksArray = fParser.request_drinks();
}

void DrinkClient::make_order()
{
   mClient->start(mDrinksArray);
}

int DrinkClient::get_beer_quantity() const
{
   return mDrinksArray.at(static_cast<int>(Drink::Beer));
}
int DrinkClient::get_water_quantity() const
{
   return mDrinksArray.at(static_cast<int>(Drink::Water));
}
int DrinkClient::get_soda_quantity() const
{
   return mDrinksArray.at(static_cast<int>(Drink::Soda));
}

DrinkClient::Drink DrinkClient::beer_type()
{
   return Drink::Beer;
}
DrinkClient::Drink DrinkClient::water_type()
{
   return Drink::Water;
}
DrinkClient::Drink DrinkClient::soda_type()
{
   return Drink::Soda;
}

std::ostream &operator<<(std::ostream &output, const DrinkClient &client)
{
   output << "Quantidade de bebidas com o cliente:" << std::endl;
   output << "Águas         : " << client.get_water_quantity() << std::endl;
   output << "Cervejas      : " << client.get_beer_quantity() << std::endl;
   output << "Refrigerantes : " << client.get_soda_quantity() << std::endl;

   return output;
}