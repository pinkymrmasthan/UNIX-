#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include <math.h>

int main() {

    char input[50];

    int result = 0;

    int num1 = 0;

    int num2 = 0;

    char op = '+';

    int i = 0;

    printf("Enter an arithmetic expression: ");

    scanf("%s", input);

    while (input[i] != '\0') {

        if (input[i] == '(') {

            // Evaluate the expression within the brackets

            int j = i + 1;

            int bracket_count = 1;

            while (bracket_count > 0) {

                if (input[j] == '(') {

                    bracket_count++;

                } else if (input[j] == ')') {

                    bracket_count--;

                }

                j++;

            }

            char bracket_input[j - i - 1];

            strncpy(bracket_input, &input[i + 1], j - i - 2);

            bracket_input[j - i - 2] = '\0';

            num2 = atoi(bracket_input);

            i = j - 1;

        } else if (isdigit(input[i])) {

            // Extract the number from the input array

            int j = i + 1;

            while (isdigit(input[j])) {

                j++;

            }

            char num_input[j - i + 1];

            strncpy(num_input, &input[i], j - i);

            num_input[j - i] = '\0';

            num2 = atoi(num_input);

            i = j - 1;

        } else if (input[i] == '*' || input[i] == '/') {

            op = input[i];

        } else if (input[i] == '+' || input[i] == '-') {

            // Evaluate the previous operation

            if (op == '+') {

                result += num1;

            } else if (op == '-') {

                result -= num1;

            } else if (op == '*') {

                result *= num1;

            } else if (op == '/') {

                result /= num1;

            }

            num1 = num2;

            op = input[i];

        }

        i++;

    }

    // Evaluate the final operation

    if (op == '+') {

        result += num1;

    } else if (op == '-') {

        result -= num1;

    } else if (op == '*') {

        result *= num1;

    } else if (op == '/') {

        result /= num1;

    }

    printf("Result = %d\n", result);

    return 0;

}

