#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
  // socket create the socket
  int listener_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (listener_fd < 0)
    std::cerr << "An error occured during socket creation" << std::endl;
  // sockaddr_in stands for internet either ipv4 or ipv6
  struct sockaddr_in address;
  address.sin_family = AF_INET;
  // here is the address specified in parameters of the input file
  address.sin_addr.s_addr = INADDR_ANY;
  // the htons for the port is mandatory
  address.sin_port = htons(4242);
  // binds the the address to the socket
  if (bind(listener_fd, (struct sockaddr*) &address, sizeof (struct sockaddr_in)) < 0)
    std::cerr << "An error occured while assigning a name to a socket" << std::endl;
  if (listen(listener_fd, 3) == -1)
    std::cerr << "An error occured while listening to the socket" << std::endl;

  socklen_t address_len = sizeof (address);
  int accepter_fd = accept(listener_fd, (struct sockaddr*) &address, &address_len);
  if (accepter_fd < 0)
    std::cerr << "An error occured while accepting the socket" << std::endl;

  char buffer[1024] = {0};
  read(accepter_fd, buffer, 1024);
  std::cout << buffer << std::endl;
  
  if (shutdown(listener_fd, SHUT_RDWR) < 0)
    std::cerr << "An error occured while closing the socket" << std::endl;
  if (close(listener_fd) < 0)
    std::cerr << "An error occured while closing the listener" << std::endl;
}
