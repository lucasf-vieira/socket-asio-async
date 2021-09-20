#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <array>
#include <iostream>
#include <string>

// Include da biblioteca Asio
#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"
#include "asio/connect.hpp"
#include "asio/read.hpp"
#include "asio/write.hpp"

using asio::ip::tcp;

class Client
{
   // Atributos privados
private:
   enum Constants : int
   {
      BufferMaxLength = 1024
   };

   char mRequest[Constants::BufferMaxLength];
   char mReply[Constants::BufferMaxLength];

   tcp::socket mSocket;
   tcp::resolver mResolver;

public:
   Client(asio::io_context &io_context, char *HostIPv4, char *Port);
   void start(std::array<int, 3> DrinksArray);

   // Métodos privados
private:
   void read_server();
};

#endif