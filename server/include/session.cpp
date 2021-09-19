#include "session.hpp"

using asio::ip::tcp;

enum Session::Constants : int
{
   BufferMaxLength = 1024
};

Session::Session(tcp::socket socket)
    : socket_(std::move(socket))
{
   std::cout << "Print in Session()" << std::endl;
}

void Session::start()
{
   std::cout << "Print in Session::start()" << std::endl;
   do_read();
}

void Session::do_read()
{
   std::cout << "Print in Session::do_read() " << std::endl;
   auto self(shared_from_this());
   socket_.async_read_some(asio::buffer(data_, Constants::BufferMaxLength),
                           [this, self](std::error_code ec, std::size_t Length)
                           {
                              data_[Length] = '\0';
                              run_async_read(ec, Length);
                           });
}

void Session::run_async_read(std::error_code ec, std::size_t Length)
{
   std::cout << "Print in Session::do_read(), asio::async_read_some" << std::endl;
   if (!ec)
   {
      std::cout << "Print in Session::do_read(), asio::async_read_some, if (!ec)" << std::endl;
      std::cout << data_ << std::endl;
      do_write(Length);
   }
}

void Session::do_write(std::size_t Length)
{
   std::cout << "Print in Session::do_write()" << std::endl;

   auto self(shared_from_this());
   asio::async_write(socket_, asio::buffer(data_, Length),
                     [this, self](std::error_code ec, std::size_t)
                     {
                        run_async_write(ec);
                     });
}

void Session::run_async_write(std::error_code ec)
{
   std::cout << "Print in Session::do_write(), asio::async_write" << std::endl;
   if (!ec)
   {
      std::cout << "Print in Session::do_write(), asio::async_write, if (!ec) " << std::endl;
      do_read();
   }
}
