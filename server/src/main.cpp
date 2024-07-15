#include <exception>
#include <iostream>
#include <stdexcept>
#include <string_view>
#ifdef WIN32
#include <sdkddkver.h>
#endif
#include <boost/asio.hpp>
#include <chrono>
#include <thread>

#include "connection_handlers.h"

namespace net = boost::asio;
namespace sys = boost::system;
using namespace std::chrono;
using namespace std::literals;
using tcp = net::ip::tcp;


#define thr_id std::this_thread::get_id()

int main(int argv, char* argc[]) {
  std::cout << "server thread = " << thr_id << std::endl;
  
  net::io_context ioc;
  
  const auto address = net::ip::make_address("0.0.0.0");
  constexpr unsigned short port = 8080;

  tcp::acceptor acceptor(ioc, {address, port});

  std::cout << "waiting socket connection" << std::endl;


  while(true) {
	tcp::socket socket(ioc);
	acceptor.accept(socket);
	handleConnection(socket);
  }
}


