#include "ConfigurationFile.h"

namespace JourneyOfDreams
{
    ConfigurationFile::ConfigurationFile()
    {
        //
        // To contain the read configuration file
        //
        std::ifstream configurationFile;

        //
        // Open the configuration file
        //
        configurationFile.open(SDL_GetBasePath() + k_filePath);

        //
        // To contain the read line
        //
        std::string line;

        //
        // Read each line of the configuration file
        //
        while (std::getline(configurationFile, line))
        {
            //
            // Remove comments from the line
            //
            for (auto &c : line)
            {
                if (c == '#')
                {
                    line = line.substr(0, line.find('#'));
                    break;
                }
            }

            //
            // Get the parameter name and value
            //
            auto parameterName = line.substr(0, line.find('='));
            auto parameterValue = line.substr(line.find('=') + 1);

            //
            // Convert parameter name to lowercase
            //
            std::transform(parameterName.begin(), parameterName.end(), parameterName.begin(), tolower);

            //
            // Check if the parameter is the server address
            //
            if (parameterName == "serveraddress")
            {
                //
                // Set the server address
                //
                m_serverAddress = parameterValue;
            }
            //
            // Check if the parameter is the server port
            //
            else if (parameterName == "serverport")
            {
                //
                // Set the server port
                //
                m_serverPort = std::stoi(parameterValue);
            }
        }

        //
        // Close the configuration file
        //
        configurationFile.close();
    }

    std::string ConfigurationFile::ServerAddress() const
    {
        //
        // Return the server address
        //
        return m_serverAddress;
    }

    int ConfigurationFile::ServerPort() const
    {
        //
        // Return the server port
        //
        return m_serverPort;
    }
}
