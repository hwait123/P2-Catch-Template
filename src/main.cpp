#include <iostream>
#include <iomanip>
#include <string>

#include "AdjacencyList.h"

using namespace std;

// prints the PageRank of all pages after p powerIterations in
//ascending alphabetical order of webpages and rounding rank to two
//decimal places

// This class and method are optional. To accept the input, you can use this method:

/*int main()
{
	//initialize variables
	int no_of_lines, power_iterations;
	string from, to;
	AdjacencyList graph;

	//accept first line of input
	cin >> no_of_lines;
	cin >> power_iterations;

	//accept following lines of input
	for (int i = 0; i < no_of_lines; i++)
	{
		cin >> from;
		cin >> to;

		//create link between urls
		graph.AddLink(to, from);
	}

	//pageRank and print ranks
	graph.PageRank(power_iterations);
	graph.Print();

}*/
