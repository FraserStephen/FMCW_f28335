/****************************************Copyright (c)**************************************************
**                       		     
**
**
**
**--------------文件信息--------------------------------------------------------------------------------
**文   件   名: user_header.h
**创   建   人: 
**最后修改日期: 
**描        述: 变换器头文件
				包括版本信息,宏定义,变量声明
**              
**--------------历史版本信息----------------------------------------------------------------------------
** 创建人: 
** 版  本: 
** 日　期: 
** 描　述: 
**
**--------------当前版本修订------------------------------------------------------------------------------
** 修改人: 
** 日　期: 
** 描　述: 
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#ifndef DCDC_header_H
#define DCDC_header_H

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------宏定义-----------------------------------------------
				
//-----------------------参数相关宏定义------------------------------------------
//--------------------------版本信息-----------------------------------------------
#define MC_TYPE 			60701			//机型参数
#define MC_REV 				41222			//软件版本号
#define MC_DATE 			60815			//出厂日期
#define MC_ID				1				//产品编号
#define MC_WRKEY			999				//功能码修改密码
#define MC_MYKEY			1021			//制造商使用的密码

//------------------------调试状态软开关-----------------------------------------------
#define	ON					1				          //开
#define	OFF					0				          //关
#define	DEBUG_OPER			OFF			              //1=不带操作器2009.6.24

//********************************************************************************************//
//===================额定电流基准值峰值（每次实验根据需要更改）=====================================
#define NPR_IACN  473        //网侧额定电流基准值 额定有效值为334A
#define GRD_UN    563        //额定电网相电压峰值690V系统

//********************************************************************************************//
 
//----------------------------系统工作常数------------------------------------------------

#define NPR_L       0.5e-3     //网侧滤波电感值（H）

//-------------常用常量宏定义-------------------------//
#define	SQRT3		1.73205081			//sqrt(3)
#define	SQRT3_2		0.8660254           //sqrt(3)/2
#define	SQRT3_3		0.57735027          //sqrt(3)/3
#define	SQRT2		1.41421356			//sqrt(2)
#define	PAI			3.1415926           //圆周率
#define TWOPAI      6.2831853           //2*PAI
#define PAI_2       1.5707963			//PAI/2
#define PAI_3       1.0471975			//PAI/3
#define TWOPAI_3    2.0943951			//2*PAI/3


//------------------------------延时时间-------------------------------------------------
#define	DELAY_MAIN1			5										//一级循环：5ms
#define	DELAY_MAIN2			10										//二级循环：10ms
#define	DELAY_MAIN3			20										//三级循环：20ms
#define	DELAY_MAIN4			50										//四级循环：50ms
#define	DELAY_MAIN5			100										//五级循环：100ms
#define	DELAY_MAIN6			1000									//六级循环：1000ms

//canopen
#define	DELAY_CANOPENTX		13										//CANOPENTX：7ms
#define	DELAY_CANOPENOVER	500										//CANOPENOVER：500ms,HEARTBEAT
#define	DELAY_SCICANOPENOVER 250									//20090817
#define	DELAY_CANFAULT       10000									//CANOPENOVER：上电后判断CAN通讯故障

#define DELAY_AMUX          5      	//慢速AD
#define DELAY_UDCWAVE		1500	//直流电压波动超时时间

#define	DELAY_POWERON		5000  	//上电时间
#define	DELAY_PWMOUT		1000   	//系统从启动标志置位到脉冲发生允许标志置位延时(ms)
#define	DELAY_NPRSTDBY		1000   	//NPR待机---板子工作灯慢速闪烁(ms)
#define	DELAY_NPRRUN		100	   	//NPR工作---板子工作灯快速闪烁(ms)
#define	DELAY_MPRSTDBY		1000   	//MPR待机---板子工作灯慢速闪烁(ms)
#define	DELAY_MPRRUN		100	   	//MPR工作---板子工作灯快速闪烁(ms) 
#define	DELAY_FREQ			200	   	//频率失败允许延时
#define	DELAY_CBFREQ		1000	//从主断反馈闭合到判断网频故障的延时（ms）

#define	DELAY_FREQ2			200	   	//频率失败允许延时
#define	DELAY_OTSER			60000  	//超时严重延时(ms)
#define	DELAY_SCISPACE		10	   	//通讯接收到发送的间隔时间(ms)
#define	DELAY_SCIOVER		100	   	//通讯接收/发送超时时(ms)
//-----Protection-------
#define	DELAY_ESTOP  		6					//
#define	DELAY_CBTP		    6					//
#define DELAY_EXFAULT       500 
#define DELAY_CBERROR       2000     //2s 
#define DELAY_MAINKERROR    2000     //2s 
#define DELAY_MAINFERROR    2000     //2s
#define DELAY_STACERROR     2000     //2s
#define DELAY_PREERROR      85000     20100920 //15s
#define DELAY_PGOVLOAD      10000    //10s
#define DELAY_QGOVLOAD      10000    //10s
#define DELAY_CBRESET       500    	 //0.5s
#define DELAY_SPEEDOUT      5    //50ms 20091022atzy 主控fastshutdown
#define DELAY_UACLV1        10000     //10s   20091027atzy

#define	DELAY_EE		    20					//eeprom延迟时间

#define	DELAY_ISTEADY0	    1000	 //RunCtrl网侧停机给定延时1s
#define	DELAY_MPRSTEADY0    50     //RunCtrl网侧停机给定延时0.05s 
#define	DELAY_SENSZFSTDY    60000    //RunCtrl网侧停机给定延时60s
/*
//sysctl_start 调试版
#define	DELAY_OPENCONTAC	2000	 //严重不可恢复故障下，发出断主断指令后到发出断定子接触器和主接触器的延时 2s 

#define	DELAY_MKOFF	        5000	 //接收到系统停机指令后，延时断主接触器计数 5s
#define	DELAY_CBOFF	        1000	 //接收到系统停机指令后，延时断主断计数 2s

#define	DELAY_CLOSE_CB	    5000	 //正常启动，主断储能到主断合闸的延时计数 5s 
#define	DELAY_PRECOK        9000	 //正常启动，预充电时间 9s   充电常数=2.115s
#define	DELAY_STEADYFB	    2000	 //正常启动，检测到Vdc稳定在1100V到允许机侧脉冲的延时 2s
#define	DELAY_MPRSTART 	    5000	 //正常启动，Vdc稳定后到MPR发脉冲的延时 5s
//sysctl_end  
*/ 

//sysctl_start 最终版
#define	DELAY_OPENCONTAC	2000	 //严重不可恢复故障下，发出断主断指令后到发出断定子接触器和主接触器的延时 2s 

#define	DELAY_ACCONTOFF	        2000	 //延时断交流侧接触器 2s
#define	DELAY_CBOFF	        1000	 //接收到系统停机指令后，延时断主断计数 2s

#define	DELAY_CLOSE_CB	    1000	 	//正常启动，20100124CPC试验改 0s 
#define	DELAY_PRECOK        8000	 //正常启动，预充电时间 8s   充电常数=2.115s

//cy
#define	DELAY_VDCSTEADY	    2000	 //正常启动，检测到Vdc稳定在240~450V之间置直流电压稳定标志位的延时 2s
#define	DELAY_ACCONTON 	    1000	 //正常启动，直流电压稳定后合AC接触器延时计数 1s
#define	DELAY_NPRSTART 	    1000	 //正常启动，交流电压在范围内延时置上位机要求NPR发脉冲标志位 1s
//cy
//sysctl_end  


#define	DELAY_RESET	        2000  	 //系统复位延时，防止误操作 2s
#define	DELAY_CLOSTACMD	    1000  	 //允许定子接触器，防止误操作 1s
#define	DELAY_NPRCMD	    1000  	 //上位机允许NPR发脉冲，防止误操作 1s
#define	DELAY_MPRCMD	    1000  	 //上位机允许MPR发脉冲，防止误操作 1s

#define	DELAY_QCAPSPDIN     120    	//转子速度检测正常120ms   20090817
#define	DELAY_QCAPDISTURB   100    	//连续10次检测转子速度不正常报故障 100ms  20090817
#define	DELAY_QEPCNTOK      1000    //连续1s未发生上溢错误 1s
#define	DELAY_QEPZDISTURB   1000    //连续1s发生Z信号提前到来被干扰错误  1s

#define	DELAY_OCSEIN1     	250    	//20090817
#define	DELAY_OCSEIN2   	250    	//20090817
#define	DELAY_OCSSYSRUN1    250    	//20090817
#define	DELAY_OCSSYSRUN2   	250    	//20090817

#define	DELAY_DATASAVE   	2000    //故障发生后延时2s后停止存储20091109atzy
//LVRT
#define	DELAY_SCRIZERO	    100  	 //检测延时1个最大转差周期 100ms/10Hz
#define	DELAY_MPWMSTOP	    0  	 	 //0ms
#define	DELAY_MPWMRESTART	200  	 //200ms
#define	DELAYMPWM			5  	 	 //5ms
#define	DELAY_SCRONDELAY	2000  	 //2s
#define	DELAY_LVSTATE		20  	 //20ms
#define	DELAY_LVRCV			20  	 //20ms

//---------------------------故障保护回差值-----------------------------------------------
#define	SC_IAC_HW			2			//输入电流保护回差(基准电流的百分值)
#define	SC_UDC_HW			20			//电压保护回差(V)
#define	SC_UAC_HW			20			//电压保护回差(V)
#define	SC_MSPD_HW			30			//转速保护回差(V) r/min
#define	SC_POWOROV_HW	    0	    	//功率过载保护回差(W) 0kW

#define	et_gate	    		50000	    //过载保护计算

//-----------------------------CANOPEN通信宏定义----------------------------------------------
#define	SCICANOPENRXNUM		10										//CANOPENRX数据包大小
#define	SCICANOPENTXNUM		18										//CANOPENTX数据包大小
#define CANOPENCOM_HEAD		0x7E									//CANOPEN报头
//#define CANOPENCOM_RX		0x03									//FUNCTION_RX
//#define CANOPENCOM_TX1		0x01									//FUNCTION_TX
//#define CANOPENCOM_TX2		0x02									//FUNCTION_TX 
//-----------------------------CANOPEN通信宏定义NORMAL----------------------------------------------
#define CAN_TEN  	  10000     //主控指令额定转矩基准值 (常牵:1800r/min时P=1560kW,Te=P*60/(n*2*pie)=8276 NM )
#define CAN_ANGLEN     90       //主控指令额定无功因数角度基准值 
#define CAN_SPEED     1500      //主控指令额定转速基准值 
#define CAN_TEMP      100       //主控指令额定温度基准值 

//-----------------------------485通藕甓ㄒ�----------------------------------------------
#define	SCI485NUM			10										//485数据包大小
#define COM_HEAD			0x7E									//SCI报头

#define RESUME_KEY			0x5A5A									//恢复出厂参数的校验码

//地址字节
#define COM_OPERATOR		0x80									//上位机为操作器(最高位为1)

//上位机发送命令
#define COM_RD				0x0001									//读取功能码(读取下位机EEPROM中的功能码值写入到上位机EEPROM中)
#define COM_WR				0x0002									//修改功能码(修改下位机RAM中的功能码值)
#define COM_SAVE			0x0004									//修改功能码并存储(修改下位机RAM中的功能码值并保存换腅EPROM)
#define COM_RESUME			0x0008									//恢复出厂参
#define COM_NEEDSTOP		0x0010									//下位机应当处于停机状态才能进行(如上电初始化,功能码读出、校验和写等,提示位机应当；�)
#define COM_SAVEALL			0x0020									//修改功能码并存储(如数据复写功能中需要下位机写入所有参数,包括具有只读属性的功能码)
#define COM_VGIVE			0x0040									//修改dcdc电压给定值
#define COM_IGIVE			0x0080									//修改dcdc电流给定值

//下位机反馈命令
#define COM_SUCCESS			0x80									//最高位为通讯握手成功标志

//上位机状态字
#define COM_UPNORM			0x0001									//0位为上位机正常标志
//#define COM_UPINIT		0x0002									//1位为上位机初始化瓿标志
#define COM_KEYSTOP			0x0100									//1=上位机'STOP'键有效(停止)
#define COM_KEYFWD			0x0200									//1=上位机'FWD'键有效(充电)
#define COM_KEYREV			0x0400									//1=上位机'REV'键有效(放电)
//#define COM_KEYRESET		0x0800									//1=上位机'RESET'键有效(预留)

//下位机反馈状态字
#define COM_SLAVENORM		0x0001									//0位为下位机正常标志
#define COM_SLAVEINIT		0x0002									//1位为下位机初始化完成标志
#define COM_SLAVERUN		0x0004									//2位为下位机运行标志
#define COM_SLAVEFWD		0x0008									//3位为下位机充电
#define COM_SLAVEREV		0x0010									//4位为下位机放电
#define COM_SLAVEDEB		0x0020									//5位为下位机调试

//CANOPEN上位机状态字
#define COM_EIN			    0x0001									//BIT0
#define COM_NPREIN			0x0002									//BIT1
#define COM_SYSRUN			0x0004									//BIT2
#define COM_PGMODE			0x0010									//BIT4
#define COM_QGMODE			0x0020									//BIT5
#define COM_OCSRESET		0x0080									//BIT7
#define COM_HEARTBEAT1		0x8000									//BIT15
//CANOPEN反馈上位机的变流器状态字1
#define COM_NPRREADY	    0x0001									//BIT0
#define COM_NPRON			0x0002									//BIT1
#define COM_READYGENERATION	0x0004									//BIT2
#define COM_FAILURE			0x0008									//BIT3
#define COM_SPEEDINRANGE	0x0010									//BIT4
#define COM_FAILUREA		0x0020									//BIT5
#define COM_FAILUREB		0x0040									//BIT6
#define COM_TOOCOLD		    0x0080									//BIT7
#define COM_PLIM	        0x0100									//BIT8
#define COM_QLIM			0x0200									//BIT9
#define COM_GRIDFAILURE 	0x0400									//BIT10
#define COM_CROWBAR			0x0800									//BIT11
#define COM_VLIM        	0x1000									//BIT12
#define COM_HEARTBEAT2		0x8000									//BIT15

#define COM_NPRREADY_NOT	    0xFFFE								//BIT0
#define COM_NPRON_NOT			0xFFFD								//BIT1
#define COM_READYGENERATION_NOT	0xFFFB								//BIT2
#define COM_FAILURE_NOT			0xFFF7								//BIT3
#define COM_SPEEDINRANGE_NOT	0xFFEF								//BIT4
#define COM_FAILUREA_NOT		0xFFDF								//BIT5
#define COM_FAILUREB_NOT		0xFFBF								//BIT6
#define COM_TOOCOLD_NOT		    0xFF7F								//BIT7
#define COM_PLIM_NOT	        0xFEFF								//BIT8
#define COM_QLIM_NOT			0xFDFF								//BIT9
#define COM_GRIDFAILURE_NOT 	0xFBFF								//BIT10
#define COM_CROWBAR_NOT			0xF7FF								//BIT11
#define COM_VLIM_NOT        	0xEFFF								//BIT12
#define COM_HEARTBEAT2_NOT		0x7FFF								//BIT15
//CANOPEN反馈上位机的变流器状态字2
#define COM_ILIM			0x0001									//BIT0
#define COM_HEATSINKT		0x0002									//BIT1
#define COM_ESTOP			0x0004									//BIT2
#define COM_CBTRIP			0x0010									//BIT4
#define COM_POWLIM			0x0040									//BIT6
#define COM_VOLDIP			0x0100									//BIT8
#define COM_CBCLOSED		0x8000									//BIT15	 20090815

#define COM_ILIM_NOT		0xFFFE									//BIT0
#define COM_HEATSINKT_NOT	0xFFFD									//BIT1
#define COM_ESTOP_NOT		0xFFFB									//BIT2
#define COM_CBTRIP_NOT		0xFFEF									//BIT4
#define COM_POWLIM_NOT		0xFFBF									//BIT6
#define COM_VOLDIP_NOT	    0xFEFF									//BIT8
#define COM_CBCLOSED_NOT	0x7FFF									//BIT15 20090815

//-------------------------AD、DA转换及数据读取的控制-----------------------------------------
#define	AD8364_CONVERT		1										//8364开始转换
//#define	AD1544_CONVERT		2										//1544开始转换
//#define	DA7614_CONVERT		4										//7614开始转换
//ad
#define AD_ASTART		    ((Uint16 *)0x100000)						//片外AD的数据读取首地址
#define AD_BSTART		    ((Uint16 *)0x110000)						//片外AD的数据读取首地址
#define NETCS		        ((Uint16 *)0x120000)						//片外AD的数据读取首地址
#define AD_DA_CTRL		    ((Uint16 *)0x130000)						//片外AD,DA的控制字节地址
//da
#define DA_ADD0				((Uint16 *)0x1B0000)						//输出地址0
#define DA_ADD1				((Uint16 *)0x1B0001)						//输出地址1
#define DA_ADD2				((Uint16 *)0x1B0002)						//输出地址2
#define DA_ADD3				((Uint16 *)0x1B0003)						//输出地址3

//External RAM 20091109atzy
#define RAM_START		    ((Uint16 *)0x200000)						//片外RAM首地址XINTF zone 7
#define RAM_END		        ((Uint16 *)0x23FFFF)						//片外RAM尾地址XINTF zone 7
#define RAM_BIAS		    10000						//每个变量偏移量=4s/(0.4ms/point)=10000points/variable
Uint16  RAMDATA_POS;						    		//存储变量的存储点位置[0,7999]


//----------------------------输入输出地址定义--------------------------------------------
#define IN1_ADDR			((Uint16 *)0x140000)	//输入地址1
#define IN2_ADDR			((Uint16 *)0x150000)	//输入地址2
#define IN3_ADDR			((Uint16 *)0x160000)	//输入地�3
#define IN4_ADDR			((Uint16 *)0x170000)	//输入地址4

#define OUT1_ADDR			((Uint16 *)0x180000)	//输出地址2
#define OUT2_ADDR			((Uint16 *)0x190000)	//输出地址3
#define OUT3_ADDR			((Uint16 *)0x1A0000)	//输出地址3
#define OUT4_ADDR			((Uint16 *)0x1C0000)	//输出地址4,与慢速AD有关

//--------------------------------SPI通讯宏定义-------------------------------------------
#define	SPINUM				4										//SPI口发送/接收数据量

//-----------------------------------时钟--------------------------------------------------
#define	HSPCLK				75      		//高速基准时钟频率(Hz)
#define	LSPCLK				37500000		//低速基准时钟频率(Hz)

//--------------------------------标志位定�-----------------------------------------------
//flag[0]显示及设定标
#define	SL_DISPLAY0			0x00			//LED显示0
#define	SL_DISPLAY1			0x01			//LED显示1
#define	SL_DISPLAY2			0x02			//LED显示2
#define	SL_DISPLAY3			0x03			//LED显示3
#define	SL_DISPLAY4			0x04			//LED显示4
#define	SL_DISPLAY5			0x05			//LED显示5
#define	SL_DISPLAY6			0x06			//LED显示6
#define	SL_DISPLAY7			0x07			//LED显示7
#define SL_OCS_NPRSTART     0x08            //=1主控要求NPR发脉冲        
#define SL_OCS_MPRSTART     0x09            //=1主控要求MPR发脉冲
#define SL_OCS_RESET        0x0A            //=1主控发过来的故障复位信号  
#define SL_SERIESTOPING    	0x0B			//=1正在严重故障停机过程 
#define	SL_SERIESTOP        0x0C      		//=1系统严重不可恢复故障标志位 
#define SL_SENSZFSTDY       0x0D            //=1传感器零漂滤波结束 
#define	SL_EINSTOPING       0x0E      		//=1正在正常断主断停机过程
#define SL_SYSSTOPING       0x0F            //=1正在正常断主接触器停机过程

 
  

//flag[1]串行通信相关标;eeprom相关标
#define SL_TX		    	0x10			//1=表示sci正在发送
#define SL_RX		    	0x11			//1=表示sci接收完成延时中
#define SL_RESUME    		0x12			//1=恢复出厂参数进行中
#define SL_HEADOK			0x13			//1=本帧数据报头正确
#define SL_SETRTIMER		0x14			//1=需要校正实时时钟
#define SL_EE_NOACK			0x15
#define	SL_EE_FAIL			0x16			//=1eeprom写入错误
#define SL_CODEOK			0x17			//=1功能码校验完毕
#define SL_EEASK_INI		0x18			//=上位机要求eeprom恢复出厂参数
#define SL_EEASK_MCODE		0x19			//=1存在修改功能码请求
#define SL_EEASK_ERRSAVE	0x1A			//=1存在保存故障信息请求
#define SL_EEBUSY_INI		0x1B			//=1恢复出厂参数进行中
#define SL_EEBUSY_MCODE		0x1C			//=1修改功能码进行中
#define SL_EEBUSY_ERRSAVE	0x1D			//=1保存故障信息进行中 
	
//flag[2]故障标志位//cy
#define SL_ACCONFAIL		0x20			//=1 接触器闭合故障
#define SL_UFO				0x21			//=1 U相上桥臂驱动保护
#define	SL_VFO	        	0x22     		//=1 V相上桥臂驱动保护  
#define	SL_WFO	    		0x22     	    //=1 W相上桥臂驱动保护
#define SL_BFO				0x23			//=1 下桥臂驱动保护
#define	SL_HIAC           	0x24      		//=1 交流硬过流
#define	SL_HUDCOV        	0x25      		//=1 直流硬过压 
#define	SL_SIA       		0x26      		//=1 交流A相软过流
#define SL_SIB        		0x27        	//=1 交流B相软过流 
#define SL_SIC   			0x28         	//=1 交流C相软过流
#define SL_SUDCOV     		0x29         	//=1 直流软过压
#define SL_SUDCLV			0x2A         	//=1 直流软欠压
#define SL_UACOV       		0x2B         	//=1 交流电压过压
#define SL_UACLV        	0x2C         	//=1 交流电压欠压 
#define SL_FE1        		0x2D         	//=1 电网频率故障 
#define SL_IPMTOV        	0x2E         	//=1 IGBT过热 
#define SL_LTOV        		0x2F         	//=1 电抗器过热 
//cy

//flag[3]状态标
#define SL_POWERON			0x30			//=1系统上电完成
#define SL_VDCON			0x31			//=1上电标志（中间电压达到此值主断可以闭合）
#define SL_WARNING			0x32			//=1报警
#define SL_OFFCB			0x33			//=1断主断
#define SL_SOFT				0x34			//=1缓慢停止
#define SL_SHUT				0x35			//=1紧急停止
#define SL_NRCVR			0x36			//=1故障不能恢复
#define SL_DRCVR			0x37			//=1故障延时恢复
#define SL_IRCVR			0x38			//=1故障立即恢复
#define SL_CNT				0x39			//=1计入故障次数
#define SL_OTSER			0x3A			//=1故障超时严重
#define SL_SAVE				0x3B			//=1故障需要存储
#define SL_STEADYGV			0x3C			//=1Vdc给定稳定
#define SL_VDCSTEADY		0x3D			//=1Vdc电压稳定
#define SL_DEADCOMP1		0x3E			//=1网侧死区补偿使能
#define SL_DEADCOMP2		0x3F			//=1电机侧死区补偿使能 

//flag[4]故障标1
#define SL_ERROR			0x40			//=1系统故障
#define SL_ERRSTOP			0x41			//=1系统严重故障导致停机
#define	SL_PDPINTA			0x42			//=1功率驱动保护A
#define	SL_PDPINTB			0x43			//=1功率驱动保护B
#define	SL_UDCWAVE			0x44			//=1中间电压不稳定，超出580V和620V
#define	SL_SUDCOVH			0x45			//=1中间电压过压故障标志位(网压跌落)
#define SL_HIA1			    0x46			//=1网侧变流器A相硬件过流
#define SL_HIB1			    0x47			//=1网侧变流器B相硬件过流
#define SL_HIC1			    0x48			//=1网侧变流器C相硬件过流
#define SL_HIA2		 	   	0x49			//=1电机侧变流器A相硬件过流
#define SL_HIB2		   	 	0x4A			//=1电机侧变流器B相硬件过流
#define SL_HIC2		   	 	0x4B			//=1电机侧变流器C相硬件过流
#define SL_SIAC1		    0x4C			//=1网侧变流器软件过流
#define SL_SIAC2		    0x4D			//=1电机侧变流器软件过流

//flag[5]故障标2//cy 
#define SL_TTOV				0x50			//=1变压器过热
#define SL_PGOV				0x51			//=1有功功率过载
#define SL_QGOV				0x52			//=1无功功率过载
#define SL_IslandPro_U		0x53			//=1电压孤岛保护
#define SL_IslandPro_F		0x54			//=1频率孤岛保护
//cy
#define	SL_GRDFQE			0x55			//=1网侧频率检测有误
#define	SL_PDPASERIES		0x56			//=1网侧严重故障
#define SL_PDPBSERIES		0x57			//=1电机侧严重故障
#define SL_HIACOV1			0x59			//=1网侧交流硬件保护过流故障
#define SL_HIACOV2			0x5A			//=1电机侧交流硬件保护过流故障
#define SL_CBTRIP 			0x5B			//=1主断脱扣或者主控断开主断故障
#define	SL_EXFAIL		    0x5C			//=1变流器外部硬件故障
#define	SL_ESTOP			0x5D			//=1外部紧急停机故障
#define SL_PHORDE		    0x5F            //=1相序正常

//flag[6]运行方式
//#define SL_NPR_SINGLE		0x60			//=1网侧独立工作模式
//#define SL_MPR_SINGLE		0x61			//=1电机侧独立工作模式
//#define SL_BACK2BACK		0x62			//=1背靠背运行
//#define SL_NPR_REACTIVE		0x63			//=1网侧无功并网工作模式
//#define SL_NPR_PWMSTOP      0x64            //=1网侧停止脉冲
//#define SL_MPR_PWMSTOP      0x65            //=1机侧停止脉冲
#define	SL_NPR_START		0x66			//网侧变流器运行指令 1=运行
#define	SL_MPR_START		0x67			//机侧变流器运行指令 1=运行
#define	SL_NPR_RUN			0x68			//=1网侧变流器工作允许
#define	SL_MPR_RUN			0x69			//=1机侧变流器工作市� 
#define	SL_NPR_RUNING		0x6A			//=1网侧变流器正在工�
#define	SL_MPR_RUNING		0x6B			//=1机侧变流器正在工作
#define	SL_TAOVONCE			0x6C			//=1网侧桥臂超温故障信号受干扰
#define	SL_TBOVONCE			0x6D			//=1电机侧桥臂超温故障信号受干扰
#define SL_FAN_WORK         0x6E			//=1要求功率风扇开始工作
#define	SL_FANSELECT		0x6F			//=0功率风机星接 1功率风机角接
								
//flag[7]输出标1,IO输出   0x180000          //继电器输出，=1 输出DC24V
#define _OUT1_DATA			flag[7]	
#define CL_OUT_CONVRUN          0x70         	//=1变流器运行P5.5
#define CL_OUT_CONVFAIL			0x71			//=1变流器故障P5.6
#define CL_OUT_ACCONTON			0x72			//=1合交流接触器P5.7
#define	CL_OUT_DCCONTON    		0x73			//=1合直流接触器P5.8
#define CL_OUT_FANWORK		    0x74			//=1风机运行P5.9

//flag[8]输出标2         0x190000           //继电器输出，=1 输出AC220V
#define _OUT2_DATA			flag[8]
#define CL_RELAY8      		0x80			//备用
#define CL_RELAY9          	0x81			//备用

//flag[15]输出标4         0x1A0000          //慢速AD地址输出
#define _OUT3_DATA			flag[15]									
#define SL_PHASEA			0xF0		     //						
#define SL_PHASEB			0xF1             //
 

//flag[11]输出标4         0x1C0000          //慢速AD地址输出
#define _OUT4_DATA			flag[11]									
#define SL_LSADA0			0xB0		     //A0						
#define SL_LSADA1			0xB1             //A1
#define SL_LSADA2			0xB2             //A2
#define SL_LSADA3			0xB3	         //A3							
							

						

//flag[9]输入标12
#define _IN12_DATA			flag[9]			//变流器布刺蠢�
//---------------------0x140000----------------------------------------------------------------------------	
#define SL_IN1_EMESTOP 			0x90			//=1 外部急停故障	P4.1
#define SL_IN1_SYSSTAR			0x91			//=1 系统启动		P4.2
#define SL_IN1_CONVRUN			0x92			//=1 逆变器并网运行，P4.3  
#define SL_IN1_ACCONTA 			0x93			//=1 交流接触器处于合闸状态	P4.4
#define SL_IN1_DCCONTA	    	0x94			//=1 直流接触器处于合闸状态，P4.5
#define SL_IN1_SPARE	  	 	0x95			//=1 备用	P4.6		
//---------------------0x150000---------------------------------------------------------------------------	
#define SL_IN2_UFO			0x98	//=1 U相上桥臂驱动保护
#define SL_IN2_VFO			0x99	//=1 V相上桥臂驱动保护
#define SL_IN2_WFO			0x9A	//=1 W相上桥臂保护					
#define SL_IN2_BFO			    0x9B	//=1 下桥臂驱动保护 
#define SL_IN2_HIAC			0x9C	//=1 交流硬过流
#define SL_IN2_HUDCOV			0x9D	//=1 直流硬过压


//flag[10]输入标34      0x160000
#define _IN34_DATA			flag[10]			//控制板硬件保护故障反馈
//-----------------------------------------------------------------------------------------------				
#define SL_IN3_VDCOV			0xA0			//=1 直流电压过压
#define SL_IN3_NPRIOV			0xA1			//=1 网侧交流硬件保护过流故障
#define SL_IN3_MPRIOV			0xA2			//=1 电机侧交流硬件保护过流故障

#define SL_IN3_CBTRIP		    0xA3			//=1 主断过流脱扣故障  P4.9   20090816
//#define SL_IN3_OCS_NPRSTART		0xA4			//=1 上位机允许发网侧脉冲  操作板信号，风场没用
//#define SL_IN3_OCS_MPRSTART		0xA5			//=1 上位机允许发机侧脉冲  操作板信号，风场没用


//flag[12]主控通讯标志位
#define SL_OCS_EIN          0xC0            //=1主控发过来的系统启动信号  bit0 合主断路器
#define SL_OCS_SYSRUN    	0xC1			//=1主控发过来的变流器启动信号  bit2 开始预充电直至定子接触器闭合
#define SL_CBCLOSED    	    0xC2			//=1反馈主控，主断已经闭合
#define SL_MPR_SYNOK        0xC3            //=1机侧同步并网完成标志位				
#define SL_OCS_NPREIN       0xC4            //=1主控要求变流器网侧单独无功并网运行				
#define SL_PGOV_COM         0xC5            //=1有功功率超出限制，通知主控 持续10s后变流器会报故障			
#define SL_QGOV_COM         0xC6            //=1无功功率超出限制，通知主控 持续10s后变流器会报障				
//canopen
#define SL_COMOVER		0xC8			//=1 通讯故障
#define SL_CANOPENHEADOK	0xC9			//=1 SL_CANOPENHEADOK
#define SL_CANOPENTX		0xCA			//=1 SL_CANOPENOVER 
#define SL_TEST		        0xCB			//=1 SL_CANOPENOVER 


//flag[13]
#define SL_GRIDLOSE70		0xD0			//为监测网压跌落20091027atzy
#define	SL_GRIDLOSE50       0xD1      		//为监测网压跌落20091027atzy
#define	SL_GRIDLOSE30       0xD2      		//为监测网压跌落20091027atzy
#define	SL_GRIDLOSE15       0xD3      		//为监测网压跌落20091027atzy
#define	SL_ERRDATASAVE      0xD4      		//触发外部RAM数据转存20091109atzy
//LVRT标志位
#define SL_LV_MSTOP         0xD5       		    
#define SL_LV_NSTOP         0xD6
#define SL_LV_SCRON         0xD7
#define SL_LV_SCRRUNING     0xD8
#define SL_LV_SCRIZERO      0xD9
#define SL_LV_MPWMOUT		0xDA		
#define SL_LV_STATE		    0xDB		


//flag[14]
#define SL_RESET            0xE1
#define SL_SIOVST           0xE2
#define SL_NPR_TLOV         0xE3
#define SL_MPR_TLOV         0xE4
#define SL_DRAW			    0xE5			//=1绘图
#define SL_CHARGEOK			0xE6			//=1预充电完成
#define SL_SPEED_IN_RANGE	0xE7			//=1转速在范围以内
#define SL_CONFIGPWM		0xE8			//=1 PWM脉冲配置完成标志位,并且保证ConfigPwm()只能运行一次
#define SL_RUN				0xE9			//=1系统运行
#define SL_STACTRIPEN		0xEA			//=1，定子电流很小，定子接触器断开允许
#define	SL_TAOV				0xEB			//网侧超温
#define SL_TBOV			    0xEC			//机侧超温
#define SL_SKTOV            0xED            //软件判断SKIIP超温
#define SL_NPR_PWMOUT       0xEE            //网侧脉冲已经使能标志位,并且保证Enepwmio_NPR()只能运行一次
#define SL_MPR_PWMOUT       0xEF            //机侧脉冲已经使能标志位,并且保证Enepwmio_MPR()只能运行一次




//------------------------------------const定义--------------------------------------------

//eeprom位操作
const  Uint16 ONEBYTE[8]={0x0080,0x0040,0x0020,0x0010,0x0008,0x0004,0x0002,0x0001};

//AD1544通道选择
const  Uint16 AD1544[4]={0x0000,0x2000,0x4000,0x6000};		
//--------------------------------------变量定义-------------------------------------------
Uint16	flag[15];													//标志位变量
Uint16	disp[15];													//标志变量

float   RUN_mpridrf_exi;
Uint16  RUN_mpriq;
Uint16  _OUT3_TEST;
Uint16  _NQEPPCO;

int32   ET_SUM1;
int32   ET_SUM2;

/*下面的用作SVPWM计算*/
Uint16 SW_NPR,SW_MPR; 
float   vdc;	 
float   m=0.0;
float   ua_m=0,ub_m=0,uc_m=0;  //调制波
float   u_alfa_NPR=0,u_beta_NPR=0;
float   u_alfa_MPR=0,u_beta_MPR=0;


//给定值寄存器
struct	GIVE{
	float   npridrf;					   //网侧中间直流电压给定值
	float   npriqrf;                   //网侧无功电流给定值(仅网侧无功运行时使用)
	float   toqrf;                      //机侧转矩给定值(有功)
	float   anglerf;                    //机侧功率因数角度给定值(无功) 角度
}GIVE;
float OCS_Trf;                          //主控给过来的转矩指令

//给定积分相关寄存器
struct	RUN{									
	float   npridrf;						//电压给定积分值
	float   npridstep;						//电压给定积分步长
	float   mpridrf;						//有功电流给定积分值
	float   mpridstep;						//有功电流给定积分步长
	float   npriqrf;						//无功电流给ɑ种?
 	float   npriqstep;						//无功电流给定积分步长
	float   mpriqrf;						//无功电流给ɑ种?
 	float   mpriqstep;						//无功电流给定积分步�
	float   toqrf;						//转矩给定积分值
	float   toqstep;					//转矩给定积分步长
	float   aglrf;						//功率因数角给定积
	float   aglstep;					//功率因数角给定积分步长

	float   staidrf;					//解列定子d轴电流指令
	float   staiqrf;					//解列定子q轴电流指令
	float   staidstep;					//解列定子d轴电流步长
	float   staiqstep;					//解列定子q轴电流步长  

	float   mpridrf_g;						
	float   mpriqrf_g;					
    
    float   radianrf;
	float   mpridrf_exi;
	float   mpridrf_var;
}RUN; 
//坐标变换相关寄存器
struct	TRANS_DATA{
    float a;           	//a相
	float b;           	//b相
	float c;           	//c相
	float alfa;	       	//alfa轴
	float beta;	       	//beta轴
	float d;		   	//d轴
	float q;           	//q轴 
	float sintheta;    	//正弦值
	float costheta;	   	//余弦值
	float dflt;	   		//滤波后d值
	float qflt;	   		//滤波后q值
	float amp;			//幅值
	float ampflt;		//滤波后幅值
	float dflt2;	   	//小滤波后d值20091027atzy为了检测电网跌落
};																 
struct	TRANS_DATA TRS_NPR_I;   //网侧变流器的电流（这里采用NPR作为后缀，不用grd，以区分电网电流还是网侧变流器电流）
struct	TRANS_DATA TRS_MPR_I;   //机侧变流器的电流
struct	TRANS_DATA TRS_MPR_U;   //机侧变流器算脉冲用
struct	TRANS_DATA TRS_NPR_U;   //网侧变流器算脉冲
struct	TRANS_DATA TRS_NGS_U;   //网侧电网电压
struct	TRANS_DATA TRS_STA_I;   //定子电流
struct	TRANS_DATA TRS_STA_U;   //定子电压
struct	TRANS_DATA TRS_GSTA_U;  //目标定子电压
struct	TRANS_DATA TRS_PSTA_U;  //用于编码器位置检测的定子电压
struct	TRANS_DATA TRS_PMPR_I;  //用于编码器位置检测的转子电流   
struct	TRANS_DATA DIP_NPR_U;  //用于功率计算  
struct	TRANS_DATA DIP_NPR_I;  //用于功率计算 
struct	TRANS_DATA DIP_STA_U;  //用于功率计算 
struct	TRANS_DATA DIP_STA_I;  //用于功率计算 
struct	TRANS_DATA DIP_MPR_I;  //用于功率计算  


//PI环相关寄存器
struct PI_DATA
{
	float reference;							//给定值
	float feedback;								//反馈值
	float errorp;								//前次误差
	float error;								//误差
	float integrator;							//前次积纸峁�
	float out;
};  
struct PI_DATA PI_NPR_Id;				//网侧变流器d轴电流闭环
struct PI_DATA PI_NPR_Iq;				//网侧变流器q轴电流闭环
struct PI_DATA PI_MPR_Id;				//机侧变髌鱠轴电流闭环
struct PI_DATA PI_MPR_Iq;				//机侧变流器q轴电流闭环
struct PI_DATA PI_NPR_U;				//网侧变流器电压环
struct PI_DATA PI_MPR_U;				//栈�
struct PI_DATA PI_STA_Id;				//励磁控制d
struct PI_DATA PI_STA_Iq;				//励磁控制q 

struct PI_PARA
{
   float kp;
   float ki;
   float kd;
   float errmax;
   float errmin;
   float incrementmax;
   float outmax;
};
struct PI_PARA PI_PARA_NPRU;
struct PI_PARA PI_PARA_NPRID;
struct PI_PARA PI_PARA_MPRU;
struct PI_PARA PI_PARA_MPRID;
struct PI_PARA PI_PARA_NPRIQ;
struct PI_PARA PI_PARA_MPRIQ;
struct PI_PARA PI_PARA_DYNU;
struct PI_PARA PI_PARA_DYNID;
struct PI_PARA PI_PARA_DYNIQ;
struct PI_PARA PI_PARA_MPRI;
struct PI_PARA PI_PARA_STAI;


//餮范ㄊ逼骷把邮奔剖�
struct	MAIN_LOOP{
	int32 cnt1;					//主循环定时寄嫫�5ms
	int32 cnt2;					//主循环定时寄存器10ms
	int32 cnt3;					//主循环定时寄存器20ms
	int32 cnt4;					//主循环定时寄存器50ms
	int32 cnt5;					//主循环定时寄存器100ms
	int32 cnt6;					//主循环定时寄存器1000ms

	int32 pulse;				//主循环分时脉冲寄存器
	
	int32 cnt_poweron;			//preparation time delay
	int32 cnt_pwmout;			//PWM输出延时
	int32 cnt_nprlamp;			//网侧脉冲发出指示灯闪烁延时计数
	int32 cnt_mprlamp;			//机侧脉冲发出指示灯闪烁延时计数 

	int32 cnt_freq;			   //频率偏移计�
	int32 cnt_freq2;
	int32 cnt_cbfreq;
	int32 cnt_estop;
	int32 cnt_rcvr;				//故障延时恢复计时
	int32 cnt_otser;			//严重延�?

	int32 cnt_exfault;
	int32 cnt_cbtp;
	int32 cnt_cberror;
	int32 cnt_mainkerror;
	int32 cnt_mainferror;
	int32 cnt_preerror;
	int32 cnt_stacerror;
	int32 cnt_pgovload;
	int32 cnt_qgovload;
	int32 cnt_canfault;
	int32 cnt_speedout;
	int32 cnt_uaclv1;   //20091027atzy
		

	int32 cnt_isteady0;
    int32 cnt_mprsteady0;
	int32 cnt_senszfstdy;

//sysctl_zl_start
    int32 cnt_opencontac;      //严重不可恢复故障下，发出断主断指令后到发出断定子接触器和主接触器的延时

	int32 cnt_accontoff;       //延时断交流接触器
	int32 cnt_cboff;           //接盏较低惩；噶詈螅邮倍现鞫霞剖�

	int32 cnt_closecb;         //正常启动/停止，主断储能到主断合闸的延时计数
	int32 cnt_precok;          //正常启动/停止，检测到Vdc达到950V到发出合主接触器指令的延时计数
	int32 cnt_scrondelay;       
//cy
	int32 cnt_vdcsteady;        //检测到Vdc稳定在240~450V之间置直流电压稳定标志位的延时计数
	int32 cnt_vdcunsteady;      //检测到Vdc不在240~450V之间清直流电压稳定标志位的延时计数
	int32 cnt_acconton;			//直流电压稳定后合AC接触器延时计数
	int32 cnt_nprstart;			//交流电压在范围内延时置上位机要求NPR发脉冲标志位
	int32 cnt_nprstop;			//交流电压不在范围内延时清上位机要求NPR发脉冲标志位
//cy

//sysctl_zl_end 
    int32 cnt_AMUX;            //慢速AD
	int32 cnt_reset;
    int32 cnt_clostacmd;
	int32 cnt_nprcmd;
	int32 cnt_mprcmd;


	//canopen
	int32 canopen_rx;
	int32 canopen_tx;
	int32 cnt_cbreset;

	int32 et_relay1;     
	int32 et_relay2;

	int32 cnt_ocsein1;     
	int32 cnt_ocsein2;
	int32 cnt_ocssysrun1;     
	int32 cnt_ocssysrun2;

	int32 cnt_datasave;

}MAIN_LOOP;  

//慢速AD处理寄存器
Uint16 _OUT_AMUX1=0;  //用于慢速AD选通信号，每次要选通下一个AD通道，_OUT_AMUX加1，然后送到CPLD去处理，选通16选1芯片
Uint16 _OUT_AMUX2;    //用于慢速AD选通信号，每次要选通下一个AD通道，_OUT_AMUX加1，然后送到CPLD去处理，选通16选1芯片
struct  AMUX{
    float NPR_tempa;  		//NPR的A相半导体温度，Skiip传回来的
    float NPR_tempb;  		//NPR的B相半导体温度，Skiip传回来的
    float NPR_tempc;  		//NPR的C相半导体温度，Skiip传回来的
    float MPR_tempa;  		//MPR的A相半导体温度，Skiip传回来的
    float MPR_tempb;  		//MPR的B相半导体温度，Skiip传回来的
    float MPR_tempc;  		//MPR的C相半导体温度，Skiip传回来的
    float Lac_temp;   		//交流测电感温度
	float Ldudt_temp; 		//du/dt的温度
	float skiiptempmax;    	//SKIIP模块的温度最大值
	float NPR_skiiptemp;    //网侧SKIIP模块的温度最大值
	float MPR_skiiptemp;    //机侧SKIIP模块的温度最大值
}AMUX;

//AD模块处理寄存器
struct	AD{
	int16  dat[24];													//AD当前转换结果存放
	Uint32 cputime;
	Uint32 cputime_last;
}AD;
//cy
//AD转换结果寄存器
struct	ADFINAL{
	int16  ia1;				//交流侧电流Ia
	int16  ib1;				//交流侧电流Ib
	int16  idc;				//直流侧电流Idc
	int16  uab;				//交流侧电压Uab
	int16  ubc;				//交流侧电压Ubc
    int16  udc;             //直流侧电压Udc
    int16  AMUX;            //慢速AD信号
	int16  ia2;				//交流380V侧电流
}ADFINAL;
//cy   

//网压矢量
struct AD_DATA{
	  float  a;
	  float  b;
	  float  c;
	  float  ab;
	  float  bc;
	  float  ac;
	  float  ba;
	  float  dc; 
	  float  a_temp;
	  float  b_temp;
	  float  c_temp;
	  float  ab_temp;
	  float  bc_temp;
	  float  a_dc;
	  float  b_dc;
	  float  c_dc;
	  float  ps;
	  float  a2;
};
struct AD_DATA AD_OUT_U;  //交流侧电压
struct AD_DATA AD_OUT_STA_U;  //电机定子侧电压 大滤波通道
struct AD_DATA AD_OUT_NGS_U;  //电网电压（主断后）
struct AD_DATA AD_OUT_NPR_I;  //网侧变流器电流
struct AD_DATA AD_OUT_MPR_I;  //机侧变流器电流
struct AD_DATA AD_OUT_STA_I;  //定子侧电流  
struct AD_DATA AD_OUT_NGF_U;  //电网电压（主断后）大滤波通道
struct AD_DATA AD_OUT_STAD_U;  //差值
struct AD_DATA AD_OUT_SCR_I;  //ACTIVECROWBAR电流  
 

float  AD_OUT_UDC; //AD计算后输出的直流电压（V）
float  AD_OUT_UDC_PRO; //AD计算后输出的直流电压（V） LVRT保护用Vdc，减小滤波

//求平均值
struct MEAN_DATA{
       float ia,ib,ic;  	//交流侧电流平均值滤波
	   float idc;  			//直流侧电流平均值滤波
	   float uab,ubc;	   	//交流侧线电压平均值滤波
	   float ua,ub,uc;	   	//交流侧相电压平均值滤波
       float ia2;  			//380V侧电流平均值滤波
	   float udc;			//直流侧电压平均值滤波

	   float zfia1,zfib1,zfic1; 	//网侧电流传感器零漂滤波
	   float zfuab,zfubc; 			//网侧电压传感器零漂滤波
	   float zfidc;					//直流侧电流传感器零漂滤波
	   float zfia2;					//380V侧电流传感器零漂滤波

}MEAN_DATA;  

//保护模块结果变量
struct	PRO{									
				float	Uab;	//交流侧 ab线电压实际值(V)
				float	Ubc;	//交流侧 bc线电压实际值(V)
				float   Ua;	  	//交流侧a相电压V RMS
				float   Ub;	  	//交流侧b相电压V RMS
				float   Uc;	  	//交流侧c相电压V RMS
				float   Ia;   	//交流侧A相并网电流有效值,单位A
				float   Ib;	  	//交流侧B相并网电流有效值,单位A
				float   Ic;	  	//交流侧C相并网电流有效值,单位A
   				float   IPM_tempa; //IPM模块A相温度
				float   IPM_tempb; //IPM模块B相温度
				float   IPMtempmax;//IPM模块的温度最大值
   				float   L_temp; //电感温度
				float   T_temp; //变压器温度 


	         	float	NPR_iac;								//并网电流峰值,基准电流的百分值
				float	MPR_iac;								//定子电流峰值,基准电流的百分值
				float	udc;									//中间直流电压正实际值(V)
				float	NPR_uab;								//网侧 ab线电压实际值(V)
				float	NPR_ubc;								//网侧 bc线电压实际值(V)
				float	STA_uab;								//定子侧 ab线电压实际值(V)
				float	STA_ubc;								//定子侧 bc线电压实际值(V)
				float	GID_uab;								//电网侧 ab线电压实际值(V) 20091026atzy
				float	GID_ubc;								//电网侧 bc线电压实际值(V) 20091026atzy
				float	rcvr;									//延迟恢复时间
				float   STA_iac;                            	//定子交流电流iac
				float   STA_iba;                            	//定子交流电流iba
				float   speed;                               	//电机转速 r/min
				float   speedflt;                               //20090815
				float   sta_iar;	  							//定子侧a相电流A RMS
				float   sta_ibr;	  							//定子侧b相电流A RMS
				float   sta_icr;	  							//定子侧c相电流A RMS
				float   sta_uar;	  							//定子侧a相电压V RMS
				float   sta_ubr;	  							//定子侧b相电压V RMS
				float   sta_ucr;	 							//定子侧c相电压V RMS
				float   npr_uar;	  							//网侧a相电压V RMS
				float   npr_ubr;	  							//网侧b相电压V RMS
				float   npr_ucr;	  							//网侧c相电压V RMS
				float   npr_iar;   								//网侧,A相并网电流行е�,单位A
				float   npr_ibr;	  							//网侧,B相并网电流行е�,单位A
				float   npr_icr;	  							//网侧,C相并网电流有效值,单位A
				float   Psactive; 								//定子侧有功功率
				float   Psreactive; 							//定硬辔薰β�
				float   Ps;          							//定子侧视在功率
				float   Pnactive;    							//网侧有功功率
				float   Pnreactive;  							//网侧无功功率
				float   Pn;          							//网侧视在功�
				float   Pgactive;    							//并网总的有功功率	
				float   Pgreactive;  							//网侧总霓功功率				
				float   Pg;       								//⑼艿氖釉诠β�
		   }PRO; 
 
//显示嗫乇淞�
struct	DISP{										
    			float  Iai;   	//交流侧电流瞬时值,单位A
				float  Ibi;	  	//交流侧电流瞬时值,单位A
				float  Ici;	  	//交流侧电流瞬时值,单位A
				float  Ia;		//交流侧电流有效值,单位A
				float  Ib;	  	//交流侧电流有效值,单位A
				float  Ic;	  	//交流侧电流有效值,单位A
    			float  Uab;	  //网侧ab相电压V RMS
				float  Ubc;	  //网侧bc相电压V RMS

				float  L_temp;  //电感温度 摄氏度
				float  T_temp;  //变压器温度 摄氏度
				float  IPM_tempa;  //IPM模块A相温度
				float  IPM_tempb;  //IPM模块B相温度
				float  udc;			//中间直流电压
				float  npridrf;		//d轴电流指令		
				float  npriqrf;		//q轴电流指令
				float  freq;
				float  pionu;   	//网侧电压环输出
				float  pionid;		//网侧电流d环输出
				float  pioniq;		//网侧电流q环输出
				float  Pnactive;    //交流侧有功功率
				float  Pnreactive;  //交流侧无功功率
				float  Pn;          //交流侧视在功率
			}DISP;
 
//痘模块变量
struct CAP_DATA	{
					float		prd;				//Cap4事件周期
					Uint32		adsmptsctr; 		//AD采样时刻的Cap4计数器值(本次AD在CAP4之后运行)
					float 		phase;	    		//事件当前相位//用于相序检查
					float 		freqtmp;			//敬问录德�
					float 		freq;	    		//确认后的频率
					float	    omigasyn;			//同步角频率－电频率
					float 		omigaslp;	    	//转差角频率
					float	    radpertb;			//计数器计单位时间矢量位置增量 rad per timebase
					float	    nprtrstheta;		//网侧算法正变换角度
					float	    npratitheta;		//网侧算法反变换角度
					float	    mprtrstheta;		//机嗨惴ㄕ浠唤嵌�
					float	    mpratitheta;		//机侧算法反变换角度
					float	    stavectheta;	    //定子磁链相对与A相轴线位置	
				};
struct CAP_DATA CAP3,CAP4;

struct QEPDATA{
//----------------------转子位置检测变量-----------------------------------------------------------
					Uint16		qcapprd;		//QCAP单元周期寄存器值，用于测周法算转速
					float 		omigamec;		//机械角速度
					float 		omigarote;	    //电气角俣� rotor electric
					float 		omigaroteflt;	//
					float 		rotpos;			//转子当前位置rad（电弧度）
					Uint32   	adsmposcnt;		//采样时刻编码器读数  
					Uint32 		posilat;        //记录Z信号上升沿时CNT计数值
					Uint32 		qposlat;        //记录Unit time内QEPCNT的计数值，用于测频法算转速
					Uint32 		qposlat1;        //记录Unit time内QEPCNT的计数值，用于测频法算转速
					Uint32 		qposlat2;        //记录Unit time内QEPCNT的计数值，用于测频法算转速
					float 		rotposdisp;		//DA显示
					float 		rotradpret0;	//用于QEP Z信号抗干扰
//----------------------编码器位置检测变量--------------------------------------------------------	
					float 		encodpos;		//编码器位置rad（电弧度）
					float 		u_stapos;		//2S参考系下定子电压矢量的位置rad（电弧度）
					float 		i_rotpos;		//2S参考系下转子电流矢量的位置rad（电弧度）
			  }QEPDATA; 

//SCI模块变量
struct	SCI{
					Uint16 txb[SCI485NUM];			//SCIB发送数据
					Uint16 rxb[SCI485NUM];			//SCIB接收数据	
					int32 cnt_sciover;				//SCI发送/接收超时定时器
					int32 cnt_scispace;				//SCI接收到发送的间隔定时器
		   }SCI;

//SCICANOPEN模块变量
struct	SCI_CANOPEN{
					Uint16 txb[SCICANOPENTXNUM];			//SCIB发送数据
					Uint16 rxb[SCICANOPENRXNUM];			//SCIB接收数据
					Uint16 heartbeat;
					int32  cnt_heartbeat;
					int32  cnt_sciover;
					Uint16 rx_controlword;
					Uint16 rx_npridrf;
					Uint16 rx_npriqrf;
					Uint16 rx_torque;
					Uint16 rx_angle;
					Uint16 tx_torque;
					Uint16 tx_speed;
					Uint16 tx_state1;
					Uint16 tx_state2;	
					Uint16 tx_watertempin;
					Uint16 tx_watertempout;
					Uint16 tx_skiiptempmax;
					Uint16 tx_demand;
		   }SCI_canopen;

//SPI模块变量
struct	SPI{
					Uint16 da7614_txb[SPINUM];		//SPI,DA发送数据
					Uint16 da7614point;				//
		   }SPI;

//EEPROM模块变量
struct	EEPROM{
				Uint16 data[11];					//读出或写入的数据
				Uint16 point;						//EEPROM当前作变量序号
				Uint16 mcode;						//需要修改的功能码名称
			  }EEPROM;

//RTIMER模块变量
struct	RTIMER{
				Uint16 time[6];				//当前时间[5~0]-->年 月 日 时 分 秒（均为8位数据）
			  }RTIMER;

//-----------------------------内部变量----------------------------------------------------------
Uint16  _NULL_VAL=0;
Uint16  _MSG_SCOUT1;												//SCOUT信息级别(前次)
Uint16  _MSG_SCOUT2;												//SCOUT信息级别(本次)
Uint16  _SY_RTRN;
Uint32   POSCNT_TEST;
float   DM_imrd;   						//转子励磁电流
float   DM_imrq;   						//转子励磁电流
float   DM_Lr;							//当前重试次数
float   Te_feedback;                    //实际转矩值反馈
float   Pnactive;    					//网侧有功功率
float   Pnreactive;    					//网侧无功功率
//----------------------------参数变量------------------------------------------------------------
Uint16 _MC_TYPE;						//机型参数
Uint16 _MC_REV;							//软件版本
Uint16 _MC_DATE;						//出厂日期
Uint16 _MC_ID;							//产品编号
Uint16 _SCIB_ADDR;						//485节点地址

Uint16 _SW_FR;							//开关频率(kHz)
Uint16 _DEADTIME;						//脉冲的最小导通时间(us)
Uint16 _COMPTIME;						//脉冲的最小导通时间(ms)
Uint16 _MINONTIME;						//脉冲的最小导通时间(us)

Uint16 _RU_UDCT;						//电压指令积分时间(ms)
Uint16 _RU_IDT;							//电流指令积分时间(ms)
Uint16 _RU_IQT;							//电流指令积分时间(ms)
Uint16 _RU_TOQT;						//转矩指令积分时�(ms)
Uint16 _RU_AGLT;                        //功率因数角指令积分时间(ms)
Uint16 _NIDRF;							//直流电压给定值
Uint16 _MIDRF;							//d轴电流给定值
Uint16 _NIQRF;							//q轴电流给定值
Uint16 _MIQRF;							//q轴电流给定值
Uint16 _TOQRF;							//转矩指令
Uint16 _AGLRF;							//机侧功率因数角
Uint16 _EIDCO;							//手动 机侧励磁电流调整系数
Uint16 _ENCODPOS;						//手动 编码器初始位置角度
Uint16 _EIN;							//
Uint16 _SYSRUN;							//
Uint16 _RESET;							//
Uint16 _STDBY1;							//备用1
Uint16 _STDBY2;							//备用2
Uint16 _STDBY3;							//备用3
Uint16 _STDBY4;							//备用4
Uint16 _STDBY5;							//备用5
Uint16 _STDBY6;							//备用6
Uint16 _STDBY7;							//备用7
Uint16 _STDBY8;							//备用8
float _eidco;
float _encodpos;

float _stdby01;							//备用经过小数点处理后值
float _stdby02;							//备用经过小数点处理后值
float _stdby03;							//备用经过小数点处理后值
float _stdby04;							//备用经过小数点处理后值
float _stdby05;							//备用经过小数点处理后值
float _stdby06;							//备用经过小数点处理后值
float _stdby07;							//备用经过小数点处理后值
float _stdby08;							//备用经∈愦砗蟮
Uint16 _SCOUTL;							//低16个故障码到SCOUT1
Uint16 _SCOUTH;							//高16个故障码到SCOUT2 
//------------------------运行模式变量-------------------------------------------------------------
Uint16 _ENSCR;							//
Uint16 _COMP2;							//电机侧变流器死钩ナ鼓�
Uint16 _AUTOCSTAC;							
Uint16 _OPERATION;						//运行模式
Uint16 _CANOPER;						//系统CAN使能模式

//-----------------------PI凡问淞�--------------------------------------------------------------
Uint16	_NPR_U_Kp;		  		//网侧变流器电压闭环比例系数
Uint16	_NPR_U_Ki;		   		//网侧淞髌鞯缪贡栈坊窒凳�
Uint16	_NPR_U_Kd;		   		//网侧变流器电压闭环微分系数
Uint16	_NPR_U_outmax;			//网侧变流器缪贡栈肥涑鱿薹�
Uint16	_NPR_U_errmax;		 	//网侧变流器电压闭环误差限幅
Uint16	_NPR_U_errmin;		   	//网侧变流器电压闭环误差钚值
Uint16	_NPR_U_incrementmax;	//网侧变流器电压闭环增量限幅

Uint16	_NPR_ID_Kp;				//网侧变流器电流闭繁壤凳�
Uint16	_NPR_ID_Ki;	   			//侧变流器电流闭环积分系数
Uint16	_NPR_ID_Kd;	   			//网侧变流器电流闭环微分系数
Uint16	_NPR_ID_outmax;			//网侧变流器电流闭环输鱿薹�
Uint16	_NPR_ID_errmax;	 		//网侧变流器电流闭环误差限幅
Uint16	_NPR_ID_errmin;	  		//网侧变流器电流闭环误差钚≈�
Uint16	_NPR_ID_incrementmax; 	//网侧变流器电流闭环隽肯薹�

Uint16	_NPR_IQ_Kp;				//网侧变流器电流闭环比例系数
Uint16	_NPR_IQ_Ki;	   			//网侧变髌鞯缌鞅栈坊窒凳�
Uint16	_NPR_IQ_Kd;	   			//网啾淞髌鞯缌鞅栈肺⒎窒凳�
Uint16	_NPR_IQ_outmax;			//网侧变流器电流闭环输出限幅
Uint16	_NPR_IQ_errmax;	 		//网侧变流器电流闭环误差限幅
Uint16	_NPR_IQ_errmin;	  		//网啾淞髌鞯缌鞅环误差最小值
Uint16	_NPR_IQ_incrementmax; 	//网侧变流器电流闭环增量限幅

Uint16	_MPR_U_Kp;	   			//机侧变流器电压闭环比例系数
Uint16	_MPR_U_Ki;	  			//机侧变流器电压闭环积分系数
Uint16	_MPR_U_Kd;	  			//机侧变流器电压闭环微分系数
Uint16	_MPR_U_outmax;	 		//机侧变流器电压闭环输出限幅
Uint16	_MPR_U_errmax;	  		//机侧变流器电压闭环误差限�
Uint16	_MPR_U_errmin;		 	//机侧变流器电压闭环误差最小值
Uint16	_MPR_U_incrementmax; 	//机侧变流器电压闭环增量限幅

Uint16 _MPR_ID_Kp;				//机侧变流器电流闭环比例系数
Uint16 _MPR_ID_Ki;				//机侧变流器电流闭环积分系数
Uint16 _MPR_ID_Kd;				//机侧变流器电流闭环微分系数
Uint16 _MPR_ID_outmax;			//机侧变流器电流闭环输出限幅
Uint16 _MPR_ID_errmax;			//机侧淞髌鞯缌鞅栈肺蟛钕薹�
Uint16 _MPR_ID_errmin;			//机侧变流器电流闭环误差最小值
Uint16 _MPR_ID_incrementmax;		//机侧变流器电流闭环增量限幅

Uint16 _MPR_IQ_Kp;				//机侧变流器电流闭环比例系数
Uint16 _MPR_IQ_Ki;				//机侧变流器电流闭环积分系数
Uint16 _MPR_IQ_Kd;				//机侧变流器电流闭环微分系数
Uint16 _MPR_IQ_outmax;			//机侧变流器电流闭环输出限幅
Uint16 _MPR_IQ_errmax;			//机侧变流器电流闭环误差限幅
Uint16 _MPR_IQ_errmin;			//机侧变流器电流闭环误差最小值
Uint16 _MPR_IQ_incrementmax;	//机侧变流器电流闭环增量限幅


Uint16	_DYN_U_Kp;	   			//机侧变流器电压闭环比例系数
Uint16	_DYN_U_Ki;	  			//机侧变流器电压闭环积分系数
Uint16	_DYN_U_Kd;	  			//机侧变流器电压闭环微分系数
Uint16	_DYN_U_outmax;	 		//机侧变流器电压闭环输出限幅
Uint16	_DYN_U_errmax;	  		//机侧变流器电贡环误差限幅
Uint16	_DYN_U_errmin;		 	//机侧变流器电压闭环误差最小值
Uint16	_DYN_U_incrementmax; 	//机侧变流器电贡栈吩隽肯薹�


Uint16 _SC_RTRN;													//故障最大重试次数
Uint16 _SC_RTRT;													//两次故障重试间隔时间(ms)

Uint16 _SC_IACOV1;													//瞬时倒鞅；ぶ担嫉缌鞯陌俜种�)
Uint16 _SC_UDCOV;													//中间直流电压过压值(V)
Uint16 _SC_UDCOVH;													//中间直流电压过压值（网压跌落）(V)
Uint16 _SC_UDCLV;													//中间直流电压欠压值(V)
Uint16 _SC_VDCON;													//上电电压
Uint16 _SC_UACOV1;													//网压交流电压过压动作值(V)
Uint16 _SC_UACLV1;													//交流电压缺相动作值(V)
Uint16 _SC_IACOV2;													//反时限过流保护值，基准电流的百分值)
Uint16 _SC_PGOV;													//
Uint16 _SC_QGOV;													//
Uint16 _SC_IACOVST;                                                 //定子电流过流保护 

Uint16 _BA_ERR4;													//第四次故障信息
Uint16 _BA_ERR3;													//第三次故障信息
Uint16 _BA_ERR2;													//第二次收闲畔�
Uint16 _BA_ERR1;													//第一次故障信息
//--------------------------------报警信息变�-----------------------------------------------------
Uint16 _BA_ENIDRF;													//最新故障时刻 d轴电流指令(A)
Uint16 _BA_ENIQRF;													//最新故障时刻 q轴电流指令(A)
Uint16 _BA_EMIQRF;													//最新故障时刻 q轴电流指令(A)
Uint16 _BA_ETOQRF;													//最新故障时刻 转矩指令(NM)
Uint16 _BA_EURF;													//最新故障时刻 中间直流电压给定(V)
Uint16 _BA_EUDC;													//最新故障时刻 中间直流电压(V)
Uint16 _BA_EAGLRF;													//最新故障时刻 无功角度指令()
Uint16 _BA_EIA1;													//最新故障时刻 网侧A相电流有效值(A)
Uint16 _BA_EIB1;													//最新故障时刻 网侧B相电流有效值(A)
Uint16 _BA_EIC1;													//最新故障时刻 网侧C相电流有效值(A)
Uint16 _BA_EIA2;													//最新故障时刻 缁郃相电流有效值(A)
Uint16 _BA_EIB2;													//最新故障时刻 电机侧B嗟缌饔行е�(A)
Uint16 _BA_EIC2;													//最新故障时刻 电机侧C相电流有效值(A)
Uint16 _BA_EUAB1;													//最新故障时刻 网侧A相电压有效值(V)
Uint16 _BA_EUBC1;													//最新故障时刻 网侧B相电压有效值(V)
Uint16 _BA_EUAB2;													//最新故障时刻 网侧相电压有效值(V)
Uint16 _BA_EUBC2;													//最新故障时刻 电机侧A相电流有效值(V)
Uint16 _BA_EUAB0;													//最新故障时刻 主断前AB线电压有效值(V)
Uint16 _BA_EUBC0;													//最新故障时刻 主断前BC线电压有效值(V)
Uint16 _BA_EFREQ;													//最新故障时刻 电网频率(hz)
Uint16 _BA_ESPEED;													//最新故障时刻 电机转速(rpm)
Uint16 _BA_ENPRUD;              			//d轴主断后网压反馈20091026atzy
Uint16 _BA_ENPRUQ;          				//q轴主断后网压反馈20091026atzy
Uint16 _BA_ENPRUD2;          				//d轴主断后网压反馈 滤波后20091026atzy
Uint16 _BA_ENPRUQ2;          				//q轴主断后网压反馈 滤波后20091026atzy
Uint16 _BA_ENUDOUT;          				//网侧d轴电压输出20091026atzy
Uint16 _BA_ENUQOUT;          				//网侧q轴电压输出20091026atzy
Uint16 _BA_ETA1;													//最新故障时刻 网侧变流器A桥臂温度
Uint16 _BA_ETB1;													//最新故障时刻 网侧变流器B桥臂温度
Uint16 _BA_ETC1;													//最新故障时刻 网侧变流器C桥臂温度
Uint16 _BA_ETA2;													//最新故障时刻 电机侧变流器A疟畚露�
Uint16 _BA_ETB2;													//最新故障时刻 电机侧淞髌鰾桥臂温度
Uint16 _BA_ETC2;													//最新故障时刻 电机侧变流器C桥臂温度
Uint16 _BA_EPIONU;													//最新故障时刻 网侧电压环输出
Uint16 _BA_EPIONID;													//最新故障时刻 网侧d轴电流环输出
Uint16 _BA_EPIONIQ;													//最新故障时刻 网侧q轴电流环输出
Uint16 _BA_EMEXI;													//最新故障时刻 机侧励磁理论计算值显示
Uint16 _BA_EPIOMID;													//最新故障时刻 机侧d轴电流环输出
Uint16 _BA_EPIOMIQ;													//最新故障时刻 机侧q轴电流环输出
Uint16 _BA_ETLAC;													//最新故障时刻 网侧电感温度
Uint16 _BA_ETLDUDT;													//最新故障时刻 机侧电感温度
Uint16 _BA_ETSKIIP;													//最新故障时刻 SKIIP温度
Uint16 _BA_ESTAIAC;	
Uint16 _BA_ESTAIBA;	
Uint16 _BA_ETOQFB;	
Uint16 _BA_EPSTA;	
Uint16 _BA_EPNPR;	
Uint16 _BA_EPGRID;	

Uint16 _BA_TIME4_0;													//最新故障时间(秒)
Uint16 _BA_TIME4_1;													//最新故障时间(�)
Uint16 _BA_TIME4_2;													//最新故障时间(时)
Uint16 _BA_TIME4_3;													//最新故障时间(日)
Uint16 _BA_TIME4_4;													//最新故鲜奔�(月)
Uint16 _BA_TIME4_5;													//最新故障时间(年)

Uint16 _BA_TIME3_0;													//第三次故障时间(秒)
Uint16 _BA_TIME3_1;													//第三次故障时间(分)
Uint16 _BA_TIME3_2;													//第三次故障时间(时)
Uint16 _BA_TIME3_3;													//第三次故障时间(日)
Uint16 _BA_TIME3_4;													//第三次故障时间(月)
Uint16 _BA_TIME3_5;													//第三次故障时间(年)

Uint16 _BA_TIME2_0;													//第二次故障时间(秒)
Uint16 _BA_TIME2_1;													//第二次故障时间(分)
Uint16 _BA_TIME2_2;													//第二次故障奔?时)
Uint16 _BA_TIME2_3;													//第二次故障时间(日)
Uint16 _BA_TIME2_4;													//第二次故障时间(月)
Uint16 _BA_TIME2_5;													//第二次故障时?年)

Uint16 _BA_TIME1_0;													//第一次故障时间(秒)
Uint16 _BA_TIME1_1;													//第一次故障时间(分)
Uint16 _BA_TIME1_2;													//第一次故障时间(时)
Uint16 _BA_TIME1_3;													//第一次故障时间(日)
Uint16 _BA_TIME1_4;													//第一次
Uint16 _BA_TIME1_5;													//第一次故障时间(年)

//-------------------------------------运行监控变量-----------------------------------------------
Uint16 _BA_MIDRF;													//d轴电流指令(A)
Uint16 _BA_NIQRF;													//q轴电流指令(A)
Uint16 _BA_MIQRF;													//q轴电流指令(A)
Uint16 _BA_TOQRF;													//转矩指令(NM)
Uint16 _BA_AGLRF;													//无功角度指令(NM)
Uint16 _BA_TOQFB;													//转矩反馈(NM)
Uint16 _BA_URF;														//中间直流电压给定(V)
Uint16 _BA_UDC;														//中间直流缪�(V)
Uint16 _BA_IA1;														//网郃相电流有效值(A)
Uint16 _BA_IB1;														//网侧B相流有е?A)
Uint16 _BA_IC1;														//网侧C相电流有效值(A)
Uint16 _BA_IA2;														//电机侧A相电流有效值(A)
Uint16 _BA_IB2;														//电机侧B相电流有效值(A)
Uint16 _BA_IC2;														//电机侧C相电流有效值(A)
Uint16 _BA_UAB1;													//网侧AB线电压有效值(V)
Uint16 _BA_UBC1;													//网侧BC线电压有效值(V)
Uint16 _BA_UAB2;													//电机侧AB线电压有效值(V)
Uint16 _BA_UBC2;													//电机侧BC线电流有效值(V)
Uint16 _BA_UAB0;												    	//主断前AB线电压有效值(V)
Uint16 _BA_UBC0;												    	//主断前BC线电流有效值(V) 
Uint16 _BA_FREQ;													//电网频�(hz)
Uint16 _BA_SPEED;													//电机转速(rpm)
Uint16 _BA_TA1;														//网侧变流器A桥畚露
Uint16 _BA_TB1;														//网侧变流鰾桥臂温度
Uint16 _BA_TC1;														//网侧变流器C桥臂温度
Uint16 _BA_TA2;														//电机侧变流器A桥臂温度
Uint16 _BA_TB2;														//电机侧变流器B桥臂温度
Uint16 _BA_TC2;														//电机侧变流器C桥臂温度
Uint16 _BA_PIONU;													//网侧电压环输出
Uint16 _BA_PIONID;													//网侧d轴电流环输出
Uint16 _BA_PIONIQ;													//网侧q轴电流环输出
Uint16 _BA_MEXI;													//
Uint16 _BA_PIOMID;													//机侧d轴电流环输出
Uint16 _BA_PIOMIQ;													//机侧q轴电流环输出
Uint16 _BA_GRDUD;													//传感器测量网压d
Uint16 _BA_GRDUQ;													//传感器测量网压q
Uint16 _BA_STAUD;													//定子电压d
Uint16 _BA_STAUQ;													//定子电筿
Uint16 _BA_STAID;													//传感器测量网压d
Uint16 _BA_STAIQ;													//传感器测量网压q
Uint16 _BA_EXCID;													//传感器测量网压d
Uint16 _BA_EXCIQ;
Uint16 _BA_TLAC;
Uint16 _BA_TLDUDT;
Uint16 _BA_TNSKIIP;
Uint16 _BA_TMSKIIP;
Uint16 _BA_STAUABD;													//定子同步并网前定子前后电压差
Uint16 _BA_STAUBCD;													//定子同步并网前定子前后电压差
Uint16 _BA_STAIAC;													//定子线电流有效值显示
Uint16 _BA_STAIBA;													//定子线电流有效值显示
Uint16 _BA_PSTA;
Uint16 _BA_PNPR;
Uint16 _BA_PGRID;
Uint16 _BA_QSTA;
Uint16 _BA_QNPR;
Uint16 _BA_QGRID;
Uint16 _BA_SSTA;
Uint16 _BA_SNPR;
Uint16 _BA_SGRID;

Uint16 _SC_NPR_TLOV;
Uint16 _SC_MPR_TLOV;
Uint16 _SC_LVUDC1;
Uint16 _SC_LVUDC2;
Uint16 _SC_LVIAC2;
Uint16 _SC_TSCRON;
Uint16 _SC_MPR_UD;
Uint16 _SC_MPR_UQ;
Uint16 _SC_MSPEED1;
Uint16 _SC_MSPEED2;
Uint16 _SC_UDSTAC;
Uint16	_SCIB_BAUD;													//485波特率
Uint16  _BA_LEDV;
Uint16  _BA_LEDB;
//-----------------------测试用变量-----------------------------------------------------------

int32 	zys = 0;
int16 	zys1,zys2,zys3,zys4;
Uint32 	i_cnt1=0;  //用于CCS波形显示
Uint32 	i_cnt2=0;  //用于CCS波形显示
Uint32 	i_cnt3=0;  //用于CCS波形显示
float   draw1[150]={0.0},draw2[150]={0.0},draw3[150]={0.0},draw4[150]={0.0},draw5[150]={0.0};
float   draw6[150]={0.0};//,draw7[100]={0.0},draw8[100]={0.0},draw9[100]={0.0},draw10[100]={0.0};
Uint16 zsector = 0;
float testtheta;


//------------------------光伏变量-------------------------------

struct AD_DATA AD_OUT_I;  //电流采样
float   MPPT_Pnactive;		//计算MPPT时的有功功率
float   Pnactive_pre;	//上一次的网侧有功功率
float   GIVE_NPR_Id_pre;	//上一次的电流给定值
Uint32 	MPPT_cnt=0;		//计算MPPT时的计数
Uint32 	cnt_Island_U=0;	//被动孤岛保护电压计数值
Uint32 	cnt_Island_F=0;	//被动孤岛保护频率计数值
float	MPPT_Time;		//计算最大功率点的时间
float	MPPT_Id;		//计算最大功率点时每次增加的电流值

struct	Island{
				float	DetaT;
				float	x;
				float	k; 
			}Island;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif

//===========================================================================
// No more.
//===========================================================================
