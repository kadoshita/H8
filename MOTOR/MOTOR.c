/***********************************************************************/
/*                                                                     */
/*  FILE        :MOTOR.c                                               */
/*  DATE        :Tue, Jan 09, 2018                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :H8/3687                                               */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.16).    */
/*                                                                     */
/***********************************************************************/
                  
#include "iodefine.h";
#include <machine.h>

void main(void);
#ifdef __cplusplus
extern "C" {
void abort(void);
}
#endif

int isTurn=0;

void SW1(){
	isTurn=!isTurn;
	if(isTurn){
		TZ0.GRC=0;
		TZ0.TCNT=0;
		TZ.TOER.BIT.EC0=0;
		TZ.TSTR.BIT.STR0=1;
	}else{
		TZ.TOER.BIT.EC0=1;
		TZ.TSTR.BIT.STR0=0;
	}
	IRR1.BIT.IRRI0=0;
}

void main(void){
	unsigned int ad_data1=0;
	
	AD.ADCSR.BYTE=0x16;
	
	set_imask_ccr(1);
	IO.PMR1.BYTE=0x30;
	IEGR1.BYTE=0x00;
	IENR1.BYTE=0x0F;
	IRR1.BYTE=0x30;
	
	TZ0.TCR.BYTE=0x23;
	TZ0.POCR.BYTE=0xF8;
	TZ.TPMR.BYTE=0x8E;
	TZ.TOCR.BYTE=0x0C;
	TZ0.GRA=25000;
	TZ0.GRC=0;
	TZ0.GRD=0;
	set_imask_ccr(0);
	
	for(;;){
		AD.ADCSR.BIT.ADST=1;
		
		for(;AD.ADCSR.BIT.ADF!=1;){}
		
		ad_data1=AD.ADDRB>>6;
		ad_data1=(int)((double)ad_data1*25000/1023.00);
		TZ0.GRC=ad_data1;
	}
}

#ifdef __cplusplus
void abort(void)
{

}
#endif
