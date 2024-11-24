#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h> //contains functions like isspace for space normalization

void randomBlockChallenge();
void randomLineChallenge();
void normalizeString(char *str);
void removeNewline(char *str);

int main() 
{
    srand(time(NULL)); //generate diff random number each time

    int choice;

    // starting screen
    printf("\n***************************************\n");
    printf("**    Welcome to the C Syntax        **\n");
    printf("**    Typing Challenge!              **\n");
    printf("***************************************\n");
    printf("\nChallenge Description:\n");
    printf("1. In the 'Block of Code' challenge, you will be given a block of code.\n");
    printf("   You need to type it exactly (ignoring spaces) and type 'END' to finish.\n");
    printf("2. In the 'Single Line' challenge, you will be given a single line of code.\n");
    printf("   You need to type it exactly to pass.\n");
    printf("\n***************************************\n");

    printf("Choose your challenge type:\n");
    printf("1. Type a block of code (multiple lines)\n");
    printf("2. Type random single lines of code\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar();  // to avoid buffer because of scanf

    if (choice == 1) 
    {
        randomBlockChallenge();  // Block of code challenge
    } 
    else if (choice == 2) 
    {
        randomLineChallenge();  // Random single line challenge
    } else 
    {
        printf("Invalid choice. Exiting...\n");
    }

    return 0;
}

void randomBlockChallenge() 
{
    // Multiple blocks of code (multi-line)
    const char *blocks[] = {
        "int main() {\n"
        "    int number = 5;\n"
        "    printf(\"Hello World!\\n\");\n"
        "    if (number > 0) {\n"
        "        printf(\"Number is positive\\n\");\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "int sum(int a, int b) {\n"
        "    return a + b;\n"
        "}\n"
        "int main() {\n"
        "    int result = sum(5, 10);\n"
        "    printf(\"Sum: %d\\n\", result);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    char grade = 'A';\n"
        "    if (grade == 'A') {\n"
        "        printf(\"Excellent!\\n\");\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    float pi = 3.14;\n"
        "    int radius = 5;\n"
        "    float area = pi * radius * radius;\n"
        "    printf(\"Area: %.2f\\n\", area);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    for (int i = 0; i < 5; i++) {\n"
        "        printf(\"Loop iteration: %d\\n\", i);\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    int a = 10, b = 20;\n"
        "    if (a > b) {\n"
        "        printf(\"a is greater\\n\");\n"
        "    } else {\n"
        "        printf(\"b is greater\\n\");\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    char str[100];\n"
        "    printf(\"Enter a string: \");\n"
        "    fgets(str, sizeof(str), stdin);\n"
        "    printf(\"You entered: %s\\n\", str);\n"
        "    return 0;\n"
        "}",

        "int factorial(int n) {\n"
        "    if (n == 0 || n == 1)\n"
        "        return 1;\n"
        "    else\n"
        "        return n * factorial(n - 1);\n"
        "}\n"
        "int main() {\n"
        "    int result = factorial(5);\n"
        "    printf(\"Factorial: %d\\n\", result);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    int i;\n"
        "    for (i = 0; i < 10; i++) {\n"
        "        if (i % 2 == 0) {\n"
        "            printf(\"Even number: %d\\n\", i);\n"
        "        }\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    int x = 10, y = 20, z;\n"
        "    z = x + y;\n"
        "    printf(\"Sum: %d\\n\", z);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    int i = 1;\n"
        "    while (i <= 5) {\n"
        "        printf(\"Count: %d\\n\", i);\n"
        "        i++;\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    char name[] = \"Alice\";\n"
        "    printf(\"Name: %s\\n\", name);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    int num1 = 10, num2 = 20, result;\n"
        "    result = num1 * num2;\n"
        "    printf(\"Product: %d\\n\", result);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    char c = 'A';\n"
        "    if (c == 'A') {\n"
        "        printf(\"Character is A\\n\");\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    float price = 45.99;\n"
        "    printf(\"Price: %.2f\\n\", price);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    int x = 5, y = 10, z;\n"
        "    z = (x + y) * 2;\n"
        "    printf(\"Result: %d\\n\", z);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    int a = 10;\n"
        "    if (a == 10) {\n"
        "        printf(\"a is 10\\n\");\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    float x = 3.14, y = 2.71;\n"
        "    printf(\"Sum: %.2f\\n\", x + y);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    int i, sum = 0;\n"
        "    for (i = 1; i <= 10; i++) {\n"
        "        sum += i;\n"
        "    }\n"
        "    printf(\"Sum of numbers: %d\\n\", sum);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    int number = 5;\n"
        "    printf(\"Hello World!\\n\");\n"
        "    if (number > 0) {\n"
        "        printf(\"Number is positive\\n\");\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "int sum(int a, int b) {\n"
        "    return a + b;\n"
        "}\n"
        "int main() {\n"
        "    int result = sum(5, 10);\n"
        "    printf(\"Sum: %d\\n\", result);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    char grade = 'A';\n"
        "    if (grade == 'A') {\n"
        "        printf(\"Excellent!\\n\");\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    float pi = 3.14;\n"
        "    int radius = 5;\n"
        "    float area = pi * radius * radius;\n"
        "    printf(\"Area: %.2f\\n\", area);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    for (int i = 0; i < 5; i++) {\n"
        "        printf(\"Loop iteration: %d\\n\", i);\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    int a = 10, b = 20;\n"
        "    if (a > b) {\n"
        "        printf(\"a is greater\\n\");\n"
        "    } else {\n"
        "        printf(\"b is greater\\n\");\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "int factorial(int n) {\n"
        "    if (n == 0 || n == 1)\n"
        "        return 1;\n"
        "    else\n"
        "        return n * factorial(n - 1);\n"
        "}\n"
        "int main() {\n"
        "    int result = factorial(5);\n"
        "    printf(\"Factorial: %d\\n\", result);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    int x, y, temp;\n"
        "    printf(\"Enter two numbers: \");\n"
        "    scanf(\"%d %d\", &x, &y);\n"
        "    temp = x; x = y; y = temp;\n"
        "    printf(\"After swapping: %d, %d\\n\", x, y);\n"
        "    return 0;\n"
        "}",

        "int fibonacci(int n) {\n"
        "    if (n <= 1)\n"
        "        return n;\n"
        "    return fibonacci(n - 1) + fibonacci(n - 2);\n"
        "}\n"
        "int main() {\n"
        "    for (int i = 0; i < 10; i++) {\n"
        "        printf(\"%d \", fibonacci(i));\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "void printArray(int arr[], int size) {\n"
        "    for (int i = 0; i < size; i++) {\n"
        "        printf(\"%d \", arr[i]);\n"
        "    }\n"
        "    printf(\"\\n\");\n"
        "}\n"
        "int main() {\n"
        "    int nums[] = {1, 2, 3, 4, 5};\n"
        "    printArray(nums, 5);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    char str1[] = \"Hello \";\n"
        "    char str2[] = \"World!\";\n"
        "    strcat(str1, str2);\n"
        "    printf(\"%s\\n\", str1);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    char c;\n"
        "    printf(\"Enter a character: \");\n"
        "    scanf(\" %c\", &c);\n"
        "    if (isalpha(c)) {\n"
        "        printf(\"%c is a letter.\\n\", c);\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    char s[100];\n"
        "    printf(\"Enter a string: \");\n"
        "    scanf(\"%s\", s);\n"
        "    printf(\"Length of string: %ld\\n\", strlen(s));\n"
        "    return 0;\n"
        "}",

        "void swap(int *x, int *y) {\n"
        "    int temp = *x;\n"
        "    *x = *y;\n"
        "    *y = temp;\n"
        "}\n"
        "int main() {\n"
        "    int a = 10, b = 20;\n"
        "    swap(&a, &b);\n"
        "    printf(\"Swapped: %d %d\\n\", a, b);\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    int nums[3][3] = {\n"
        "        {1, 2, 3},\n"
        "        {4, 5, 6},\n"
        "        {7, 8, 9}\n"
        "    };\n"
        "    for (int i = 0; i < 3; i++) {\n"
        "        for (int j = 0; j < 3; j++) {\n"
        "            printf(\"%d \", nums[i][j]);\n"
        "        }\n"
        "        printf(\"\\n\");\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    int a = 10, b = 5;\n"
        "    int result = (a > b) ? a : b;\n"
        "    printf(\"Greater value: %d\\n\", result);\n"
        "    return 0;\n"
        "}",

        "void printArray(int arr[], int size) {\n"
        "    for (int i = 0; i < size; i++) {\n"
        "        printf(\"%d \", arr[i]);\n"
        "    }\n"
        "    printf(\"\\n\");\n"
        "}\n"
        "int main() {\n"
        "    int numbers[] = {1, 2, 3, 4, 5};\n"
        "    printArray(numbers, 5);\n"
        "    return 0;\n"
        "}",

        "int fibonacci(int n) {\n"
        "    if (n <= 1) return n;\n"
        "    return fibonacci(n - 1) + fibonacci(n - 2);\n"
        "}\n"
        "int main() {\n"
        "    int num = 7;\n"
        "    printf(\"Fibonacci of %d: %d\\n\", num, fibonacci(num));\n"
        "    return 0;\n"
        "}",

        "int main() {\n"
        "    int matrix[2][2] = {{1, 2}, {3, 4}};\n"
        "    for (int i = 0; i < 2; i++) {\n"
        "        for (int j = 0; j < 2; j++) {\n"
        "            printf(\"%d \", matrix[i][j]);\n"
        "        }\n"
        "        printf(\"\\n\");\n"
        "    }\n"
        "    return 0;\n"
        "}",

        "void reverseString(char str[]) {\n"
        "    int len = strlen(str);\n"
        "    for (int i = 0; i < len / 2; i++) {\n"
        "        char temp = str[i];\n"
        "        str[i] = str[len - i - 1];\n"
        "        str[len - i - 1] = temp;\n"
        "    }\n"
        "}\n"
        "int main() {\n"
        "    char text[] = \"C Programming\";\n"
        "    reverseString(text);\n"
        "    printf(\"Reversed string: %s\\n\", text);\n"
        "    return 0;\n"
        "}"
    };

    int numBlocks = sizeof(blocks) / sizeof(blocks[0]); //number of blocks
    char userInput[2048];  
    int correctCount = 0;

    printf("\nTyping Challenge: Block of Code\n");

    // Randomly choose a block of code
    int randomIndex = rand() % numBlocks;
    const char *block = blocks[randomIndex];
    printf("Type the following block of code. Type 'END' on a new line when you're finished.\n%s\n", block);

    clock_t start, end; //to record the typing time
    start = clock();

    // Collect all user input into userInput variable
    userInput[0] = '\0';  // Initialize the user input string

    // Read multi-line input
    printf("Your input: ");
    while (1) 
    {
        char temp[256];
        fgets(temp, sizeof(temp), stdin);
        if (strcmp(temp, "END\n") == 0) break;  
        // Stop if user types "END"
        strcat(userInput, temp);
    }


    end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // ignores no spaces and extra spaces
    char normalizedUserInput[2048];
    char normalizedBlock[2048];
    strcpy(normalizedUserInput, userInput);
    strcpy(normalizedBlock, block);

    normalizeString(normalizedUserInput);
    normalizeString(normalizedBlock);

    // Check if normalized strings match
    if (strcmp(normalizedBlock, normalizedUserInput) == 0) 
    {
        printf("Correct! Time taken: %.2f seconds\n", timeTaken);
        correctCount++;
    } 
    else 
    {
        printf("Incorrect! Expected: %s\n", block);
    }

    printf("\nTyping Challenge Completed!\n");
    printf("Correct Blocks: %d / 1\n", correctCount);
}

void randomLineChallenge() 
{
    const char *lines[] = 
    {
        "printf(\"Hello, World!\\n\");",
        "int number = 5;",
        "return 0;",
        "float result = 3.14 * 2;",
        "if (number > 0) { printf(\"Positive\\n\"); }",
        "for (int i = 0; i < 10; i++) { printf(\"%d\\n\", i); }",
        "char grade = 'A';",
        "double x = 5.5 + 3.2;",
        "long long int bigNumber = 1234567890;",
        "const float pi = 3.14159;",
        "int sum(int a, int b) { return a + b; }",
        "int number = 10;",
        "char name[] = \"John\";",
        "float area = pi * radius * radius;",
        "int main() { printf(\"Hello World!\\n\"); return 0; }",
        "double a = 5.0, b = 10.0;",
        "if (a == b) { printf(\"Equal\\n\"); }",
        "int max(int x, int y) { return (x > y) ? x : y; }",
        "char letter = 'B';",
        "int array[5] = {1, 2, 3, 4, 5};",
        "printf(\"%s\\n\", \"Hello!\");",
        "float price = 10.5;",
        "int result = (10 + 20) * 2;",
        "if (num > 10) { printf(\"Greater\\n\"); }",
        "long x = 1000000000;",
        "while (x < 5) { x++; }",
        "int temp = 25;",
        "float sum = 1.23 + 4.56;",
        "char str[] = \"C Programming\";",
        "int a = 7, b = 8;",
        "void func() { printf(\"Inside function\\n\"); }",
        "short int number = 25;",
        "printf(\"Current value: %d\\n\", number);",
        "for (int i = 0; i < 10; i++) { printf(\"%d\\n\", i); }",
        "if (x > 0) { printf(\"Positive\\n\"); }",
        "float area = 3.14 * radius * radius;",
        "int sum = a + b;",
        "char c = 'A';",
        "scanf(\"%d\", &number);",
        "printf(\"Sum: %d\\n\", sum);",
        "int factorial = 1;",
        "while (n > 0) { factorial *= n--; }",
        "void swap(int *x, int *y);",
        "char name[50];",
        "int arr[5] = {1, 2, 3, 4, 5};",
        "printf(\"Array element: %d\\n\", arr[0]);",
        "int max = (a > b) ? a : b;",
        "for (int i = 0; i < n; i++) { arr[i] = i * 2; }",
        "printf(\"Character: %c\\n\", c);",
        "if (isalpha(ch)) { printf(\"Alphabet\\n\"); }",
        "return 0;",
        "const float PI = 3.14159;",
        "int len = strlen(str);",
        "strcpy(destination, source);",
        "fgets(buffer, sizeof(buffer), stdin);",
        "int diff = abs(a - b);",
        "double pow(double base, double exp);",
        "FILE *file = fopen(\"data.txt\", \"r\");",
        "fclose(file);",
        "int x = rand() % 100;",
        "srand(time(NULL));",
        "float avg = (a + b + c) / 3.0;",
        "int *ptr = &num;",
        "*ptr = 20;",
        "printf(\"Pointer value: %d\\n\", *ptr);",
        "if (p == NULL) { printf(\"Null pointer!\\n\"); }",
        "fwrite(data, sizeof(char), strlen(data), file);",
        "if (feof(file)) { printf(\"End of file reached\\n\"); }",
        "int result = strcmp(str1, str2);",
        "if (result == 0) { printf(\"Strings are equal\\n\"); }",
        "void reverseArray(int arr[], int size);",
        "for (int i = size - 1; i >= 0; i--) { printf(\"%d \", arr[i]); }",
        "printf(\"Enter a number: \");",
        "scanf(\"%lf\", &value);",
        "struct Point { int x, y; };",
        "struct Point p1 = {0, 0};",
        "enum Days { SUN, MON, TUE, WED, THU, FRI, SAT };",
        "Days today = FRI;",
        "printf(\"Today is %d\\n\", today);",
        "int gcd = findGCD(a, b);",
        "int lcm = (a * b) / gcd;",
        "printf(\"Greatest common divisor: %d\\n\", gcd);",
        "printf(\"Sum of first 10 natural numbers: %d\\n\", (10 * (10 + 1)) / 2);"
    };

    int numLines = sizeof(lines) / sizeof(lines[0]); //number of lines
    char userInput[256];
    int correctCount = 0;

    printf("\nTyping Challenge: Single Lines of Code\n");

    for (int i = 0; i < 5; i++) 
    { // Loop for 5 random line challenges
        int randomIndex = rand() % numLines; //chooses random Index
        const char *randomLine = lines[randomIndex];

        printf("\nTyping Challenge #%d:\n", i + 1);
        printf("Type the following line of code:\n%s\n", randomLine);

        clock_t start, end;
        start = clock();

        // Get user input
        printf("Your input: ");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = '\0'; 
        // Remove extra new and replaces with '\0'

        end = clock();
        double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Normalize both the expected and user input strings
        char normalizedUserInput[256];
        char normalizedLine[256];
        strcpy(normalizedUserInput, userInput);
        strcpy(normalizedLine, randomLine);

        normalizeString(normalizedUserInput);
        normalizeString(normalizedLine);

        // Check if normalized strings match
        if (strcmp(normalizedLine, normalizedUserInput) == 0) 
        {
            printf("Correct! Time taken: %.2f seconds\n", timeTaken);
            correctCount++;
        } else {
            printf("Incorrect! Expected: %s\n", randomLine);
        }
    }

    printf("\nTyping Challenge Completed!\n");
    printf("Correct Lines: %d / 5\n", correctCount);
}

void normalizeString(char *str) 
{
    char temp[256];
    int j = 0;

    for (int i = 0; str[i]; i++) 
    {
        if (!isspace((unsigned char)str[i])) 
        {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

void removeNewline(char *str) 
{
    str[strcspn(str, "\n")] = '\0';
}
