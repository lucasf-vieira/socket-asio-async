#include "server.hpp"

using asio::ip::tcp;

Server::Server(asio::io_context &io_context, short port)
    : acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
{
   std::cout << "Server started. Listening on port " << port << std::endl;
   do_accept();
}

void Server::do_accept()
{
   std::cout << "Print in Server::do_accept()" << std::endl;

   acceptor_.async_accept([this](std::error_code ec, tcp::socket Socket)
                          { run_async_accept(ec, std::move(Socket)); });
}

void Server::run_async_accept(std::error_code ec, tcp::socket Socket)
{
   std::cout << "Print in Server::do_accept(), async_accept()" << std::endl;
   if (!ec)
   {
      std::cout << "Print in Server::do_accept(), async_accept(), if (!ec) " << std::endl;
      std::make_shared<Session>(std::move(Socket))->start();
   }

   do_accept();
}