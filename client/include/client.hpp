#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <array>
#include <iostream>
#include <string>

class Client
{
private:
   enum class Drink;

public:
   Client();
   bool initialize_client_id();

   int get_client_id() const;
   int get_beer_quantity() const;
   int get_water_quantity() const;
   int get_soda_quantity() const;

   void make_order();
   void make_order(int NumCervejas, int NumAguas, int NumRefrigerantes);
   bool check_availability(Drink Drink, int Quantity);

   Drink beer_type();
   Drink water_type();
   Drink soda_type();

   void add_drink(Drink fDrink, int Quantity);

   friend std::ostream &operator<<(std::ostream &output, const Client &client);

private:
   int mClientID;
   std::array<int, 3> mDrinksArray;
};

std::ostream &operator<<(std::ostream &output, const Client &client);

#endif