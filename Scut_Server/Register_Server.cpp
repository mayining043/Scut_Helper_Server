#include "stdafx.h"
#include "Form1.h"
using namespace Scut_Server;


Void Form1::button3_Click(System::Object^  sender, System::EventArgs^  e){
	if(!obj2->isstart){
		ThreadStart^startRead=gcnew ThreadStart(this,&Form1::start_Register_count);
		register_count=gcnew Thread(startRead);
		register_count->Start();
	}
	obj2->run();
	lb_regist->Text=L"启动成功,等待连接";
}

Void Form1::button4_Click(System::Object^  sender, System::EventArgs^  e){
	lb_regist->Text=L"正在关闭";
	try{
		register_count->Abort();
		obj2->stop();

	}
	catch(Exception^){}
	extern int register_total;
	register_total=0;
	lb_regist->Text=L"注册侦听未初始化";
}

void Form1::start_Register_count(){
	extern int register_total;
	int cur=register_total;
	while(1){
		Thread::Sleep(200);
		if(register_total!=cur)
			lb_regist->Text="新接入注册请求("+register_total+")";
		cur=register_total;
	}
}