#include "utf8core.h"

utf8core::utf8core() : strcore("UTF-32", "UTF-8")
{
}

void utf8core::init()
{
    strcore::init();
    std::string endl = "\r\n";
    char *p = const_cast<char *>(endl.c_str());
    char *q = core;
    size_t m = endl.length(), n = coremax;
    iconv(inp, &p, &m, &q, &n);
}
