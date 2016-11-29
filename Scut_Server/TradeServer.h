namespace Server{
	using namespace User;
	using namespace Exchange;
	ref class Card_server:ServerTemplate{
	public:
		Card_server(String ^in):ServerTemplate(in){}
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
			Int32 port=Int32::Parse(Tradeportnum);
			IPAddress^localAddr=IPAddress::Parse(IP);	
			TCP_server=gcnew TcpListener(localAddr,port);
			//启动协议
			try{
				TCP_server->Start();
			}
			catch(Exception^){}
			//连接Scoket

			while(con){
				//连接请求
				Socket_now=TCP_server->AcceptSocket();	
				++total_connects;
				extern int trade_total;
				++trade_total;
				int choose;
				//接收新信息
				String^out;
				array<Byte>^buffer=gcnew array<Byte>(102400);	//Receive buffer
				try{
					int byteCount=Socket_now->Receive(buffer);
					out=Encoding::UTF8->GetString(buffer);	//encoding
					if(byteCount>0){
						if(out[0]=='$')
							choose=1;
	
						else
							choose=2;
					}
				}
				catch(Exception^){}
				//连接数据库进行操作
				String^ans="N";
				try{
					if(choose==1)//添加二手交易
					{
						trade ^o=gcnew trade;
						o->decode(out);
						bool t=o->write();
						if(t)
							ans="Y";
						else
							ans="N";
					}
					
					if(choose==2)//返回所有信息
					{
						ans=trade::readall();
					}
				}
				catch(Exception^e){
					MessageBox::Show(e->ToString());
				}
				//回复写入成功与否
				try{
					array<Byte>^buffer;
					buffer=Encoding::UTF8->GetBytes(ans);
					Socket_now->Send(buffer);
				}
				catch(Exception^){}
				Thread::Sleep(500);
			}
		}
	};
}
