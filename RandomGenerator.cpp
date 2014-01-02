#include <stdint.h>
#include <cmath>
#include <fstream>

const uint32_t A = 16807;
const uint32_t Q = 127773;
const uint32_t R = 2836;
const uint32_t RANGE = 2147483647;

const uint32_t RANDOM_NUMBERS_COUNT = 1000;

const double LOW_RANGE = 2.0;
const double UP_RANGE = 12.0;
const double MEAN = 5.43;

long int g_core = 194069;

void NextCore( void )
{
	uint32_t h = (uint32_t)( g_core / Q);
	g_core = A * ( g_core - Q * h ) - R * h;
	if ( 0 > g_core)
	{
		g_core += RANGE;
	}
}

double GetNextUni( void )
{
	NextCore();
	double randomUniNumber = ( g_core / (double) RANGE) * ( UP_RANGE - LOW_RANGE ) + LOW_RANGE;
	return randomUniNumber;
}

double GetNextExp( void )
{
	double randomExpNumber = -( 1.0 / (double) MEAN ) * log( GetNextUni() );
}

int main( void )
{
	std::ofstream randomNumbers;
	randomNumbers.open("randomNumbers");

	for ( unsigned int randomNumberIndex = 0; randomNumberIndex < RANDOM_NUMBERS_COUNT; ++randomNumberIndex )
	{
		double randomNumber = GetNextUni();
		randomNumbers << randomNumber << "\n";
	}

	randomNumbers.close();
	return 0;
}
