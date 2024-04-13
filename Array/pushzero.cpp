#include <iostream>
#include <vector>
using namespace std;

// Push all the zero's in a binary number to the end
// Thus, zero's in the beginning(if any) don't make it to array, hence don't get pushed back

void pushthatzero(long long n)
{
    vector<long long> nums;
    
    // Push binary digits to vector
    for (long long x = n; x > 0; x /= 10)
        nums.insert(nums.begin(), x % 10);

    // Push zero
    for (long long a = 0, b = 0; b < nums.size(); b++)
        if (nums[b] != 0)
            swap(nums[a++], nums[b]);

    // print result
    for (long long i : nums)
        cout << i;
}

int main()
{
    long long n;
    cout << "Type a binary number: ";
    cin >> n;
    pushthatzero(n);
    return 0;
}
