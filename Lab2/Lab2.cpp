/*
 * Lab2.cpp
 *
 * Author: Ihar Simanovich
 * Date: 04/19/2016
 * Class: CSS 342A
 * Exercise: Lab #2
 *
 * Goal: This programming assignment empirically analyzes the running time of the Sieve of Eratosthenes.
 *
 * About program: This program reads the integer n and finds all primes in the range 2 to n.
 * Also, it prints out the running cost, (i.e., the number of array-sweeping operations
 * required to find all those primes).
 *
 */

//-------------------------------------------------START OF LAB #2----------------------------------------------------
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//---------------------------------------------sieve---------------------------------------------------
//method that finds prime numbers in range from 2 to n
//by using Sieve of Eratosthenes algorithm
int sieve( int n, vector<int> &primes ) {
	//initializing variables
	int cost = 0;
	bool array[n + 1];
	//loop that sets all values in array to true
	//because we think initially that all numbers are primes
	for(int i = 0; i < n+1; i++)
	{
		array[i] = true;
	}

	//loop that goes through array and uses its indexes
	//as numbers to find primes
	for(int s = 2; s <= n; s++)
	{
		//if value under current index is TRUE
		if(array[s] == true){
			//this number is being added to primes
			primes.push_back(s);
		}
		//loop that goes through array of booleans
		for(int j = s*s; j <= n; j += s){
			//if value is multiple of prime number
			//and currently is not set as FALSE
			if(array[j] != false){
				//then setting value to false
				array[j] = false;
				//incrementing cost for sweeping operation
				cost++;
			}
		}
	}
	return cost;
}//end of sieve function

//--------------------------------------------CODE PROVIDED BY LAB #2----------------------------------------------
int main( ) {
int n = 0;

cout << "Enter n ";
cin >> n;

char printOption = 'n';
cout << "print all primes (y|n)? ";
cin >> printOption;

//

for ( int i = 2; i <= n; i++ ) {

	vector<int> primes;
	int cost = sieve( i, primes );

	cout << "primes[1.." << i << "] took " << cost
	<< " sweeping operations" << endl;

	if ( printOption == 'y' ) {
		cout << "all primes = ";
		for ( int j = 0; j < primes.size( ); j++ )
			cout << primes[j] << " ";
		cout << endl;
}

cerr << i << " " << cost << endl;

}

return 0;
}
//-------------------------------------------------END OF LAB #2----------------------------------------------------
