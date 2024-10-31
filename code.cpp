#include <iostream>
#include <cstring>

void vulnerableFunction(char *input) {
    char buffer[50];  // Small buffer on the stack
    // No bounds checking on input, leading to potential overflow
    strcpy(buffer, input);  // Vulnerable to buffer overflow
    std::cout << "You entered: " << buffer << std::endl;
}

int main() {
    char largeInput[100];
    std::cout << "Enter some text: ";
    std::cin >> largeInput;  // Input that could exceed buffer size in `vulnerableFunction`
    
    vulnerableFunction(largeInput);
    return 0;
}
