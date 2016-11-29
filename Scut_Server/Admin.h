namespace Server{
	using namespace User;
	ref class Admin_Server:ServerTemplate{
	public:
		Admin_Server(String ^in):ServerTemplate(in){}
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
			Int32 port=Int32::Parse(Adminportnum);
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
				extern int admin_server_total;
				++admin_server_total;
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
						else if(out[0]=='A')
							choose=2;
						else if(out[0]=='L')
							choose=3;
						else if(out[0]=='D')
							choose=4;
					}
				}
				catch(Exception^){}
				//连接数据库进行操作
				String^ans="N";
				try{
					if(choose==1)//数据库更新
					{
						_teacher_do^ teach=gcnew _teacher_do;
						if(teach->_changePeople(out))
							ans="Y";
						else
							ans="N";
					}
					if(choose==2)//返回查询结果
					{
						ans=_teacher_do::readall();
					}
					if(choose==3)//登陆
					{
					 try{
						out=out->Substring(1);
						_teacher_do^ teach=gcnew _teacher_do;
						//解码
						
						String^temp;
						int i=1;
						//------------------------------
						//用户名
						temp="";
						while(out[i]!='$')
							temp+=out[i++];
						i++;
						teach->admin_name=temp;
						//------------------------------
						//密码
						temp="";
						while(out[i]!='$')
							temp+=out[i++];
						i++;
						teach->admin_password=temp;
						temp="";

						bool right=0;
						right=teach->checklogin();
						if(right)
							ans="Y";
						else
							ans="N";
					 }
					 catch(Exception^){}
					}
					if(choose==4)//删除
					{
						_teacher_do^ teach=gcnew _teacher_do;
						teach->Set_SchoolId(out->Substring(1,12));
						MessageBox::Show(teach->get_SchoolId());
						if(teach->_deletePeople())
							ans="Y";
						else
							ans="N";
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
