#pragma once
#ifndef XUMH_WIN_H_
#define XUMH_WIN_H_
#include <windows.h>
#include <string>

namespace Xumh{
	//¸ù¾İ´íÎóÂë·µ»Ø£¬´íÎóÃèÊö
	BOOL GetErrorMessage(DWORD code,std::wstring& message);
}

#endif