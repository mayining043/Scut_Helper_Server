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
	lb_regist->Text=L"�����ɹ�,�ȴ�����";
}

Void Form1::button4_Click(System::Object^  sender, System::EventArgs^  e){
	lb_regist->Text=L"���ڹر�";
	try{
		register_count->Abort();
		obj2->stop();

	}
	catch(Exception^){}
	extern int register_total;
	register_total=0;
	lb_regist->Text=L"ע������δ��ʼ��";
}

void Form1::start_Register_count(){
	extern int register_total;
	int cur=register_total;
	while(1){
		Thread::Sleep(200);
		if(register_total!=cur)
			lb_regist->Text="�½���ע������("+register_total+")";
		cur=register_total;
	}
}