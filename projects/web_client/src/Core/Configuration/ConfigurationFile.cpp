// Copyright (c) 2024 Andreas Åkerberg.

#include "ConfigurationFile.h"

// ConfigurationFile class implementation.

namespace journey_of_dreams
{
  ConfigurationFile::ConfigurationFile() {
    // to contain the read configuration file
    std::ifstream _configurationFile;
    // open the configuration file
    _configurationFile.open(SDL_GetBasePath() + k_filePath);
    // to contain the read line
    std::string _line;
    // read each line of the configuration file
    while (std::getline(_configurationFile, _line)) {
      // remove comments from the line
      for (auto &_c : _line) {
        if (_c == '#') {
          _line = _line.substr(0, _line.find('#'));
          break;
        }
      }
      // get the parameter name and value
      auto _parameterName = _line.substr(0, _line.find('='));
      auto _parameterValue = _line.substr(_line.find('=') + 1);
      // convert parameter name to lowercase
      std::transform(_parameterName.begin(), _parameterName.end(),
                     _parameterName.begin(), tolower);

      // check if the parameter is the server address
      if (_parameterName == "serveraddress") {
        // set the server address
        m_serverAddress = _parameterValue;
      }
      // check if the parameter is the server port
      else if (_parameterName == "serverport") {
        // set the server port
        m_serverPort = std::stoi(_parameterValue);
      }
    }
    // close the configuration file
    _configurationFile.close();
  }

  std::string ConfigurationFile::ServerAddress() const {
    // return the server address
    return m_serverAddress;
  }

  int ConfigurationFile::ServerPort() const {
    // return the server port
    return m_serverPort;
  }
} // namespace journey_of_dreams
