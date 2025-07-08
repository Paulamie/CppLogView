#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "log.hpp"



int main() {
    //create_long function being called 
    Log myLog("log.in"); // Create an instance of the Log class
    if (myLog.create_log("log.in")) {
        std::cout << "File opened successfully." << std::endl;
        myLog.next();
        // File path
        std::string filename = "log.in";
        // Create an input file stream object
        std::ifstream inputFile(filename);

        //Line 
        std::string fileLine;
        while (std::getline(inputFile, fileLine)) {
            // Process the line using the 'line' function
            std::string processedLine = myLog.line();

            // Display the processed message
            std::cout << processedLine << std::endl;
            }
        
        
        // Reset file position to the beginning
        inputFile.clear(); // clear any error flags
        inputFile.seekg(0);

        //Level #######################################
        // Read each line from the file
        while (std::getline(inputFile, fileLine)) {
            std::string result = myLog.level();
            std::cout << result << std::endl;
        }   

         // Reset file position to the beginning
        inputFile.clear(); // clear any error flags
        inputFile.seekg(0);

        //Reformat ########################################

        std::string line;
        while (std::getline(inputFile, line)) {
            // Reformat each line and display the result
            std::string reformattedLine = myLog.reformat();
            std::cout << reformattedLine << std::endl;
        }

        inputFile.close();
        
    }

    else {
        std::cerr << "Unable to open the file." << std::endl;// Handle the error case
    }
    return 0;



}