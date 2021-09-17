#ifndef SESSION_HPP
#define SESSION_HPP

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>

#include "asio.hpp"

using asio::ip::tcp;

class Session
    : public std::enable_shared_from_this<Session>
{
public:
   Session(tcp::socket socket);
   
   void start();

private:
   enum
   {
      max_length = 1024
   };

   void do_read();

   void do_write(std::size_t length);

   tcp::socket socket_;

   char data_[max_length];
};

#endif