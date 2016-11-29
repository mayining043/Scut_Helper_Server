namespace Server{
	using namespace User;
	ref class Login:ServerTemplate{
	public:
		Login(String ^in):ServerTemplate(in){}
		virtual void run()override{
			if(isstart)
				return;
			try{
				con=1;
				check_num=0;
				curnum=0;
				ThreadStart^startRead=gcnew ThreadStart(this,&Server::server::heart_check);
				myThread=gcnew Thread(startRead);
				myThread->Start();
				ThreadStart^startRead2=gcnew ThreadStart(this,&Server::server::doit);
				heartcheck_Thread=gcnew Thread(startRead2);
				heartcheck_Thread->Start();
				isstart=1;
			}
			catch(Exception^){}
		}
		virtual void doit()override{
			//set ip
			Int32 port=Int32::Parse(Loginportnum);
			IPAddress^localAddr=IPAddress::Parse(IP);	
			TCP_server=gcnew TcpListener(localAddr,port);
			//启动协议
			try{
				TCP_server->Start();
			}
			catch(Exception^){}
			//连接Scoket
			int i=0;
			while(con){
				Socket_now=TCP_server->AcceptSocket();	
				++total_connects;
				extern int login_total;
				++login_total;
				Boolean ok=0;
				//接收登陆信息
				String^name="";
				String^password="";
				array<Byte>^buffer=gcnew array<Byte>(256);	//Receive buffer
				try{
					int byteCount=Socket_now->Receive(buffer);
					String^out=Encoding::UTF8->GetString(buffer);	//encoding
					if(byteCount>0){
						int i=1;
						if(out->Length>0&&out[0]=='$')
							while(out[i]!='$')
								name+=out[i++];
						i++;
						while(out[i]!='$')
							password+=out[i++];
					}
				}
				catch(Exception^){}
				//检查数据库是否可以登录
				_student_do^ a=gcnew _student_do();
				a->Set_Password(password);
				a->Set_SchoolId(name);
				ok=a->checklogin();
				//回复是否可以登录
				try{
					array<Byte>^buffer;
					if(ok)
						buffer=Encoding::UTF8->GetBytes("Y");
					else
						buffer=Encoding::UTF8->GetBytes("N");
					Socket_now->Send(buffer);
				}
				catch(Exception^){}
				Thread::Sleep(500);
			}
		}
	};
}
		