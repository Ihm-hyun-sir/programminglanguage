#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#define string std::string

auto test(auto , auto);

auto test(auto z, auto y)
{
	auto x = 4.0;
	auto s = true;
	auto i = "string";
	return 1;
}

auto main( ) {
    auto s, i, x, last = 100;

    s = 0.0;
    i = 1;
    x = true;
    while (x == false) {
	i = i + 1;    
	x = i < last;
    }
    if(s != 0.0){
        last = 200;
    }


    return i;
}
