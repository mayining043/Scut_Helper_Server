#include "stdafx.h"
#include "Form1.h"
using namespace Scut_Server;

Void Form1::button10_Click(System::Object^  sender, System::EventArgs^  e){
	if(!obj5->isstart){
		ThreadStart^startRead=gcnew ThreadStart(this,&Form1::Change_People_count);
		ChangePeople_count=gcnew Thread(startRead);
		ChangePeople_count->Start();
	}
	obj5->run();
	lb_ChangePeople->Text=L"�����ɹ�,�ȴ�����";
}

Void Form1::button9_Click(System::Object^  sender, System::EventArgs^  e){
	lb_ChangePeople->Text=L"���ڹر�";
	try{
		ChangePeople_count->Abort();
		obj5->stop();

	}
	catch(Exception^){}
	extern int Change_People_total;
	Change_People_total=0;
	lb_ChangePeople->Text=L"������Ϣ����δ��ʼ��";
}

void Form1::Change_People_count(){
	extern int Change_People_total;
	int cur=Change_People_total;
	while(1){
		Thread::Sleep(200);
		if(Change_People_total!=cur)
			lb_ChangePeople->Text="�½���ע������("+Change_People_total+")";
		cur=Change_People_total;
	}
}