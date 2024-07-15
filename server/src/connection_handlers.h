#pragma once
#include <boost/asio.hpp>
#include <chrono>
#include <thread>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <optional>

namespace net = boost::asio;
namespace sys = boost::system;
using namespace std::chrono;
using namespace std::literals;
using tcp = net::ip::tcp;
namespace beast = boost::beast;
namespace http = beast::http;
using StringRequest = http::request<http::string_body>
using StringResponse = http::response<http::string_body>

std::optional<StringRequest> readRequest(tcp::socket& beast::flat_buffer &buffer);

void handleConnection(tcp::socket& socket) {
  std::cout << "connection received" << std::endl;

  constexpr	std::string_view response  = "HTTP/1.1 200 OK\n"sv
										  "Content-Type: text/plain\r\n\r\n"sv
										  "<p>Hello</p>"sv;
	net::write(socket, net::buffer(response));


}
