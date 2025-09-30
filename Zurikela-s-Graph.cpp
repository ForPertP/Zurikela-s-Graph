#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int main()
{
    string t_temp;
    getline(cin, t_temp);
    int Q = stoi(ltrim(rtrim(t_temp)));

    TreeDP solver(100000);  
    int t = 1;    

    for (int t_itr = 0; t_itr < Q; t_itr++)
    {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
        char O = first_multiple_input[0][0];
        
        switch (O)
        {
            case 'A' :
            {
                int a = stoi(ltrim(rtrim(first_multiple_input[1])));
                solver.node_value[t++] = a;
            }
                break;
                
            case 'B' :
            {
                int a = stoi(ltrim(rtrim(first_multiple_input[1])));
                int b = stoi(ltrim(rtrim(first_multiple_input[2])));
                solver.adj[a].push_back(b);
                solver.adj[b].push_back(a);
            }
                break;

            case 'C' :
            {
                int a = stoi(ltrim(rtrim(first_multiple_input[1])));
                solver.dfs(a, a);
                solver.node_value[t++] = max(solver.dp[a][0], solver.dp[a][1]);
            }
                break;
        }
    }

}



string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
