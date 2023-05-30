#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#define string std::string

auto main( ) {
    auto s, i, x, last = 100;

    s = 0.0;
    i = 1;
    x = true;
    while (x == false) {

	i = i + 1;
        x = i < last;
    }
    if(i == false){
        last = 200;
    }

    printf("sum(%d) = %f\n", last, s);

    return i;
}
