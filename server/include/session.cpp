#include "session.hpp"

using asio::ip::tcp;

enum Session::Constants : int
{
   BufferMaxLength = 1024
};

Session::Session(tcp::socket socket, std::shared_ptr<DrinkStore> fDrinkStore)
    : socket_(std::move(socket))
{
   mDrinkStore = fDrinkStore;
}

void Session::start()
{
   do_read();
}

void Session::do_read()
{
   auto self(shared_from_this());
   socket_.async_read_some(asio::buffer(data_, Constants::BufferMaxLength),
                           [this, self](std::error_code ec, std::size_t)
                           {
                              data_[std::strlen(data_)] = '\0';
                              run_async_read(ec);
                           });
}

void Session::run_async_read(std::error_code ec)
{
   if (!ec)
   {
      const std::string ClientData(data_);

      std::string Reply;
      Reply = create_client_message(ClientData);

      do_write(Reply);
   }
}

std::string Session::create_client_message(const std::string ClientData)
{
   Parser fParser;
   std::array<int, 3> ClientDrinksOrder;
   ClientDrinksOrder = fParser.convert_drinks_string(ClientData);

   std::string ClientMessage;
   ClientMessage = mDrinkStore->check_drink_list_availability(ClientDrinksOrder);
   return ClientMessage;
}

void Session::do_write(std::string Reply)
{
   Reply.append("\nAte a proxima!");
   std::strcpy(data_, Reply.c_str());

   auto self(shared_from_this());
   asio::async_write(socket_, asio::buffer(data_, Constants::BufferMaxLength),
                     [this, self](std::error_code ec, std::size_t)
                     {
                        run_async_write(ec);
                     });
}

void Session::run_async_write(std::error_code ec)
{
   std::cout << *mDrinkStore;
   if (!ec)
   {
      do_read();
   }
}
