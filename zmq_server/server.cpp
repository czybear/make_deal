#include <iostream>
#include <process.h>
#include <thread> 
#include <stdio.h>
#include "zmq.h"
#include "zmq_utils.h"
#pragma comment(lib,"libzmq-v120-mt-4_0_4.lib")
#pragma comment(lib,"lib/json_vc71_libmt.lib")
#include "json/json.h"
#include "O.h"
#include "TradeCode.h"
#include "amqp_tcp_socket.h"  
#include "amqp.h"  
#include "amqp_framing.h" 
#include "OrderTradeThread.h"
#include "RemoveOrderTradeThread.h"

using boost::multiprecision::cpp_dec_float_50;
using namespace Json;
using namespace std;

static TradeCode TC;
void addOrder();
void addOrder();
void sellRevoke();
void buyRevoke();
void remakeOrder();
//void PrintfNode(O o);
OrderTradeThread OTT;
RemoveOrderTradeThread ROTT;
enum Type
{
	nullValue = 0, ///< 'null' value  
	intValue,      ///< signed integer value  
	uintValue,     ///< unsigned integer value  
	realValue,     ///< double value  
	stringValue,   ///< UTF-8 string value  
	booleanValue,  ///< bool value  
	arrayValue,    ///< array value (ordered list)  
	objectValue    ///< object value (collection of name/value pairs).  
};
int main()
{
	Redis* red((redis.getObj()).get());
	Redis redis_ = *red;
	system("pause");
	cout << "" << endl;
	InitializeCriticalSection(&sellQuene_CS);
	InitializeCriticalSection(&buyQuene_CS);
	InitializeCriticalSection(&removeSellQuene_CS);
	InitializeCriticalSection(&removeBuyQuene_CS);
	InitializeCriticalSection(&RabbitMQ_Send_CS);

	ToJson<BuyQuene> toJson_buyQuene;
	ToJson<SellQuene> toJson_sellQuene;
	ToJson<BuyQuene> toJson_removeBuyQuene;
	ToJson<SellQuene> toJson_removeSellQuene;
	redis_.open();

	EnterCriticalSection(&sellQuene_CS);
	EnterCriticalSection(&buyQuene_CS);
	EnterCriticalSection(&removeSellQuene_CS);
	EnterCriticalSection(&removeBuyQuene_CS);

	removeBuyQuene = toJson_removeBuyQuene.JsonObject(redis_.getRedis("removeBuyQuene"));//�����ݴ�redis����
	toJson_removeBuyQuene.~ToJson();

	redis_.open();
	removeSellQuene = toJson_removeSellQuene.JsonObject(redis_.getRedis("removeSellQuene"));
	toJson_removeSellQuene.~ToJson();

	redis_.open();
	buyQuene = toJson_buyQuene.JsonObject(redis_.getRedis("buyQuene"));
	toJson_buyQuene.~ToJson();

	redis_.open();
	sellQuene = toJson_sellQuene.JsonObject(redis_.getRedis("sellQuene"));
	toJson_sellQuene.~ToJson();

	LeaveCriticalSection(&sellQuene_CS);
	LeaveCriticalSection(&buyQuene_CS);
	LeaveCriticalSection(&removeSellQuene_CS);
	LeaveCriticalSection(&removeBuyQuene_CS);

	thread addOrder(addOrder), remakeOrder(remakeOrder), sellRevokeThreda(sellRevoke), buyRevokeThreda(buyRevoke);
	//HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, addOrder, 0, 0, NULL);
	//���ģ���ϣ�
	while (true)
	{
		TC.core();
		//Sleep(1);
	}
	//while (!buyQuene.empty()) {
		//OTT.PrintfNode(buyQuene.top());
		//buyQuene.pop();
	//}
	//WaitForSingleObject(hThread, INFINITE);
	return 1;
}
/*
�ҵ������߳�
*/
void addOrder() 
{
	OTT.addOrder();
}
/*
���������߳�
*/
void  remakeOrder()
{
	ROTT.remakeOrder();
}
/*
sell�������ķ���
*/
void sellRevoke()
{
	while (true)
	{

		if (!removeSellQuene.empty())
		{
			if (removeSellQuene.size() < 5)
			{
				Sleep(10);
			}
			EnterCriticalSection(&sellQuene_CS);
			TC.remaveSell(sellQuene);//���ó���������
			LeaveCriticalSection(&sellQuene_CS);
		}
		else
		{
			Sleep(1000);
		}
	}
}
/*
buy�������ķ���
*/
void buyRevoke()
{
	while (true)
	{

		if (!removeBuyQuene.empty())
		{
			if (removeBuyQuene.size() < 5)
			{
				Sleep(10);
			}
			EnterCriticalSection(&buyQuene_CS);
			TC.remaveBuy(buyQuene);//���ó��򵥷���
			LeaveCriticalSection(&buyQuene_CS);
		}
		else
		{
			//buyRevokeThreda.~thread
			Sleep(1000);
		}

	}
}