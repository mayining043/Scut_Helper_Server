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
	lb_admin->Text=L"�����ɹ�,�ȴ�����";
}

Void Form1::button15_Click(System::Object^  sender, System::EventArgs^  e){
	lb_admin->Text=L"���ڹر�";
	try{
		Admin_server_count->Abort();
		obj8->stop();

	}
	catch(Exception^){}
	extern int admin_server_total;
	admin_server_total=0;
	lb_admin->Text=L"����Ա����δ��ʼ��";
}

void Form1::admin_server_count(){
	extern int admin_server_total;
	int cur=admin_server_total;
	while(1){
		Thread::Sleep(200);
		if(admin_server_total!=cur)
			lb_admin->Text="�½���ע������("+admin_server_total+")";
		cur=admin_server_total;
	}
}