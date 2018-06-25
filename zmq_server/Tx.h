#pragma once
#include <string>
using namespace std;
#include <boost/multiprecision/cpp_dec_float.hpp>
using boost::multiprecision::cpp_dec_float_50;
using boost::long_long_type;
class Tx
{
public:
	Tx();
	~Tx();
	//set
	void setCancelOrderId(string cancelOrderId)
	{
		Tx::cancelOrderId = cancelOrderId;
	}
	void setCancelRemainAmt(cpp_dec_float_50 cancelRemainAmt)
	{
		Tx::cancelRemainAmt = cancelRemainAmt;
	}
	void setTxType(string txType)
	{
		Tx::txType = txType;
	}
	void setBuyOrderId(string buyOrderId)
	{
		Tx::buyOrderId = buyOrderId;
	}
	void setSellOrderId(string sellOrderId)
	{
		Tx::sellOrderId = sellOrderId;
	}
	void setSellRemainAmt(cpp_dec_float_50 sellRemainAmt)
	{
		Tx::sellRemainAmt = sellRemainAmt;
	}
	void setBuyRemainAmt(cpp_dec_float_50 buyRemainAmt)
	{
		Tx::buyRemainAmt = buyRemainAmt;
	}
	void setDealVolumePrice(cpp_dec_float_50 dealVolumePrice)
	{
		Tx::dealVolumePrice = dealVolumePrice;
	}
	void setDealPrice(cpp_dec_float_50 dealPrice)
	{
		Tx::dealPrice = dealPrice;
	}
	void setDealQuantity(cpp_dec_float_50 dealQuantity)
	{
		Tx::dealQuantity = dealQuantity;
	}
	void setBuyUserId(string buyUserId)
	{
		Tx::buyUserId = buyUserId;
	}
	void setSellUserId(string sellUserId)
	{
		Tx::sellUserId = sellUserId;
	}
	void setCancelUserId(string cancelUserId)
	{
		Tx::cancelUserId = cancelUserId;
	}

	//get
	string getCancelOrderId()
	{
		return cancelOrderId;
	}
	cpp_dec_float_50 getCancelRemainAmt()
	{
		return cancelRemainAmt;
	}
	string getTxType()
	{
		return txType;
	}
	string getBuyOrderId()
	{
		return buyOrderId;
	}
	string getSellOrderId()
	{
		return sellOrderId;
	}
	cpp_dec_float_50 getSellRemainAmt()
	{
		return sellRemainAmt;
	}
	cpp_dec_float_50 getBuyRemainAmt()
	{
		return buyRemainAmt;
	}
	cpp_dec_float_50 getDealVolumePrice()
	{
		return dealVolumePrice;
	}
	cpp_dec_float_50 getDealPrice()
	{
		return dealPrice;
	}
	cpp_dec_float_50 getDealQuantity()
	{
		return dealQuantity;
	}
	string getBuyUserId()
	{
		return buyUserId;
	}
	string getSellUserId()
	{
		return sellUserId;
	}
	string getCancelUserId()
	{
		return cancelUserId;
	}

private:
	// ����id
	string cancelOrderId;
	// ������ʣ��Ķ����� (��������)
	cpp_dec_float_50 cancelRemainAmt;
	// �������� buy ��sell��cancel
	string txType;
	// ��id
	string buyOrderId;
	// ����id
	string sellOrderId;
	// ����ʣ�ඳ����
	cpp_dec_float_50 sellRemainAmt;
	// ��ʣ�ඳ����
	cpp_dec_float_50 buyRemainAmt;
	// �ɽ���
	cpp_dec_float_50 dealVolumePrice;
	// �ɽ���
	cpp_dec_float_50 dealPrice;
	// �ɽ���
	cpp_dec_float_50 dealQuantity;
	// ���uuid�������ǳ������ǹҵ�
	string buyUserId;
	// ����uuid�������ǳ������ǹҵ�
	string sellUserId;
	// �������û���uid
	string cancelUserId;
};

