namespace Server{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Text;
	using namespace System::Threading;
	using namespace MySql::Data::MySqlClient;

	interface class server{
	public:
		void run();
		void stop();
		void heart_check();
		void doit();
	};
}
namespace Server{
	ref class ServerTemplate:server{
	public:
		//���캯�� ���ö˿� һЩ�����ĳ�ʼ��
		ServerTemplate(String^in)
		{
			portnow=in;
			isstart=0;
			con=1;
			total_connects=0;
			check_num=0;
			curnum=0;
		}
		//�������� ��ȫ�Ľ�������
		~ServerTemplate(){
			try{
				if(myThread->IsAlive){
					Int32 port=Int32::Parse(portnow);
					IPAddress^localAddr=IPAddress::Parse(IP);	
					IPEndPoint^remoteEP=gcnew IPEndPoint(localAddr,port);
					Socket^socketTemp=gcnew Socket(AddressFamily::InterNetwork,SocketType::Stream,ProtocolType::Tcp);
					socketTemp->Connect(remoteEP);	
				}
				myThread->Abort();
				TCP_server->Stop();
				heartcheck_Thread->Abort();
			}
			catch(Exception^){}	
		}
		//ֹͣ���� ��ֹĿǰ�ķ���
		virtual void stop(){
			isstart=0;
			con=0;
			try{
				if(myThread->IsAlive){
					Int32 port=Int32::Parse(portnow);
					IPAddress^localAddr=IPAddress::Parse(IP);	
					IPEndPoint^remoteEP=gcnew IPEndPoint(localAddr,port);
					Socket^socketTemp=gcnew Socket
						(AddressFamily::InterNetwork,SocketType::Stream,ProtocolType::Tcp);//set connection
					socketTemp->Connect(remoteEP);	//connect server
				}	
				Thread::Sleep(500);
			}
			catch(Exception^){}	
			try{
				TCP_server->Stop();
				}
			catch(Exception^){}	
			try{
				myThread->Abort();
			}
			catch(Exception^){}	
			try{
				heartcheck_Thread->Abort();
			}
			catch(Exception^){}	
			
		}
		//��ʼ���� ��ʼ���ڵķ�����������
		virtual void run(){}
		virtual void doit(){}
		//������� �ͷŴ�������
		virtual void heart_check(){
			while(con){
				if(check_num<3){
					if(total_connects==curnum)
						check_num++;
					else{
						curnum=total_connects;
						check_num=0;
					}
				}
				else{
					check_num=0;
					curnum=total_connects;
					try{
						Socket_now->Close();
					}
					catch(Exception^){};
				}
				Thread::Sleep(500);
			}
		}
	public:
		String^portnow;
		Socket^Socket_now;//�������ڴ��������
		Thread^myThread;//����ѭ��ִ�е��߳�
		Thread^heartcheck_Thread;//�����������
		TcpListener^TCP_server;//������������
		Boolean isstart;//�޸�bug��ΰ���
		Boolean con;//�޸�bugϵͳ��������
		int total_connects;//�ܹ�������
		int check_num;//�����ظ�����
		int curnum;//��ǰ������
	};
}
