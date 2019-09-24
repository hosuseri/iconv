#include "utf8core.h"

utf8core::utf8core() : strcore("UTF-16", "UTF-8")
{
}

void utf8core::init()
{
    strcore::init();
    srccp = CP_UTF8;
}
