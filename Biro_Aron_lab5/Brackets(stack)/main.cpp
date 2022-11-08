#include <iostream>
#include "stack.h"

int main() {
    itemType *stack;
    init(stack);
    char c;
    std::cin.get(c);
    while (c != '\n')
    {
        if(c == '(')
            push(stack, c);
        else if((stack == nullptr && c==')'))
        {
            std::cout<<"A zarojelezes helytelen.";
            break;
        }
        else if(c==')' && stack -> data == '(')
            pop(stack);

        std::cin.get(c);
    }

    if(c == '\n' && stack == nullptr)
        std::cout<<"A zarojelezes helyes.";
    else if(c == '\n')
        std::cout<<"A zarojelezes helytelen.";
    return 0;
}
