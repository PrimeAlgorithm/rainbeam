#include "rainbeam/api/routes/index.h"
#include <cpp-httplib/httplib.h>

void setup_routes(httplib::Server &server) {
    server.Get("/", routes::index::get);
}
