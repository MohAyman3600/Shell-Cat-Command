/*
* @Author: ayman
* @Date:   2018-02-18 11:05:13
* @Last Modified by:   ayman
* @Last Modified time: 2018-02-18 13:45:32
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define bSize 1000

int main(int argc, char const *argv[])
{
	char *input[bSize];
	int f;
	if (argc == 1)
	{
		int sSize = read(0,input,bSize);
		write(1,input,sSize);
	}
	else if(argc > 1)
	{	
		for (int i = 1; i < argc; ++i)
		{	
			f = open(argv[i],O_RDONLY);
			if (f != -1)
			{	
				while(read(f,input,1) > 0){
					write(1,input,1);
				}
			}else{
				perror("The Error : ");
				return 0;
			}
			close(f);
		}
	}
	return 0;
}