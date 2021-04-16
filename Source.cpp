#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef vector<vector<bool>> Graph;

int countVertexDegree(int vertex, Graph a)
{
    int res = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[vertex][i] == true) res++;
    }
    return res;
}

int countStar(Graph a)
{
    if (a.size() == 0 || a.size() == 1) return 0;

    if (a.size() == 2)
    {
        if (a[0][1] == 1 && a[1][0] == 1 && a[0][0] == 0 && a[1][1] == 0) return 1;
        else return 0;
    }
    int res = 0;

    vector<int> adjVertex;
    vector<bool> check(a.size(), false);
    for (int i = 0; i < a.size(); i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            for (int j = 0; j < a.size(); j++)
            {
                if (a[i][j] == true)
                {
                    adjVertex.push_back(j);
                    check[j] = true;
                }
            }

            int checkV = true;
            for (int j : adjVertex)
            {
                cout << j << endl;
                cout << ' ' << countVertexDegree(j, a) << ' ' << a[j][i] << endl;
                if (countVertexDegree(j, a) != 1 || a[j][i] == false)
                {
                    
                    checkV = false;
                    break;
                }
            }
            if (checkV == true && adjVertex.size() > 0) res++;
        }
        adjVertex.clear();
    }

    return res;
}

int main()
{
    ifstream inFile("input.txt");
    if (!inFile)
    {
        cout << "cant find file";
        return 0;
    }
    int n;
    cin >> n;
    vector <vector<bool>> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = vector<bool>(n);
    }

    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inFile >> temp;
            arr[i][j] = (bool)temp;
        }
    }
    inFile.close();
    cout << "res : " << countStar(arr) << endl;
}