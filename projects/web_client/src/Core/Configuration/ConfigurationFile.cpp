/* Copyright (c) 2024 Andreas Åkerberg. */

#include "ConfigurationFile.h"

/* ConfigurationFile class implementation. */

namespace JourneyOfDreams
{
  ConfigurationFile::ConfigurationFile() {
    /* 1) Create object to contain the read configuration file.
     * 2) Open the configuration file.
     * 3) Create string to contain the read line.
     * 4) Read each line of the configuration file.
     * 5) Remove comments from the line.*/
    std::ifstream configurationFile;
    configurationFile.open(SDL_GetBasePath() + k_filePath);
    std::string line;
    while (std::getline(configurationFile, line)) {
      for (auto &c : line) {
        if (c == '#') {
          line = line.substr(0, line.find('#'));
          break;
        }
      }
      /* 1) Get the parameter name and value.
       * 2) Convert parameter name to lowercase.
       * 3) Check if the parameter is the server address.
       * 4) Set the server address.
       * 5) Check if the parameter is the server port.
       * 6) Set the server port.
       * 7) Close the configuration file. */
      auto parameterName = line.substr(0, line.find('='));
      auto parameterValue = line.substr(line.find('=') + 1);
      std::transform(parameterName.begin(), parameterName.end(),
                     parameterName.begin(), tolower);
      if (parameterName == "serveraddress") {
        m_serverAddress = parameterValue;
      } else if (parameterName == "serverport") {
        m_serverPort = std::stoi(parameterValue);
      }
    }
    configurationFile.close();
  }

  std::string ConfigurationFile::ServerAddress() const {
    return m_serverAddress;
  }

  int ConfigurationFile::ServerPort() const {
    return m_serverPort;
  }
}