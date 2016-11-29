#include "stdafx.h"
#include "Form1.h"
using namespace Scut_Server;

Void Form1::button16_Click(System::Object^  sender, System::EventArgs^  e){
	if(!obj8->isstart){
		ThreadStart^startRead=gcnew ThreadStart(this,&Form1::admin_server_count);
		Admin_server_count=gcnew Thread(startRead);
		Admin_server_count->Start();
	}
	obj8->run();
	lb_admin->Text=L"启动成功,等待连接";
}

Void Form1::button15_Click(System::Object^  sender, System::EventArgs^  e){
	lb_admin->Text=L"正在关闭";
	try{
		Admin_server_count->Abort();
		obj8->stop();

	}
	catch(Exception^){}
	extern int admin_server_total;
	admin_server_total=0;
	lb_admin->Text=L"管理员侦听未初始化";
}

void Form1::admin_server_count(){
	extern int admin_server_total;
	int cur=admin_server_total;
	while(1){
		Thread::Sleep(200);
		if(admin_server_total!=cur)
			lb_admin->Text="新接入注册请求("+admin_server_total+")";
		cur=admin_server_total;
	}
}