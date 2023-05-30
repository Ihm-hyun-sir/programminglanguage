#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#define string std::string

auto fun1(auto, auto);
auto fun1(auto p1, auto p2){
    auto v = 3;
    auto v2 = 3.3;
    return 1 + 2;
}

auto main() {
    auto dou, in, boo = true, ch, st, boo2, in3, in4;
    auto dec = 10;
    dou = 0.0;
    in = 1 * 3 + 2;
    boo = true;
    boo2 = 1 < 2;
    ch = 'a';
    st = "kkk";

    in3 = (in == in) ? in : in;

    in4 = fun1(2, 3);
}
