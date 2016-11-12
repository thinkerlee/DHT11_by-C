/******************************************************************************
NAME:Sensor DHT11's driver
AUTHOR:Thinkelreo
VERSION:V1.0
DATE:2016.11.12
******************************************************************************/

#include<stdio.h>
#include<wiringPi.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

#define GPIO_PIN 0

typedef struct {
	int TEMP;
	int RH;
}dht_data;

uint8_t dht11[] = {0, 0, 0, 0, 0};
int	laststate = HIGH;
int	counter = 0;
int i = 0;
int j = 0;

FILE * fp;

int
main()
{
	dht_data* t  = (dht_data*)malloc(sizeof(dht_data));
	wiringPiSetup();
	pinMode(GPIO_PIN, OUTPUT);
	digitalWrite(GPIO_PIN, LOW);
	delay(22);
	digitalWrite(GPIO_PIN, HIGH);
	delayMicroseconds(40);
	pinMode(GPIO_PIN, INPUT);
	
	fp = open("a.dat",  )

	while(1)
	{
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
			printf("TEMP: %d, RH: %d", t->TEMP, t->RH);
			if((fp = fopen("a.dat", "a+")) == NULL)
			{
				printf("OPEN FILE ERROR\n");	
				return -1;
			}
			system("date >> a.dat");
			fprintf(fp, "TEMP: %d, RH: %d\n", t->TEMP, t->RH);
		}
		else
		{
			printf("Broken data\n");
		}
		sleep(2);
	}
}
