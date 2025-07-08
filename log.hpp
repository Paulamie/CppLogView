#pragma once

#include <iostream> 
#include <fstream>

class Log { 
private:
    std::string filename; // Declare filename as a private member variable
    std::ifstream inputFile;
    std::string message;


public:
    Log(const char* filename);
    ~Log();
    bool create_log(const std::string& filename); 
    bool next();
    std::string line();
    std::string level();
    std::string reformat();
};


