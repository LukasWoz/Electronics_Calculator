#include"System_Record.h"

std::ostream& operator << (std::ostream& o, const TSystem_Record& obj) {
    o << obj.Get_NumbSystem(); 
    return o;
}

std::istream& operator >> (std::istream& i, TSystem_Record& obj) {
    std::string a{};
    int b{};
    i >> a; obj.Set_NumbSystem(a);
    i >> b; obj.Set_NumbBase(b);
    return i;
}



