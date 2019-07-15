#include "strcore.h"

strcore::strcore(std::string dstname, std::string srcname) :
    dstname(dstname), srcname(srcname)
{
}

strcore::~strcore()
{
    iconv_close(inp);
    iconv_close(outp);
}

void strcore::init()
{
    inp = iconv_open(dstname.c_str(), srcname.c_str());
    outp = iconv_open(srcname.c_str(), dstname.c_str());
}

std::wstring strcore::load(const void *src, size_t len)
{
    const char *p = reinterpret_cast<const char *>(src);
    char *q = core;
    size_t m = len, n = coremax;
    /* int k = */ iconv(inp, &p, &m, &q, &n);
    std::wstring s(reinterpret_cast<wchar_t *>(core),
		   coremax - n);
    return s;
}

void strcore::pack(std::wstring s)
{
    const char *p = reinterpret_cast<const char *>(s.data());
    char *q = core;
    size_t m = s.length(), n = coremax;
    iconv(outp, &p, &m, &q, &n);
    len = coremax - n;
}

void *strcore::store(std::wstring s, void *dst, size_t n)
{
    pack(s);
    register char *p = reinterpret_cast<char *>(dst);
    register char *q = core;
    for (register size_t r = n <= len ? n - 1 : len; r > 0; --r)
	*p++ = *q++;
    *p = '\0';
    return dst;
}
