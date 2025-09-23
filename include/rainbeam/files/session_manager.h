#pragma once
#include <filesystem>

/// @brief Simple file manager which is used to create and clone files/directories.
class SessionManager
{
public:
    /// @brief Creates a "Rainbeam" folder in the users documents directory if possible.
    SessionManager();

    /// @brief Creates a save session under the "Rainbeam" directory.
    /// @param The name of the save session.
    /// @return A boolean representing whether the operation was successful.
    bool create_save_session(std::string);

private:
    /// @brief Contains the path to the user's documents directory.
    std::filesystem::path documents_dir;

    /// @brief Contains the path to the user's rainbeam directory.
    std::filesystem::path rainbeam_dir;

    /// @brief Finds the user's documents directory.
    /// @return A std::filesystem::path that links to the users document's directory.
    std::filesystem::path load_documents_dir();

    /// @brief Creates the "Rainbeam" directory in documents.
    /// @return A path containing the document directories.
    std::filesystem::path create_required_directories();
};