#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#define string std::string

auto fun1(auto, auto);
auto fun2(auto, auto);
auto fun2(auto p1, auto p2){
    return 'h';
}
auto fun1(auto p1, auto p2){
    auto v = 3.0;
    auto v2 = 3.3;
    return v + v2;
}

auto main() {
    auto x, s, c;
    x = true;
    s = 0.0;
    c = 'j';
    s = fun1(true, "Hi");
    c = fun2("hi", 100.0);
    return 1;
}
