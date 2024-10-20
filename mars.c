#include <stdio.h>
#include "math.h"

double calculateTemperatureChange(double t, double T, double G)
{
	if (t == 0) return T;
	T = G * (T/30);
	T = T/t;
	return T;
}

double calculateOxygenChange(double t, double O)
{
	if (t == 0) return O;
	O = O+1;
	O *= O;
	O = 5/O;
	O = O/t;
	return O;
}

double calculateWaterChange(double t, double W, double O, double T)
{
	if (t == 0) return W;
	T = (T-200)/118;
	T *= T * T;
	O = 2*O;
	W = W/6;
	W += O-T;
	W = W/t;
	return W;
}

double calculateCarbonChange(double t, double C, double O)
{
	if (t == 0) return C;
	C = C/50;
	C -= O;
	C = C/t;
	return C;
}

double calculateGreenhouseChange(double t, double G, double C, double O, 
	double T)
{
	if (t == 0) return G;
	G = (-(C+O)/15) * (T/300);
	G = G/t;
	return G;
}

int main(int argc, char **argv)
{
	double time = 0;			// in Gyr
	double temperature = 230;	// in Kelvin

	double greenhouseGases = 10; 	// These values are all
	double water = 0.005;			// relative to Earth
	double carbon = 25;
	double oxygen = 0.01;
	
	int maxCalculations = 5;
	
	for (int i = 0; i <= maxCalculations; i++)
	{
		time = i;
		double T = calculateTemperatureChange(time, temperature, 
			greenhouseGases);
		double G = calculateGreenhouseChange(time, greenhouseGases, carbon, 
			oxygen, temperature);
		double W = calculateWaterChange(time, water, oxygen, temperature);
		double C = calculateCarbonChange(time, carbon, oxygen);
		double O = calculateOxygenChange(time, oxygen);
		
		printf("\n%f Gyr:\n", time);
		printf("Oxygen: %f\n", O);
		printf("Carbon: %f\n", C);
		printf("Temperature: %f\n", T);
		printf("Greenhouse Gases: %f\n", G);
		printf("Water: %f\n", W);
		
		oxygen = O;
		carbon = C;
		temperature = T;
		greenhouseGases = G;
		water = W;
	}
	return 0;
}

