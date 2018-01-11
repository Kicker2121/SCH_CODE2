#include <iomanip>
#include <iostream>

using namespace std;

#define MAX 1000

int main(void)  // main
{
	string a[MAX];
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    
    load(a, siz)
    cout << "Maximum contiguous sum is \n" << max_sum;
    
    return 0;
} // exit main

void load (int size, string a[MAX])
{
	for (int i = 0; i < size; i++) {
       cin >> a[i];
	}
}

int maxSubArraySum(int a[MAX], int size)
{
    int max_start=0, max_end=0;
 
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];

        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
    }
    return max_so_far;
}