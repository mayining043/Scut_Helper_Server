#include "stdafx.h"
#include "Form1.h"
using namespace Scut_Server;


Void Form1::button8_Click(System::Object^  sender, System::EventArgs^  e){

	if(!obj4->isstart){
		ThreadStart^startRead=gcnew ThreadStart(this,&Form1::start_SendMessage_count);
		Send_message_count=gcnew Thread(startRead);
		Send_message_count->Start();
	}
	obj4->run();
	lb_send_message->Text=L"�����ɹ�,�ȴ�����";
}

Void Form1::button7_Click(System::Object^  sender, System::EventArgs^  e){
	lb_send_message->Text=L"���ڹر�";
	try{
		Send_message_count->Abort();
		obj4->stop();

	}
	catch(Exception^){}
	extern int Send_Message_total;
	Send_Message_total=0;
	lb_send_message->Text=L"������Ϣ����δ��ʼ��";
}

void Form1::start_SendMessage_count(){
	extern int Send_Message_total;
	int cur=Send_Message_total;
	while(1){
		Thread::Sleep(200);
		if(Send_Message_total!=cur)
			lb_send_message->Text="�½��������Ϣ����("+Send_Message_total+")";
		cur=Send_Message_total;
	}
}