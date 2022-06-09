#include <iostream>
using namespace std;

#include<vector>

struct games
{
    string sportname;
    int score;
    string winner;
    string winst;

    games(string sn = "football", int s = 0, string wi = "1", string wst = "yes")

    {
        sportname = sn;
        score = s;
        winner = wi;
        winst = wst;

    }


};

int main()
{

    games games1("cricket", 10, "0", "no");

    cout << " Sportname " << games1.sportname << "with score " << games1.score << " is the winner " << games1.winner << " with a streak" << games1.winst << endl;

    return 0;

}