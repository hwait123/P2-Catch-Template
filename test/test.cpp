#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <algorithm>

// change if you choose to use a different header name

#include "AdjacencyList.h"

using namespace std;

// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
TEST_CASE("Example Test Name - Change me!", "[tag]"){
    // instantiate any class members that you need to test here
    int one = 1;

    // anything that evaluates to false in a REQUIRE block will result in a failing test
    REQUIRE(one == 1); // fix me!

    // all REQUIRE blocks must evaluate to true for the whole test to pass
    REQUIRE(true); // also fix me!
}

TEST_CASE("Test 2", "[tag]"){
    // you can also use "sections" to share setup code between tests, for example:
    int one = 1;

    SECTION("num is 2") {
        int num = one + 1;
        REQUIRE(num == 2);
    };

    SECTION("num is 3") {
        int num = one + 2;
        REQUIRE(num == 3);
    };

    // each section runs the setup code independently to ensure that they don't affect each other
}

// you must write 5 unique, meaningful tests for extra credit on this project!

// See the following for an example of how to easily test your output.
// This uses C++ "raw strings" and assumes your PageRank outputs a string with
//   the same thing you print.
TEST_CASE("Example PageRank Output Test", "[flag]"){
    // the following is a "raw string" - you can write the exact input (without
    //   any indentation!) and it should work as expected
    string input = R"(7 2
google.com gmail.com
google.com maps.com
facebook.com ufl.edu
ufl.edu google.com
ufl.edu gmail.com
maps.com facebook.com
gmail.com maps.com)";

    string expectedOutput = R"(facebook.com 0.20
gmail.com 0.20
google.com 0.10
maps.com 0.30
ufl.edu 0.20
)";

    string expectedOutputOutlinks = "1 1 2 1 2 ";

    AdjacencyList graph;
    graph.ParseInput(input);

    string actualOutput = graph.GetStringRepresentation();
    string actualOutputOutlinks = graph.GetStringRepresentationOutlinkCount();

    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(actualOutputOutlinks == expectedOutputOutlinks);

}

TEST_CASE("(1) 1 site pointing at 25 sites", "[flag]"){
    // the following is a "raw string" - you can write the exact input (without
    //   any indentation!) and it should work as expected
    string input = R"(25 2
google.com ufl.edu
google.com youtube.com
google.com gmail.com
google.com bing.com
google.com discord.com
google.com facebook.com
google.com maps.com
google.com outlook.com
google.com geeksforgeeks.org
google.com one.uf.edu
google.com indeed.com
google.com instagram.com
google.com khanacademy.org
google.com github.com
google.com ufl.instructure.com
google.com amazon.com
google.com depop.com
google.com etsy.com
google.com reddit.com
google.com zoom.us
google.com ebay.com
google.com aldi.us
google.com ikea.com
google.com store.steampowered.com
google.com delta.com)";

    string expectedOutput = R"(aldi.us 0.00
amazon.com 0.00
bing.com 0.00
delta.com 0.00
depop.com 0.00
discord.com 0.00
ebay.com 0.00
etsy.com 0.00
facebook.com 0.00
geeksforgeeks.org 0.00
github.com 0.00
gmail.com 0.00
google.com 0.00
ikea.com 0.00
indeed.com 0.00
instagram.com 0.00
khanacademy.org 0.00
maps.com 0.00
one.uf.edu 0.00
outlook.com 0.00
reddit.com 0.00
store.steampowered.com 0.00
ufl.edu 0.00
ufl.instructure.com 0.00
youtube.com 0.00
zoom.us 0.00
)";

    string expectedOutputOutlinks = "0 0 0 0 0 0 0 0 0 0 0 0 25 0 0 0 0 0 0 0 0 0 0 0 0 0 ";

    AdjacencyList graph;
    graph.ParseInput(input);

    string actualOutput = graph.GetStringRepresentation();
    string actualOutputOutlinks = graph.GetStringRepresentationOutlinkCount();

    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(actualOutputOutlinks == expectedOutputOutlinks);
}

TEST_CASE("(2) 25 sites pointing at 1 site", "[flag]"){
    // the following is a "raw string" - you can write the exact input (without
    //   any indentation!) and it should work as expected
    string input = R"(25 2
ufl.edu google.com
youtube.com google.com
gmail.com google.com
bing.com google.com
discord.com google.com
facebook.com google.com
maps.com google.com
outlook.com google.com
geeksforgeeks.org google.com
one.uf.edu google.com
indeed.com google.com
instagram.com google.com
khanacademy.org google.com
github.com google.com
ufl.instructure.com google.com
amazon.com google.com
depop.com google.com
etsy.com google.com
reddit.com google.com
zoom.us google.com
ebay.com google.com
aldi.us google.com
ikea.com google.com
store.steampowered.com google.com
delta.com google.com)";

    string expectedOutput = R"(aldi.us 0.00
amazon.com 0.00
bing.com 0.00
delta.com 0.00
depop.com 0.00
discord.com 0.00
ebay.com 0.00
etsy.com 0.00
facebook.com 0.00
geeksforgeeks.org 0.00
github.com 0.00
gmail.com 0.00
google.com 0.96
ikea.com 0.00
indeed.com 0.00
instagram.com 0.00
khanacademy.org 0.00
maps.com 0.00
one.uf.edu 0.00
outlook.com 0.00
reddit.com 0.00
store.steampowered.com 0.00
ufl.edu 0.00
ufl.instructure.com 0.00
youtube.com 0.00
zoom.us 0.00
)";

    string expectedOutputOutlinks = "1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 ";

    AdjacencyList graph;
    graph.ParseInput(input);

    string actualOutput = graph.GetStringRepresentation();
    string actualOutputOutlinks = graph.GetStringRepresentationOutlinkCount();

    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(actualOutputOutlinks == expectedOutputOutlinks);
}

TEST_CASE("(3) 10k power iterations", "[flag]"){
    // the following is a "raw string" - you can write the exact input (without
    //   any indentation!) and it should work as expected
    string input = R"(7 10000
google.com gmail.com
google.com maps.com
facebook.com ufl.edu
ufl.edu google.com
ufl.edu gmail.com
maps.com facebook.com
gmail.com maps.com)";

    string expectedOutput = R"(facebook.com 0.24
gmail.com 0.18
google.com 0.12
maps.com 0.24
ufl.edu 0.24
)";

    string expectedOutputOutlinks = "1 1 2 1 2 ";

    AdjacencyList graph;
    graph.ParseInput(input);

    string actualOutput = graph.GetStringRepresentation();
    string actualOutputOutlinks = graph.GetStringRepresentationOutlinkCount();

    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(actualOutputOutlinks == expectedOutputOutlinks);
}

TEST_CASE("(4) Circular graph", "[flag]"){
    // the following is a "raw string" - you can write the exact input (without
    //   any indentation!) and it should work as expected
    string input = R"(5 10000
google.com gmail.com
gmail.com facebook.com
facebook.com ufl.edu
ufl.edu maps.com
maps.com google.com)";

    string expectedOutput = R"(facebook.com 0.20
gmail.com 0.20
google.com 0.20
maps.com 0.20
ufl.edu 0.20
)";

    string expectedOutputOutlinks = "1 1 1 1 1 ";

    AdjacencyList graph;
    graph.ParseInput(input);

    string actualOutput = graph.GetStringRepresentation();
    string actualOutputOutlinks = graph.GetStringRepresentationOutlinkCount();

    REQUIRE(actualOutput == expectedOutput);
    REQUIRE(actualOutputOutlinks == expectedOutputOutlinks);
}

TEST_CASE("(5) 10k lines of input", "[flag]") {

    vector<string> expectedOutput, actualOutput;
    AdjacencyList graph;
    int i = 0;

    while (i < 10000)
    {
        string randomInput = to_string(rand()) + ".com";

        if (graph.IsVertice(randomInput))
            continue;

        expectedOutput.push_back(randomInput);

        graph.AddLink("gmail.com", randomInput);

        i++;
    }

    expectedOutput.push_back("gmail.com");
    std::sort(expectedOutput.begin(), expectedOutput.end());

    actualOutput = graph.CreateTestVec();

    REQUIRE(actualOutput == expectedOutput);
}

