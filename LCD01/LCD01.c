/***********************************************************************/
/*                                                                     */
/*  FILE        :LCD01.c                                               */
/*  DATE        :Fri, Oct 20, 2017                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :H8/3687                                               */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.16).    */
/*                                                                     */
/***********************************************************************/
                  
#include "iodefine.h";
#include "lcd_func.h";

void main(void);
#ifdef __cplusplus
extern "C" {
void abort(void);
}
#endif

void main(void)
{
	lcd_init();
	lcd_xy(2,1);
	lcd_puts("�������޸�ޯ��");
	lcd_xy(4,2);
	lcd_dataout(1234567890);
}

#ifdef __cplusplus
void abort(void)
{

}
#endif
