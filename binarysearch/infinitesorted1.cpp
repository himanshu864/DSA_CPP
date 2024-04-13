#include <iostream>
int get(long long index)
{
    // For demonstration purposes only
    // this would get us the element from that array
    return (index % 3 == 0) ? 1 : 0;
}

// find index of first one in a sorted infinite binary number array
long long firstOne()
{
    // Find the upper bound of the range containing the first occurrence of 1
    long long s = 0;
    long long e = 1;
    while (get(e) == 0)
    {
        s = e;
        e *= 2;
    }

    // Perform binary search to find the first occurrence of 1
    long long ans = e;
    while (s <= e)
    {
        long long mid = s + (e - s) / 2;
        if (get(mid) == 1)
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}

int main()
{
    std::cout << "First occurrence of 1 is at index: " << firstOne() << std::endl;
    return 0;
}
