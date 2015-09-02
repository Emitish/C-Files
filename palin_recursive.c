#include <stdio.h>
#include <string.h>

int palindrome(const char *str, int start, int end) {
	if (start > end)
	 {
		printf("%s is a palindrome\n", str);
	 }
	else if (*(str+start) == *(str+end))
	 {
		palindrome(str, start+1, end-1);
	 }
	else 
	{
	 printf("%s is not a palindrome\n", str);
	 }

	return 0;
}

int main() 
{
	char arr[500];
	int l;

	printf("This program will test to see if a string is palindrome.\nInput a deblanked, unpunctated string of characters.\nEnter exit to stop.\nInput:  ");
	scanf("%s", arr);
        fgets(arr, 500, stdin);

	while (strcmp(arr, "exit") != 0) {
		l = strlen(arr);
		palindrome(arr, 0, l-1);
		printf("Input: ");
		scanf("%s", arr); }

return 0;
}


