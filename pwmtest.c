#include<wiringPi.h>
#include<stdio.h>

int main(int argc, char **argv)
{
	wiringPiSetup();
	pinMode(1, PWM_OUTPUT);
	int i = 800;	
	while(1)
	{
		while(i < 1024)
		{
      			pwmWrite(1, i++);
			delay(3);
		}
		printf("%d\n", digitalRead(1));
		while(i > 800)
		{
      			pwmWrite(1, i--);
			delay(3);
		}
		printf("%d\n", digitalRead(1));
	}
	return 0;
}
