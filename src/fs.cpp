#include "./include/fs.h"

void fire::fs::move(fire::fs::filePaths paths)
{
    filesystem::path songPath = fire::fs::getSong(paths.songID);
    filesystem::path currentDir = filesystem::current_path();
    filesystem::path replacedSongDir = currentDir / "GDSongs";

    // Create the GDSongs dir if it doesn't exist.
    if (!filesystem::exists(replacedSongDir))
    {
        filesystem::create_directory(replacedSongDir);
    };

    // We only needed to copy the original file, just in case :)
    if (!filesystem::exists(replacedSongDir / (paths.songID + ".mp3")))
    {
        filesystem::rename(songPath, replacedSongDir / (paths.songID + ".mp3"));
    }
    filesystem::copy(fire::fs::getLocalSong(paths.newSongPath.string()), songPath);
}

filesystem::path fire::fs::getGDSongDir()
{
    filesystem::path roaming = getenv("LOCALAPPDATA");
    return roaming / "GeometryDash";
}

filesystem::path fire::fs::getSong(string id)
{
    return fire::fs::getGDSongDir() / (id + ".mp3");
}

filesystem::path fire::fs::getLocalSong(string name)
{
    return filesystem::current_path() / "Files" / (name + ".mp3");
}

bool fire::fs::GDPathHasSong(string id)
{
    filesystem::path path = fire::fs::getSong(id);
    return filesystem::exists(path);
}