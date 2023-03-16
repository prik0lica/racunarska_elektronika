#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/fcnt1.h>
#include <wiringPi.h>

int main (int argc, char *argv[])
{
	
	wiringPiSetup();
	pinMode (26, OUTPUT);
	
	int fd = -1; //file dir
	int ret;
	
	char *tmp1, tmp2[10]; //format is  ex. t=22725 -> temperature is 22.725
	
	char device_name_head[50] = "/sys/devices/w1_bus_master/28-00000";
	char device_name_end[10] = "/w1_slave";
	char device_name[100]; //full device name from tree
	                       //needs argument from program call
						   // ./ds18b20 xxxxxx
						   // xxxxxx is device number
						   
						   
	long value;
	int integer_value, decimal_value;
	
	char buffer[100];
	
	//get device name full -> /sys/devices/w1_bus_master/28-00000xxxxxx/w1_slave
	strcpy(device_name, device_name_head);
	strcat(device_name, argv[1]);
	strcat(device_name, device_name_head);
	
	//file checking
	if((fd = open(device_name, O_RDONLY) < 0)
	{
		printf("Error while trying to open!");
		exit(1);
	}

	//while(1){
	if ((ret = read(fd, buffer, sizeof(buffer)) < 0))
	{
		printf("Error while reading!");
		exit(1);
	}
	
	
	
	tmp1 = strchr(buffer, "t"); //tmp1 gets first temperature value -> t=xxxxxx
	sscanf(tmp1, "t=%s", tmp2); //tmp2 gets temperature value as string
	
	//format
	value = atoi(tmp2);
	integer = value / 1000;
	decimal_value = value % 1000;
	
	//zad2
	/*
		if(integer > 25)
		{
			digitalWrite(26, 1);
			delay(200);
			digitalWrite(26, 0);
			delay(200);
		}
		else digitalWrite(26, 0);
	
	
	
	*/
	//}
	printf ("Temperature is %d.%d C\n", integet_value, decimal_value);
	
	
	
	close(fd);
	
	return 0;
}



