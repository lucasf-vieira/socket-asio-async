#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <array>
#include <iostream>
#include <string>

class Client
{
private:
   enum class BEBIDA
   {
      CERVEJA,
      AGUA,
      REFRIGERANTE
   };

   int mClientID;
   std::array<BEBIDA, 3> mDrinksArray;

public:
   Client(/* args */);
   bool initialize_client_id();

   int get_client_id();

   void make_order();
   void make_order(int NumCervejas, int NumAguas, int NumRefrigerantes);
   bool check_availability(BEBIDA Drink, int Quantity);

   BEBIDA get_cerveja();
   BEBIDA get_agua();
   BEBIDA get_refrigerante();

   void add_cerveja(int Quantity);
   void add_agua(int Quantity);
   void add_refrigerante(int Quantity);

   friend std::ostream &operator<<(std::ostream &output, const Client &client);
};

std::ostream &operator<<(std::ostream &output, const Client &client);

#endif