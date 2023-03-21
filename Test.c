#include <stdio.h>

int main() {
    char input[100];
    int result = 0;
    char operator = '+';
    int i = 0;
    while (1) {
        char c = getchar();
        if (c == '\n' || c == EOF) {
            input[i] = '\0';
            break;
        }
        input[i++] = c;
    }
    i = 0;
    while (input[i] != '\0') {
        if (input[i] >= '0' && input[i] <= '9') {
            int num = 0;
            while (input[i] >= '0' && input[i] <= '9') {
                num = num * 10 + (input[i] - '0');
                i++;
            }
            switch (operator) {
                case '+':
                    result += num;
                    break;
                case '-':
                    result -= num;
                    break;
                case '*':
                    result *= num;
                    break;
                case '/':
                    result /= num;
                    break;
                case '%':
                    result %= num;
                    break;
                default:
                    printf("Invalid operator: %c\n", operator);
                    return 1;
            }
        } else if (input[i] == '+') {
            if (input[i+1] == '+') {
                result++;
                i += 2;
            } else {
                operator = '+';
                i++;
            }
        } else if (input[i] == '-') {
            if (input[i+1] == '-') {
                result--;
                i += 2;
            } else {
                operator = '-';
                i++;
            }
        } else if (input[i] == '*') {
            operator = '*';
            i++;
        } else if (input[i] == '/') {
            operator = '/';
            i++;
        } else if (input[i] == '%') {
            operator = '%';
            i++;
        } else if (input[i] == '=') {
            printf("%d\n", result);
            break;
        } else {
            printf("Invalid input: %c\n", input[i]);
            return 1;
        }
    }
    return 0;
}
