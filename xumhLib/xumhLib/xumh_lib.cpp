#pragma once

#include "xumh_lib.h"

#include <cstring>
#include <sstream>


namespace Xumh{
	bool C_StrStartsWith(const char *pre, const char *str){
		if(pre==NULL||str==NULL){
			return false;
		}
		size_t lenpre = std::strlen(pre),
			lenstr = strlen(str);
		return lenstr < lenpre ? false : strncmp(pre, str, lenpre) == 0;
	}

	std::string ConvertToString(unsigned long value){
		std::ostringstream stream;
		int i = 5;
		stream << i;
		std::string str = stream.str();
		return str;
	}
}