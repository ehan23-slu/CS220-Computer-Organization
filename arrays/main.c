#include <stdio.h>

/*
* Square each item in the array vec
* square each item in the original array (modifying)
*/
void sqrall(int vec[], int n) {

	for (int i = 0; i < n; i++)
		vec[i] = vec[i] * vec[i];
}

/*
* print the each vec value in the one line
*/
void printvec(int vec[], int n) {

	for (int i = 0; i < n; i++)
		printf("%d,", vec[i]);

	printf("\n");
}

/*
* Add up the items in vec
* n is the number of items in vec,
* precondition: n should not be negative or zero.
* n should be less than the number of actual items in vec
* return the sum
*/
int sum(int vec[], int n) {

	int t = 0;

	for (int i = 0; i < n; i++)
		t += vec[i]; // doesn't need {}
	return t;
}

int main () {

	// array of numbers
	int grades[6]; // not int[] // allocated 4*6 = 24 bytes allocated
	int nums[] = {9, 1, -3, 44, 71, 23};

	//printf("%d %d %d\n", nums[0], nums[5], nums[6]);

	printf("Sum is %d\n", sum(nums,6));
	printf("Sum is %d\n", sum(grades,6));

	// when passing an array "the location (address)" of the
	// array is passed and not a copy. The address of the
	// first item in the array
	printvec(nums, 6);
	sqrall(nums, 6);
	printvec(nums, 6);
}
