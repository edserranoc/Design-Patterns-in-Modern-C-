# include "Singleton.h"

int main()
{
    // Access the singleton instance and call its methods
    Singleton &s = Singleton::Instance();
    s.MethodA();
    return 0;
};