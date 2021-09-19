#include "client.hpp"

using asio::ip::tcp;

Client::Client(asio::io_context &io_context, char *HostIPv4, char *Port)
    : mSocket(io_context), mResolver(io_context)
{
   asio::connect(mSocket, mResolver.resolve(HostIPv4, Port));
   std::cout << "Cliente conectado a " << HostIPv4 << ":" << Port << std::endl;
}

void Client::start(std::array<int, 3> DrinksArray)
{
   std::string DrinksStr;
   int Counter = 0;
   for (auto it = DrinksArray.begin(); it != DrinksArray.end();
        it++)
   {
      DrinksStr.append(std::to_string(*it));
      if (Counter < 2)
      {
         DrinksStr.append(" ");
      }
      Counter++;
   }

   std::cout << "Print in Client::start() - " << DrinksStr << std::endl;

   std::strcpy(mRequest, DrinksStr.c_str());
   asio::write(mSocket, asio::buffer(mRequest, std::strlen(mRequest)));
   read_server();
}

void Client::read_server()
{
   size_t ReplyLength = asio::read(mSocket, asio::buffer(mReply, std::strlen(mRequest)));
   std::cout << "Reply is: ";
   std::cout.write(mReply, ReplyLength);
   std::cout << std::endl;
}
