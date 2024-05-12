#include <stdio.h>

int Selection;
int x, y;

int Multiply(int x, int y)
{
	printf("%d %d",x,y);
	return 0;
}

int Divide()
{
	printf("two\n");
	return 0;
}

int Times()
{

	return 0;
}

int Division()
{

	return 0;
}

int main()
{
	scanf("%d", &Selection);
		switch(Selection) {
			case 1: scanf("%d", &x);
			        scanf("%d", &y);	
				Multiply(x,y);
				break;
			case 2: 
				Divide();
				break;
			default: break;
		}
	return 0;
}
