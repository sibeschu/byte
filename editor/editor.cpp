#include <logger.h>

int main()
{
  TRB_FATAL("Help");
  TRB_ERROR("HELP");
  TRB_WARN("Hilfe %d " , 42);
  TRB_INFO("HELP");
  TRB_DEBUG("HELP");

  return 0;
}
