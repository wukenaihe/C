#pragma once
#ifndef XUMH_WIN_H_
#define XUMH_WIN_H_
#include <windows.h>
#include <string>

namespace Xumh{
	//���ݴ����뷵�أ���������
	BOOL GetErrorMessage(DWORD code,std::wstring& message);


	//ͬ�������Զ��ͷ�
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