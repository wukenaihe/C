#pragma once
#ifndef XUMH_WIN_H_
#define XUMH_WIN_H_
#include <windows.h>
#include <string>

namespace Xumh{
	//���ݴ����뷵�أ���������
	BOOL GetErrorMessage(DWORD code,std::wstring& message);
}

#endif