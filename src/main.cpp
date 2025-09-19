#include "rainbeam/api/router.h"
#include <cpp-httplib/httplib.h>

int main() {
    httplib::Server server;

    // Set routes
    setup_routes(server);

    // Mount Server
    server.listen("0.0.0.0", 8080);

    return 0;
}
