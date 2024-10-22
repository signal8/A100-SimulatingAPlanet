#include <stdio.h>

double calculateTemperatureChange(double t, double T, double G)
{
	if (t == 0) return T;
	double ans;
	T = T*G;
	ans = T/30;
	ans = ans/t;
	return ans; //updated
}

double calculateOxygenChange(double t, double O)
{
	if (t == 0) return O;
	double ans;
	O++; O = O*O;
	ans = 5/O;
	ans = ans/t;
	return ans; //updated
}

double calculateWaterChange(double t, double W, double O, double T)
{
	if (t == 0) return W;
	double ans;
	T -= 200; T = T/118;
	T = T*T*T;
	W = W/6;
	O = O*2;
	ans = (W+O)-T;
	ans = ans/t;
	return ans; //updated
}

double calculateCarbonChange(double t, double C, double O)
{
	if (t == 0) return C;
	double ans;
	C = C/50;
	ans = C-O;
	ans = ans/t;
	return ans; //updated
}

double calculateGreenhouseChange(double t, double G, double C, double O, 
	double T)
{
	if (t == 0) return G;
	double ans;
	double x = C+O;
	x = x*-1;
	x = x/15;
	T = T/300;
	ans = x*T;
	ans = ans/t;
	return ans;
}

int main(int argc, char **argv)
{
	double time = 0;			// in Gyr
	double temperature = 230;	// in Kelvin

	double greenhouseGases = 10;// These values are all
	double water = 0.005;		// relative to Earth
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
		
		oxygen += O;
		carbon += C;
		temperature += T;
		greenhouseGases += G;
		water += W;
	}
	return 0;
}
