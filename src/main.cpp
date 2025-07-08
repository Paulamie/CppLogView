#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string line(std::string message) {
    size_t endPos = message.find("]:") + 3;

    if (endPos != std::string::npos) {
        std::string logMessage = message.substr(endPos);
        return logMessage;
    } else {
        return "Invalid log format";
    }
}

std::string level(std::string message) {
    size_t startPos = message.find("[") + 1;
    size_t endPos = message.find("]");

    if (startPos != std::string::npos && endPos != std::string::npos) {
        std::string logLevel = message.substr(startPos, endPos - startPos);
        return logLevel;
    } else {
        return "Invalid log format";
    }
}

std::string reformat(std::string message) {
    std::string lineLog = line(message);
    std::string levelLog = level(message);

    return lineLog + " (" + levelLog + ")";
}

int main() {
    // Example log message
    std::string logMessage = "[ERROR]: Invalid operation";

    // Process the log message using the 'line' function
    std::string processedLine = line(logMessage);
    std::cout << "Processed Line: " << processedLine << std::endl;

    // Process the log message using the 'level' function
    std::string result = level(logMessage);
    std::cout << "Log Level: " << result << std::endl;

    // Process the log message using the 'reformat' function
    std::string reformattedLine = reformat(logMessage);
    std::cout << "Reformatted Line: " << reformattedLine << std::endl;

    return 0;
}