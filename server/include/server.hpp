#ifndef SERVER_HPP
#define SERVER_HPP

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>

#include "asio.hpp"
#include "session.hpp"

class Server
{
public:
   Server(asio::io_context &io_context, short port);

private:
   void do_accept();

   asio::ip::tcp::acceptor acceptor_;
};

#endif