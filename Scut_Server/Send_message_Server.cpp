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
	lb_send_message->Text=L"启动成功,等待连接";
}

Void Form1::button7_Click(System::Object^  sender, System::EventArgs^  e){
	lb_send_message->Text=L"正在关闭";
	try{
		Send_message_count->Abort();
		obj4->stop();

	}
	catch(Exception^){}
	extern int Send_Message_total;
	Send_Message_total=0;
	lb_send_message->Text=L"发送信息侦听未初始化";
}

void Form1::start_SendMessage_count(){
	extern int Send_Message_total;
	int cur=Send_Message_total;
	while(1){
		Thread::Sleep(200);
		if(Send_Message_total!=cur)
			lb_send_message->Text="新接入接收信息请求("+Send_Message_total+")";
		cur=Send_Message_total;
	}
}