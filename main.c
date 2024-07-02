#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int find_lcm_of_array(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = lcm(result, arr[i]);
    }
    return result;
}

int main() {
    int p;
    printf("Введіть кількість чисел p (2 ≤ p ≤ 20): ");
    scanf("%d", &p);

    if (p < 2 || p > 20) {
        printf("Некоректне значення p. Повинно бути від 2 до 20.\n");
        return 1;
    }

    int numbers[p];
    printf("Введіть %d натуральних чисел, розділених пробілом: ", p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &numbers[i]);
    }

    int result = find_lcm_of_array(numbers, p);
    printf("Найменше спільне кратне заданих чисел: %d\n", result);

    return 0;
}

