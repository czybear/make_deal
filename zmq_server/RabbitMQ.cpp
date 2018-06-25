#include "RabbitMQ.h"


RabbitMQ::RabbitMQ()
{
}


RabbitMQ::~RabbitMQ()
{
	
}
bool RabbitMQ::send(Tx tx)
{
	amqp_connection_state_t conn=NULL;
	//��url����½
	login(conn);
	//������
	open(conn);
	char const *exchange ="";/*�����ֵ����ֵ��ʹbindingkeyʧЧ�� */
		
		//��ʼ����Ϣ��
		new_root = TxtoJSON(tx);
		//������Ϣ
		amqp_basic_publish(conn, 1,
			amqp_cstring_bytes(""),
			amqp_cstring_bytes(bindingkey.c_str()),
			0, 0, NULL,
			amqp_cstring_bytes(new_root.c_str()));
		//������ϢEND

		//�ر�����
		close(conn);
	//RMQ_END
	return false;
}

string RabbitMQ::TxtoJSON(Tx tx)
{
	(!tx.getBuyOrderId().empty()) ? (new_item["buyOrderId"] = tx.getBuyOrderId()) :"";

	(!tx.getTxType().empty()) ? (new_item["txType"] = tx.getTxType()) : "";

	(!tx.getSellOrderId().empty()) ? (new_item["sellOrderId"] = tx.getSellOrderId()) : "";
	
	(!tx.getBuyRemainAmt().str().empty()) ? (new_item["buyRemainAmt"] = tx.getBuyRemainAmt().str()) : "";

	(!tx.getDealVolumePrice().str().empty()) ? (new_item["dealVolumePrice"] = tx.getDealVolumePrice().str()) : "";

	(!tx.getDealPrice().str().empty()) ? (new_item["dealPrice"] = tx.getDealPrice().str()) : "";

	(!tx.getDealQuantity().str().empty()) ? (new_item["dealQuantity"] = tx.getDealQuantity().str()) : "";

	(!tx.getSellUserId().empty()) ? (new_item["sellUserId"] = tx.getSellUserId()) : "";

	(!tx.getBuyUserId().empty()) ? (new_item["buyUserId"] = tx.getBuyUserId()) : "";

	(!tx.getSellRemainAmt().str().empty()) ? (new_item["sellRemainAmt"] = tx.getSellRemainAmt().str()) : "";

	(!tx.getCancelUserId().empty()) ? (new_item["cancelUserId"] = tx.getCancelUserId()) : "";

	(!tx.getCancelOrderId().empty()) ? (new_item["cancelOrderId"] = tx.getCancelOrderId()) : "";

	(!tx.getCancelRemainAmt().str().empty()) ? (new_item["cancelRemainAmt"] = tx.getCancelRemainAmt().str()) : "";

	//new_item["txType"] = txType;
	
	//new_item["sellOrderId"] = sell.getOrderId();
	//new_item["buyRemainAmt"] = buyRemainAmt.str();
	//new_item["dealVolumePrice"] = dealVolumePrice.str();
	//new_item["dealPrice"] = dealPrice.str();
	//new_item["dealQuantity"] = dealQuantity.str();
	//new_item["buyUserUuid"] = buy.getUserUuid();
	//new_item["sellUserUuid"] = sell.getUserUuid();
	return new_item.toStyledString();
}

void RabbitMQ::open(amqp_connection_state_t& conn)
{
	//������
	amqp_channel_open(conn, 1);
	amqp_get_rpc_reply(conn);
}

void RabbitMQ::login(amqp_connection_state_t& conn)
{
	Config_ configSettings("config.txt");
	string name;
	string pwd;
	hostname = configSettings.Read("RMQ.hostname", hostname);
	bindingkey = configSettings.Read("RMQ.bindingkey", bindingkey);
	port = configSettings.Read("RMQ.port", port);
	name = configSettings.Read("RMQ.name", name);
	pwd = configSettings.Read("RMQ.pwd", pwd);

	//RMQ
	conn = amqp_new_connection();
	socket_qmqp = amqp_tcp_socket_new(conn);
	status = amqp_socket_open(socket_qmqp, hostname.c_str(), port);
	amqp_login(conn, "/", 0, 131072, 0, AMQP_SASL_METHOD_PLAIN, name, pwd);//��¼
}

void RabbitMQ::close(amqp_connection_state_t& conn)
{
	amqp_channel_close(conn, 1, AMQP_REPLY_SUCCESS);
	amqp_connection_close(conn, AMQP_REPLY_SUCCESS);
	amqp_destroy_connection(conn);
}
