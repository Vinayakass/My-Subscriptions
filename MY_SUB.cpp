#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Newspaper
{
public:
    int no_of_newspapers;
    vector<pair<string, vector<float>>> prices;
    vector<pair<float, string>> newspaper_weekly_cost;

    Newspaper(int number_of_newspapers)
    {
        no_of_newspapers = number_of_newspapers;
    }

    void take_input()
    {
        cout << "Enter the name of the newspaper and its prices on each 7 days of the week:" << endl;
        for(int i = 0; i < no_of_newspapers; i++)
        {
            string s;
            cin >> s;
            vector<float> temp(7);
            for(int i = 0; i < 7; i++)
                cin >> temp[i];
            prices.push_back({s, temp});
            newspaper_weekly_cost.push_back( {accumulate(begin(temp), end(temp), 0.0), s} );
        }
    }
    vector<pair<string, string>> get_all_possible_combinations(float budget)
    {
        vector<pair<string, string>> answer;
        for(int i = 0; i < no_of_newspapers - 1; i++)
        {
            for(int j = i+1; j < no_of_newspapers; j++)
            {
                if(newspaper_weekly_cost[i].first + newspaper_weekly_cost[j].first <= budget)
                {
                    answer.push_back({ newspaper_weekly_cost[i].second, newspaper_weekly_cost[j].second });
                }
            }
        }
        return answer;
    }
};

int main()
{
    Newspaper city1(5);
    city1.take_input();

    vector<pair<string, string>> comb;
    float budget = 0;
    cout << "Enter Budget: ";
    cin >> budget;
    while(budget != -1)
    {
        comb = city1.get_all_possible_combinations(budget);
        for(auto p:comb)
        {
            cout << '{' << p.first << ", " << p.second << '}' << ", ";
        }
        cout << endl << endl << "Enter Budget: ";
        cin >> budget;
    }

    return 0;
}

/*Sample Input:
TOI 3 3 3 3 3 5 6
HINDU 2.5 2.5 2.5 2.5 2.5 4 4
ET 4 4 4 4 4 4 10
BM 1.5 1.5 1.5 1.5 1.5 1.5 1.5
HT 2 2 2 2 2 4 4*/

