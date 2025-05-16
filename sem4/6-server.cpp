#include<iostream>
#include<boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

string read_(tcp::socket & socket) {
    boost::asio::streambuf buf;
    boost::asio::read_until(socket, buf, "\n");
    std::string data(boost::asio::buffers_begin(buf.data()), boost::asio::buffers_end(buf.data())); // !!!!!
    return data;
}

void send_(tcp::socket & socket, const string& message) {
    const string msg = message + "\n";
    boost::asio::write(socket, boost::asio::buffer(message));
}

int main() {
    boost::asio::io_context ios;
    tcp::acceptor acceptor_(ios, tcp::endpoint(tcp::v4(), 1234));
    tcp::socket socket_(ios);
    acceptor_.accept(socket_);
    string message = read_(socket_);
    cout << message << endl;
    send_(socket_, "Hello From Server!");
    cout << "Servent sent Hello message to Client!" << endl;
    return 0;
}