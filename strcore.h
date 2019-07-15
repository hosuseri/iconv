#ifndef __STRCORE_H__
#define __STRCORE_H__

#include <stdlib.h>
#include <wchar.h>
#include <iconv.h>
#include <string>

class strcore {
public:
    strcore(std::string dstname, std::string srcname);
    ~strcore();
    void init();
    std::wstring load(const void *src, size_t n);
    void pack(std::wstring s);
    void *store(std::wstring s, void *dst, size_t n);

protected:
    static const size_t coremax = 2048 * sizeof(wchar_t);
    size_t len;
    char core[coremax];
    iconv_t inp, outp;
    std::string dstname, srcname;
};

#endif  /*  __STRCORE_H__ */
