#pragma once
#include <cpp-httplib/httplib.h>

namespace routes::sessions
{

    void get(const httplib::Request &, httplib::Response &res);
    void post(const httplib::Request &, httplib::Response &res);
    void deleter(const httplib::Request &, httplib::Response &res);
}
