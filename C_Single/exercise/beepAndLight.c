/*这是一个八院“芯梦启航”的个人代码
功能：
1.蜂鸣器“唱歌”——蓝精灵
2.八个灯光<呼吸><爆闪><跑马灯><频率灯>
*/
#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int
#define LED P0			 //LED contral pin
sbit beep = P1 ^ 4;		 //beep contral pin
uchar kind = 0;			 //contral light kind
uchar isFrequentNumber;	 //degree number
uchar timeh, timel;		 //contral degree time
uchar code isHorse[] = { //Horse Race light
	0xfb, 0xef, 0xbf, 0x7f, 0xdf, 0xf7, 0xfd};
uchar code isMelody[] = {
	0x02, 0x31, 0x41,
	0x52, 0x42, 0x32, 0x42, 0x52, 0x42, 0x32, 0x42,
	0x52, 0x51, 0x41, 0x52, 0xa2, 0x85, 0x21, 0x31,
	0x42, 0x32, 0x42, 0x92, 0x75, 0x21, 0x31,
	0x42, 0x32, 0x42, 0x62, 0x55, 0x31, 0x41,
	0x52, 0x42, 0x32, 0x42, 0x52, 0x42, 0x32, 0x42,
	0x52, 0x51, 0x41, 0x52, 0xa2, 0x95, 0x21, 0x31,
	0x42, 0x32, 0x42, 0x92, 0x82, 0x72, 0x62, 0x72,
	0x8c, 0x54,
	0x54, 0xa2, 0xa2, 0x84, 0x54,
	0x3c, 0x54,
	0x44, 0x92, 0x92, 0x74, 0x44,
	0x2c, 0x22, 0x31, 0x41,
	0x52, 0x42, 0x32, 0x42, 0x52, 0x42, 0x32, 0x42,
	0x52, 0x51, 0x41, 0x52, 0x82, 0xa6, 0x21, 0x31,
	0x42, 0x32, 0x42, 0x92, 0x82, 0x72, 0x62, 0x72,
	0x8c, 0x04};
uchar code isTimeRule[] = {
	0xff, 0xff, //take place
	0xFC, 0x44, //middle
	0xFC, 0xac,
	0xFd, 0x0a,
	0xFD, 0x34,
	0xFD, 0x82,
	0xFD, 0xc8,
	0xFE, 0x06,
	//	0xf8,0x85, //deep
	//	0xf9,0x5a,
	//	0xfa,0x13,
	//	0xfa,0x68,
	//	0xfb,0x04,
	//	0xfb,0x90,
	//	0xfc,0x0c
	0xFe, 0x21, //high
	0xFe, 0x56,
	0xFe, 0x85,
	0xFe, 0x9a,
	0xFe, 0xc1,
	0xFe, 0xe4,
	0xFf, 0x03};
void delay(uint z);
void delay2(uint i);
void delay1(uint z);

void main()
{
	uint temp;
	uint pwm_high, pwm_low;
	uchar i = 0;
	TMOD = 0X11;
	ET1 = 1;
	ET0 = 1;
	EA = 1;
	LED = 0x00;
	TR1 = 1;
	for (pwm_high = 1; pwm_high < 600; pwm_high++)
	{
		LED = 0xFF;
		delay2(pwm_high);
		LED = 0x00;
		pwm_low = 600 - pwm_high;
		delay2(pwm_low);
	}
	delay1(1000);
	while (1)
	{
		temp = isMelody[i]; //read song
		if (temp == 0xff)
			break;
		isFrequentNumber = temp / 16; //degree
		if (isFrequentNumber != 0)
		{
			timeh = isTimeRule[isFrequentNumber * 2];
			timel = isTimeRule[isFrequentNumber * 2 + 1];
			TR0 = 1;
		}
		else
		{
			TR0 = 0;
			beep = 1;
		}
		delay(temp % 16);
		TR0 = 0;
		i++;
	}
}
void timer1() interrupt 3 //stop timer 1
{
	static uint number = 0;
	number++;
	if (kind == 0) //控制模式0
	{
		LED = ~LED;
	}
	if (kind == 1) //控制模式1
	{
		if (number % 10 == 0)
		{
			uint tmp = number / 10;
			LED = isHorse[tmp - 1];
		}
	}
	if (kind == 2) //控制模式2
	{
		if (number % 10 == 0)
		{
			uint tmp = 8 - number / 10;
			LED = isHorse[tmp - 1];
		}
	}
	if (kind >= 3) //控制模式3
	{
		if (isFrequentNumber < 2)
			LED = 0xfc;
		if (isFrequentNumber < 5 && isFrequentNumber > 1)
			LED = 0xf0;
		if (isFrequentNumber < 7 && isFrequentNumber > 4)
			LED = 0xc0;
		if (isFrequentNumber >= 7)
			LED = 0x00;
	}
	if (number >= 77)
	{
		kind++;
		LED = 0xfe;
		number = 0;
	}
}
void timer0() interrupt 1 //stop timer 0
{
	TH0 = timeh;  //high 8
	TL0 = timel;  //low 8
	beep = ~beep; //trun over
}
void delay(uint z) //delay 168*zms maybe
{
	uint y;
	for (z; z > 0; z--)
		for (y = 19000; y > 0; y--)
			;
}
void delay2(uint i) //ius
{
	while (i--)
		;
}
void delay1(uint z) //delay zms
{
	uint y;
	for (z; z > 0; z--)
		for (y = 112; y > 0; y--)
			;
}