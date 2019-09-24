#include <stdexcept>
#include "strcore.h"

strcore::strcore(std::string dstname, std::string srcname) :
    dstname(dstname), srcname(srcname)
{
}

strcore::~strcore()
{
 }

void strcore::init()
{
    if (dstname == "UTF-16")
	;
    else
	throw std::invalid_argument("dstname");
}

std::wstring strcore::load(const void *src, size_t len)
{
    char *p = const_cast<char *>(reinterpret_cast<const char *>(src));
    return str_load(p, srccp);
}

void strcore::pack(std::wstring s)
{
    std::string t = wstr_store(s, srccp);
    char *p = const_cast<char *>(reinterpret_cast<const char *>(t.data()));
    size_t n = t.length();
    if (n > coremax)
	throw std::overflow_error("n > coremax");
    ::strncpy(core, p, n);
    core[n++] = '\0';
    len = n;
}

void *strcore::store(std::wstring s, void *dst, size_t n)
{
    pack(s);
    if (n < len)
	throw std::overflow_error("n < len");
    char *p = reinterpret_cast<char *>(dst);
    ::memcpy(p, core, len);
    return dst;
}
