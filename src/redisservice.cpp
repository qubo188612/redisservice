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

