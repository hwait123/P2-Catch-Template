#include <iostream>
#include <iomanip>
#include <string>

#include "AdjacencyList.h"

using namespace std;


int main()
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
}
