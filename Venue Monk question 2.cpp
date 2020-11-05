#include <iostream>
#include <cstring>
using namespace std;

int count( int notes[], int m, int n) /*function to get the answer, note is an array of values of 
different denominations, m is number of denominations which will be 8 here and n is the total value which will be 2000 here*/
{
	/* We will build our answer from answers for smaller value
	that can be changed to our required value by adding an available note i. e. 
	if a value i can be arrnaged in ans[i] ways then value ans[i+note] can be construted in those ways too
	hence we add all possible such values to constuct our answer for a particular value*/
	
	int ans[n+1]; //for stroing answer for different values

	memset(ans, 0, sizeof(ans)); 

	ans[0] = 1; //for value 0 there's only one option i.e. no notes
	
	for(int i=0; i<m; i++) 
		for(int j=notes[i]; j<=n; j++) 
			ans[j] += ans[j-notes[i]]; /*contructing answer for value j by going over all possible answer for 
			                           values which can be chnaged to j after adding a note*/

	return ans[n]; //answer for avlue n
} 


int main() {
	int notes[]={10, 20, 50, 100, 200, 500, 1000, 2000};
	cout<<"Number of ways to make the sum 2000 is  : "<<count(notes, 8, 2000);
	return 0;
}