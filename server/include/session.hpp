#ifndef SESSION_HPP
#define SESSION_HPP

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>

#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"
#include "asio/write.hpp"

#include "drink_store.hpp"

using asio::ip::tcp;

class Session
    : public std::enable_shared_from_this<Session>
{
private:
   enum Constants : int;
   std::string mDataString;
   std::shared_ptr<DrinkStore> mDrinkStore;

   char data_[1024];

   tcp::socket socket_;

public:
   Session(tcp::socket socket, std::shared_ptr<DrinkStore> fDrinkStore);

   void start();

private:
   void do_write(std::string Reply);
   void run_async_write(std::error_code ec);

   void do_read();
   void run_async_read(std::error_code ec);

   std::string create_client_message(const std::string ClientData);
};

#endif