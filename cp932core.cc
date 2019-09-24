#include "cp932core.h"

cp932core::cp932core() : strcore("UTF-16", "cp932")
{
}

void cp932core::init()
{
    strcore::init();
    srccp = 932;
}
