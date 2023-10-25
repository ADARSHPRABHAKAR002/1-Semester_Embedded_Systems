#include <stdio.h>
#include <stdlib.h>

void display(char arr_p[], int arr_bt[], int arr_at[], int arr_tat[], int arr_wt[], int n);
void display1(char arr_p[], int arr_bt[], int arr_at[],int n);

int main() {
    int n, sum1 = 0, sum2 = 0;
    printf("Enter the number\n");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input for 'n'\n");
        return 1; // Exit with an error code
    }

    char arr_p[n];
    int arr_at[n], arr_bt[n], arr_wt[n], arr_tat[n];
    
    printf("Process_ID__Burst_Time__Arrival_Time\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c %d %d", arr_p + i,&arr_bt[i],&arr_at[i]);
    }
	display1(arr_p,arr_bt,arr_at,n);
	
    for (int i = 0; i < n; i++) {
        sum1 += arr_bt[i];
        arr_tat[i] = sum1-arr_at[i];
	
    }
	arr_wt[0] = 0;
	for(int i=1;i<n;i++)
	{
	sum2 += arr_bt[i - 1];
        arr_wt[i] = sum2 - arr_at[i];
	}
    
    
    
    printf("Process_ID\tBurst_time\tArr_Time\tTurn_A_Time\tWait_Time\n");
    display(arr_p, arr_bt, arr_at, arr_tat, arr_wt, n);

    return 0;
}

void display(char arr_p[], int arr_bt[], int arr_at[], int arr_tat[], int arr_wt[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c\t\t%d\t\t%d\t\t%d\t\t%d\n", arr_p[i], arr_bt[i], arr_at[i], arr_tat[i], arr_wt[i]);
    }
}

void display1(char arr_p[], int arr_bt[], int arr_at[],int n) {
    for (int i = 0; i < n; i++) {
        printf("%c\t\t%d\t\t%d\n", arr_p[i], arr_bt[i], arr_at[i]);
    }
}
