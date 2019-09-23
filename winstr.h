#ifndef __WINSTR_H__

#include <windows.h>
//#include <stringapi.h>

std::wstring str_load(const std::string &s, UINT codePage = CP_UTF8);
std::string wstr_store(const std::wstring &s, UINT codePage = CP_UTF8);

#endif  /* __WINSTR_H__ */
