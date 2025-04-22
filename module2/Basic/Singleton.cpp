# include "Singleton.h"
Singleton Singleton::m_Instance; // Static instance pointer
// Singleton instance
Singleton & Singleton::Instance()
{
    return m_Instance;
}

void Singleton::MethodA(){
}

void Singleton::MethodB(){

}