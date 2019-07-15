#include "cp932core.h"

cp932core::cp932core() : strcore("UTF-32", "cp932")
{
}

void cp932core::init()
{
    strcore::init();
    std::string endl = "\r\n";
    const char *p = endl.c_str();
    char *q = core;
    size_t m = endl.length(), n = coremax;
    iconv(inp, &p, &m, &q, &n);
}
