#pragma once
#ifndef XUMH_H_
#define XUMH_H_

#include <string>

namespace Xumh{
	/*
	*C类型字符串，比较str是否以pre开头
	*/
	bool C_StrStartsWith(const char *pre, const char *str);

	/*
	*将DWORD转换为string
	*/
	std::string ConvertToString(unsigned long value);
}
#endif