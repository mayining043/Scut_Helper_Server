namespace Server{
	using namespace User;
	ref class Regist:ServerTemplate{
	public:
		Regist(String ^in):ServerTemplate(in){}
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
			Int32 port=Int32::Parse(Registerportnum);
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
				_student_do^ stu=gcnew _student_do();
				Socket_now=TCP_server->AcceptSocket();	
				++total_connects;
				extern int register_total;
				++register_total;
				Boolean ok=0;
				//接收注册信息
				array<Byte>^buffer=gcnew array<Byte>(102400);	//Receive buffer
				try{
					int byteCount=Socket_now->Receive(buffer);
					String^out=Encoding::UTF8->GetString(buffer);	//encoding
					//MessageBox::Show(out);
					if(byteCount>0)
						if(out->Length>0&&out[0]=='$')
							stu->decode(out);
				}
				catch(Exception^){
					//MessageBox::Show(e->ToString());
				}
				//连接数据库进行注册
				try{
					ok=stu->regist();
				}
				catch(Exception^e){
					MessageBox::Show(e->ToString());
					ok=0;
				}
				//回复注册成功与否
				try{
					array<Byte>^buffer;
					if(ok)
						buffer=Encoding::UTF8->GetBytes("Y");
					else
						buffer=Encoding::UTF8->GetBytes("N");
					Socket_now->Send(buffer);
				}
				catch(Exception^){}
				Thread::Sleep(1500);
			}
		}
	};
}
