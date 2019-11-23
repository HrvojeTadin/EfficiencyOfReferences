/*
   Author: Hrvoje Tadin
   Calculation of copy efficiency using references compared to classic copying.
*/

#include<iostream>
#include<vector>
#include<chrono>

using namespace std;
using namespace std::chrono;

int main() {

	double first{ 0 };
	double second{ 0 };
	double percentage{ 0 };

	const char* a_long_string = "iwueuelisanlesinufl";

	vector<string> strings;

	constexpr int elements = 1000000;

	// we create a string of character strings

	cout << "The program shows the efficiency of using the \"reference\""
		" in \"for loops\" versus \"classic copy\"." << endl;
	cout << "\nPreparing a string..." << endl << endl;

	for (int i = 0; i < elements; i++)
		strings.emplace_back(a_long_string);

	cout << "The string is ready.." << endl << endl;

	// in the next loop we make a copy

	cout << "-> Launched loop 'for' that uses 'copy' ......" << endl << endl;

	auto start = high_resolution_clock::now();

	for (string s : strings)
		string a = s + "ttt";

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);

	cout << "Done.\nDuration of copying loop: " << duration.count() << " milliseconds." << endl << endl;

	first = duration.count();

	// we fetch in the following loop via reference

	cout << "-> Launched 'for loop' using 'reference' ..." << endl << endl;

	start = high_resolution_clock::now();

	for (string &s : strings)
		string a = s + "ttt";

	stop = high_resolution_clock::now();

	duration = duration_cast<milliseconds>(stop - start);

	cout << "Done.\nLoading time with 'referencing': " << duration.count() << " milliseconds." << endl << endl;

	second = duration.count();

	percentage = ((second - first) / (unsigned(first))) * 100;

	cout.precision(3);
	cout << "The difference is: " << percentage << "% on behalf of references.\n\nPress ENTER for the end program." << endl;

	cin.sync();
	cin.get();

	return 0;
}