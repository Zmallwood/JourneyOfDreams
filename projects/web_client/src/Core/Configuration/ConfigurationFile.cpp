#include "ConfigurationFile.h"

namespace JourneyOfDreams
{
    ConfigurationFile::ConfigurationFile()
    {
        std::ifstream configurationFile;                        // To contain the read configuration file
        configurationFile.open(SDL_GetBasePath() + k_filePath); // Open the configuration file

        std::string line; // To contain the read line

        while (std::getline(configurationFile, line)) // Read each line of the configuration file
        {
            auto parameterName = line.substr(0, line.find('='));   // Get the parameter name
            auto parameterValue = line.substr(line.find('=') + 1); // Get the parameter value

            std::transform( // Convert parameter name to lowercase
                parameterName.begin(), parameterName.end(), parameterName.begin(), tolower);

            if (parameterName == "serveraddress") // Check if the parameter is the server address
            {
                m_serverAddress = parameterValue; // Set the server address
            }
            else if (parameterName == "serverport") // Check if the parameter is the server port
            {
                m_serverPort = std::stoi(parameterValue); // Set the server port
            }
        }

        configurationFile.close(); // Close the configuration file
    }

    std::string ConfigurationFile::ServerAddress() const
    {
        return m_serverAddress;
    }

    int ConfigurationFile::ServerPort() const
    {
        return m_serverPort;
    }
}
