#include "server.hh"

// TODO : create our own errors and throw them here
Server::Server(const std::string name, short unsigned int port,
               const std::string ip, const std::string root_dir)
    : Server(name, port, ip, root_dir, "", false) {}

Server::Server(const std::string name, short unsigned int port,
               const std::string ip, const std::string root_dir,
               const std::string log_file, bool dry_run)
    : name_(name), port_(port), ip_(ip), root_dir_(root_dir),
      log_file_(log_file), dry_run_(dry_run) {
  listener_fd_ = socket(AF_INET, SOCK_STREAM, 0);
  if (listener_fd_ < 0)
    std::cerr << "An error occured during socket creation" << std::endl;

  int opt = 1;
  // REUSE allow to reuse socket address's and port's
  if (setsockopt(listener_fd_, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                 sizeof(int)) < 0)
    std::cerr << "An error occured while setting options to the socket"
              << std::endl;
  //struct sockaddr_in address;
  address_.sin_family = AF_INET;
  // TODO : change address to ip_
  // use this for instance :
  // inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr
  address_.sin_addr.s_addr = INADDR_ANY;
  // TODO : port_ is an unsigned
  address_.sin_port = htons(port_);
  if (bind(listener_fd_, (struct sockaddr *)&address_,
           sizeof(struct sockaddr_in)) < 0)
    std::cerr << "An error occured while assigning a name to a socket"
              << std::endl;

  // TODO : change 3 to a private attributes of the priority q len
  if (listen(listener_fd_, 3) == -1)
    std::cerr << "An error occured while listening to the socket" << std::endl;
}

// TODO : put it back in the ctor
void Server::acpt() {
  socklen_t address_len = sizeof(struct sockaddr_in);
  accepter_fd_ =
      accept(listener_fd_, (struct sockaddr *)&address_, &address_len);
  std::cout << "accepter_fd_ : " << accepter_fd_ << std::endl;
  if (accepter_fd_ < 0)
    std::cerr << "An error occured while accepting the socket" << std::endl;
}

Server::~Server() {
  if (shutdown(listener_fd_, SHUT_RDWR) < 0)
    std::cerr << "An error occured while closing the socket" << std::endl;
  if (close(listener_fd_) < 0)
    std::cerr << "An error occured while closing the listener" << std::endl;
}

void Server::print() const {
  std::cout << name_ << " ";
  std::cout << port_ << " ";
  std::cout << ip_ << " ";
  std::cout << root_dir_ << " ";
  std::cout << std::endl;
}

void Server::echo() const
{
  char buffer[1024] = {0};
  read(accepter_fd_, buffer, 1024);
  std::cout << buffer << std::endl;
}
