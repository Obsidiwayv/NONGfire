#include "./include/cli.h"
#include "./include/fs.h"

int fire::cli::handle() {
    if (!filesystem::exists(filesystem::current_path() / "Files"))
    {
        filesystem::create_directory(filesystem::current_path() / "Files");
    }

    if (!filesystem::exists(fire::fs::getGDSongDir())) {

        cout << "You don't seem to have Geometry Dash installed...\n";
        cout << "Press any key to continue...";
        cin.get();
        return 1;
    }

    fire::fs::filePaths paths;

    cout << "Enter the ID of the song.\n";
    cin >> paths.songID;

    if (!fire::fs::GDPathHasSong(paths.songID))
    {
        cout << "That song wasn't found in the Geometry Dash directory.\n";
        return fire::cli::handle();
    }

    cout << "Enter the song name you put in Files. (soundcloud is not yet supported)\n";
    cin >> paths.newSongPath;

    string pathString = paths.newSongPath.string();

    if (!filesystem::exists(fire::fs::getLocalSong(pathString)))
    {
        cout << "You didn't appear to put a file of that name into Files.";
        return fire::cli::handle();
    }

    if (pathString.find("/https://") == 0 && pathString.find("soundcloud") != string::npos)
    {
        cout << "This feature is not ready yet.\n";
        // cout << "Detected a soundcloud URL. attempting to fetch content.";
        return fire::cli::handle();
    }

    try {
        fire::fs::move(paths);
    } catch (const std::filesystem::filesystem_error& e)
    {
        cout << e.what();
        cout << "Press any key to continue...";
        cin.get();
    }

    cout << "File move complete!\n";
    return fire::cli::handle();
}