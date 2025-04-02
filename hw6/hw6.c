#include <stdio.h>
#include "dow.h" 

int main(void) {
	// have user enter a month, day, and year
	printf("Enter a month (0-11): ");
	int m; 				// month
	scanf("%d", &m);  	// use addressof &

	printf("Enter a day (0-31): ");
	int d;  			// day
	scanf("%d", &d);

	printf("Enter a year: ");
	int y; 				// year
	scanf("%d", &y);

	// Error checking
	if (m < 1 || m > 12 || d < 1 || d > 31 || y < 0) {
		printf("Error! Invalid Input.\n");
		return 1;
	}

	// call function dow
	// store int output into result variable
	int result = dow(m, d, y);

	// print output using if-else statements
	if (result < 0 || result > 6) {printf("Error! Invalid result.\n");}
	 else if (result == 0) {printf("Sunday\n");}
	 else if (result == 1) {printf("Monday\n");}
	 else if (result == 2) {printf("Tuesday\n");}
	 else if (result == 3) {printf("Wednesday\n");}
	 else if (result == 4) {printf("Thursday\n");}
	 else if (result == 5) {printf("Friday\n");}
	 else if (result == 6) {printf("Saturday\n");}
}
