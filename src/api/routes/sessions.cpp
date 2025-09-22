#include <cpp-httplib/httplib.h>

namespace routes::sessions
{
    void get(const httplib::Request &, httplib::Response &res)
    {
        res.set_content("Mock Sessions Data", "text/plain");
    }

    void post(const httplib::Request &, httplib::Response &res)
    {
        res.set_content("Upload Sessions Here", "text/plain");
    }

    void deleter(const httplib::Request &, httplib::Response &res)
    {
        res.set_content("Delete Sessions Here", "text/plain");
    }
}