#include <iostream>
using namespace std;

// n = no. of books, m = no. of students
bool isPossibleSol(int pages[], int n, int m, int mid)
{
    int CountStudent = 1;
    int PageSum = 0;
    for (int i = 0; i < n; i++) // allote all books
    {
        if (PageSum + pages[i] <= mid)
            PageSum += pages[i];
        else
        {
            CountStudent++;
            if (CountStudent > m || pages[i] > mid)
                return false; // if all books couldn't be alloted to m student, or there are more pages in a book then mid, false.
            PageSum = pages[i];
        }
    }
    return true;
}

int allocation(int pages[], int n, int m)
{
    int ans = -1;
    if (n < m) // if students more than books, false
        return ans;

    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
        end += pages[i]; // apply BS on range: 0 to total no. of pages

    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        if (isPossibleSol(pages, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}

int main()
{
    int pages[4] = {20, 30, 10, 20};
    int m = 5;
    cout << allocation(pages, 4, m) << endl;
    return 0;
}
