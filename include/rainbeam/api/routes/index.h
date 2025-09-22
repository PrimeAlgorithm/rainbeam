#pragma once
#include <cpp-httplib/httplib.h>

namespace routes::index
{

    void get(const httplib::Request &, httplib::Response &res);

}
