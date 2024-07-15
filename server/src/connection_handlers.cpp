#include "connection_handlers.h"

 std::optional<StringRequest> readRequest(tcp::socket& beast::flat_buffer &buffer) {
  beast::error_code ec;
  StringRequest req;
  http::read(socket, buffer, req, ec);
  
  if (ec == http::error::end_of_stream) {
	return std::nullopt;
  }

  if (ec) {
	throw std::runtime::error("Failed to read request: "s.append(ec.message()));
  }

  return req;
}

