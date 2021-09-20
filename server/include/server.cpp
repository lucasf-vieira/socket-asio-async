#include "server.hpp"

using asio::ip::tcp;

Server::Server(asio::io_context &io_context, short port)
    : acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
{
   // Inicialização objeto DrinkStore
   mDrinkStore = std::make_shared<DrinkStore>();

   std::cout << std::endl;
   std::cout << "Servidor iniciado. Escutando na porta " << port << std::endl;
   do_accept();
}

void Server::do_accept()
{

   acceptor_.async_accept([this](std::error_code ec, tcp::socket Socket)
                          { run_async_accept(ec, std::move(Socket)); });
}

void Server::run_async_accept(std::error_code ec, tcp::socket Socket)
{
   if (!ec)
   {
      std::make_shared<Session>(std::move(Socket), mDrinkStore)->start();
   }

   do_accept();
}