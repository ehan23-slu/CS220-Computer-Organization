#include <stdio.h> // header file
#include <math.h> // angle brackets mean it is a system header

double windchill(double t, double v) {
	return 35.74 + 0.6215 * t + (0.4275 * t - 35.75) * pow(v,0.16);
}
int main(void) {
	printf("Enter a temperature (F): ");

	// have user enter a termerature and velocity
	double t; // temperature
	scanf("%lf", &t); // & addressof

	double v;
	printf("Enter a velocity in MPH: ");
	scanf("%lf", &v);

	printf("%.2f\n", windchill(t, v));

}

