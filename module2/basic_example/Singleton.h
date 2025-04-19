#pragma once
class Singleton
{
    Singleton() = default; // Private constructor
    static Singleton m_Instance; // Static instance pointer
public: 
    static Singleton & Instance();
    void MethodA();
    void MethodB();
};