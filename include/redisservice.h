#pragma once

#define DLL_EXPORTS extern "C" __declspec(dllexport)
#define DLL_CLASSEXP __declspec(dllexport)
#include "dataStructure.h"

class redisserviceParam;

class DLL_CLASSEXP redisservice
{
public:
	static redisservice *instance();
private:
	redisservice();
	~redisservice();

	redisserviceParam *p;
};

