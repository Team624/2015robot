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
	//strobepulse();
	//toteCount();
	//win();
	scanner();
	//sixtwofour();
	//rainbow(50);
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
	
	for(i=0;i<255;i+=5)
	{
		fillStrip(c, i);
		strip.show();
		delay(15);
	}
	
	for(i=255;i>0;i-=5)
	{
		fillStrip(c, i);
		strip.show();
		delay(15);
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
	uint16_t i, c, w, flag;
	c=strip.Color(0,255,0);
	fillStrip(strip.Color(0,10,0), 255);
	w=16;
	flag=95;
	for(i=0;i<(strip.numPixels()+w);i++)
	{
		strip.setPixelColor(i,strip.Color(0,255,0));
		for(int it=0;it<w;it++)
		{
			//strip.setBrightness(flag);
			
			if(it<w/2)
			{
				flag+=20;
			}
			else
			{
				flag-=20;
			}
		}
		strip.setPixelColor(i-w,strip.Color(0,10,0));
		//strip.setPixelColor(i+5,0);
		strip.show();
		delay(1000);
	}
	
}