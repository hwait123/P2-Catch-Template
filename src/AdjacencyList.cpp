#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <sstream>

#include "AdjacencyList.h"

#include <functional>

using namespace std;

void AdjacencyList::InitializePageRank()
{
	auto iter = vertices.begin();

	//initialize each page rank to 1/|V|
	for (; iter != vertices.end(); iter++)
		iter->second->pageRank = 1.0 / vertices.size();
}

void AdjacencyList::SetPageRank()
{
	auto iter = vertices.begin();

	//use pageRank unordered_map to update pageRank values after power iteration
	for (; iter != vertices.end(); iter++)
		iter->second->pageRank = pageRanks[iter->first];
}

void AdjacencyList::PageRank(int n)
{
	//set all pageRanks to 1/|V|
	InitializePageRank();

	//if power iteration n is over 1, start loop
	for (int i = 1; i < n; i++)
	{
		auto iter = vertices.begin();

		//iterate through each vertices element
		for (; iter != vertices.end(); iter++)
		{
			//create tempVec for readability and initialize tempRank
			auto tempVec = iter->second->inLinks;
			float tempRank = 0;

			//if inLinks is not empty, begin iteration
			if (tempVec.size() != 0)
			{
				//sum the values (1/inLink->numOutLinks) * pageRank for each inLink
				//to calculate new pageRank
				for (unsigned int i = 0; i < tempVec.size(); i++)
					tempRank += (1.0 / tempVec[i]->numOutLinks) * tempVec[i]->pageRank;

				//append tempRank to pageRanks
				pageRanks[iter->first] = tempRank;
			}

		}

		//using pageRanks unordered_map, update pageRank values for next power iteration
		SetPageRank();
	}
}

void AdjacencyList::AddLink(string in, string out)
{
	//if in is not found in vertices map
	if (vertices.find(in) == vertices.end())
	{
		//create new node and add to map
		Vertex* newIn = new Vertex(in);
		vertices[in] = newIn;
	}

	//if out is not found in vertices map
	if (vertices.find(out) == vertices.end())
	{
		//create new node and add to map
		Vertex* newOut = new Vertex(out);
		vertices[out] = newOut;
	}

	//link in and out, add out to in's link vector
	vertices[in]->inLinks.push_back(vertices[out]);

	//increment out's outLink count
	vertices[out]->numOutLinks++;

}

void AdjacencyList::Print()
{
	auto iter = vertices.begin();

	//print each url and pageRank (using setprecision)
	for (; iter != vertices.end(); iter++)
	{
		cout << iter->first << " ";
		cout << setprecision(2) << fixed << iter->second->pageRank << endl;
	}

}

void AdjacencyList::ParseInput(string input)
{
	stringstream sstream(input);
	string temp;

	//retreive power iterations number from first line of input
	getline(sstream, temp, '\n');
	int powerIters = stoi(temp.substr(temp.find(' ') + 1));

	//get each line of input string
	while (!sstream.eof()) {
		getline(sstream, temp, '\n');

		//assign from and to variables and add link
		string from = temp.substr(0, temp.find(' '));
		string to = temp.substr((temp.find(' ') + 1));

		AddLink(to, from);
	}

	//perform pagerank using power iterations number
	PageRank(powerIters);
}

string AdjacencyList::GetStringRepresentation()
{
	string res;
	auto iter = vertices.begin();

	for(; iter != vertices.end(); iter++)
	{
		//roundabout way to set precision of float pagerank value
		stringstream sstream;
		sstream << setprecision(2) << fixed << iter->second->pageRank << endl;
		string pagerank;
		sstream >> pagerank;

		//append string literal with vertice's url and pagerank
		res += iter->first + " " + pagerank + "\n";
	}
	return res;
}

string AdjacencyList::GetStringRepresentationOutlinkCount()
{
	string res;
	auto iter = vertices.begin();

	//append numOutLinks of each vertice to res string
	for(; iter != vertices.end(); iter++)
		res += to_string(iter->second->numOutLinks) + " ";

	return res;
}

bool AdjacencyList::IsVertice(string url)
{
	//check if given vertice exists
	if (vertices.find(url) == vertices.end())
		return false;

	return true;
}

vector<string> AdjacencyList::CreateTestVec()
{
	vector<string> res;
	auto iter = vertices.begin();

	//append vertice's url to vector
	for (; iter != vertices.end(); iter++)
		res.push_back(iter->first);

	return res;
}



