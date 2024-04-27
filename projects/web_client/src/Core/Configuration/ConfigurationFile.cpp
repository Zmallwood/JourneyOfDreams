#include "ConfigurationFile.h"

namespace zw
{
    ConfigurationFile::ConfigurationFile()
    {

        std::ifstream configurationFile;
        configurationFile.open(SDL_GetBasePath() + k_filePath);

        std::string line;

        while (std::getline(configurationFile, line))
        {
            auto parameterName = line.substr(0, line.find('='));
            auto parameterValue = line.substr(line.find('=') + 1);

            std::transform(parameterName.begin(), parameterName.end(), parameterName.begin(), tolower);

            if (parameterName == "serveraddress")
            {
                m_serverAddress = parameterValue;
            }
            else if (parameterName == "serverport")
            {
                m_serverPort = std::stoi(parameterValue);
            }
        }

        configurationFile.close();
    }
}
