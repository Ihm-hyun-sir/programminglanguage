#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#define string std::string

auto test(auto,auto,auto);

auto test(auto x , auto y, auto z)
{
	
	return 1;
}
auto main( ) {
    auto s, i = 50, x, last = 100;
    auto f;
    f = i ? 50 : 70;
    s = 0.0;
    i = 10;
    x = true;
    last =  test(x,i,f);
 
    if( x != true){
	f = i + 60 ? 90 : 80;
}
    while (x == true) {
	s = s + 21.0;

	i = i + 1;
        x = i < last;
    }


    return 1;
}

