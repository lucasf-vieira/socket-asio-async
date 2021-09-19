#ifndef SERVER_HPP
#define SERVER_HPP

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>

#include "asio.hpp"
#include "session.hpp"

using asio::ip::tcp;

class Server
{
public:
   Server(asio::io_context &io_context, short port);

private:
   tcp::acceptor acceptor_;

   void do_accept();
   void run_async_accept(std::error_code ec, tcp::socket Socket);
};

#endif