#include "Logger.h"

Logger *Logger::m_pInstance;  // Static instance pointer

// Constructor initializes the log file
Logger::Logger(){
    m_pStream = fopen("applog.txt", "w");   
}


// Instance returns the singleton instance of Logger
Logger & Logger::Instance(){ 
    if (m_pInstance == nullptr)     // Lazy initialization
        m_pInstance = new Logger(); // Create the instance
    return *m_pInstance;       // Return the instance
}

// Destructor closes the log file
Logger::~Logger(){
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