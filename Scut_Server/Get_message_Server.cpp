#include "stdafx.h"
#include "Form1.h"
using namespace Scut_Server;


Void Form1::button6_Click(System::Object^  sender, System::EventArgs^  e){

	if(!obj3->isstart){
		ThreadStart^startRead=gcnew ThreadStart(this,&Form1::start_GetMessage_count);
		Get_message_count=gcnew Thread(startRead);
		Get_message_count->Start();
	}
	obj3->run();
	lb_get_message->Text=L"�����ɹ�,�ȴ�����";
}

Void Form1::button5_Click(System::Object^  sender, System::EventArgs^  e){
	lb_get_message->Text=L"���ڹر�";
	try{
		Get_message_count->Abort();
		obj3->stop();

	}
	catch(Exception^){}
	extern int Get_Message_total;
	Get_Message_total=0;
	lb_get_message->Text=L"������Ϣ����δ��ʼ��";
}

void Form1::start_GetMessage_count(){
	extern int Get_Message_total;
	int cur=Get_Message_total;
	while(1){
		Thread::Sleep(200);
		if(Get_Message_total!=cur)
			lb_get_message->Text="�½��������Ϣ����("+Get_Message_total+")";
		cur=Get_Message_total;
	}
}