// This program uses its own function for allocating and freeing memory for matrices
// It can be seen as an intermediate step towards the construction of a more general 
// matrix vector class

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include "time.h"

using namespace std; // note use of namespace
int main (int argc, char* argv[])
{
  // read in dimension of square matrix
  auto n = atoi(argv[1]);
  auto s = 1.0/sqrt( (double) n);
  // Start timing
  clock_t start, finish;
  // Allocate space for the three matrices
  vector <vector<double> > A(n, vector<double>(n));
  vector <vector<double> > B(n, vector<double>(n));
  vector <vector<double> > C(n, vector<double>(n));
  // Set all elements to zero
  for(auto& row : A) fill(row.begin(),row.end(),0.0);
  for(auto& row : B) fill(row.begin(),row.end(),0.0);
  for(auto& row : C) fill(row.begin(),row.end(),0.0);
  // Set up values for matrix A and B and zero matrix C
  for (auto i = 0; i < n; i++){
    for (auto j = 0; j < n; j++) {
      double angle = 2.0*M_PI*i*j/ (( double ) n);
      A[i][j] = s * ( sin ( angle ) + cos ( angle ) );
      B[j][i] =  A[i][j];
    }
  }
  // Then perform the matrix-matrix multiplication
  start = clock();
  for (auto i = 0; i < n; i++){
    for (auto j = 0; j < n; j++) {
      double sum = 0.0;
       for (auto k = 0; k < n; k++) {
           sum += B[i][k]*A[k][j];
       }
       C[i][j] = sum;
    }
  }
  // Compute trace
  auto TraceMat = 0.0; 
  for (auto i = 0; i < n; i++){
    TraceMat += C[i][i];
   }
  finish = clock();
  double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
  cout << setiosflags(ios::showpoint | ios::uppercase);
  cout << setprecision(10) << setw(20) << "Time used  for matrix-matrix multiplication and trace evaluation=" << timeused  << endl;
  cout << setprecision(10) << setw(20) << "Trace of Matrix=" << TraceMat  << endl;
  return 0;
}















