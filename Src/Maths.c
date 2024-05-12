#include <stdio.h>

int Multi() {
	printf("Multi\n");
return 0;
}

int Divide() {
	printf("Divde\n");
return 0;
}
int main() {
	
	int input;

	printf("Multi = 1 Divide = 2: ");
	scanf("%d", input);
	printf("%d", input);

/*	if (input == 1) 
		Multi();
	else if (input == 2) 
		Divide();*/	
	return 0;
}
