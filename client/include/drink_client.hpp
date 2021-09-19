#ifndef DRINK_CLIENT_HPP
#define DRINK_CLIENT_HPP

#include <array>
#include <iostream>
#include <memory>
#include <string>

// Include da biblioteca Asio
#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"
#include "asio/connect.hpp"
#include "asio/read.hpp"
#include "asio/write.hpp"

// Include de arquivos pessoais
#include "terminal_parser.hpp"
#include "client.hpp"

class DrinkClient
{
private:
   enum class Drink;

   std::shared_ptr<Client> mClient;
   std::array<int, 3> mDrinksArray;

public:
   DrinkClient();
   void request_drinks();
   void make_order();

   void connect(asio::io_context &io_context, char *HostIPv4, char *Port);

   int get_beer_quantity() const;
   int get_water_quantity() const;
   int get_soda_quantity() const;

   Drink beer_type();
   Drink water_type();
   Drink soda_type();

   friend std::ostream &operator<<(std::ostream &output, const DrinkClient &client);

   // Métodos privados
private:
};

std::ostream &operator<<(std::ostream &output, const DrinkClient &client);

#endif