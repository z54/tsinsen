// 冒泡排序（BubbleSort）
int Bublesort(int a[],int n)
{
     int i,j,k;
     for(j=0;j<n;j++)   /* 气泡法要排序n次*/
     {
          for(i=0;i<n-j;i++)  /* 值比较大的元素沉下去后，只把剩下的元素中的最大值再沉下去就可以啦 */
          {
               if(a[i]>a[i+1])  /* 把值比较大的元素沉到底 */
               {
                    k=a[i];
                    a[i]=a[i+1];
                    a[i+1]=k;
               }
          }
     }
     return 0;
}

// 选择排序
void SelectSort(int a[],int n)  
{  
    int i,j;  
    for(i = 0;i < n - 1; i++)              //n个数要进行n-1趟比较，每次确定一个最小数放在a[i]中  
    {  
        int k = i;                    //假设a[0]是最小的数，把下标0放在变量K里面，  
        for(j=i+1;j<n;j++)            
            if(a[k] > a[j])  
                k=j;     //如果a[k]>a[j] 前面的数比后面的数大，交换下标，此时k指向小的数  
        if(k != i)  
        {  
            int temp = a[i];  
            a[i] = a[k];  
            a[k] = temp;  
        }  
    }  
} 

