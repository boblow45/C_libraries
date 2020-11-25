#include "sorting_alg.h"
#include <stdlib.h>

static void swop(int32_t * a, int32_t * b){
    int32_t tmp = *a;
    *a = *b;
    *b = tmp;
}

static uint32_t partition(int32_t base[], uint32_t low, uint32_t high){
    int32_t pivot = base[high];

    uint32_t i = low;
    for(uint32_t j=low; j<=high; j++){
        if(base[j]< pivot){
            swop(&base[j], &base[i]);
            i++;
        }
    }
    swop(&base[high], &base[i]);
    return i;
}



void quick_sort(int32_t base[], uint32_t low, uint32_t high){
    if(low < high){
        uint32_t pivot = partition(base, low, high);
        quick_sort(base, low, pivot-1);
        quick_sort(base, pivot+1, high);
    }
}

static void merge(int32_t base[], uint32_t low, uint32_t mid, uint32_t high){
    
    uint32_t i,j,k;
    uint32_t len_arr1 = mid - low + 1;
    uint32_t len_arr2 = high - mid;

    int32_t arr1[len_arr1];
    int32_t arr2[len_arr2];

    for(i = 0; i<len_arr1;i++){
        arr1[i] = base[low + i];
    }

    for(j = 0; j<len_arr2;j++){
        arr2[j] = base[mid + 1 + j];
    }

    i=0, j=0, k=low;
    while (i<len_arr1 &&j<len_arr2){
        if(arr1[i] < arr2[j]){
            base[k] = arr1[i++];
        }
        else{
            base[k] = arr2[j++];
        }
        k++;
    }

    for(;i<len_arr1;k++,i++){
        base[k] = arr1[i];
    }
    
    for(;j<len_arr2;k++,j++){
        base[k] = arr2[j];
    }
}

void merge_sort(int32_t base[], uint32_t low, uint32_t high){
    if(low < high){
        uint32_t mid = (high - low)/2 + low;
        merge_sort(base, low, mid);
        merge_sort(base, mid+1, high);

        merge(base, low, mid, high);
    }
}



void swop_objects(void *pa, void *pb, uint32_t size){
    uint8_t tmp;
    uint8_t *a = pa, *b = pb;
    while(size--){
        tmp = *a;
        *a = *b;
        *b = tmp;
        (char *)a++;
        (char *)b++;
    }
}


// for(uint32_t j=low; j<=high; j++){
//     if(base[j]< pivot){
//         swop(&base[j], &base[i]);
//         i++;
//     }
// }
// swop(&base[high], &base[i]);

uint32_t partition_with_cmpr(void * data, uint32_t n_ele, uint32_t size, int(* compr)(const void *, const void *)){
    void * pivot = (void *)((char*)data + (size * (n_ele - 1)));

    uint32_t i = 0;
    void * current = NULL;
    void * index_ls_than_piv = NULL;
    for(uint32_t j=0; j<n_ele;j++){
        // compar returns negivate value if second para is greater than the first para
        current = (void *)((char*)data + (size * j));
        if(compr(pivot, current) >0){
            index_ls_than_piv = (void *)((char*)data + (size * i));
            swop_objects(current, index_ls_than_piv, size);
            i++;
        }

    }

    index_ls_than_piv = (void *)((char*)data + (size * i));
    swop_objects(pivot, index_ls_than_piv, size);
    return i;
}


void quickSort(void * data, uint32_t n_ele, uint32_t size, int32_t(* compr)(const void *, const void *)){
    uint32_t pivot_index = partition_with_cmpr(data, n_ele, size, compr);
    if (n_ele > 1){
        if (pivot_index)
            quickSort(data, pivot_index, size, compr); 
        if (n_ele - (pivot_index + 1)){
            void * tmp = (void *)((char *) data + (size * (pivot_index + 1)));
            quickSort(tmp, n_ele - (pivot_index + 1) , size, compr);
        }
    }
}