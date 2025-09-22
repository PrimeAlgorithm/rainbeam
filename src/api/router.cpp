#include "rainbeam/api/routes/index.h"
#include "rainbeam/api/routes/sessions.h"
#include <cpp-httplib/httplib.h>

void setup_routes(httplib::Server &server)
{
    server.Get("/test", routes::index::get);

    // sessions
    server.Get("/sessions", routes::sessions::get);
    server.Post("/sessions", routes::sessions::post);
    server.Delete("/sessions", routes::sessions::deleter);
}
