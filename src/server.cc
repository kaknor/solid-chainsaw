#include "server.hh"

Server::Server(const std::string name
	       , const std::string port
	       , const std::string ip
	       , const std::string root_dir)
  : name_(name)
  , port_(port)
  , ip_(ip)
  , root_dir_(root_dir)
{}

Server::Server(const std::string name
	       , const std::string port
	       , const std::string ip
	       , const std::string root_dir
	       , const std::string log_file
	       , bool dry_run)
  : name_(name)
  , port_(port)
  , ip_(ip)
  , root_dir_(root_dir)
  , log_file_(log_file)
  , dry_run_(dry_run)
{}
