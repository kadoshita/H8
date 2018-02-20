/***********************************************************************/
/*                                                                     */
/*  FILE        :serial01.c                                            */
/*  DATE        :Fri, Dec 22, 2017                                     */
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

void func_sci(){
	IO.PDR3.BYTE=SCI3.RDR;
	
}
void wait(){
	int i=0;
	for(i=0;i<10000;i++){
		
	}
}
void main(void)
{
	IO.PCR3=0xFF;
	IO.PDR3.BYTE=0x00;
	SCI3.SCR3.BIT.RE=0;
	SCI3.SMR.BYTE=0x00;
	SCI3.BRR=64;
	
	wait();
	
	SCI3.SCR3.BIT.RE=1;
	SCI3.SCR3.BIT.RIE=1;
	
	while(1);
}

#ifdef __cplusplus
void abort(void)
{

}
#endif
