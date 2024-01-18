#pragma once

#include <filesystem>
#include <iostream>
#include <string>

using namespace std;

namespace fire
{
  namespace fs
  {
    struct filePaths
    {
      string songID;
      filesystem::path newSongPath;
    };

    void move(filePaths paths);

    // void downloadSongFromSoundcloud(string trackURL);
    
    filesystem::path getSong(string id);

    filesystem::path getGDSongDir();

    filesystem::path getLocalSong(string name);

    bool GDPathHasSong(string id);
  }
}