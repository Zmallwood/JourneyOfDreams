// Copyright (c) 2024 Andreas Åkerberg.

#include "ConfigurationFile.h"

// ConfigurationFile class implementation.

namespace journey_of_dreams
{
  ConfigurationFile::ConfigurationFile() {
    // 1) Create object to contain the read configuration file.
    // 2) Open the configuration file.
    // 3) Create string to contain the read line.
    // 4) Read each line of the configuration file.
    // 5) Remove comments from the line.
    std::ifstream _configurationFile;
    _configurationFile.open(SDL_GetBasePath() + k_filePath);
    std::string _line;
    while (std::getline(_configurationFile, _line)) {
      for (auto &_c : _line) {
        if (_c == '#') {
          _line = _line.substr(0, _line.find('#'));
          break;
        }
      }
      // 1) Get the parameter name and value.
      // 2) Convert parameter name to lowercase.
      // 3) Check if the parameter is the server address.
      // 4) Set the server address.
      // 5) Check if the parameter is the server port.
      // 6) Set the server port.
      // 7) Close the configuration file.
      auto _parameterName = _line.substr(0, _line.find('='));
      auto _parameterValue = _line.substr(_line.find('=') + 1);
      std::transform(_parameterName.begin(), _parameterName.end(),
                     _parameterName.begin(), tolower);
      if (_parameterName == "serveraddress") {
        m_serverAddress = _parameterValue;
      } else if (_parameterName == "serverport") {
        m_serverPort = std::stoi(_parameterValue);
      }
    }
    _configurationFile.close();
  }

  std::string ConfigurationFile::ServerAddress() const {
    return m_serverAddress;
  }

  int ConfigurationFile::ServerPort() const {
    return m_serverPort;
  }
} // namespace journey_of_dreams
