#pragma once
using namespace std;
#include <string>
#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using boost::multiprecision::cpp_dec_float_50;
using boost::long_long_type;
class O
{
public:
	
	O();
	~O();
	/**
	* ����ID
	*/
	void setOrderId(string orderId) 
	{
		O::orderId = orderId;
	}
	/**
	* �������ͣ�buy/sell��
	*/
	void setOrderType(string orderType) 
	{
		O::orderType = orderType;
	}
	/**
	* �����۸�
	*/
	void setPrice(cpp_dec_float_50  price) 
	{
		O::price = price;
	}
	/**
	* ��������
	*/
	void setQuantity(cpp_dec_float_50 quantity) 
	{
		O::quantity = quantity;
	}
	/**
	* ����ͨ�������Ҷԣ�
	*/
	void setSymbol(string symbol)
	{
		O::symbol = symbol;
	}
	/**
	* ����������buy���ᷨ��/sell������۵ıң�
	*/
	void setFreezeAmt(cpp_dec_float_50 freezeAmt)
	{
		O::freezeAmt = freezeAmt;
	}
	/**
	* �û�ID
	*/
	void setUserUuid(string userUuid)
	{
		O::userUuid = userUuid;
	}
	/**
	* �������ͣ��м�/�޼ۣ�
	*/
	void setTradeType(string tradeType)
	{
		O::tradeType = tradeType;
	}
	/**
	* ȡ����־��0:������1:ȡ����
	*/
	void setIsCancel(int isCancel)
	{
		O::isCancel = isCancel;
	}
	/**
	* ��������ʱ��
	*/
	void setTime(string time)
	{
		O::time = time;
	}
	/**
	* ����ID
	*/
	string getOrderId() 
	{
		return orderId;
	}
	/**
	* �������ͣ�buy/sell��
	*/
	string getOrderType() 
	{
		return orderType;
	}
	/**
	* �����۸�
	*/
	cpp_dec_float_50  getPrice() const
	{
		return price;
	}
	/**
	* ��������
	*/
	cpp_dec_float_50 getQantity() 
	{
		return quantity;

	}
	/**
	* ����ͨ�������Ҷԣ�
	*/
	string getSymbol() 
	{
		return symbol;
	}
	/**
	* ����������buy���ᷨ��/sell������۵ıң�
	*/
	cpp_dec_float_50 getFreezeAmt() 
	{
		return freezeAmt;
	}
	/**
	* �û�ID
	*/
	string getUserUuid() 
	{
		return userUuid;
	}
	/**
	* �������ͣ��м�/�޼ۣ�
	*/
	string getTradeType() 
	{
		return tradeType;
	}
	/**
	* ȡ����־��0:������1:ȡ����
	*/
	int getIsCancel() 
	{
		return isCancel;
	}
	/**
	* ��������ʱ��
	*/
	string getTime() const
	{
		return time;
	}
private:
	/**
	* ����ID
	*/
	string orderId;
	/**
	* �������ͣ�buy/sell��
	*/
	string orderType;
	/**
	* �����۸�
	*/
	cpp_dec_float_50  price;
	/**
	* ��������
	*/
	cpp_dec_float_50 quantity;
	/**
	* ����ͨ�������Ҷԣ�
	*/
	string symbol;
	/**
	* ����������buy���ᷨ��/sell������۵ıң�
	*/
	cpp_dec_float_50 freezeAmt;
	/**
	* �û�ID
	*/
	string userUuid;
	/**
	* �������ͣ��м�/�޼ۣ�
	*/
	string tradeType;
	/**
	* ȡ����־��0:������1:ȡ����
	*/
	int isCancel;
	/**
	* ��������ʱ��
	*/
	string time;
	
};

