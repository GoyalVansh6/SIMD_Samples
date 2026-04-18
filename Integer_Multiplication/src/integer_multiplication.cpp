#include<iostream>
#include "../includes/integer_multiplication.hpp"

static void MulI16(void);
static void MulI32a(void);
static void MulI32b(void);

int main(){
    MulI16();
    MulI32a();
    MulI32b();
    return 0;
}

static void MulI16(void){
    const char nl = '\n';
    XmmVal a, b, c[2];

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

    MulI16_Iavx(c, &a, &b);

    std::cout << "c1: " << c[0].m_I16[0] << " " << c[0].m_I16[1] << " " << c[0].m_I16[2] << " " << c[0].m_I16[3] << " " << c[0].m_I16[4] << " " << c[0].m_I16[5] << " " << c[0].m_I16[6] << " " << c[0].m_I16[7] << nl;
    std::cout << "c2: " << c[1].m_I16[0] << " " << c[1].m_I16[1] << " " << c[1].m_I16[2] << " " << c[1].m_I16[3] << " " << c[1].m_I16[4] << " " << c[1].m_I16[5] << " " << c[1].m_I16[6] << " " << c[1].m_I16[7] << nl;
}

static void MulI32a(void){
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

    MulI32a_Iavx(&c, &a, &b);

    std::cout << "a: " << a.m_I32[0] << " " << a.m_I32[1] << " " << a.m_I32[2] << " " << a.m_I32[3] << nl;
    std::cout << "b: " << b.m_I32[0] << " " << b.m_I32[1] << " " << b.m_I32[2] << " " << b.m_I32[3] << nl;
    std::cout << "c: " << c.m_I32[0] << " " << c.m_I32[1] << " " << c.m_I32[2] << " " << c.m_I32[3] << nl;
}

static void MulI32b(void){
    const char nl = '\n';
    XmmVal a, b, c[2];

    a.m_I32[0] = 10;
    a.m_I32[1] = 3000;
    a.m_I32[2] = -2000;
    a.m_I32[3] = 4200;

    b.m_I32[0] = -500;
    b.m_I32[1] = 100;
    b.m_I32[2] = -12000;
    b.m_I32[3] = 1000;

    MulI32b_Iavx(c, &a, &b);

    std::cout << "a: " << a.m_I32[0] << " " << a.m_I32[1] << " " << a.m_I32[2] << " " << a.m_I32[3] << nl;
    std::cout << "b: " << b.m_I32[0] << " " << b.m_I32[1] << " " << b.m_I32[2] << " " << b.m_I32[3] << nl;
    std::cout << "c: " << c[0].m_I32[0] << " " << c[0].m_I32[1] << " " << c[0].m_I32[2] << " " << c[0].m_I32[3] << nl;
    std::cout << "c: " << c[1].m_I32[0] << " " << c[1].m_I32[1] << " " << c[1].m_I32[2] << " " << c[1].m_I32[3] << nl;
}