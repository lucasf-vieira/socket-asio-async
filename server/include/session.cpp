#include "session.hpp"

using asio::ip::tcp;

Session::Session(tcp::socket socket)
    : socket_(std::move(socket))
{
}

void Session::start()
{
   do_read();
}

void Session::do_write(std::size_t length)
{
   auto self(shared_from_this());
   asio::async_write(socket_, asio::buffer("HAHAHA", length),
                     [this, self](std::error_code ec, std::size_t /*length*/)
                     {
                        if (!ec)
                        {
                           do_read();
                        }
                     });
}

void Session::do_read()
{
   auto self(shared_from_this());
   socket_.async_read_some(asio::buffer(data_, max_length),
                           [this, self](std::error_code ec, std::size_t length)
                           {
                              if (!ec)
                              {
                                 std::cout << data_ << std::endl;
                                 do_write(length);
                              }
                           });
}
