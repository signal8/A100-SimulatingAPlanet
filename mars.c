#include <stdio.h>

float calculateTemperatureChange(float t, float T, float G)
{
	if (t == 0) return T;
	int ans;
	T = T*G;
	ans = T/30;
	ans = ans/t;
	return ans; //updated
}

float calculateOxygenChange(float t, float O)
{
	if (t == 0) return O;
	int ans;
	O++; O = O*O;
	ans = 5/O;
	ans = ans/t;
	return ans; //updated
}

float calculateWaterChange(float t, float W, float O, float T)
{
	if (t == 0) return W;
	int ans;
	T -= 200; T = T/118;
	T = T*T*T;
	W = W/6;
	O = O*2;
	ans = (W+O)-T;
	ans = ans/t;
	return ans; //updated
}

float calculateCarbonChange(float t, float C, float O)
{
	if (t == 0) return C;
	int ans;
	C = C/50;
	ans = C-O;
	ans = ans/t;
	return ans; //updated
}

float calculateGreenhouseChange(float t, float G, float C, float O, 
	float T)
{
	if (t == 0) return G;
	int ans;
	int x = C+O;
	x = x*-1;
	x = x/15;
	T = T/300;
	ans = x*T;
	ans = ans/t;
	return ans;
}

int main(int argc, char **argv)
{
	float time = 0;			// in Gyr
	float temperature = 230;	// in Kelvin

	float greenhouseGases = 10;// These values are all
	float water = 0.005;		// relative to Earth
	float carbon = 25;
	float oxygen = 0.01;
	
	int maxCalculations = 5;
	
	for (int i = 0; i <= maxCalculations; i++)
	{
		time = i;
		float T = calculateTemperatureChange(time, temperature, 
			greenhouseGases);
		float G = calculateGreenhouseChange(time, greenhouseGases, carbon, 
			oxygen, temperature);
		float W = calculateWaterChange(time, water, oxygen, temperature);
		float C = calculateCarbonChange(time, carbon, oxygen);
		float O = calculateOxygenChange(time, oxygen);
		
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
