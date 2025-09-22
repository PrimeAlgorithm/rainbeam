#include <cpp-httplib/httplib.h>
#include <iostream>
#include <string>

namespace routes::index
{

    void get(const httplib::Request &, httplib::Response &res)
    {
        res.set_content("Test Page", "text/plain");
    }

} // namespace routes::index
