#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "utf8core.h"
#include "cp932core.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
	std::cerr << argv[0] << "<fname>" << std::endl;
	::exit(2);
    }
    utf8core core;
    core.init();
    cp932core cp932;
    cp932.init();
    std::ifstream ifs;
    ifs.open(argv[1]);
    while (ifs.good()) {
	const int maxline = 2048;
	char s[maxline];
	ifs.getline(s, sizeof s);
	std::wstring t = core.load(s, ::strlen(s));
#if 0
	std::string u =
	    reinterpret_cast<char *>(core.store(t, s, sizeof s));
#else
	std::string u =
	    reinterpret_cast<char *>(cp932.store(t, s, sizeof s));
#endif	
	std::cout << u << std::endl;
    }
    ifs.close();
    return 0;
}

