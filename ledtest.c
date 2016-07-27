#include<wiringPi.h>

int main()
{
	wiringPiSetup();
	pinMode(0, OUTPUT);
	while(1)
	{
		digitalWrite(0, LOW);
		delay(2000);
		digitalWrite(0, HIGH);
		delay(2000);
	}
	return 0;
}
