//
//  Copyright (C) 2024 Andreas Åkerberg.
//
#include "ConfigurationFile.h"
//
//  ConfigurationFile class implementation.
//
namespace JourneyOfDreams
{
   ConfigurationFile::ConfigurationFile() {
      //to contain the read configuration file
      std::ifstream configurationFile;
      //open the configuration file
      configurationFile.open(SDL_GetBasePath() + k_filePath);
      //to contain the read line
      std::string line;
      //read each line of the configuration file
      while (std::getline(configurationFile, line)) {
         //remove comments from the line
         for (auto &c : line) {
            if (c == '#') {
               line = line.substr(0, line.find('#'));
               break;
            }
         }
         //get the parameter name and value
         auto parameterName = line.substr(0, line.find('='));
         auto parameterValue = line.substr(line.find('=') + 1);
         //convert parameter name to lowercase
         std::transform(parameterName.begin(), parameterName.end(), parameterName.begin(), tolower);

         //check if the parameter is the server address
         if (parameterName == "serveraddress") {
            //set the server address
            m_serverAddress = parameterValue;
         }
         //check if the parameter is the server port
         else if (parameterName == "serverport") {
            //set the server port
            m_serverPort = std::stoi(parameterValue);
         }
      }
      //close the configuration file
      configurationFile.close();
   }
   std::string ConfigurationFile::ServerAddress() const {
      //return the server address
      return m_serverAddress;
   }
   int ConfigurationFile::ServerPort() const {
      //return the server port
      return m_serverPort;
   }
} // namespace JourneyOfDreams
