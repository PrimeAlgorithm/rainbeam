#include "rainbeam/files/session_manager.h"
#include <nlohmann/json.hpp>
#include <filesystem>
#include <iostream>
#include <fstream>

#ifdef _WIN32
#include <shlobj.h>
#endif

// Constructors

SessionManager::SessionManager()
{
    // Find the users documentsd directory.
    documents_dir = this->load_documents_dir();

    // Create Rainbeam directory if needed.
    rainbeam_dir = this->create_required_directories();
};

// Public methods

bool SessionManager::create_save_session(std::string name)
{
    std::filesystem::path save_session = this->rainbeam_dir / std::filesystem::path{name};

    if (std::filesystem::create_directories(save_session))
    {
        std::ofstream settings_file(save_session / "settings.json");
        nlohmann::json settings;
        settings["name"] = name;
        settings["password"] = "";
        settings["expire_date"] = "";
        settings_file << settings.dump(4);
        settings_file.close();

        return true;
    }

    return false;
}

// Private methods

std::filesystem::path SessionManager::load_documents_dir()
{
#ifdef _WIN32
    // User is on Windows
    PWSTR path_tmp;
    auto response = SHGetKnownFolderPath(FOLDERID_Documents, 0, nullptr, &path_tmp);

    if (response != S_OK)
    {
        CoTaskMemFree(path_tmp);
        throw std::runtime_error("Documents folder cannot be found on Windows system.");
    }

    std::filesystem::path appdata(path_tmp);
    CoTaskMemFree(path_tmp);

    return appdata;
#else
    // User is on a UNIX like system
    std::filesystem::path home_path = std::filesystem::path(std::getenv("HOME"));
    std::filesystem::path documents_path = home_path / "Documents";

    if (std::filesystem::exists(documents_path))
    {
        return documents_path;
    }
    else
    {
        throw std::runtime_error("Documents path cannot be found on UNIX system");
    }
#endif
}

std::filesystem::path SessionManager::create_required_directories()
{
    std::filesystem::path documents = this->documents_dir;
    std::filesystem::path rainbeam_path = documents / "Rainbeam";
    std::filesystem::create_directories(rainbeam_path);
    return rainbeam_path;
}
