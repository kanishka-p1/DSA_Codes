#include <iostream>
using namespace std;

class solution
{
public:
    int merge(long long arr[], long long temp[], long long left, long long mid, long long right)
    {
        long long i = left, j = mid, k = left;
        int count = 0;
        while ((i <= mid - 1) && (j <= right))
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                count = count + (mid - i);
            }
        }
        while (i <= mid - 1)
        {
            temp[k++] = arr[i++];
        }
        while (j <= right)
        {
            temp[k++] = arr[j++];
        }
        for (i = left; i <= right; i++)
        {
            arr[i] = temp[i];
        }
        return count;
    }

    int mergesort(long long arr[], long long temp[], long long left, long long right)
    {
        long long mid;
        int count = 0;
        if (right > left)
        {
            mid = (left + right) / 2;
            count += mergesort(arr, temp, left, mid);
            count += mergesort(arr, temp, mid + 1, right);
            count += merge(arr, temp, left, mid + 1, right);
        }
        return count;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        int ans = mergesort(arr, temp, 0, N - 1);
        return ans;
    }
};

int main()
{
    long long T;
    cin >> T;
    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }
    return 0;
}