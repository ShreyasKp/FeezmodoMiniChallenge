#include <bits/stdc++.h>

using namespace std;

map <string, vector <string>> AL;
const char *arr[] = {"Andy", "Ben", "Carl", "Denise", "Elena", "Fiona"};

int BFS(string start, string finish) {
    map<string, bool> visited;
    map<string, int> distance;
    for(string name: arr) {
        visited[name] = false;
        distance[name] = 100;
    }
    queue<string> Q;
    distance[start] = 0;
    Q.push(start);
    visited[start] = true;
    while(!Q.empty()) {
        string x = Q.front();
        Q.pop();
        for(auto v : AL[x]) {
            if(!visited[v]) {
                if(distance[v] > distance[x] + 1)
                    distance[v] = distance[x] + 1;
                visited[v] = true;
                Q.push(v);
            }
        }
    }
    return distance[finish];
}
int main()
{
    AL["Andy"].push_back("Ben");
    AL["Ben"].push_back("Andy");
    AL["Ben"].push_back("Carl");
    AL["Ben"].push_back("Denise");
    AL["Carl"].push_back("Elena");
    AL["Carl"].push_back("Ben");
    AL["Denise"].push_back("Ben");
    AL["Denise"].push_back("Fiona");
    AL["Elena"].push_back("Carl");
    AL["Elena"].push_back("Fiona");
    AL["Fiona"].push_back("Elena");
    AL["Fiona"].push_back("Denise");

    string name1, name2;
    cout << "First name: ";
    getline(cin, name1);
    cout << "Second name: ";
    getline(cin, name2);

    int degree = BFS(name1, name2);
    if(degree != 100)
        cout << "Degree of Separation = " << BFS(name1, name2) << endl;
    else
        cout << "Incorrect name" << endl;
    return 0;
}
