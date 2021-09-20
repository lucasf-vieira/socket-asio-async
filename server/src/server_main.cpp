//
//
//
//
//
//
//

#include <iostream>
#include <memory>

#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"

#include "server.hpp"
#include "session.hpp"

using asio::ip::tcp;

int main(int argc, char *argv[])
{
   try
   {
      if (argc != 2)
      {
         std::cerr << "Usage: ./server.out [port]\n";
         return 1;
      }

      asio::io_context io_context;

      Server MainServer(io_context, std::atoi(argv[1]));

      io_context.run();
   }
   catch (std::exception &e)
   {
      std::cerr << "Exception caught. " << e.what() << "\n";
   }

   return 0;
}