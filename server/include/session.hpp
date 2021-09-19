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
   enum Constants : int;
   std::string mDataString;

   char data_[1024];

   tcp::socket socket_;

   void do_write(std::size_t Length);
   void run_async_write(std::error_code ec);

   void do_read();
   void run_async_read(std::error_code ec, std::size_t Length);
};

#endif