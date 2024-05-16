#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int  t = arr[0]; 
    for(int i=1;i<n;i++)
    {
        if(t < arr[i])
        {
            t = arr[i];
        }
    }
    cout<<"The largest of all elements in the array is "<<t<<endl;
    return 0;
}