#include <iostream>
using namespace std;

int arr[20], B[20];
int n;

void input(){
    while (true){
        cout << "Masukkan Panjang Element Array : ";
        cin >> n;

        if (n <= 20){
            break;
        }
        else{
            cout << "\nMaksimal Panjang Array Adalah 20" << endl;
        }
    }
    cout << "\n--------------------------" << endl;
    cout << "\nInputkan Isi Element array" << endl;
    cout << "\n--------------------------" << endl;

    for (int i = 0; i < n; i++){
        cout << "Array Index Ke- " << i << " : ";
        cin >> arr[i];
    }
}

void mergeSort(int low, int high){
    if (low >= high){ 
        return;
    } 

    int mid = (low + high) / 2;
    
    mergeSort(low, mid);
    mergeSort(mid + 1, high);

    int i = low; 
    int j = mid + 1;
    int k = low;
    
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j]){
            B[k] = arr[i];
            i++;
        } 
        else{
            B[k] = arr[j];
            j++;
        }
        k++; //step 4.d.ii
    } 

    while (j <= high)
    {  
        B[k] = arr[j];
        j++;
        k = k + 1;
    }

    while (i <= mid)
    {
        B[k] = arr[i];
        i++;
        k++;
    }

    for (int x = low; x <= high; x++)
    {
        arr[x] = B[x];
    }
}

void output()
{
    cout << "\nData Setelah Diurutkan (Merge Sort): ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    input();
    mergeSort(0, n - 1);
    output();
}