#include "Logger.h"
#include <iostream>

Logger *Logger::m_pInstance;  // Static instance pointer

// Constructor initializes the log file
Logger::Logger(){
    std::cout << __FUNCTION__ << std::endl;
    m_pStream = fopen("applog.txt", "w");   
    atexit([]() { 
        delete m_pInstance; // Ensure the instance is deleted at program exit
    });
}


// Instance returns the singleton instance of Logger
Logger & Logger::Instance(){ 
    if (m_pInstance == nullptr)     // Lazy initialization
        m_pInstance = new Logger(); // Create the instance
        //m_pInstance.reset(new Logger{}); // Use smart pointer to manage the instance
    return *m_pInstance;       // Return the instance
}

// Destructor closes the log file
Logger::~Logger(){
    std::cout << __FUNCTION__ << std::endl;
    fclose(m_pStream);
}

// WriteLog writes a message to the log file with the current tag
void Logger::WriteLog(const char *pMessage){
    fprintf(m_pStream, "[%s] %s\n", m_Tag.c_str(), pMessage);
    fflush(m_pStream); // Ensure the message is written immediately
}

// SetTag sets the current tag for logging
// This could be an IP address, user ID, etc.
void Logger::SetTag(const char *pTag){
    m_Tag = pTag;
}