// Alanté "Alan" D. Powell
// Spring 2021 - Programming Language Concepts
// Exam 2 - Question 6 - Q6.c

//Declaration of boolean values (C does not give these for free)
#declare FALSE = 0
#declare TRUE = 1

void EBNF_If(bool (*boolean_expression)(), void (*block)(), int while_statement) {
    if (boolean_expression()) {
        block();
        
        if (while_statement) {
            EBNF_If(boolean_expression, block, while_statement);
        }
    }
}
