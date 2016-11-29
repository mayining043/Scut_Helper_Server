#include "stdafx.h"
#include "Form1.h"
using namespace Scut_Server;


Void Form1::button1_Click(System::Object^  sender, System::EventArgs^  e){
	
	if(!obj1->isstart){
		ThreadStart^startRead=gcnew ThreadStart(this,&Form1::start_Login_count);
		login_count=gcnew Thread(startRead);
		login_count->Start();
	}
	obj1->run();
	lb_Login->Text=L"启动成功,等待连接";
}

Void Form1::button2_Click(System::Object^  sender, System::EventArgs^  e){
	lb_Login->Text=L"正在关闭";
	try{
		login_count->Abort();
		obj1->stop();

	}
	catch(Exception^){}
	extern int login_total;
	login_total=0;
	lb_Login->Text=L"登陆侦听未初始化";
}

void Form1::start_Login_count(){
	extern int login_total;
	int cur=login_total;
	while(1){
		Thread::Sleep(200);
		if(login_total!=cur)
			lb_Login->Text="新接入登录请求("+login_total+")";
		cur=login_total;
	}
}