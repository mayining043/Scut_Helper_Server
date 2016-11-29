namespace Server{
	using namespace User;
	ref class Send_message:ServerTemplate{
	public:
		Send_message(String ^in):ServerTemplate(in){}
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
			Int32 port=Int32::Parse(SendMessageportnum);
			IPAddress^localAddr=IPAddress::Parse(IP);	
			TCP_server=gcnew TcpListener(localAddr,port);
			//启动协议
			try{
				TCP_server->Start();
			}
			catch(Exception^){}
			//连接Scoket

			while(con){
				int a;
				//实例化新消息
				_chat_message_do ^newmsg=gcnew _chat_message_do();
				_news_message_do ^newmsg2=gcnew _news_message_do();
				//连接请求
				Socket_now=TCP_server->AcceptSocket();	
				++total_connects;
				extern int Send_Message_total;
				++Send_Message_total;
				String^ ok="N";
				//接收新信息
				String^out="";
				String^temp="";
				array<Byte>^buffer=gcnew array<Byte>(102400);	//Receive buffer
				try{
					int byteCount=Socket_now->Receive(buffer);
					temp=Encoding::UTF8->GetString(buffer);	//encoding
					//解码
					if(byteCount>0&&temp->Length>0&&temp[0]=='$'){
						int i=1;
						while(temp[i]!='$')
							out+=temp[i++];
						a=1;
					}
					if(byteCount>0&&temp->Length>0&&temp[0]=='*'){
						int i=1;
						while(temp[i]!='$')
							out+=temp[i++];
						a=2;
					}
				}
				catch(Exception^){}
				
				//连接数据库进行寻找
				try{
					if(!out->Equals("")){
						if(a==1)
						ok=newmsg->read(out);
						if(a==2)
						ok=newmsg2->read(out);
					}
					
					else
						ok="N";
				}
				catch(Exception^e){
					MessageBox::Show(e->ToString());
					ok="N";
				}
				//MessageBox::Show("out:"+out+"ok:"+ok+"*");
				//回复消息
				//MessageBox::Show(ok);
				try{
					array<Byte>^buffer;
				
					buffer=Encoding::UTF8->GetBytes(ok);
	
					Socket_now->Send(buffer);
				}
				catch(Exception^){}
				Thread::Sleep(500);
			}
		}
	};
}
