#include "StdAfx.h"
#include "xumh_win_lib.h"
#include <string>
#include <windows.h>

namespace Xumh{
	BOOL GetErrorMessage(DWORD code,std::wstring& message){
		HLOCAL lpMsgBuf;
		DWORD bufLen = FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			code,
			MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
			(LPTSTR) &lpMsgBuf,
			0, NULL );
		if (bufLen)
		{
			LPCSTR lpMsgStr = (LPCSTR)lpMsgBuf;
			std::wstring result(lpMsgStr, lpMsgStr+bufLen);

			LocalFree(lpMsgBuf);

			message=result;
		}

		return false;

	}
}