#include<iostream>
#include "../includes/integer_addition.hpp"

static void AddI16(void);
static void AddU16(void);

int main(){
    AddI16();
    AddU16();
    return 0;
}

static void AddI16(void){
    const char nl = '\n';
    XmmVal a, b, c1, c2;

    a.m_I16[0] = 1;
    a.m_I16[1] = 2;
    a.m_I16[2] = 3;
    a.m_I16[3] = 4;
    a.m_I16[4] = 5;
    a.m_I16[5] = 6;
    a.m_I16[6] = 7;
    a.m_I16[7] = 8;

    b.m_I16[0] = 1;
    b.m_I16[1] = 2;
    b.m_I16[2] = 3;
    b.m_I16[3] = 4;
    b.m_I16[4] = 5;
    b.m_I16[5] = 6;
    b.m_I16[6] = 7;
    b.m_I16[7] = 8;

    AddI16_Iavx(&c1, &c2, &a, &b);

    std::cout << "c1: " << c1.m_I16[0] << " " << c1.m_I16[1] << " " << c1.m_I16[2] << " " << c1.m_I16[3] << " " << c1.m_I16[4] << " " << c1.m_I16[5] << " " << c1.m_I16[6] << " " << c1.m_I16[7] << nl;
    std::cout << "c2: " << c2.m_I16[0] << " " << c2.m_I16[1] << " " << c2.m_I16[2] << " " << c2.m_I16[3] << " " << c2.m_I16[4] << " " << c2.m_I16[5] << " " << c2.m_I16[6] << " " << c2.m_I16[7] << nl;
}

static void AddU16(void){
    const char nl = '\n';
    XmmVal a, b, c1, c2;

    a.m_U16[0] = 1;
    a.m_U16[1] = 2;
    a.m_U16[2] = 3;
    a.m_U16[3] = 4;
    a.m_U16[4] = 5;
    a.m_U16[5] = 6;
    a.m_U16[6] = 7;
    a.m_U16[7] = 8;

    b.m_U16[0] = 1;
    b.m_U16[1] = 2;
    b.m_U16[2] = 3;
    b.m_U16[3] = 4;
    b.m_U16[4] = 5;
    b.m_U16[5] = 6;
    b.m_U16[6] = 7;
    b.m_U16[7] = 8;

    AddU16_Iavx(&c1, &c2, &a, &b);

    std::cout << "c1: " << c1.m_U16[0] << " " << c1.m_U16[1] << " " << c1.m_U16[2] << " " << c1.m_U16[3] << " " << c1.m_U16[4] << " " << c1.m_U16[5] << " " << c1.m_U16[6] << " " << c1.m_U16[7] << nl;
    std::cout << "c2: " << c2.m_U16[0] << " " << c2.m_U16[1] << " " << c2.m_U16[2] << " " << c2.m_U16[3] << " " << c2.m_U16[4] << " " << c2.m_U16[5] << " " << c2.m_U16[6] << " " << c2.m_U16[7] << nl;
}