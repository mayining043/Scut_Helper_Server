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
		//构造函数 设置端口 一些变量的初始化
		ServerTemplate(String^in)
		{
			portnow=in;
			isstart=0;
			con=1;
			total_connects=0;
			check_num=0;
			curnum=0;
		}
		//析构函数 安全的结束阻塞
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
		//停止按键 终止目前的服务
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
		//开始按键 开始现在的服务和心跳检测
		virtual void run(){}
		virtual void doit(){}
		//心跳检测 释放错误链接
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
		Socket^Socket_now;//用于正在处理的请求
		Thread^myThread;//用于循环执行的线程
		Thread^heartcheck_Thread;//用于心跳检测
		TcpListener^TCP_server;//用于启动监听
		Boolean isstart;//修改bug多次按键
		Boolean con;//修改bug系统残留进程
		int total_connects;//总共连接数
		int check_num;//连接重复次数
		int curnum;//当前连接数
	};
}
