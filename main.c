#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 15


int partition(int arr[], int low, int high, int pivot){
    int i = low;
    int temp;
    int j;
    for (j = low; j < high; ++j) {
        if(arr[j]<pivot) {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        }
        else if(arr[j]==pivot){
            temp = arr[j];
            arr[j] = arr[high];
            arr[high] = temp;
            j--;
        }
    }
    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void matchPairs(int lock[], int key[], int low, int high){
    if(low<high){
        int random = low + rand() % (high - low);
        printf("Random: %d\n", random);
        int pivot = partition(lock, low, high, key[random]);
        partition(key, low, high, lock[pivot]);

        matchPairs(lock, key, low, pivot-1);
        matchPairs(lock, key, pivot+1, high);
    }
}

//bu fonksiyon kullanilmiyor ancak siz testlerinizde kullanabilirsiniz
void generateRandomArray(int arr[], int n){
    int random;
    int i,j;
    for (i = 0; i < n; ++i) {
        random = 1 + rand() % n;
        for (j = 0; j < i; ++j) {
            if(arr[j]==random){
                random = 1 + rand() % n;
                j=-1;
            }
        }
        arr[i] = random;
    }
}


int main() {
    srand(time(NULL));
    int lock[N]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int key[N]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int i;
    printf("Locks: ");
    for (i = 0; i < N; ++i) {
        printf("%d ", lock[i]);
    }
    printf("\nKeys: ");
    for (i = 0; i < N; ++i) {
        printf("%d ", key[i]);
    }
    printf("\n");
    matchPairs(lock, key, 0, N-1);

    printf("Locks: ");
    for (i = 0; i < N; ++i) {
        printf("%d ", lock[i]);
    }
    printf("\nKeys: ");
    for (i = 0; i < N; ++i) {
        printf("%d ", key[i]);
    }
    printf("\n");
    return 0;
}
