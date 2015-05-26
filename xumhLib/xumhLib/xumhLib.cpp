// xumhLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "xumh_lib.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	bool result=Xumh::C_StrStartsWith(NULL,"OK this is right");
	cout<<(result?"true":"false")<<endl;
	return 0;
}

