#ifndef __STRCORE_H__
#define __STRCORE_H__

#include <windows.h>
#include <stdlib.h>
#include <wchar.h>
#include <string>
#include <cstring>
#include "winstr.h"

class strcore {
public:
    strcore(std::string dstname, std::string srcname);
    ~strcore();
    void init();
    std::wstring load(const char *s) { return load(s, ::strlen(s)); }
    std::wstring load(const void *src, size_t n);
    void pack(std::wstring s);
    void *store(std::wstring s, void *dst, size_t n);

protected:
    static const size_t coremax = 2048 * sizeof(wchar_t);
    char core[coremax + sizeof(wchar_t)];
    size_t len;
    std::string dstname, srcname;
    UINT dstcp, srccp;
};

#endif  /*  __STRCORE_H__ */
