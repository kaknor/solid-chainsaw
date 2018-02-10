#include "server.hh"

int main()
{
  // TODO : handle parsing of config file here
  short unsigned int a = 4242;
  Server t("server1", a, "127.0.0.0", "./");
  t.print();
  t.acpt();
  while(1)
    {
      t.echo();
    }
}
