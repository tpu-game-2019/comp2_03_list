#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	char str[5];
	int array[100] = { 0 };
	while (fgets(str, sizeof(str), stdin)) {

		int input = atoi(str);

		if (input == -1)
		{
			printf("%d\n",array[0]);
			for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
			{
				if (i + 1 < sizeof(array) / sizeof(array[0]) && array[i] != 0)
					array[i] = array[i + 1];
				else
					break;
			}
		}
		else if(input == 0)
		{
			for (int i = 0; i < sizeof(array) / sizeof(array[0]) && array[i] != 0; i++)
			{
					if(i == 0)
						printf("%d", array[i]);
					else
						printf(",%d", array[i]);
			}
			printf("\n");
		}
		else
		{
			for (int i = 0; i <  sizeof(array) / sizeof(array[0]) - 1; i++)
				array[sizeof(array) / sizeof(array[0]) - 1 - i] = array[sizeof(array) / sizeof(array[0]) - 2 - i];
	
			array[0] = input;
		}
	}
	return 0;
}
