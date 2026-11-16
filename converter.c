#include <stdio.h>

#define MAX_SIZE 128

typedef struct {
    int data[MAX_SIZE];
    int top;
} SeqStack;

static void InitStack(SeqStack *stack)
{
    stack->top = -1;
}

static int IsEmpty(const SeqStack *stack)
{
    return stack->top == -1;
}

static int IsFull(const SeqStack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

static int Push(SeqStack *stack, int value)
{
    if (IsFull(stack)) {
        return 0;
    }

    stack->data[++stack->top] = value;
    return 1;
}

static int Pop(SeqStack *stack, int *value)
{
    if (IsEmpty(stack)) {
        return 0;
    }

    *value = stack->data[stack->top--];
    return 1;
}

static char DigitToChar(int digit)
{
    if (digit >= 0 && digit <= 9) {
        return (char)('0' + digit);
    }

    return (char)('A' + digit - 10);
}

static void PrintInBase(long long value, int base, const char *label)
{
    SeqStack stack;
    unsigned long long magnitude;
    int negative = value < 0;

    InitStack(&stack);

    if (negative) {
        magnitude = (unsigned long long)(-(value + 1)) + 1ULL;
    } else {
        magnitude = (unsigned long long)value;
    }

    do {
        int digit = (int)(magnitude % (unsigned long long)base);
        if (!Push(&stack, digit)) {
            fprintf(stderr, "Stack overflow.\n");
            return;
        }
        magnitude /= (unsigned long long)base;
    } while (magnitude > 0);

    printf("%s: ", label);
    if (negative) {
        putchar('-');
    }

    while (!IsEmpty(&stack)) {
        int digit;
        Pop(&stack, &digit);
        putchar(DigitToChar(digit));
    }
    putchar('\n');
}

int main(void)
{
    long long value;

    printf("Input a decimal integer: ");
    if (scanf("%lld", &value) != 1) {
        fprintf(stderr, "Invalid input: please enter a decimal integer.\n");
        return 1;
    }

    printf("\nResults:\n");
    PrintInBase(value, 2, "Binary");
    PrintInBase(value, 8, "Octal");
    PrintInBase(value, 16, "Hexadecimal");

    return 0;
}
