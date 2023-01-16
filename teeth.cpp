#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
int main()
{

    int m = 0;
    int n = 0;
    fstream newFile;

    newFile.open("input.txt", ios::in);
    // checking if file was open correctly
    if (!newFile.is_open())
    {
        cout << "File was not open" << endl;
    }
    // geting the size of both sets
    newFile >> n;
    newFile >> m;
    // creating to arrays of size n and m
    int top[n];
    int bot[m];
    // filling the arrays with given input from the file
    for (int i = 0; i < n; i++)
    {
        newFile >> top[i];
    }
    // filling the arrays with given input from the file
    for (int j = 0; j < m; j++)
    {
        newFile >> bot[j];
    }
    // intializing 2D array
    int arr[2][m];
    // finding max height
    int maxheight = max(top[0] + bot[0], top[n - 1] + bot[m - 1]);

    // Filling the 2D array with the arrays top and bot
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[0][j] = top[j];
            arr[1][j] = bot[j];
        }
    }

    // Logic on how find the align height
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < m; j++)
        {

            if (i == -1 || j == -1)
            {
                return 1;
            }

            else if (arr[i][j] + arr[i + 1][j] <= maxheight) // if the sum of element is less than maxheight
            {

                continue;
            }
            else
            {
                /*
                int top_min = min(arr[i][j - 1], arr[i][j + 1]); // checking neighbors
                top_min = min(top_min, arr[i][j]);               // checking with current
                int bot_min = min(arr[i + 1][j - 1], arr[i + 1][j + 1]);
                bot_min = min(bot_min, arr[i + 1][j]); // checking with current
                */

                arr[i][j] = min(arr[i][j - 1], arr[i][j + 1]);

                // arr[i][j] = min(top_min, bot_min);
            }
        }
    }

    // Create and open a text file
    ofstream MyFile("output.txt");
    MyFile << maxheight << endl;
    // writing in the output file
    for (int i = 0; i < n; i++)
    {
        MyFile << arr[0][i] << " " << arr[1][i] << endl;
    }

    MyFile.close();
}
