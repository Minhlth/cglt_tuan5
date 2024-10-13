#include <iostream>
using namespace std;
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int n)
{
    int i, j, min_f;
    for (i = 0; i < n - 1; i++)
    {
        min_f = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_f])
                min_f = j;
        swap(&arr[min_f], &arr[i]);
    }
}

bool ck_prime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool ck_blum(int n)
{
    if (n < 2) return false;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0 && ck_prime(i) && ck_prime(n / i)) {
            return true;
        }
    }
    return false;
}


int main()
{
    cout << "Bai 1" << endl;
    int arr[] = { 2, 0, 2, 0, 0, 1, 0, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, n);
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cout << "do ";
        else if (arr[i] == 1) cout << "trang ";
        else if (arr[i] == 2) cout << "xanh ";
    }
    cout << endl;

    cout << "Bai 2" << endl;
    {
        int M = 10, N = 20;
        int countPrime = 0; int countBlum = 0;
        int* PrimeArr = new int[N];
        if (N > 1) PrimeArr[countPrime++] = 2;
        for (int i = 3; i <= N / 2; i = i + 2) {
            if (ck_prime(i)) PrimeArr[countPrime++] = i;
        }
        int* BlumArr = new int[countPrime];
        for (int i = 0; i < countPrime; i++) {
            for (int j = i; j < countPrime; j++) {
                int mul = PrimeArr[i] * PrimeArr[j];
                if (mul < N) {
                    BlumArr[countBlum++] = mul;
                }
            }
        }
        selection_sort(BlumArr, countBlum);
        for (int i = 0; i < countBlum; i++) {
            cout << BlumArr[i] << ' ';
        }
        cout << endl;

        for (int i = 0; i < countBlum; i++) {
            if (BlumArr[i] == M) {
                cout << "M thuoc day blum cho truoc" << endl;
            }
        }
        cout << "cac cap co tong la blum nho hon N la: " << endl;
        {
            for (int i = 0; i < countBlum; i++) {
                for (int j = i + 1; j < countBlum; j++) {
                    int sum = BlumArr[i] + BlumArr[j];
                    if (ck_blum(sum) && (sum) < N) {
                        cout << '(' << BlumArr[i] << ";" << BlumArr[j] << ")" << endl;
                    }
                }
            }
        }
    }
}