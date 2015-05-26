#pragma once

#include "xumh_lib.h"


namespace Xumh{
	bool C_StrStartsWith(const char *pre, const char *str){
		if(pre==NULL||str==NULL){
			return false;
		}
		size_t lenpre = std::strlen(pre),
			lenstr = strlen(str);
		return lenstr < lenpre ? false : strncmp(pre, str, lenpre) == 0;
	}
}