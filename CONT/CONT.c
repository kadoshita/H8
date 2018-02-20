/***********************************************************************/
/*                                                                     */
/*  FILE        :CONT.c                                                */
/*  DATE        :Fri, Jan 12, 2018                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :H8/3687                                               */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.16).    */
/*                                                                     */
/***********************************************************************/

/*
* A相:P50
* B相:回転方向の検出を行っていないため、未使用
* 左側フォト・マイクロセンサ(モータ側):P51
* 右側フォト・マイクロセンサ(モータの逆側):P52
* モータ電源+:J7-1
* モータ電源-:J7-2
* フォトマイクロセンサプルアップ:内部
* フォトマイクロセンサ、動作モード:遮光時
*/

#include "iodefine.h";
#include <machine.h>

#define MSK_WKP0 0x01
#define MSK_WKP1 0x02
#define MSK_WKP2 0x04

void main(void);
#ifdef __cplusplus
extern "C" {
void abort(void);
}
#endif

int count=0;
int movedist=0;

void moveRight(int dist){
	movedist=(dist/(15.5*3.14))*600;
	TZ0.GRC=18750;
	TZ.TOER.BIT.EC0=0;
	TZ.TOER.BIT.ED0=1;
	TZ0.TCNT=0;
	TZ.TSTR.BIT.STR0=1;
}
void moveLeft(int dist){
	movedist=(dist/(15.5*3.14))*600;
	TZ0.GRD=18750;
	TZ.TOER.BIT.EC0=1;
	TZ.TOER.BIT.ED0=0;
	TZ0.TCNT=0;
	TZ.TSTR.BIT.STR0=1;
}
void stop(){
	count=0;
	movedist=0;
	TZ.TOER.BIT.EC0=1;
	TZ.TOER.BIT.ED0=1;
	TZ.TSTR.BIT.STR0=0;
	IRR1.BIT.IRRI0=0;
	TZ0.GRC=0;
	TZ0.GRD=0;
}

void SW1(){
	moveLeft(500);
	IRR1.BIT.IRRI0=0;
}
void SW2(){
	moveLeft(50);
	IRR1.BIT.IRRI1=0;
}
void SW3(){
	moveRight(50);
	IRR1.BIT.IRRI2=0;
}
void SW4(){
	moveRight(500);
	IRR1.BIT.IRRI3=0;
}
void WKP(){
	if((IWPR.BYTE&MSK_WKP0)==MSK_WKP0){
		count++;
			
		if(movedist==count){
			stop();
		}
		IWPR.BIT.IWPF0=0;
		return;
	}
	
	if((IWPR.BYTE&MSK_WKP1)==MSK_WKP1){
		stop();
		IWPR.BIT.IWPF1=0;
		return;
	}
	
	if((IWPR.BYTE&MSK_WKP2)==MSK_WKP2){
		stop();
		IWPR.BIT.IWPF2=0;
		return;
	}
}

void main(void){	
	set_imask_ccr(1);
	IO.PMR1.BYTE=0xF0;
	IEGR1.BYTE=0x00;
	IENR1.BYTE=0x1F;
	IRR1.BYTE=0x30;
	
	TZ0.TCR.BYTE=0x23;
	TZ0.POCR.BYTE=0xF8;
	TZ.TPMR.BYTE=0x8E;
	TZ.TOCR.BYTE=0x0C;
	TZ0.GRA=25000;
	TZ0.GRC=0;
	TZ0.GRD=0;
	
	IO.PMR5.BYTE=0x07;
	IO.PUCR5.BYTE=0x07;
	IEGR2.BYTE=0x00;
	IENR1.BIT.IENWP=1;
	IWPR.BYTE=0x00;
	set_imask_ccr(0);
	
	while(1);
}

#ifdef __cplusplus
void abort(void)
{

}
#endif
