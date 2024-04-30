/*
 * @author Kashikizu
 * File Creation Date: 29/04/2024 (dd/mm/yyyy)
 * Initial Completion Date: 2/04/2024
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> elems;

void printVect(vector<int> a) //Function to Print the Vector
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merger(int lo, int mid, int hi) //Function to merge the two vectors
{
    int m = mid - lo + 1, n = hi - mid;
    vector<int> L(m + 1);
    vector<int> R(n + 1); //Initializing the vector that will have the merged quantity
    for(int i = 0; i <= m -1; i++)
    {
        L[i] = elems[lo + i];
    }
    for(int j = 0; j <= n -1; j++)
    {
        R[j] = elems[mid + 1 + j];
    }
    L[m] = 999; //Setting the mth term in the ascending vector to something big
    R[n] = 999;
    // cout << "This is L: ";
    // printVect(L);
    // cout << "This is R: ";
    // printVect(R);
    int i = 0;
    int j = 0;
    for (int k = lo; k <= (m + n - 1); k++)
    {
        if (L[i] <= R[j]) //Checks which is smaller
        {
            // cout << L[i] << endl;
            elems[k] = L[i];
            i++;
        }
        else
        {
            // cout << "R[j] = " << R[j] << endl;
            elems[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int lo, int hi)
{
    if(lo < hi)
    {
        // cout << "Sorting" << endl;
        int mid = (hi + lo) / 2;
        mergeSort(lo, mid);
        mergeSort(mid + 1, hi);
        merger(lo, mid, hi);
    }
    // cout << "lo > hi" << endl;
}


int main()
{
    int input;
    cout << "Enter the number of elements you want to add:" << endl;
    cin >> input;
    cout << input << " number of inputs were selected" << endl;
    cout << endl;
    // vector<int> elems;
    int elem;
    for (int i = 0; i < input; i++)
    {
        cout << "Enter element no. " << i + 1 << ": ";
        cin >> elem;
        elems.push_back(elem);
    }
    cout << "List of elements:" << endl;
    printVect(elems);
    mergeSort(0, input - 1);
    mergeSort(0, input - 1);
    cout << "Sorted list:" << endl;
    printVect(elems);
    cout << endl;
}
