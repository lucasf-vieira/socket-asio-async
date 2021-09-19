//
// async_tcp_echo_server.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2021 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <iostream>
#include <memory>
// #include <utility>

#include "asio.hpp"
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