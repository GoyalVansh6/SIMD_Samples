#include <iostream>
#include "../includes/shift_operations.hpp"

static void ShiftLeft();
static void ShiftRight();

int main(){
    ShiftLeft();
    ShiftRight();
    return 0;
}

static void ShiftLeft(void){
    const char nl = '\n';
    XmmVal a, b;

    a.m_I32[0] = 10;
    a.m_I32[1] = 3000;
    a.m_I32[2] = -2000;
    a.m_I32[3] = 4200;

    b.m_I32[0] = -500;
    b.m_I32[1] = 100;
    b.m_I32[2] = -12000;
    b.m_I32[3] = 1000;

    ShiftLeft_Iavx(&a, &b, 2);

    std::cout << "ShiftLeft:\n";
    std::cout << "a: " << a.m_I32[0] << " " << a.m_I32[1] << " " << a.m_I32[2] << " " << a.m_I32[3] << nl;
    std::cout << "b: " << b.m_I32[0] << " " << b.m_I32[1] << " " << b.m_I32[2] << " " << b.m_I32[3] << nl;
}

static void ShiftRight(void){
    const char nl = '\n';
    XmmVal a, b;

    a.m_I32[0] = 10;
    a.m_I32[1] = 3000;
    a.m_I32[2] = -2000;
    a.m_I32[3] = 4200;

    b.m_I32[0] = -500;
    b.m_I32[1] = 100;
    b.m_I32[2] = -12000;
    b.m_I32[3] = 1000;

    ShiftRight_Iavx(&a, &b, 2);

    std::cout << "ShiftRight:\n";
    std::cout << "a: " << a.m_I32[0] << " " << a.m_I32[1] << " " << a.m_I32[2] << " " << a.m_I32[3] << nl;
    std::cout << "b: " << b.m_I32[0] << " " << b.m_I32[1] << " " << b.m_I32[2] << " " << b.m_I32[3] << nl;
}
