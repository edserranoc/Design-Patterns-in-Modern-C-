#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <memory>
#include <mutex>

class Logger{
    static std::mutex m_Mtx;
    struct Deleter{
        void operator()(Logger *p) {
            delete p ;
        }
    };
    FILE *m_pStream;
    std::string m_Tag;
    Logger();
    static Logger *m_pInstance; // Static instance pointer
    //inline static std::unique_ptr<Logger,Deleter> m_pInstance{} ; // Smart pointer to manage the instance
    ~Logger() ; // Destructor to close the log file to be private
public:
    Logger(const Logger &) = delete; // Prevent copying
    Logger & operator=(const Logger &) = delete; // Prevent assignment
    static Logger & Instance();
    void WriteLog(const char *pMessage) ;
    void SetTag(const char *pTag) ;
};