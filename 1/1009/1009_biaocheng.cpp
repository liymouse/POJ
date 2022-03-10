#include <iostream.h>
#include <stdlib.h>
const int MAXRUNS = 1000; 

// input data
long imageWidth;
long runLength[MAXRUNS + 2]; // runs with dummy border runs at ends
int pixVal[MAXRUNS + 2];  // pixel values in runs.  
int lastRunIndex;  // excluding final added border
// dummy border runs at indices 0 and lastRunIndex+1 are added 

// data for position in grid
// maintain positions in image of a pixel in the previous, current, 
//   and next row with indices 0, 1, and 2 respectively in each array 
//        runIndex and leftInRun 
//   where an entry i in runIndex is used to reference the run given by
//   runLength[i] and pixVal[i] and the entries in leftInRun are the number 
//   of pixels after the current pixel in its run.
//   Pixels may be in the dummy run before or after the image.
//   The pixel in the center row is in the center of the edge filter.
int  runIndex[3];    // index of run containing pixel
long leftInRun[3];  // number of further pixels in the run
long column;  // column of pixel in center of filter, 0 to imageWidth - 1
  // only care about extreme values which mark edges

int firstInRun(int r) {
  return (leftInRun[r] == runLength[runIndex[r]] - 1);
}
  
void advance(long nTot) {
  // advance the center pixel in preceding, current, and next rows 
  // by n pixels as given by runIndex and leftInRun
  // and update the column 
  column = (column + nTot) % imageWidth;
  for (int r = 0; r < 3; r++)
    for (long n = nTot; n > 0; ) 
      if (n <= leftInRun[r]) {
        leftInRun[r] -= n;
        n = 0;
      }
      else {
        n -= (leftInRun[r]+1);
        runIndex[r]++;
        leftInRun[r] = runLength[runIndex[r]]-1;
      }
}
    
int updateMax(int runI, int mid, int max) {
  int dif = pixVal[runI] - mid;
  if (dif < 0) dif = -dif;
  return (dif > max) ? dif : max;
}

int edgeFilter() {
  // calculate edge filter for the pixel in the middle row
  // This works for an image with any positive number of rows or columns
  int mid = pixVal[runIndex[1]]; // pixel value in mid row 
  int max = 0;
  for (int r = 0; r < 3; r++) // for each row used in the filter
    if (runIndex[r] > 0 && runIndex[r] <= lastRunIndex) {  // skip dummy rows
      max = updateMax(runIndex[r], mid, max);  // use pixel value in row
      if (column > 0 && firstInRun(r)) // refer back to previous run if must 
        max = updateMax(runIndex[r]-1, mid, max); // for pixel before 
      if (column < imageWidth -1 && leftInRun[r] == 0) // see next run if must
        max = updateMax(runIndex[r]+1, mid, max);       // for pixel after
    }
  return max;
}

long minRun() {
  // If for each of the current and previous and next row,
  // the pixel matches the pixel before and n > 0 pixels after, then
  // the edge filter value is the first of at least n that are the same.
  // Return the largest such n, or 1 if there is no such matchup
  // NOTE -- this does not give too large a number even
  //   wrapping around an edge
  // It does not give the largest possible number always
  // -- it is reduced by nonmatches in pixels past borders.
  // The output buffer will assemble runs with the same
  //   pixel value, so this is OK.
  long minAfter = 2000000000;  
  for (int r = 0; r < 3; r++) { 
    if (firstInRun(r)) return 1;
    if (minAfter > leftInRun[r]) minAfter = leftInRun[r];
  }
  if (minAfter == 0) return 1;
  return minAfter; 
}

int main () {

  cin >> imageWidth;
  cout << imageWidth << endl;

  while (imageWidth > 0) { // assume end sentinal is 0 image width
    // read, initialize image data
    runLength[0] = 2*imageWidth;  // add initial border 
    lastRunIndex = 0;
    do {
      lastRunIndex++;
      cin >> pixVal[lastRunIndex] >> runLength[lastRunIndex];
    } while (runLength[lastRunIndex] > 0);  // assume dataset ends with 0 run length
    runLength[lastRunIndex] = 2*imageWidth; // add end border two lines wide 
    lastRunIndex--;  // border not counted in real run indices
    
    column = 0; 
    // set up pixel to be filtered as first pixel in image in two steps:
    // simplest to place all pixels before first real row
    for (int r = 0; r < 3; r++) {
      runIndex[r] = 0;  // dummy run index before actual image
      leftInRun[r] = (3-r)*imageWidth - 1;// pixels -3,-2,-1 rows into image 
    }
    advance(2*imageWidth); // +2 rows to first pixels -1,0,1 rows into image                    

    // first time, initialize output buffer variables
    int outBufferPixVal = edgeFilter();  // apply filter
    long outBufferRun = minRun();// same filtered value for at least this int
    advance(outBufferRun);  // skip past all the pixels calculated
    while (runIndex[1] <= lastRunIndex) {// while center before end of image
      int outPixVal = edgeFilter(); // same three steps as above
      long outRun = minRun();       //   but with different
      advance(outRun);              //   run variables   
      if (outPixVal == outBufferPixVal) // combine runs with equal values
        outBufferRun += outRun;
      else {  // output old runLength, save new one
        cout << outBufferPixVal << " " << outBufferRun << endl;
        outBufferPixVal = outPixVal;
        outBufferRun = outRun;
      }
    }  // end of loop processing the input image

    // check input integrity -- integral number of rows
    if (column != 0) cout << " not multiple of width " << imageWidth << endl;
    
    cout << outBufferPixVal << " " << outBufferRun << endl; // clear buffer
    cout << 0 << " " << 0 << endl; // assume same sentinal format as input 
    cin >> imageWidth;
    cout << imageWidth << endl;
  } // end of all data sets
  return 0;
}