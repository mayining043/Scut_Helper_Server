// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
#pragma once
#define _AFXDLL
//���ݿ��û�����
#define sqlusn "root"
#define sqlpsw "894841535"
//������IP��ַ
//#define IP "125.216.245.7"
//#define IP "125.216.245.5"
//#define IP "182.61.54.89"
//#define IP "119.29.118.241"
//#define IP "10.0.0.2"
//#define IP "172.16.0.2"
#define IP "127.0.0.1"
//#define IP "192.168.43.50"
//�������˿�
#define Loginportnum "4869"
#define Registerportnum "4870"
#define GetMessageportnum "4871"
#define SendMessageportnum "4872"
#define ChangePeopleportnum "4873"
#define Cardportnum "4874"
#define Tradeportnum "4875"
#define Adminportnum "4876"

//���õ�ͷ�ļ�
//#include <iostream>
//#include <Windows.h>
//�Զ�����Ҫͷ�ļ�
#include "Socket.h"
#include "People.h"
#include "Message.h"
#include "Card.h"
#include "Exchange.h"
#include "ServerBase.h"
//����ͷ�ļ�

#include "Login.h"
#include "Regist.h"
#include "Get_message.h"
#include "Send_message.h"
#include "Change_People.h"
#include "CardServer.h"
#include "TradeServer.h"
#include "Admin.h"
//����ͷ�ļ�
#include "Form1.h"
int login_total;
int register_total;
int Get_Message_total;
int Send_Message_total;
int Change_People_total;
int card_total;
int trade_total;
int admin_server_total;

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�