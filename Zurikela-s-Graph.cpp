#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

const int NUMS = 100001;
int V[NUMS];
std::vector<int> adj[NUMS];
int dir[NUMS][2];
bool g_b[NUMS];

void recursive_check(int a, int b)
{
    g_b[a] = true;
    dir[a][0] = 0;
    dir[a][1] = V[a];
    
    for (auto& v: adj[a])
    {
        if(v != b)
        {
            recursive_check(v, a);
            dir[a][0]+=max(dir[v][0], dir[v][1]);
            dir[a][1]+=dir[v][0];
        }
    }                
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int Q = stoi(ltrim(rtrim(t_temp)));

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
                V[t++] = a;
            }
                break;
                
            case 'B' :
            {
                int a = stoi(ltrim(rtrim(first_multiple_input[1])));
                int b = stoi(ltrim(rtrim(first_multiple_input[2])));
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
                break;

            case 'C' :
            {
                int a = stoi(ltrim(rtrim(first_multiple_input[1])));
                recursive_check(a, a);
                V[t++] = std::max(dir[a][0], dir[a][1]);
            }
                break;
                
        }
    }


    int result = 0;
    for (int i = 1; i <= t; ++i)
    {
        if (!g_b[i])
        {
            recursive_check(i, i);
            result += std::max(dir[i][0], dir[i][1]);
        }
    }
    cout << result << "\n";

    return 0;
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
