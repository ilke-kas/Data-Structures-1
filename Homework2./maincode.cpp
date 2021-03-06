#include <iostream>
#include <chrono>
#include <cstdlib>
#include <algorithm>
using namespace std;

void Algorithm1(const int* arr1, const int* arr2,int*& arr3, int N)
{
	auto start = std::chrono::high_resolution_clock::now();
	//Append all items in arr1 in the same order to arr3.
	for(int i = 0; i < N; i++)
		arr3[i] = arr1[i];
	// find the right place to insert arr2 elements
	for(int i = 0; i < N; i++)//arr2 element
	{
		int place = 2*N-1;
		//if last element of arr1< the first element of arr2, right plcae willbe N + i
		if(arr1[N-1]< arr2[0])
		{
			place = N + i;
		}
		else
		{
			for(int j = 0; j < 2*N; j++)//arr3 element
			{
				if(arr2[i] <= arr3[j])
				{
					place = j;
					break;//when find the place exit loop
				}
			}
			//shift one all elements in arr3 from the point of place
			for(int k = N+i-1; place<=k; k--)
			{
				arr3[k+1] = arr3[k];
			}
		}
		arr3[place] = arr2[i];//insert the element of arr2 to the right place
	}
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time for algorithm 1 with " <<N<<" inputs: " << elapsed.count() << " s\n";
}
void Algorithm2(const int* arr1, const int* arr2,int*& arr3, int N)
{
	auto start = std::chrono::high_resolution_clock::now();
    int ind1 = 0; //arr1's index
    int ind2 = 0; //arr2's index
    int ind3 = 0; //arr3's index

    //traverse the arrays with n sizes until reach end of one
    while(ind1 < N && ind2 < N)
    {
        if (arr1[ind1] < arr2[ind2])//compare the elements of arr1 and arr2
        {
            arr3[ind3] = arr1[ind1];
            ind3++;//increase the indexes
            ind1++;
        }
        else
        {
            arr3[ind3] = arr2[ind2];
            ind3++;//increase the indexes
            ind2++;
        }
    }

    //complete rest of the arr3 with the leftover of ind1 or ind2
    while(ind1 < N)
    {
        arr3[ind3] = arr1[ind1];
        ind3++;//increase the indexes
        ind1++;
    }
    while(ind2 < N)
    {
        arr3[ind3] = arr2[ind2];
        ind3++;//increase the indexes
        ind2++;
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time for algorithm 2 with " <<N<<" inputs: " << elapsed.count() << " s\n";
}
int main()
{
	//to randomize number totally
	srand(time(0));
	//sizes
	const int size = 7;
	int sizes[size] ={10,50,100,500,1000,5000,10000};//in report i used values up to 100000
	int n = 0; //size
	//output array
	int* arr3 = NULL;
	cout<<"all numbers in arr1 are smaller than arr2"<<endl;
	// (i) all numbers in arr1 are smaller than arr2

	for(int i = 0; i <size ; i++)
	{
		n = sizes[i];
		//create arr1 and arr2
		int arr1[n];
		int arr2[n];
		arr3 = new int[2*n];
		for(int j = 0; j <2*n; j++)
            arr3[j]= 0;
		for(int j = 0; j < n; j++)
		{
			arr1[j] = rand() % (n);
			arr2[j] = (rand() % (2*n)) + n;
		}
		sort(arr1,arr1+n);
		sort(arr2,arr2+n);
		Algorithm1(arr1,arr2,arr3,n);
		Algorithm2(arr1,arr2,arr3,n);
		delete[] arr3;
	}
	cout<<endl;
	cout<<"all numbers in arr2 are smaller than arr1"<<endl;
	// (ii) all numbers in arr2 are smaller than arr1
	for(int i = 0; i <size ; i++)
	{
		n = sizes[i];
		//create arr1 and arr2
		int arr1[n];
		int arr2[n];
		arr3 = new int[2*n];
		for(int j = 0; j <2*n; j++)
            arr3[j]= 0;
		for(int j = 0; j < n; j++)
		{
			arr2[j] = rand() % (n);
			arr1[j] = (rand() % (2*n)) + n;
		}
		sort(arr1,arr1+n);
		sort(arr2,arr2+n);
		Algorithm1(arr1,arr2,arr3,n);
		Algorithm2(arr1,arr2,arr3,n);
		delete[] arr3;
	}
	cout<<endl;
	cout<<"there is no such ordering between these arrays"<<endl;
	// (iii) there is no such ordering between these arrays
	for( int i = 0; i <size ; i++)
	{
		n = sizes[i];
		//create arr1 and arr2
		int arr1[n];
		int arr2[n];
		arr3 = new int[2*n];
		for(int j = 0; j <2*n; j++)
            arr3[j]= 0;
		for(int j = 0; j < n; j++)
		{
			arr1[j] = rand();
			arr2[j] = rand();
		}
		sort(arr1,arr1+n);
		sort(arr2,arr2+n);
		Algorithm1(arr1,arr2,arr3,n);
		Algorithm2(arr1,arr2,arr3,n);
		delete[] arr3;
	}
}
