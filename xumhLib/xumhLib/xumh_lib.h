#pragma once
#ifndef XUMH_H_
#define XUMH_H_

#include <string>

namespace Xumh{
	/*
	*C�����ַ������Ƚ�str�Ƿ���pre��ͷ
	*/
	bool C_StrStartsWith(const char *pre, const char *str);

	/*
	*��DWORDת��Ϊstring
	*/
	std::string ConvertToString(unsigned long value);
}
#endif