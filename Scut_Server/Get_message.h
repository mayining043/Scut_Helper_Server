namespace Server{
	using namespace User;
	ref class Get_message:ServerTemplate{
	public:
		Get_message(String ^in):ServerTemplate(in){}
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
			Int32 port=Int32::Parse(GetMessageportnum);
			IPAddress^localAddr=IPAddress::Parse(IP);	
			TCP_server=gcnew TcpListener(localAddr,port);
			//启动协议
			try{
				TCP_server->Start();
			}
			catch(Exception^){}
			//连接Scoket
			
			while(con){
				//实例化新消息
				_chat_message_do ^newmsg=gcnew _chat_message_do();
				//连接请求
				Socket_now=TCP_server->AcceptSocket();	
				++total_connects;
				extern int Get_Message_total;
				++Get_Message_total;
				Boolean ok=0;
				//接收新信息
				array<Byte>^buffer=gcnew array<Byte>(102400);	//Receive buffer
				try{
					int byteCount=Socket_now->Receive(buffer);
					String^out=Encoding::UTF8->GetString(buffer);	//encoding
					if(byteCount>0){
						newmsg->decode(out);
					}
				}
				catch(Exception^){}
				//连接数据库进行写入
				try{
					ok=newmsg->write();
				}
				catch(Exception^e){
					MessageBox::Show(e->ToString());
					ok=0;
				}
				//回复写入成功与否
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
