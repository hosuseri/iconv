#include <string>
#include "winstr.h"

std::wstring str_load(const std::string &s, UINT codePage)
{
    int n = ::MultiByteToWideChar(
	codePage,
	MB_PRECOMPOSED,
	s.c_str(),
	-1,
	NULL,
	0);
    WCHAR *buf = new WCHAR[n];
    ::MultiByteToWideChar(
	codePage,
	MB_PRECOMPOSED,
	s.c_str(),
	-1,
	buf,
	n);
    std::wstring t = buf;
    delete [] buf;
    return t;
}

std::string wstr_store(const std::wstring &s, UINT codePage)
{
    int n = ::WideCharToMultiByte(
	codePage,
	WC_NO_BEST_FIT_CHARS | WC_COMPOSITECHECK | WC_DEFAULTCHAR,
	s.c_str(),
	-1,
	NULL,
	0,
	NULL,
	NULL);
    CHAR *buf = new CHAR[n];
    ::WideCharToMultiByte(
	codePage,
	WC_NO_BEST_FIT_CHARS | WC_COMPOSITECHECK | WC_DEFAULTCHAR,
	s.c_str(),
	-1,
	buf,
	n,
	NULL,
	NULL);
    std::string t = buf;
    delete [] buf;
    return t;
}
