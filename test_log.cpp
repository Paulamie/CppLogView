#include "simpletest/simpletest.h"
#include "log.hpp"


using namespace std;

char const * groups[] = { "Log", };


DEFINE_TEST_G(LogTest1, Log) {
    Log log("log.in");
    bool success = log.create_log("./log.in");
    TEST_MESSAGE(success == true, "Failed to open log!!!!");
    success = log.next();
    TEST_MESSAGE(success == true, "Failed to read log!!!!");
    std::string line = log.line();
    TEST_MESSAGE(line.compare("Invalid operation") == 0, "Expecting Invalid ↪ operation!!!!");
    
}

DEFINE_TEST_G(LogTest2, Log) {
    Log log("log.in");
    bool success = log.create_log("./log.in");
    TEST_MESSAGE(success == true, "Failed to open log!!!!");

    // Read the first log entry
    success = log.next();
    TEST_MESSAGE(success == true, "Failed to read log!!!!");
    std::string line = log.line();
    TEST_MESSAGE(line.compare("Invalid operation") == 0, "Expecting Invalid operation!!!!");

    // Read the second log entry
    success = log.next();
    TEST_MESSAGE(success == true, "Failed to read log!!!!");
    std::string level = log.level();
    TEST_MESSAGE(level.compare("INFO") == 0, "Expecting INFO level!!!!");
}

DEFINE_TEST_G(LogTest3, Log) {
    Log log("log.in");
    bool success = log.create_log("./log.in");
    TEST_MESSAGE(success == true, "Failed to open log!!!!");

    // Read the first log entry
    success = log.next();
    TEST_MESSAGE(success == true, "Failed to read log!!!!");
    std::string reformat = log.reformat();
    TEST_MESSAGE(reformat.compare("Invalid operation (ERROR)") == 0, "Expecting reformat: Invalid operation (ERROR)!!!!");
}

DEFINE_TEST_G(LogTest4, Log) {
    Log log("log.in");
    bool success = log.create_log("./log.in");
    TEST_MESSAGE(success == true, "Failed to open log!!!!");

    // Read all log entries
    while (log.next()) {
        // Do nothing, just advance to the end
    }

    std::string line = log.line();
    TEST_MESSAGE(line.compare("Invalid log format") == 0, "Expecting Invalid log format after reaching end of file!!!!");
}

DEFINE_TEST_G(LogTest5, Log) {
    Log log("nonexistent_log.in");
    bool success = log.create_log("./nonexistent_log.in");
    TEST_MESSAGE(success == false, "Expecting failure to open nonexistent log file!!!!");
}


int main() {
    bool pass = true;
    for (auto group : groups) {
        pass &= TestFixture::ExecuteTestGroup(group, TestFixture::Verbose); 
    }

    return pass ? 0 : 1; 
}