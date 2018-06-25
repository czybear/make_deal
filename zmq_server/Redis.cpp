#include "Redis.h"


Redis::Redis()
{
	
}

void Redis::setRedis(string key, string val) {
	
	if (c->err) {
		redisFree(c);
		return;
	}
	string cm = ("set " + key + " " + val);
	//std::cout << "ִ����redis�������  " << cm<<std::endl;
	const char* command1 =cm.c_str();
	r = (redisReply*)redisCommand(c, command1);
	if (NULL == r) {
		redisFree(c);
		return;
	}
	if (!(r->type == REDIS_REPLY_STATUS && (strcmp(r->str, "OK")) == 0 || strcmp(r->str, "ok") == 0)) {
		std::cout << "δ��ִ������" << command1 << std::endl;
		freeReplyObject(r);
		redisFree(c);
		return;
	}
	freeReplyObject(r);
	//std::cout << "�ɹ�ִ������ " << key << std::endl;

}

int Redis::getcount(string key)
{

	const char* command2 = ("get " + key).c_str();
	r = (redisReply*)redisCommand(c, command2);
	if (r->type != REDIS_REPLY_INTEGER) {
		std::cout << "δ��ִ������" << key << std::endl;
		freeReplyObject(r);
		redisFree(c);
		return 0;
	}
	int length = r->integer;
	freeReplyObject(r);
	//std::cout << "ֵ�� " << length << std::endl;
	//std::cout << "�ɹ�ִ������ " << key << std::endl;
	return length;

}

string Redis::getRedis(string key)
{
	string str;
	//std::cout << " key:" << key << std::endl;
	try
	{
		string cm = ("get " + key);
		const char* command3 = cm.c_str();
		r = (redisReply*)redisCommand(c, command3);
		if (r->type != REDIS_REPLY_STRING) {
			std::cout << "δ��ִ������ " << key << std::endl;
			freeReplyObject(r);
			redisFree(c);
			return "";
		}
		str = r->str;
		freeReplyObject(r);
		std::cout << "�ɹ�ִ�в�ѯ " << key << std::endl;
	}
	catch (const std::exception&)
	{
		return "";
	}

	return  str;
}


void Redis::open()
{
	Config_ configSettings("config.txt");
	url = configSettings.Read("Redis.url", url);
	port = configSettings.Read("Redis.port", port);

	c = redisConnect(url.c_str(), port);
	if (c->err) {
		redisFree(c);
		return;
	}
}

void Redis::close()
{
	/*freeReplyObject(r);
	redisFree(c);*/
}


Redis::~Redis()
{
	
}
