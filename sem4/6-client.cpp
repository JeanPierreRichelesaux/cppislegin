#include<iostream>
#include<boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

int main() {
    boost::asio::io_context ios;
    tcp::socket socket_(ios);
    socket_.connect(tcp::endpoint(ip::make_address("127.0.0.1"), 1234));
    const string msg = "Hello from Client!\n";
    boost::system::error_code error;
    boost::asio::write(socket, boost::asio::buffer(msg), error);
    if(!error) {
        cout << "Client sent hello message!" << endl;
   } else {
    cout << "send failed: " << error.message() << endl;
   }
   boost::asio::streambuf receive_buffer;
   boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
   if(error && error != error::eof) {
    cout << "receive failed:" << error.message() << endl;
   } else {
    const char* data = buffers_begin(buf.data());
   }
}