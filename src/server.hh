#pragma once

class Server
{
  const std::string name_;
  const std::string port_;
  // TODO : check weather if string is the best type for ip
  const std::string ip_;
  const std::string root_dir_;

  // Optional settings
  const std::string log_file_ = "";
  bool dry_run_ = false;

public:
  Server(const std::string name
	 , const std::string port
	 , const std::string ip
	 , const std::string root_dir_);
  Server(const std::string name
	 , const std::string port
	 , const std::string ip
	 , const std::string root_dir_
	 , const std::string log_file
	 , bool dry_run);
  ~Server();
  
  const std::string& name_get() const;
  const std::string& port_get() const;
  const std::string& ip_get() const;
  const std::string& root_dir_get() const;
  const std::string& log_file_get() const;
  const bool dry_run_get() const;
};
