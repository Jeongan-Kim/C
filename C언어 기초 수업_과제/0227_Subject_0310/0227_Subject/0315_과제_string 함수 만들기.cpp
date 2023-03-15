#include <stdio.h>

void my_strlen(char arr[]);
void my_strcpy(char arr1[], char arr[]);
void my_strcmp(char arr[], char arr1[]);
void my_strcat(char arr[], char arr1[]);


int main()
{
	char str[100] = "hello C language";
	my_strlen(str);
	
	char str1[20];
	my_strcpy(str1, str);

	str[0] = 'z';
	my_strcmp(str, str1);

	my_strcat(str, str1);
	
	return 0;
}

void my_strlen(char arr[])
{
	int i = 0;
	int len = 0;
	while (arr[i] != '\0')
	{
		len++;
		i++;
	}
	printf("my_strlen : %d\n", len);
}

void my_strcpy(char arr1[], char arr[])
{
	int i = 0;
	while (arr[i] != '\0')
	{
		arr1[i] = arr[i];
		i++;
	}
	arr1[i] = '\0';
	printf("my_strcpy : %s\n", arr1);
}

void my_strcmp(char arr[], char arr1[])
{
	int i = 0;
	int answer;
	while (true)
	{
		if (arr[i] > arr1[i])
		{
			answer = 1;
			break;
		}
		else if (arr[i] < arr1[i])
		{
			answer = -1;
			break;
		}
		else if (arr[i] == '\0' && arr1[i] == '\0')
		{
			answer = 0;
			break;
		}
		else
			i++;
	}
	printf("my_strcmp : %d\n", answer);
}

void my_strcat(char arr[], char arr1[])
{
	int i = 0;
	int j = 0;
	while (arr[i] != '\0')
	{
		i++;
	}

	while (arr1[j] != '\0')
	{
		arr[i] = arr1[j];
		i++;
		j++;
	}
	arr[i] = '\0';
	printf("my_strcat : %s\n", arr);
}
