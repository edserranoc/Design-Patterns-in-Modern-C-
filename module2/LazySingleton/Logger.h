#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>

class Logger{
    FILE *m_pStream;
    std::string m_Tag;
    Logger();
    static Logger *m_pInstance; // Static instance pointer
public:
    Logger(const Logger &) = delete; // Prevent copying
    Logger & operator=(const Logger &) = delete; // Prevent assignment
    static Logger & Instance();
    ~Logger() ;
    void WriteLog(const char *pMessage) ;
    void SetTag(const char *pTag) ;
};

