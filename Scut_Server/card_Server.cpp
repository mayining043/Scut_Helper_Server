#include "stdafx.h"
#include "Form1.h"
using namespace Scut_Server;

Void Form1::button12_Click(System::Object^  sender, System::EventArgs^  e){
	if(!obj6->isstart){
		ThreadStart^startRead=gcnew ThreadStart(this,&Form1::card_server_count);
		 Card_server_count=gcnew Thread(startRead);
		 Card_server_count->Start();
	}
	obj6->run();
	lb_card->Text=L"�����ɹ�,�ȴ�����";
}

Void Form1::button11_Click(System::Object^  sender, System::EventArgs^  e){
	lb_card->Text=L"���ڹر�";
	try{
		 Card_server_count->Abort();
		 obj6->stop();

	}
	catch(Exception^){}
	extern int card_total;
	card_total=0;
	lb_card->Text=L"һ��ͨ����δ��ʼ��";
}

void Form1::card_server_count(){
	extern int card_total;
	int cur=card_total;
	while(1){
		Thread::Sleep(200);
		if(card_total!=cur)
			lb_card->Text="�½���ע������("+card_total+")";
		cur=card_total;
	}
}