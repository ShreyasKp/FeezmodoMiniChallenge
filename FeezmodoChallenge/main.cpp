#include <bits/stdc++.h>

using namespace std;

map <string, vector <string>> AL;
string arr[100];
int originalCount = 6;

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

void addPerson() {
    string newPerson, neighbour;
    int cnt;
    cin.get();
    cout << "Enter name of new person: ";
    getline(cin, newPerson);
    cout << "Enter the number of connections: ";
    cin >> cnt;
    cin.get();
    for (int i = 0; i < cnt; i++) {
        cout << "Enter " << (i+1) << "th connection: ";
        getline(cin, neighbour);
        AL[newPerson].push_back(neighbour);
        AL[neighbour].push_back(newPerson);
        arr[originalCount++] = newPerson;
    }
    cout << "Person added" << endl;
}
int main()
{
    arr[0] = "Andy";
    arr[1] = "Ben";
    arr[2] = "Carl";
    arr[3] = "Denise";
    arr[4] = "Elena";
    arr[5] = "Fiona";
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

    int option;

    do {
        cout << "Press 1 for adding new persons" << endl;
        cout << "Press 2 for finding degree of separation" << endl;
        cout << "Press 3 to exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        switch(option) {
        case 1:
            addPerson();
            break;
        case 2:
            string name1, name2;
            cin.get();
            cout << "First name: ";
            getline(cin, name1);

            cout << "Second name: ";
            getline(cin, name2);

            int degree = BFS(name1, name2);
            if(degree != 100)
                cout << "Degree of Separation = " << BFS(name1, name2) << endl;
            else
                cout << "Incorrect name" << endl;
            break;
        }
        cout << endl;
    } while (option!=3);
    return 0;
}
