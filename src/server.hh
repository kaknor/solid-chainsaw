#pragma once
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>

class Server
{
  const std::string name_;
  short unsigned int port_;
  // TODO : check weather if string is the best type for ip
  const std::string ip_;
  const std::string root_dir_;

  // Optional settings
  const std::string log_file_ = "";
  bool dry_run_ = false;

  // TODO : create private settings for listener fd etc...
  // Listener socket fd
  int listener_fd_;
  // Accepter socket fd
  int accepter_fd_;
  struct sockaddr_in address_;

public:
  Server(const std::string name
	 , short unsigned int port
	 , const std::string ip
	 , const std::string root_dir);

  Server(const std::string name
	 , short unsigned int port
	 , const std::string ip
	 , const std::string root_dir
	 , const std::string log_file
	 , bool dry_run);
  ~Server();
  
  const std::string& name_get() const;
  const std::string& port_get() const;
  const std::string& ip_get() const;
  const std::string& root_dir_get() const;
  const std::string& log_file_get() const;
  bool dry_run_get() const;

  void acpt();
  void print() const;
  void echo() const;
};
