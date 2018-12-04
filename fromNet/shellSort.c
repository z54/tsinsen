int shellsort(int a[],int n)
{
    int temp, gap; // gap 步长
    int i, j;
    while (gap < n / 3){
        gap = gap * 3 + 1;
    }
    for (;gap > 0; gap /= 3){
        for (i = gap; i < n; i++){
            temp = a[i];
            for (j = i - gap; j > 0 && a[j] > temp; j-=gap){
                a[j + gap] = a[j];
            }
            a[j + gap] = temp;
        }
    }
    return a;
}