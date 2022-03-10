#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAXRUNS = 1000; 

long imageWidth;
long runLength[MAXRUNS + 2];
int pixVal[MAXRUNS + 2];
int lastRunIndex;

int  runIndex[3];
long leftInRun[3];
long column;

int firstInRun(int r)
{
	return (leftInRun[r] == runLength[runIndex[r]] - 1);
}
  
void advance(long nTot)
{
	column = (column + nTot) % imageWidth;
	for (int r = 0; r < 3; r++)
		for (long n = nTot; n > 0; ) 
			if (n <= leftInRun[r])
			{
				leftInRun[r] -= n;
				n = 0;
			}
			else
			{
				n -= (leftInRun[r]+1);
				runIndex[r]++;
				leftInRun[r] = runLength[runIndex[r]]-1;
			}
}
    
int updateMax(int runI, int mid, int max)
{
	int dif = pixVal[runI] - mid;
	if (dif < 0) dif = -dif;
	return (dif > max) ? dif : max;
}

int edgeFilter()
{
int mid = pixVal[runIndex[1]];
int max = 0;
	
	for (int r = 0; r < 3; r++)
	if (runIndex[r] > 0 && runIndex[r] <= lastRunIndex)
	{
		max = updateMax(runIndex[r], mid, max);
		if (column > 0 && firstInRun(r))
        max = updateMax(runIndex[r]-1, mid, max);
		if (column < imageWidth -1 && leftInRun[r] == 0)
		max = updateMax(runIndex[r]+1, mid, max);
	}
	return max;
}

long minRun()
{
long minAfter = 2000000000;  
	
	for (int r = 0; r < 3; r++)
	{ 
		if (firstInRun(r)) return 1;
		if (minAfter > leftInRun[r]) minAfter = leftInRun[r];
	}
	if (minAfter == 0) return 1;
	return minAfter; 
}

int main ()
{
	cin >> imageWidth;
	cout << imageWidth << endl;
	while (imageWidth > 0)
	{
		runLength[0] = 2*imageWidth;
		lastRunIndex = 0;
		do
		{
			lastRunIndex++;
			cin >> pixVal[lastRunIndex] >> runLength[lastRunIndex];
		}
		while (runLength[lastRunIndex] > 0);
		runLength[lastRunIndex] = 2*imageWidth;
		lastRunIndex--;
		column = 0; 
		for (int r = 0; r < 3; r++)
		{
			runIndex[r] = 0;
			leftInRun[r] = (3-r)*imageWidth - 1;
		}
		advance(2*imageWidth);
		int outBufferPixVal = edgeFilter();
		long outBufferRun = minRun();
		advance(outBufferRun);
		while (runIndex[1] <= lastRunIndex)
		{
			int outPixVal = edgeFilter();
			long outRun = minRun();
			advance(outRun);
			if (outPixVal == outBufferPixVal)
			outBufferRun += outRun;
			else
			{
				cout << outBufferPixVal << " " << outBufferRun << endl;
				outBufferPixVal = outPixVal;
				outBufferRun = outRun;
			}
		}
		if (column != 0) cout << " not multiple of width " << imageWidth << endl;
		cout << outBufferPixVal << " " << outBufferRun << endl;
		cout << 0 << " " << 0 << endl;
		cin >> imageWidth;
		cout << imageWidth << endl;
	}
	return 0;
}
