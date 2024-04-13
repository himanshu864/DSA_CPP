#include <iostream>
#include <cstdlib>
using namespace std;

int sumArr(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

int main()
{
    char *cp = new char;
    cout << ">> new char -> " << endl;
    cout << "Stack(static) memory of pointer: " << sizeof(cp) << endl;
    cout << "Heap(dynamic) memory of new char: " << sizeof(char) << endl;
    cout << "Total memory allocated: " << sizeof(cp) + sizeof(char) << endl;

    int *arr = new int[5];
    cout << ">> new array -> " << endl;
    cout << "memory of pointer: " << sizeof(arr) << endl;
    cout << "memory of new int[5]: " << sizeof(int[5]) << endl;
    cout << "Total memory allocated: " << sizeof(arr) + sizeof(int[5]) << endl;

    cout << ">> new variable sized array -> " << endl;
    int n;
    cout << "Enter n: ";
    cin >> n;
    int *p = new int[n];

    cout << "Heap(dynamic) memory of new int[n]: " << sizeof(int[n]) << endl;

    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Sum of array: " << sumArr(arr, n) << endl;

    delete cp;
    delete[] arr;
    delete[] p;

    // can also use malloc and calloc to allocate memory dynamically
    int num = 5;
    // pointer = (data_type*)malloc(size_t sizeof(data_type));
    int *ptr = (int *)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++)
        ptr[i] = i * 2;
    // uses <cstdlib> library; returns void pointer
    /* ptr[i] and *(ptr+i) can be used interchangeably */
    for (int i = 0; i < num; i++)
        cout << ptr[i] << endl;
    free(ptr);

    int *ptr2 = (int *)calloc(5, sizeof(int));
    // calloc is same but it initializes with zero
    for (int i = 0; i < 5; i++)
        cout << ptr2[i] << endl;
    free(ptr2);

    return 0;
}

// stacks are small, fixed and static
// created during compiler time.
// automatic release after out of scope
// memory can be contigous
// heaps are large free pool of dynamic memory
// created during runtime
// not released even after out of scope. (delete/free manually)
// can't be contigous, only referenced using pointers
