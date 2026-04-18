#include <iostream>
#include "../includes/bitwise_logical_operation.hpp"

static void And();
static void Or();
static void Xor();

int main(){
    And();
    Or();
    Xor();
    return 0;
}

static void And(void){
    const char nl = '\n';
    XmmVal a, b, c;

    a.m_I32[0] = 10;
    a.m_I32[1] = 3000;
    a.m_I32[2] = -2000;
    a.m_I32[3] = 4200;

    b.m_I32[0] = -500;
    b.m_I32[1] = 100;
    b.m_I32[2] = -12000;
    b.m_I32[3] = 1000;

    And_Iavx(&c, &a, &b);

    std::cout << "And:\n";
    std::cout << "a: " << a.m_I32[0] << " " << a.m_I32[1] << " " << a.m_I32[2] << " " << a.m_I32[3] << nl;
    std::cout << "b: " << b.m_I32[0] << " " << b.m_I32[1] << " " << b.m_I32[2] << " " << b.m_I32[3] << nl;
    std::cout << "c: " << c.m_I32[0] << " " << c.m_I32[1] << " " << c.m_I32[2] << " " << c.m_I32[3] << nl;
}

static void Or(void){
    const char nl = '\n';
    XmmVal a, b, c;

    a.m_I32[0] = 10;
    a.m_I32[1] = 3000;
    a.m_I32[2] = -2000;
    a.m_I32[3] = 4200;

    b.m_I32[0] = -500;
    b.m_I32[1] = 100;
    b.m_I32[2] = -12000;
    b.m_I32[3] = 1000;

    Or_Iavx(&c, &a, &b);

    std::cout << "Or:\n";
    std::cout << "a: " << a.m_I32[0] << " " << a.m_I32[1] << " " << a.m_I32[2] << " " << a.m_I32[3] << nl;
    std::cout << "b: " << b.m_I32[0] << " " << b.m_I32[1] << " " << b.m_I32[2] << " " << b.m_I32[3] << nl;
    std::cout << "c: " << c.m_I32[0] << " " << c.m_I32[1] << " " << c.m_I32[2] << " " << c.m_I32[3] << nl;
}

static void Xor(void){
    const char nl = '\n';
    XmmVal a, b, c;

    a.m_I32[0] = 10;
    a.m_I32[1] = 3000;
    a.m_I32[2] = -2000;
    a.m_I32[3] = 4200;

    b.m_I32[0] = -500;
    b.m_I32[1] = 100;
    b.m_I32[2] = -12000;
    b.m_I32[3] = 1000;

    Xor_Iavx(&c, &a, &b);

    std::cout << "Xor:\n";
    std::cout << "a: " << a.m_I32[0] << " " << a.m_I32[1] << " " << a.m_I32[2] << " " << a.m_I32[3] << nl;
    std::cout << "b: " << b.m_I32[0] << " " << b.m_I32[1] << " " << b.m_I32[2] << " " << b.m_I32[3] << nl;
    std::cout << "c: " << c.m_I32[0] << " " << c.m_I32[1] << " " << c.m_I32[2] << " " << c.m_I32[3] << nl;
}