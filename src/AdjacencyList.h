#pragma once

#include <string>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

struct Vertex
{
    string url;
    int numOutLinks;
    vector <Vertex*> inLinks;
    float pageRank;

    Vertex(string url)
    {
        this->url = url;
        numOutLinks = 0;
        pageRank = 0;
    }
};

class AdjacencyList {

private:

    //initialize maps
    map <string, Vertex*> vertices;
    unordered_map <string, float> pageRanks;

    //setters
    void InitializePageRank();
    void SetPageRank();

public:

    //mutators
    void PageRank(int n);
    void AddLink(string in, string out);

    //behaviors
    void Print();

    //tests
    void ParseInput(string input);
    string GetStringRepresentation();
    string GetStringRepresentationOutlinkCount();
    bool IsVertice(string url);
    vector<string> CreateTestVec();
};