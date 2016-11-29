#pragma once

namespace Scut_Server {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Server;
	using namespace Threading;
	using namespace User;
	using namespace Card;

	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			open=0;
			//初始化登陆
			extern int login_total;
			login_total=0;
			obj1=gcnew Login(Loginportnum);
			//初始化注册
			extern int register_total;
			register_total=0;
			obj2=gcnew Regist(Registerportnum);
			//初始化获取信息
			extern int Get_Message_total;
			Get_Message_total=0;
			obj3=gcnew Get_message(GetMessageportnum);
			//初始化发送信息
			extern int Send_Message_total;
			Send_Message_total=0;
			obj4=gcnew Send_message(SendMessageportnum);
			//修改people
			extern int Change_People_total;
			Change_People_total=0;
			obj5=gcnew Change_People(ChangePeopleportnum);
			//一卡通
			extern int card_total;
			card_total=0;
			obj6=gcnew Card_server(Cardportnum);
			//二手交易
			extern int trade_total;
			trade_total=0;
			obj7=gcnew Trade_server(Tradeportnum);
			//管理员
			extern int admin_server_total;
			admin_server_total=0;
			obj8=gcnew Admin_Server(Adminportnum);
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
			this->Hide();
			try{
				obj1->stop();
				login_count->Abort();
				obj2->stop();
				register_count->Abort();
				obj3->stop();
				Get_message_count->Abort();
				obj4->stop();
				Send_message_count->Abort();
				obj5->stop();
				ChangePeople_count->Abort();
				obj6->stop();
				Card_server_count->Abort();
				obj7->stop();
				Trade_server_count->Abort();
				obj8->stop();
				Admin_server_count->Abort();
			}
			catch(Exception^){}
			//std::system("taskkill /f /t /im Scut_Helper_Server.exe");
		}
	private: System::Windows::Forms::GroupBox^  _groupBoxLogin;
	private: System::Windows::Forms::Label^  lb_Login;
	protected: 

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  lb_regist;

	private: System::Windows::Forms::Button^  button4;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  lb_get_message;

	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  lb_send_message;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Label^  lb_ChangePeople;

	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::Label^  lb_card;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  bt_open;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::Label^  lb_trade;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
private: System::Windows::Forms::GroupBox^  groupBox7;
private: System::Windows::Forms::Label^  lb_admin;
private: System::Windows::Forms::Button^  button15;
private: System::Windows::Forms::Button^  button16;









	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->_groupBoxLogin = (gcnew System::Windows::Forms::GroupBox());
			this->lb_Login = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lb_regist = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->lb_get_message = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->lb_send_message = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->lb_ChangePeople = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->lb_card = (gcnew System::Windows::Forms::Label());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->bt_open = (gcnew System::Windows::Forms::Button());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->lb_trade = (gcnew System::Windows::Forms::Label());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->lb_admin = (gcnew System::Windows::Forms::Label());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->_groupBoxLogin->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->SuspendLayout();
			// 
			// _groupBoxLogin
			// 
			this->_groupBoxLogin->BackColor = System::Drawing::Color::Transparent;
			this->_groupBoxLogin->Controls->Add(this->lb_Login);
			this->_groupBoxLogin->Controls->Add(this->button2);
			this->_groupBoxLogin->Controls->Add(this->button1);
			this->_groupBoxLogin->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->_groupBoxLogin->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->_groupBoxLogin->Location = System::Drawing::Point(115, 96);
			this->_groupBoxLogin->Name = L"_groupBoxLogin";
			this->_groupBoxLogin->Size = System::Drawing::Size(194, 166);
			this->_groupBoxLogin->TabIndex = 0;
			this->_groupBoxLogin->TabStop = false;
			this->_groupBoxLogin->Text = L"登陆服务器(4869)";
			// 
			// lb_Login
			// 
			this->lb_Login->AutoSize = true;
			this->lb_Login->Location = System::Drawing::Point(6, 44);
			this->lb_Login->Name = L"lb_Login";
			this->lb_Login->Size = System::Drawing::Size(138, 22);
			this->lb_Login->TabIndex = 2;
			this->lb_Login->Text = L"登陆侦听未初始化";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LavenderBlush;
			this->button2->FlatAppearance->BorderSize = 5;
			this->button2->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button2->Location = System::Drawing::Point(34, 117);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 32);
			this->button2->TabIndex = 1;
			this->button2->Text = L"关闭侦听";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LavenderBlush;
			this->button1->FlatAppearance->BorderSize = 5;
			this->button1->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button1->Location = System::Drawing::Point(34, 79);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"启动侦听";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->groupBox1->Controls->Add(this->lb_regist);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox1->Location = System::Drawing::Point(354, 96);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(197, 166);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"注册服务器(4870)";
			// 
			// lb_regist
			// 
			this->lb_regist->AutoSize = true;
			this->lb_regist->Location = System::Drawing::Point(6, 44);
			this->lb_regist->Name = L"lb_regist";
			this->lb_regist->Size = System::Drawing::Size(138, 22);
			this->lb_regist->TabIndex = 2;
			this->lb_regist->Text = L"注册侦听未初始化";
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::LavenderBlush;
			this->button4->FlatAppearance->BorderSize = 5;
			this->button4->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button4->Location = System::Drawing::Point(34, 117);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(105, 32);
			this->button4->TabIndex = 1;
			this->button4->Text = L"关闭侦听";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::LavenderBlush;
			this->button3->FlatAppearance->BorderSize = 5;
			this->button3->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button3->Location = System::Drawing::Point(34, 79);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(105, 32);
			this->button3->TabIndex = 0;
			this->button3->Text = L"启动侦听";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::Transparent;
			this->groupBox2->Controls->Add(this->lb_get_message);
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->button6);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupBox2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox2->Location = System::Drawing::Point(115, 286);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(194, 166);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"接收消息服务器(4871)";
			// 
			// lb_get_message
			// 
			this->lb_get_message->AutoSize = true;
			this->lb_get_message->Location = System::Drawing::Point(6, 44);
			this->lb_get_message->Name = L"lb_get_message";
			this->lb_get_message->Size = System::Drawing::Size(138, 22);
			this->lb_get_message->TabIndex = 2;
			this->lb_get_message->Text = L"接收消息未初始化";
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::LavenderBlush;
			this->button5->FlatAppearance->BorderSize = 5;
			this->button5->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button5->Location = System::Drawing::Point(34, 117);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(105, 32);
			this->button5->TabIndex = 1;
			this->button5->Text = L"关闭侦听";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::LavenderBlush;
			this->button6->FlatAppearance->BorderSize = 5;
			this->button6->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button6->Location = System::Drawing::Point(34, 79);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(105, 32);
			this->button6->TabIndex = 0;
			this->button6->Text = L"启动侦听";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::Color::Transparent;
			this->groupBox3->Controls->Add(this->lb_send_message);
			this->groupBox3->Controls->Add(this->button7);
			this->groupBox3->Controls->Add(this->button8);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupBox3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox3->Location = System::Drawing::Point(354, 286);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(197, 166);
			this->groupBox3->TabIndex = 5;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"发送消息服务器(4872)";
			// 
			// lb_send_message
			// 
			this->lb_send_message->AutoSize = true;
			this->lb_send_message->Location = System::Drawing::Point(6, 44);
			this->lb_send_message->Name = L"lb_send_message";
			this->lb_send_message->Size = System::Drawing::Size(138, 22);
			this->lb_send_message->TabIndex = 2;
			this->lb_send_message->Text = L"发送消息未初始化";
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::LavenderBlush;
			this->button7->FlatAppearance->BorderSize = 5;
			this->button7->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button7->Location = System::Drawing::Point(34, 117);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(105, 32);
			this->button7->TabIndex = 1;
			this->button7->Text = L"关闭侦听";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::LavenderBlush;
			this->button8->FlatAppearance->BorderSize = 5;
			this->button8->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button8->Location = System::Drawing::Point(34, 79);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(105, 32);
			this->button8->TabIndex = 0;
			this->button8->Text = L"启动侦听";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->BackColor = System::Drawing::Color::Transparent;
			this->groupBox4->Controls->Add(this->lb_ChangePeople);
			this->groupBox4->Controls->Add(this->button9);
			this->groupBox4->Controls->Add(this->button10);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupBox4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox4->Location = System::Drawing::Point(601, 96);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(196, 166);
			this->groupBox4->TabIndex = 4;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"个人信息服务器(4873)";
			// 
			// lb_ChangePeople
			// 
			this->lb_ChangePeople->AutoSize = true;
			this->lb_ChangePeople->Location = System::Drawing::Point(6, 44);
			this->lb_ChangePeople->Name = L"lb_ChangePeople";
			this->lb_ChangePeople->Size = System::Drawing::Size(170, 22);
			this->lb_ChangePeople->TabIndex = 2;
			this->lb_ChangePeople->Text = L"个人信息侦听未初始化";
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::LavenderBlush;
			this->button9->FlatAppearance->BorderSize = 5;
			this->button9->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button9->Location = System::Drawing::Point(34, 117);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(105, 32);
			this->button9->TabIndex = 1;
			this->button9->Text = L"关闭侦听";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::LavenderBlush;
			this->button10->FlatAppearance->BorderSize = 5;
			this->button10->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button10->Location = System::Drawing::Point(34, 79);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(105, 32);
			this->button10->TabIndex = 0;
			this->button10->Text = L"启动侦听";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->BackColor = System::Drawing::Color::Transparent;
			this->groupBox5->Controls->Add(this->lb_card);
			this->groupBox5->Controls->Add(this->button11);
			this->groupBox5->Controls->Add(this->button12);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupBox5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox5->Location = System::Drawing::Point(601, 286);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(196, 166);
			this->groupBox5->TabIndex = 5;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"一卡通服务器(4874)";
			// 
			// lb_card
			// 
			this->lb_card->AutoSize = true;
			this->lb_card->Location = System::Drawing::Point(6, 44);
			this->lb_card->Name = L"lb_card";
			this->lb_card->Size = System::Drawing::Size(154, 22);
			this->lb_card->TabIndex = 2;
			this->lb_card->Text = L"一卡通侦听未初始化";
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::LavenderBlush;
			this->button11->FlatAppearance->BorderSize = 5;
			this->button11->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button11->Location = System::Drawing::Point(34, 117);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(105, 32);
			this->button11->TabIndex = 1;
			this->button11->Text = L"关闭侦听";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::LavenderBlush;
			this->button12->FlatAppearance->BorderSize = 5;
			this->button12->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button12->Location = System::Drawing::Point(34, 79);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(105, 32);
			this->button12->TabIndex = 0;
			this->button12->Text = L"启动侦听";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// bt_open
			// 
			this->bt_open->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bt_open.BackgroundImage")));
			this->bt_open->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bt_open->FlatAppearance->BorderSize = 0;
			this->bt_open->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bt_open->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->bt_open->Location = System::Drawing::Point(12, 12);
			this->bt_open->Name = L"bt_open";
			this->bt_open->Size = System::Drawing::Size(66, 67);
			this->bt_open->TabIndex = 6;
			this->bt_open->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->bt_open->UseVisualStyleBackColor = true;
			this->bt_open->Click += gcnew System::EventHandler(this, &Form1::bt_open_Click);
			// 
			// groupBox6
			// 
			this->groupBox6->BackColor = System::Drawing::Color::Transparent;
			this->groupBox6->Controls->Add(this->lb_trade);
			this->groupBox6->Controls->Add(this->button13);
			this->groupBox6->Controls->Add(this->button14);
			this->groupBox6->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupBox6->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox6->Location = System::Drawing::Point(115, 479);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(196, 166);
			this->groupBox6->TabIndex = 6;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"二手交易服务器(4875)";
			// 
			// lb_trade
			// 
			this->lb_trade->AutoSize = true;
			this->lb_trade->Location = System::Drawing::Point(6, 44);
			this->lb_trade->Name = L"lb_trade";
			this->lb_trade->Size = System::Drawing::Size(170, 22);
			this->lb_trade->TabIndex = 2;
			this->lb_trade->Text = L"二手交易侦听未初始化";
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::LavenderBlush;
			this->button13->FlatAppearance->BorderSize = 5;
			this->button13->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button13->Location = System::Drawing::Point(34, 117);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(105, 32);
			this->button13->TabIndex = 1;
			this->button13->Text = L"关闭侦听";
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::LavenderBlush;
			this->button14->FlatAppearance->BorderSize = 5;
			this->button14->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button14->Location = System::Drawing::Point(34, 79);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(105, 32);
			this->button14->TabIndex = 0;
			this->button14->Text = L"启动侦听";
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &Form1::button14_Click);
			// 
			// groupBox7
			// 
			this->groupBox7->BackColor = System::Drawing::Color::Transparent;
			this->groupBox7->Controls->Add(this->lb_admin);
			this->groupBox7->Controls->Add(this->button15);
			this->groupBox7->Controls->Add(this->button16);
			this->groupBox7->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupBox7->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox7->Location = System::Drawing::Point(355, 479);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(196, 166);
			this->groupBox7->TabIndex = 7;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"管理员服务器(4876)";
			// 
			// lb_admin
			// 
			this->lb_admin->AutoSize = true;
			this->lb_admin->Location = System::Drawing::Point(6, 44);
			this->lb_admin->Name = L"lb_admin";
			this->lb_admin->Size = System::Drawing::Size(154, 22);
			this->lb_admin->TabIndex = 2;
			this->lb_admin->Text = L"管理员侦听未初始化";
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::Color::LavenderBlush;
			this->button15->FlatAppearance->BorderSize = 5;
			this->button15->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button15->Location = System::Drawing::Point(34, 117);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(105, 32);
			this->button15->TabIndex = 1;
			this->button15->Text = L"关闭侦听";
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &Form1::button15_Click);
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::Color::LavenderBlush;
			this->button16->FlatAppearance->BorderSize = 5;
			this->button16->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->button16->Location = System::Drawing::Point(34, 79);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(105, 32);
			this->button16->TabIndex = 0;
			this->button16->Text = L"启动侦听";
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Click += gcnew System::EventHandler(this, &Form1::button16_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(915, 712);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->bt_open);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->_groupBoxLogin);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"华工帮服务器";
			this->_groupBoxLogin->ResumeLayout(false);
			this->_groupBoxLogin->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	//一键开关
	private: bool open;
	private: System::Void bt_open_Click(System::Object^  sender, System::EventArgs^  e) {
		 open=!open;
		 if(open){
			 button1_Click(sender,e);
			 // Thread::Sleep(500);
			 button3_Click(sender,e);
			 // Thread::Sleep(500);
			 button6_Click(sender,e);
		      //Thread::Sleep(500);
			 button8_Click(sender,e);
		      //Thread::Sleep(500);
			 button10_Click(sender,e);
			 // Thread::Sleep(500);
			 button12_Click(sender,e);
			  //Thread::Sleep(500);
			 button14_Click(sender,e);

			 button16_Click(sender,e);
		 }
		 else{
			button2_Click(sender,e);
			// Thread::Sleep(500);
			button4_Click(sender,e);
			// Thread::Sleep(500);
			button5_Click(sender,e);
			// Thread::Sleep(500);
			button7_Click(sender,e);
			// Thread::Sleep(500);
			button9_Click(sender,e);
			// Thread::Sleep(500);
			button11_Click(sender,e);
			//Thread::Sleep(2000);
			button13_Click(sender,e);

			button15_Click(sender,e);
		 }
	}
	//登陆
	private: Login^obj1;
			 Thread^login_count;
			 
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
	private: void start_Login_count();
	//注册
	private: Regist^obj2;
			 Thread^register_count;
	private: void start_Register_count();
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);
	//获取信息
	private: Get_message^obj3;
			Thread^Get_message_count;
	private: void start_GetMessage_count();
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e);
	//发送信息
	private: Send_message^obj4;
			 Thread^Send_message_count;
	private: void start_SendMessage_count();
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e);
	//修改people
	private: Change_People^obj5;
			 Thread^ChangePeople_count;
	private: void Change_People_count();
	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e);
	//一卡通
	private: Card_server^obj6;
			 Thread^ Card_server_count;
	private: void  card_server_count();
	private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e);
	//二手交易
	private: Trade_server^obj7;
			Thread^ Trade_server_count;
	private: void  trade_server_count();
	private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e);
	//管理员
	private: Admin_Server^obj8;
			 Thread^ Admin_server_count;
	private: void  admin_server_count();
	private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e);
};
}
