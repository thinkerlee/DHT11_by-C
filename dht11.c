/******************************************************************************
NAME:Sensor DHT11's driver
AUTHOR:Thinkelreo
VERSION:V1.0
DATE:2016.7.27
******************************************************************************/

#include<stdio.h>
#include<wiringPi.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int TEMP;
	int RH;
}dht_data;

dht_data* dht_get(int GPIO_PIN)
{
	uint8_t dht11[] = {0, 0, 0, 0, 0};
	int	laststate = HIGH;
	int	counter = 0;
	int i = 0;
	int j = 0;
	
	dht_data* t  = (dht_data*)malloc(sizeof(dht_data));
	wiringPiSetup();
	pinMode(GPIO_PIN, OUTPUT);
	digitalWrite(GPIO_PIN, LOW);
	delay(22);
	digitalWrite(GPIO_PIN, HIGH);
	delayMicroseconds(40);
	pinMode(GPIO_PIN, INPUT);
	
		for(i = 0; i < 85; i++)
		{
			counter = 0;
			while(digitalRead(GPIO_PIN) == laststate)
			{
				counter++;
				delayMicroseconds(GPIO_PIN);
				if(counter == 255)
				{
					break;
				}
			}
			laststate = digitalRead(GPIO_PIN);
			if(counter == 255)
				break;
			if( (i >= 4) && (i % 2 == 0)) 
			{
				dht11[j/8] = dht11[j/8] << 1;
				if(counter > 16)
				{
					dht11[j/8] = dht11[j/8] | 1;
				}	
				j++;
			}
		}		
		if( (j >= 4)  && (dht11[4] == dht11[0] + dht11[1] + dht11[2]+dht11[3]))
		{
			t->TEMP = dht11[2];
			t->RH = dht11[0];
			return  t;	
		}
		else
		{
			printf("Broken data\n");
			exit(-1);
		}
}      

int main(int argc, char** argv)
{
	dht_data*  a;
	a = dht_get(1);	
	printf("TEMP:%d\n", a->TEMP);
	printf("RH:%d\n", a->RH);
	
	return 0;
}

