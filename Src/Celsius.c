#include <stdio.h>

#define LOWER 0 /* lower limit of table */
#define UPPER 300 /* upper limit of table */
#define STEP 20 /* step size */

/* print Celsius-Fahrenheiti table */

int main()
{
	int celsius;	

	for (celsius = UPPER; celsius >= LOWER; celsius = celsius - STEP)
		printf("%3d\t%6.0f\n", celsius, (celsius*1.8)+32);
}
