 
#include "DSP2833x_Project.h"
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include <stdio.h>
#include <string.h>

#include "user_header.h"
#include "user_macro.h"
#include <math.h>

#define DELAY 35.700L

//////// ADC start parameters ////////
#define ADC_MODCLK 0x3 // HSPCLK = SYSCLKOUT/2*ADC_MODCLK2 = 150/(2*3)   = 25.0 MHz
#define ADC_CKPS   0x0   // ADC module clock = HSPCLK/1      = 25.5MHz/(1)   = 25.0 MHz
#define ADC_SHCLK  0x1   // S/H width in ADC module periods                  = 2 ADC cycle
#define AVG        1000  // Average sample limit
#define ZOFFSET    0x00  // Average Zero offset
#define BUF_SIZE   256  // Sample buffer size
#define FFT_SIZE 256
#define OFFSET    0.0

#define POST_SHIFT   0  // Shift results after the entire sample table is full
#define INLINE_SHIFT 1  // Shift results as the data is taken from the results regsiter
#define NO_SHIFT     0  // Do not shift the results
//////// ////////


//////// FFT function parameters ////////
#define PI 3.14159           //����Բ����ֵ
#define FFT_N 256                                                   //���帣��Ҷ�任�ĵ���



struct compx {float real,imag;};                                    //����һ�������ṹ
struct compx s[FFT_N];
float s_abs[FFT_N];
Uint16 array_index;
Uint16 i;
Uint16 gpio_flag;

struct compx EE(struct compx a,struct compx b)
{
 struct compx c;
 c.real=a.real*b.real-a.imag*b.imag;
 c.imag=a.real*b.imag+a.imag*b.real;
 return(c);
}

//////// ///////


float adoffset;
float adsum;

// Global variable for this example
Uint16 A0Sample[FFT_SIZE];

//Define user function
void SetSys();
void SetAdc();
void FFT(struct compx *xin);
void Sampling(void);



void main(void)
{

////////Confige system start//////
   SetSys();
   InitAdc();
   asm(" RPT #8 || NOP");
   SetAdc();
////////Confige system end //////


   // Clear A0Sample
   for (i=0; i<BUF_SIZE; i++) {A0Sample[i] = 0;}
   // Start SEQ1
   AdcRegs.ADCTRL2.all = 0x2000;

   ////////// Main Loop ////////////
   while(1)
   {
  
     array_index = 0;
     gpio_flag = 1;
     for(i=0; i<(BUF_SIZE/16);i++){Sampling();}
     //After sample complete

     //FFT transform
     for(i=0;i<FFT_N;i++)                           //���ṹ�帳ֵ
      {
#if POST_SHIFT
         s[i].real = (A0Sample[i]>>4)*3.0/4095.0;
#endif
#if  INLINE_SHIFT
         s[i].real = (A0Sample[i])*3.0/4095.0;
#endif
         s[i].imag = 0;
      }
     FFT(s);                                        //���п��ٸ���Ҷ�任

     for(i=0;i<FFT_N;i++)                           //��任������ģֵ�����븴����ʵ������
     s_abs[i] = sqrt(s[i].real*s[i].real+s[i].imag*s[i].imag);

  }
}



///////////////////////////////////////////////////////////////////

// User Define Function

///////////////////////////////////////////////////////////////////


void configtestledON(void)
{
   EALLOW;
    SYSRUN_SET = 1;
   EDIS;
}

void configtestledOFF(void)
{
   EALLOW;
    SYSRUN_CLEAR = 1;
   EDIS;
}
void delay (Uint16 t)
{ Uint16 i;
  while(t--)
  {
     for(i=0;i<125;i++)
      asm(" RPT #3 || NOP"); 
  }
}

void SetAdc()
{
    // Configure ADC
       EALLOW; // set state register
       SysCtrlRegs.HISPCP.all = ADC_MODCLK; // HSPCLK = SYSCLKOUT/ADC_MODCLK
       EDIS; //rest state register
       // Specific ADC setup for this example:
       AdcRegs.ADCTRL1.bit.ACQ_PS = ADC_SHCLK;  // Sequential mode: Sample rate   = 1/[(2+ACQ_PS)*ADC clock in ns]
                               //                     = 1/(3*40ns) =8.3MHz (for 150 MHz SYSCLKOUT)
                               //                     = 1/(3*80ns) =4.17MHz (for 100 MHz SYSCLKOUT)
                               // If Simultaneous mode enabled: Sample rate = 1/[(3+ACQ_PS)*ADC clock in ns]
       AdcRegs.ADCTRL3.bit.ADCCLKPS = ADC_CKPS;
       AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;        // 1  Cascaded mode
       AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0x0;
       AdcRegs.ADCTRL1.bit.CONT_RUN = 1;       // Setup continuous run

       AdcRegs.ADCTRL1.bit.SEQ_OVRD = 1;       // Enable Sequencer override feature
       AdcRegs.ADCCHSELSEQ1.all = 0x0;         // Initialize all ADC channel selects to A0
       AdcRegs.ADCCHSELSEQ2.all = 0x0;
       AdcRegs.ADCCHSELSEQ3.all = 0x0;
       AdcRegs.ADCCHSELSEQ4.all = 0x0;
       AdcRegs.ADCMAXCONV.bit.MAX_CONV1 = 0xF;  // convert and store in 8 results registers
}

/*****************************************************************
����ԭ�ͣ�void FFT(struct compx *xin,int N)
�������ܣ�������ĸ�������п��ٸ���Ҷ�任��FFT��
���������*xin�����ṹ������׵�ַָ�룬struct��
*****************************************************************/
void FFT(struct compx *xin)
{
  int f,m,nv2,nm1,i,k,l,j=0;
  struct compx u,w,t;

   nv2=FFT_N/2;                  //��ַ���㣬������Ȼ˳���ɵ�λ�򣬲����׵��㷨
   nm1=FFT_N-1;
   for(i=0;i<nm1;i++)
   {
    if(i<j)                    //���i<j,�����б�ַ
     {
      t=xin[j];
      xin[j]=xin[i];
      xin[i]=t;
     }
    k=nv2;                    //��j����һ����λ��
    while(k<=j)               //���k<=j,��ʾj�����λΪ1
     {
      j=j-k;                 //�����λ���0
      k=k/2;                 //k/2���Ƚϴθ�λ���������ƣ�����Ƚϣ�ֱ��ĳ��λΪ0
     }
   j=j+k;                   //��0��Ϊ1
  }

  {
   int le,lei,ip;                            //FFT����ˣ�ʹ�õ����������FFT����
    f=FFT_N;
   for(l=1;(f=f/2)!=1;l++)                  //����l��ֵ����������μ���
           ;
  for(m=1;m<=l;m++)                         // ���Ƶ��νἶ��
   {                                        //m��ʾ��m�����Σ�lΪ���μ�����l=log��2��N
    le=2<<(m-1);                            //le���ν���룬����m�����εĵ��ν����le��
    lei=le/2;                               //ͬһ���ν��вμ����������ľ���
    u.real=1.0;                             //uΪ���ν�����ϵ������ʼֵΪ1
    u.imag=0.0;
    w.real=cos((float)PI/(float)lei);                     //wΪϵ���̣�����ǰϵ����ǰһ��ϵ������
    w.imag=-sin((float)PI/(float)lei);
    for(j=0;j<=lei-1;j++)                   //���Ƽ��㲻ͬ�ֵ��νᣬ������ϵ����ͬ�ĵ��ν�
     {
      for(i=j;i<=FFT_N-1;i=i+le)            //����ͬһ���ν����㣬������ϵ����ͬ���ν�
       {
        ip=i+lei;                           //i��ip�ֱ��ʾ�μӵ�������������ڵ�
        t=EE(xin[ip],u);                    //�������㣬�����ʽ
        xin[ip].real=xin[i].real-t.real;
        xin[ip].imag=xin[i].imag-t.imag;
        xin[i].real=xin[i].real+t.real;
        xin[i].imag=xin[i].imag+t.imag;
       }
      u=EE(u,w);                           //�ı�ϵ����������һ����������
     }
   }
  }

}




//------------------------------------------------------------------------------------
 
//------------------------------------------------------------------------------------

 void SetSys(void){
     InitSysCtrl();
     asm(" RPT #8 || NOP");
     DINT;
     InitGpio();
     DINT;

     // Enable the pin GPIO34 as output
     EALLOW;
     GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;    // GPIO pin
     GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;     // Output pin
     EDIS;


     InitPieCtrl();
     DINT;// Disable Interrupts at the CPU level:
     InitFlash();

     IER = 0x0000;
     IFR = 0x0000;
     InitPieVectTable();
 }


void Sampling(void){
    //wait for ADC INT
    while(AdcRegs.ADCST.bit.INT_SEQ1== 0){}
    if(gpio_flag){
        GpioDataRegs.GPBSET.bit.GPIO34 = 1;  // Set GPIO34 for monitoring
        gpio_flag = 0;
    }else{
        GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;  // Clear GPIO34 for monitoring
        gpio_flag = 1;
    }
    AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1; //Clear ADC_INT

#if INLINE_SHIFT
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT0)>>4);
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT1)>>4);
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT2)>>4);
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT3)>>4);
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT4)>>4);
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT5)>>4);
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT6)>>4);
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT7)>>4);

#endif //-- INLINE_SHIFT

#if NO_SHIFT || POST_SHIFT

       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT0));
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT1));
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT2));
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT3));
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT4));
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT5));
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT6));
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT7));

#endif //-- NO_SHIFT || POST_SHIFT

//       while (AdcRegs.ADCST.bit.INT_SEQ1== 0){}
//       GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;  // Clear GPIO34 for monitoring
//       AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;

#if INLINE_SHIFT

       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT8)>>4);
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT9)>>4);
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT10)>>4);
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT11)>>4);
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT12)>>4);
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT13)>>4);
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT14)>>4);
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT15)>>4);

#endif //-- INLINE_SHIFT

#if NO_SHIFT || POST_SHIFT

       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT8));
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT9));
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT10));
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT11));
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT12));
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT13));
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT14));
       A0Sample[array_index++]= ( (AdcRegs.ADCRESULT15));
#endif // -- NO_SHIFT || POST_SHIFT


    GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;  // Clear GPIO34 for monitoring  -optional
}

