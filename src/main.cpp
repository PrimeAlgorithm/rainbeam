#include "rainbeam/api/router.h"
#include <cpp-httplib/httplib.h>
#include <filesystem>

int main()
{
    httplib::Server server;

    // Serve Static Files
    const std::string static_dir =
        (std::filesystem::path(__FILE__).parent_path() / "static").string();
    server.set_mount_point("/", static_dir);

    // Set routes
    setup_routes(server);

    // Mount Server
    server.listen("0.0.0.0", 8080);

    return 0;
}