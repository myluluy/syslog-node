#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#include "syslog.win.cc"
#else
#include "syslog.cc"
#endif