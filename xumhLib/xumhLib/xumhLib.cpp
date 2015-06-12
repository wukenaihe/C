// xumhLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "xumh_lib.h"
#include "xumh_win_lib.h"
#include <iostream>
using namespace std;
using namespace Xumh;

void TestC_StrStartsWith(){
	bool result=Xumh::C_StrStartsWith(NULL,"OK this is right");
	cout<<(result?"true":"false")<<endl;
}



void TestGetErrorMessage(){
	wstring message;
	BOOL result=GetErrorMessage(10053,message);
	wcout<<message<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	TestGetErrorMessage();
	
	return 0;
}

