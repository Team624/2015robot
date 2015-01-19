#include <Adafruit_NeoPixel.h>
#include "Wire.h"

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(120, PIN, NEO_GRB + NEO_KHZ800);
bool on = true;
#include "utilities.h"
#include "packets.h"

void setup() {
	pinMode(PIN,OUTPUT);
	
	Wire.onReceive(getPackets);
	Wire.begin(2);
	
	strip.begin();
	strip.show(); // Initialize all pixels to 'off'
}

void loop() {
	//fillStrip(strip.Color(0,0,0),0);
	//laser();
	//bouncelaser();
	//strobe();
	strobepulse();
//	toteCount();
 /*
if(newData)
{
	if(gameState==MODE_TELEOP)
	{
		if(unload==0)
		{
			if(newTote)
			{
				newTote=addTote();
			}
			else if(newBin)
			{
				newBin=addBin();
			}
			else
			{
				toteCount();
			}
		}
		else
		{
			
		}
	}
	else if(gameState==MODE_AUTO)
	{
		pixelate();
	}
	else if(gameState==MODE_DISABLED)
	{
		strobepulse();
	}
	else
	{
		rainbow(50);
	}
	
	newData=false;
}

 */
	//win();
	//scanner();
	//sixtwofour();
	
	
	//rainbow(10);
	//rainbowlaser();
	
	//pixelate();
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void laser()
{
	uint16_t i, c, w;
	c=strip.Color(0,255,0);
	
	w=7;
	
	for(i=0;i<(strip.numPixels()+w);i++)
	{
		strip.setPixelColor(i,c);
		strip.setPixelColor(i-w,0);
		//strip.setPixelColor(i+5,0);
		strip.show();
		delay(15);
	}
	
}

void rainbowlaser()
{
	uint32_t ii, c, w, r,o,y,g,b,i,v;
	r=strip.Color(255,0,0);
	o=strip.Color(255,128,0);
	y=strip.Color(255,255,0);
	
	g=strip.Color(0,255,0);
	
	b=strip.Color(0,0,255);
	ii=strip.Color(128,0,255);
	v=strip.Color(255,0,255);
	
	w=12;
	for(i=0;i<(strip.numPixels()+w);i++)
	{
		strip.setPixelColor(i,r);
		strip.setPixelColor(i-2,o);
		strip.setPixelColor(i-4,y);
		strip.setPixelColor(i-6,g);
		strip.setPixelColor(i-8,b);
		strip.setPixelColor(i-10,ii);
		strip.setPixelColor(i-12,v);
		strip.setPixelColor(i-w,0);
		strip.show();
		delay(15);
	}
}

void bouncelaser()
{
	uint16_t i, c, w;
	c=strip.Color(0,255,0);
	
	w=7;
	
	for(i=0;i<(strip.numPixels()+(w-3));i++)
	{
		strip.setPixelColor(i,c);
		strip.setPixelColor(i-w,0);
		//strip.setPixelColor(i+5,0);
		strip.show();
		delay(15);
	}
	
	for(i=strip.numPixels()-(w-3);(i+3)>0;i--)
	{
		strip.setPixelColor(i,c);
		strip.setPixelColor(i+w,0);
		//strip.setPixelColor(i+5,0);
		strip.show();
		delay(15);
	}
	
}

void toteCount()
{
	uint16_t i,ii, c, cc;
	uint8_t w, b;
	c=strip.Color(0,255,0);
	cc=strip.Color(255,255,0);
	//i=0;
	w=totes*17;
	for(i=0; i<w; i++)
	{
		strip.setPixelColor(i,strip.Color(0,255,0));
	}
	b=bins*45;
	for(ii=w; ii<(w+b); ii++)
	{
		strip.setPixelColor(ii,strip.Color(255,255,0));
	}
	//strip.setPixelColor(w,c);
	//strip.setPixelColor(0,0);
	//strip.setPixelColor(i+5,0);
	strip.show();
	
}

void strobe()
{
	uint16_t i, c;
	c=strip.Color(0,255,0);
	
	if(on)
	{
		fillStrip(c, 255);
		on = false;
	}
	else
	{
		fillStrip(strip.Color(0,0,0), 255);
		on=true;
	}
	delay(300);
	strip.show();
}


void strobepulse()
{
	uint16_t i, c;
	c=strip.Color(0,255,0);
	
	for(i=0;i<=255;i+=5)
	{
		fillStrip(c, i);
		strip.show();
		delay(10);
	}
	
	for(i=255;i>0;i-=5)
	{
		fillStrip(c, i);
		strip.show();
		delay(10);
	}
	
}
void sixtwofour()
{
	uint16_t i, c, s, t, f;
	c=strip.Color(0,255,0);
	
	s=6;
	t=2;
	f=4;
	
	for(i=0;i<(strip.numPixels()+s+t+f+15);i++)
	{
		strip.setPixelColor(i,c);
		strip.setPixelColor(i-s,0);
		strip.setPixelColor(i-s-5,c);
		strip.setPixelColor(i-s-5-t,0);
		strip.setPixelColor(i-s-5-t-5,c);
		strip.setPixelColor(i-s-5-t-5-f,0);
		strip.setPixelColor(i-s-5-t-5-f-5,0);
		//strip.setPixelColor(i+5,0);
		strip.show();
		delay(50);
	}
}

void win()
{
	uint32_t i,u,s,a;
	u=strip.Color(255,0,0);
	s=strip.Color(255,255,255);
	a=strip.Color(0,0,255);
	
	for(i=0;i<(strip.numPixels()+1+3+3+3+3+5+1+3+1+5+3+3+1);i++)
	{
		strip.setPixelColor(i,u);
		strip.setPixelColor(i-1,0); //dot
		strip.setPixelColor(i-1-3,u);//space
		strip.setPixelColor(i-1-3-3,0);//dash
		strip.setPixelColor(i-1-3-3-3,u);//space
		strip.setPixelColor(i-1-3-3-3-3,0);//dash
		strip.setPixelColor(i-1-3-3-3-3-5,s);//space W
		strip.setPixelColor(i-1-3-3-3-3-5-1,0);//dot
		strip.setPixelColor(i-1-3-3-3-3-5-1-3,s);//space
		strip.setPixelColor(i-1-3-3-3-3-5-1-3-1,0);//dot
		strip.setPixelColor(i-1-3-3-3-3-5-1-3-1-5,a);//space I
		strip.setPixelColor(i-1-3-3-3-3-5-1-3-1-5-3,0);//dash
		strip.setPixelColor(i-1-3-3-3-3-5-1-3-1-5-3-3,a);//space
		strip.setPixelColor(i-1-3-3-3-3-5-1-3-1-5-3-3-1,0);//dot N
		//strip.setPixelColor(i+5,0);
		strip.show();
		delay(200);
	}
} 

void scanner()
{
	uint16_t i, c, w;
	uint8_t distance,divisor,pulseHead;
	c=strip.Color(0,255,0);
	pulseHead=0;
	while(pulseHead<=strip.numPixels())
	{
		for(uint8_t i=0; i<strip.numPixels(); ++i) 
		{
			uint8_t divisor = 0;
			uint8_t distance = abs(i - pulseHead);
			if      (distance <= 2) divisor = 1;
			else if (distance <= 4) divisor = 2;
			else if (distance <= 6) divisor = 4;
			else if (distance <= 8) divisor = 6;
			else if (distance <= 10) divisor = 8;
			else if (distance <= 12) divisor = 10;
			else if (distance <= 14) divisor = 12;
			else divisor = 16; 
			strip.setPixelColor(i, 0, 255/divisor, 0);
		}
		pulseHead++;
		strip.show();
		delay(100);
	}
	
	
	
}

bool addTote()
{
	uint16_t i,ii,iii, c, cc;
	uint8_t w, w_n, b;
	c=strip.Color(0,255,0);
	cc=strip.Color(255,255,0);
	//i=0;
	w=(totes-1)*17;
	w_n = totes*17;
	for(i=0; i<w; i++)
	{
		strip.setPixelColor(i,strip.Color(0,255,0));
	}
	b=bins*45;
	for(ii=w; ii<(w+b); ii++)
	{
		strip.setPixelColor(ii,strip.Color(255,255,0));
	}
	strip.show();
	for(iii=(w+b); iii<(w_n+b);iii++)
	{
		strip.setPixelColor(iii,strip.Color(255,255,0));
		strip.setPixelColor(iii-b,0);
		strip.setPixelColor(iii-b,strip.Color(0,255,0));
		strip.setPixelColor(iii-b-w_n,0);
		strip.show();
		delay(50);
	}
	
	//strip.setPixelColor(w,c);
	//strip.setPixelColor(0,0);
	//strip.setPixelColor(i+5,0);
	return false;
}

bool addBin()
{
	uint16_t i,ii,iii, c, cc;
	uint8_t w, b_n, b;
	c=strip.Color(0,255,0);
	cc=strip.Color(255,255,0);
	//i=0;
	w = totes*17;
	for(i=0; i<w; i++)
	{
		strip.setPixelColor(i,strip.Color(0,255,0));
	}
	b=(bins-1)*45;
	b_n = bins*1;
	for(ii=w; ii<(w+b); ii++)
	{
		strip.setPixelColor(ii,strip.Color(255,255,0));
	}
	strip.show();
	for(iii=(w+b); iii<(b_n+w);iii++)
	{
		strip.setPixelColor(iii,strip.Color(255,255,0));
		strip.setPixelColor(iii-b_n,0);
		strip.setPixelColor(iii-b_n,strip.Color(0,255,0));
		strip.setPixelColor(iii-b_n-w,0);
		strip.show();
		delay(50);
	}
	
	//strip.setPixelColor(w,c);
	//strip.setPixelColor(0,0);
	//strip.setPixelColor(i+5,0);
	return false;
	
}


void pixelate()
{
	uint8_t i, px, color;
	uint32_t g, w, b,c;
	g=strip.Color(0,255,0);
	b=strip.Color(0,0,255);
	w=strip.Color(255,255,255);
	c=strip.Color(0,0,0);
	
	
	px = random(0,strip.numPixels());
	color = random(0,4);
	if(color==0)
	{
		strip.setPixelColor(px,g);
	}
	else if(color==1)
	{
		strip.setPixelColor(px,b);
	}
	else if(color==2)
	{
		strip.setPixelColor(px,c);
	}
	else
	{
		strip.setPixelColor(px,w);
	}
	
	strip.show();
	delay(10);
	
}