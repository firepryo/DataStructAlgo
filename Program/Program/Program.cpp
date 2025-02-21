// Tay Kian Kai Reuben P2002356
// Teh Jia Hao Herman P2020150

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Task {
public:
    char from;
    char to;
    bool pickedup = false;
    bool completed = false;
};

int main() {
    vector<Task> a(4);//need to store 4 tasks
    //Task a[4];
    char f, t;
    int TotalDist = 0;

    //2-D array for distances
    int b[4][4];
    char points[4] = { 'H','A','B','C' };

    ifstream my_file("C:/Users/reube/Downloads/task2.txt"); //w3schools
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (row == col) {
                b[row][col] = 0;
            }
            else {
                char ch;
                if (!my_file) {
                    cout << "No such file";
                }
                else {
                    while (1) {
                        my_file >> ch;
                        if (isdigit(ch)) {
                            break;
                        }
                    }
                }
                b[row][col] = ch - '0';
            }
        }
    }
    my_file.close();

    //print 2d distance array
    cout << "  H A B C\n";
    for (int row = 0; row < 4; row++) {
        cout << points[row] << " ";
        for (int col = 0; col < 4; col++) {
            cout << b[row][col] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    //get tasks
    for (int i = 0; i < 4; i++) {
        cout << "Please enter task " << i << ":\n";
        cout << "from: ";
        cin >> f;
        cout << "to: ";
        cin >> t;
        Task x;
        x.from = f;
        x.to = t;
        a[i] = x;
        //store task x in a[0],a[1],a[2],a[3]
       
    }
    cout << "\n";

    //print tasks
    for (int i = 0; i < 4; i++) {
        cout << " task " << i << " from: " << a[i].from << " to " << a[i].to << endl;
    }

    
    int pos = 0; 
    int closestDist = 999;
    int currentTask = 999;
    int dest = 999;

    
    for (int j = 0; j < 4; j++) {
        cout << "\n";
        closestDist = 999;
        for (int i = 0; i < 4; i++) {
            if (a[i].pickedup == false) {
                char* potentialDestIndex = find(begin(points), end(points), a[i].from);
                int potentialDest = potentialDestIndex - points;

                if (closestDist > b[pos][potentialDest]) {
                    closestDist = b[pos][potentialDest];

                    dest = potentialDest;
                    currentTask = i;
                }
            }
        }
        cout << "Going from " << points[pos] << " to " << points[dest] << "\n";
        pos = dest;
        a[currentTask].pickedup = true;
        cout << "Task " << currentTask << " picked up: true\n";
        cout << "closestdist = " << closestDist << ", pos = " << pos << "\n";
        TotalDist += closestDist;
    }

    for (int j = 0; j < 4; j++) {
        cout << "\n";
        closestDist = 999;
        for (int i = 0; i < 4; i++) {
            if (a[i].completed == false) {
                char* potentialDestIndex = find(begin(points), end(points), a[i].to);
                int potentialDest = potentialDestIndex - points;

                if (closestDist > b[pos][potentialDest]) {
                    closestDist = b[pos][potentialDest];

                    dest = potentialDest;
                    currentTask = i;
                }
            }
        }
        cout << "Going from " << points[pos] << " to " << points[dest] << "\n";
        pos = dest;
        a[currentTask].completed = true;
        cout << "Task " << currentTask << " completed: true\n";
        cout << "closestdist = " << closestDist << ", pos = " << pos << "\n";
        TotalDist += closestDist;
    }
    TotalDist += b[pos][0];
    pos = 0;
    cout << "\nTime to go home.\n";
    cout << "Total distance: " << TotalDist;
    //expected result: H A B A C H

    return 0;
}