#include "commitid.h"
#include "alg_base_common.h"
#include "redisservice.h"
#include <sw/redis++/redis++.h>
using namespace sw::redis;

class redisserviceParam
{
public:
	redisserviceParam() {};
	~redisserviceParam() {};

	Redis *redis;
};

namespace Redisservice {
	redisservice *redisservice::instance()
	{
		static redisservice obj;
		return &obj;
	}

	redisservice::redisservice()
	{
		p = new redisserviceParam;
		p->redis = new Redis("tcp://127.0.0.1:6379");

	}

	redisservice::~redisservice()
	{
		delete p->redis;
		delete p;
	}

	void redisservice::setValue(const char *key, const char *value)
	{
		p->redis->set(key, value);
	}

	void redisservice::setValue(const char *key, int value)
	{
		std::string s_value = std::to_string(value);
		p->redis->set(key, s_value);
	}

	void redisservice::setValue(const char *key, double value)
	{
		std::string s_value = std::to_string(value);
		p->redis->set(key, s_value);
	}

	void redisservice::setValue(const char *key, bool value)
	{
		std::string s_value;
		if (value == true)
		{
			s_value = "true";
		}
		else
		{
			s_value = "true";
		}
		p->redis->set(key, s_value);
	}

	redisType redisservice::getValue(const char *key)
	{
		redisType rc;
		auto name = p->redis->get(key);
		if (name.has_value()) {
			std::string name_str = *name;  // 解引用获取 std::string
			rc.setvalue(name_str);
		}
		return rc;
	}
}

double redisType::toDouble()
{
	double rc;
	if (s_value.empty())
	{
		rc = 0;
	}
	else
	{
		rc = std::stod(s_value);
	}
	return rc;
}

int redisType::toInt()
{
	int rc;
	if (s_value.empty())
	{
		rc = 0;
	}
	else
	{
		rc = std::stoi(s_value);
	}
	return rc;
}

std::string redisType::toString()
{
	return s_value;
}

bool redisType::toBool()
{
	bool rc = false;
	if (s_value.empty())
	{
		rc = false;
	}
	else
	{
		if (s_value == "true" || s_value == "TRUE" || s_value == "True")
		{
			rc = true;
		}
		else
		{
			rc = false;
		}
	}
	return rc;
}

bool redisType::isNull()
{
	bool rc;
	if (s_value.empty())
	{
		rc = true;
	}
	else
	{
		rc = false;
	}
	return rc;
}
