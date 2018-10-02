// File Name: counter on 8051
// Author: R.venkatesan
// lcd 16X2 8bit method 
 // lcd pin connection port0 -data pin (D0-D7)
 // control pin lcd conection  RS=P2^7, R/W=P2^6, E=P2^5
 // 8051 have two counter on micro controller

# include <reg51.h>
# include <stdio.h>
# include "lcd.h"  // lcd library 
/* if want change the lcd pin connection open lcd file library change the pin as per your aspect 
 And also remain you change busy flag= bf(used name in lcdlibrary ) also for inlcd pin data  lcd file libary  */
 sfr16 DPTR=0x82;  // 16 bit operater 
 
 void number(int a);
 void main()
 {
  port(); // pulldown the all pin in micro controller
	lcd_initial(); // lcd basic initialization cammand line 
	 TMOD=0x44;  // basic initialization on counter use both counter run
	 
	 //TMOD=0x04; counter one //TMOD=0x40; counter one
	
	 TL1=0x00;
	 TH1=0x00;
	 TL0=0x00;
	 TH0=0x00;  // initial condition start on zero
   TR1=1; TR0=1;          // And run the time
	 
	 while(1)
	 {
	   lcd_com(0x01);  // lcd cammand dispaly frist line
		 lcd_string(" counter0:"); 
		 DPH=TH0;
     DPL=TL0; 
		 number(DPTR);
		 
		 lcd_com (0xc0);  // lcd cammand dispaly second line
		 lcd_string("counter1:");  
		 DPH=TH1;
	   DPL=TL1;
		 number(DPTR);
		 
		  delay(100); // delay for seen the lcd lines display
	 }
		 
 }
	 void number(int a)
	 {
	   lcd_data(a/10000+0x30);
		 lcd_data((a%10000)/1000+0x30);
		 lcd_data((a%1000)/100+0x30);
		 lcd_data((a%100)/10+0x30);
		 lcd_data(a%10+0x30);
	 }