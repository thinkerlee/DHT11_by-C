#include<stdio.h>
#include<unistd.h>

int main()
{
	while(1)
	{
		execle("dht11", NULL);
	}

	return 0;
}
 
