#pragma once
#ifndef XUMH_WIN_H_
#define XUMH_WIN_H_
#include <windows.h>
#include <string>

namespace Xumh{
	//根据错误码返回，错误描述
	BOOL GetErrorMessage(DWORD code,std::wstring& message);


	//同步锁，自动释放
	//CRITICAL_SECTION lock;
	//InitializeCriticalSection(&lock);
	//DeleteCriticalSection(&lock);
	class synchronize
	{
	private:
		CRITICAL_SECTION* plock;

	public:
		synchronize(CRITICAL_SECTION* lock)
		{
			plock = lock;
			if ( plock == NULL ) return;

			EnterCriticalSection(plock);
		}

		~synchronize()
		{
			if ( plock != NULL )
				LeaveCriticalSection(plock);
		} 
	};
}

#endif