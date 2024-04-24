/*
 * @author Kashikizu
 * File Creation Date: 23/04/2024 (dd/mm/yyyy)
 * Initial Completion Date: 24/04/2024
 */

#include <bits/stdc++.h>
using namespace std;

void printVect(vector<int> a) //Function to Print the Vector
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

vector<int> merger(vector<int> L, vector<int> R) //Function to merge the two vectors
{
    int m = L.size(), n = R.size();
    vector<int> A(m + n); //Initializing the vector that will have the merged quantity
    L[m] = 99; //Setting the mth term in the ascending vector to something big
    int i = 0; //i for the ascending vector
    int j = n - 1; //j for the descending vector; j has to be compared from the opposite side
    for (int k = 0; k <= (m + n - 1); k++)
    {
        if (L[i] <= R[j]) //Checks which is smaller
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j--;
        }
    }
    return A; //Returns the merged vector
}

int main()
{
    vector<int> L = {5, 10, 15, 20, 25}; //Ascending Vector
    vector<int> R = {26, 22, 14, 11, 4}; //Descending Vector
    vector<int> A; //Merged Vector
    cout << "Ascending List:" << endl;
    printVect(L);
    cout << "Descending List:" << endl;
    printVect(R);
    A = merger(L, R); //Sending the 2 lists in the merging function
    printVect(A);
}
