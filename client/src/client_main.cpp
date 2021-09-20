//
// blocking_tcp_echo_client.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//
//
//

#include <cstdlib>
#include <cstring>
#include <iostream>

#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"
#include "asio/connect.hpp"
#include "asio/read.hpp"
#include "asio/write.hpp"

#include "drink_client.hpp"

using asio::ip::tcp;

int main(int argc, char *argv[])
{
   try
   {
      if (argc != 3)
      {
         std::cerr << "Usage: ./client.out <host> <port>\n";
         return 1;
      }
      DrinkClient StoreClient;

      asio::io_context io_context;
      StoreClient.connect(io_context, argv[1], argv[2]);

      StoreClient.request_drinks();
      StoreClient.make_order();
   }
   catch (std::exception &e)
   {
      std::cerr << "Exception caught. " << e.what() << "\n";
   }

   return 0;
}