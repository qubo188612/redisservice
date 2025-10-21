#pragma once

#define DLL_EXPORTS extern "C" __declspec(dllexport)
#define DLL_CLASSEXP __declspec(dllexport)
#include "dataStructure.h"
#include <vector>

class redisserviceParam;

class DLL_CLASSEXP redisType
{
public:
	redisType() {};
	~redisType() {};
	void setvalue(std::string str) { s_value = str; };
	double toDouble();
	int toInt();
	std::string toString();
	bool toBool();
	bool isNull();
private:
	std::string s_value;
};

namespace Redisservice {

	class DLL_CLASSEXP redisservice
	{
	public:
		static redisservice *instance();

		void setValue(const char *key, const char *value);
		void setValue(const char *key, int value);
		void setValue(const char *key, double value);
		void setValue(const char *key, bool value);

		redisType getValue(const char *key);
	private:
		redisservice();
		~redisservice();

		redisserviceParam *p;
	};

}

#define ReidsCmd Redisservice::redisservice::instance()
