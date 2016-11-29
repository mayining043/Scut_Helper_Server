#include "stdafx.h"
#include "Form1.h"
using namespace Scut_Server;

Void Form1::button14_Click(System::Object^  sender, System::EventArgs^  e){
	if(!obj7->isstart){
		ThreadStart^startRead=gcnew ThreadStart(this,&Form1::trade_server_count);
		Trade_server_count=gcnew Thread(startRead);
		Trade_server_count->Start();
	}
	obj7->run();
	lb_trade->Text=L"启动成功,等待连接";
}

Void Form1::button13_Click(System::Object^  sender, System::EventArgs^  e){
	lb_trade->Text=L"正在关闭";
	try{
		Trade_server_count->Abort();
		obj7->stop();

	}
	catch(Exception^){}
	extern int trade_total;
	trade_total=0;
	lb_trade->Text=L"二手交易侦听未初始化";
}

void Form1::trade_server_count(){
	extern int trade_total;
	int cur=trade_total;
	while(1){
		Thread::Sleep(200);
		if(trade_total!=cur)
			lb_trade->Text="新接入注册请求("+trade_total+")";
		cur=trade_total;
	}
}