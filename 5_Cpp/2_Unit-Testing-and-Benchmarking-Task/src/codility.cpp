#include "codility.h"
#include <iostream>
#include <bitset>

int Solution::solutionBinaryGap(int N)
{
	if (N == 0)
		return 0;
	unsigned int Bit = 1 << 31;
	int Gap = 0, MaxGap = 0;
	while (!(N & Bit))
	{
		Bit >>= 1;
	}
	for (int iterator = 1; iterator <= 32; iterator++)
	{
		if (N & Bit)
		{
			MaxGap = Gap > MaxGap ? Gap : MaxGap;
			Gap = 0;
		}
		else
		{
			Gap++;
		}
		Bit >>= 1;
	}
	return MaxGap;
}
int Solution::solutionFrogJmp(int X, int Y, int D)
{
	if ((X <= Y) && (X >= 0))
	{
		int multiplier = (Y - X) / D;
		if ((Y - X) % D == 0)
		{
			// return X + (D * multiplier);
			return multiplier;
		}
		if (multiplier >= 0)
		{
			// return X + D;
			// return X + (D * (multiplier + 1));
			return multiplier + 1;
		}
	}
	return 0;
}