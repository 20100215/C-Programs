#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void input_values(int arr[], int n);
void display(int arr[], int count);
int *get_factors(int list[], int count, int value, int *ret_count);
// int *get_factors(int list[], int value);

int main() {
    int list[SIZE], count, n, val, *factors, total_factors;

    printf("How many numbers? ");
    scanf("%d", &n);

    input_values(list, n);

    printf("Enter value: ");
    scanf("%d", &val);
    
    printf("The collection: ");
    display(list, n);

    factors = get_factors(list, n, val, &total_factors);

    printf("The factors of %d present in collection: ", val);
    //display(factors, total_factors);

    printf("This display has been created in main {");
    for(int i = 0; i < total_factors; ++i) {
        printf("%d", factors[i]);
        if(i < total_factors - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    free(factors);
    return 0;
}

void input_values(int arr[], int n) {
    int i;
    for(i = 0; i < n; ++i) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int *get_factors(int list[], int count, int value, int *ret_count) {
    int temp[count], ctr = 0, *factor_list;

    for(int i = 0; i < count; ++i) {
        if(value % list[i] == 0) {
            temp[ctr++] = list[i];
        }
    }

    factor_list = malloc(sizeof(int) * ctr);
    
    // memcpy(factor_list, temp, sizeof(int) * ctr);
    for(int i = 0; i < ctr; ++i) {
        factor_list[i] = temp[i];
    }

    *ret_count = ctr;

    return factor_list;
}

// int *get_factors(int list[], int count, int value, int *ret_count) {
//     int ctr = 0;
//     int *factor_list = malloc(sizeof(int) * SIZE);

//     for(int i = 0; i < count; ++i) {
//         if(value % list[i] == 0) {
//             factor_list[ctr++] = list[i];
//         }
//     }
//     *ret_count = ctr;

//     return factor_list;
// }

void display(int arr[], int count) {
    printf("{");
    for(int i = 0; i < count; ++i) {
        printf("%d", arr[i]);
        if(i < count - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}