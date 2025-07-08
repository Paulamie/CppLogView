#include <iostream> 
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include "log.hpp"

Log::Log(const char* filename) { //simple declaration
    std::cout << "Log object created with log file: " << filename << std::endl;
    
    // // Call create_log to open the file and display messages
    // if (!create_log(filename)) {
    //     std::cerr << "Unable to create log file: " << filename << std::endl;
    // }
}

bool Log::create_log(const std::string& filename) { //read a file and return true or false.

    // Set the filename member variable
    this->filename = filename;

    // Create an input file stream object
    inputFile.open(filename);

    // std::getline(inputFile, message);
    // std::cout << "***" << message << "***" << std::endl;

    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return false; // Return false if unable to open
    }

    return true; // Return true if the file is successfully opened
}

bool Log::next() {
    // Attempt to read the next line into the filename member variable
    if (std::getline(inputFile, message)) {
        return true;  // Successfully read the next line
    } else {
        return false; // End of file or error occurred
    }
}

std::string Log::line(){ //its meant to only read the message after the square brackets.
    size_t endPos = message.find("]:") + 3;

    if (endPos != std::string::npos){
        std::string logMessage = message.substr(endPos);
        return logMessage;
    }
    else {
        // Return an empty string or handle the case where the format is not as expected
        return "Invalid log format";
        }  
}

std::string Log::level() {
    // Find the position of the colon after the opening square bracket
    size_t startPos = message.find("[") + 1;
    size_t endPos = message.find("]");

    // Check if the opening and closing square brackets are found
    if (startPos != std::string::npos && endPos != std::string::npos) {
        // Extract the substring between the square brackets
        std::string logLevel = message.substr(startPos, endPos - startPos);
        return logLevel;
    } else {
        // Return an empty string or handle the case where the format is not as expected
        return "Invalid log format";
    }
}

std::string Log::reformat() {

    std::string lineLog = line();
    std::string levelLog = level ();

    return lineLog + " (" + levelLog + ")";
}


Log::~Log() { //simple declaration 
    // Destructor logic
    if (inputFile.is_open()) {
        std::cout << "Closing log file." << std::endl;
        inputFile.close(); // Close the file
    }
    std::cout << "Log object destroyed." << std::endl;
}