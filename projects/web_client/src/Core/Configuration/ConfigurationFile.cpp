// Copyright (c) 2024 Andreas Åkerberg.

#include "ConfigurationFile.h"

// ConfigurationFile class implementation.

namespace journey_of_dreams
{
  ConfigurationFile::ConfigurationFile() {
    // To contain the read configuration file.
    std::ifstream _configurationFile;
    // Open the configuration file.
    _configurationFile.open(SDL_GetBasePath() + k_filePath);
    // To contain the read line.
    std::string _line;
    // Read each line of the configuration file.
    while (std::getline(_configurationFile, _line)) {
      // Remove comments from the line.
      for (auto &_c : _line) {
        if (_c == '#') {
          _line = _line.substr(0, _line.find('#'));
          break;
        }
      }
      // Get the parameter name and value.
      auto _parameterName = _line.substr(0, _line.find('='));
      auto _parameterValue = _line.substr(_line.find('=') + 1);
      // Convert parameter name to lowercase.
      std::transform(_parameterName.begin(), _parameterName.end(),
                     _parameterName.begin(), tolower);
      // Check if the parameter is the server address.
      if (_parameterName == "serveraddress") {
        // Set the server address.
        m_serverAddress = _parameterValue;
      }
      // Check if the parameter is the server port.
      else if (_parameterName == "serverport") {
        // Set the server port.
        m_serverPort = std::stoi(_parameterValue);
      }
    }
    // Close the configuration file.
    _configurationFile.close();
  }

  std::string ConfigurationFile::ServerAddress() const {
    return m_serverAddress;
  }

  int ConfigurationFile::ServerPort() const {
    return m_serverPort;
  }
} // namespace journey_of_dreams
