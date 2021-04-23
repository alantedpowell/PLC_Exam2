// Alanté "Alan" D. Powell
// Spring 2021 - Programming Language Concepts
// Exam 2 - Question 1 - QUESTION_1.c
// References: GSU Programming Langauge Concepts Slides, YouTube

// Helpers
#include <stdio.h>
#include <ctype.h>

// Declaration of Variables
int character_class;
char lexeme[100];
char next_character;
int length_of_lexeme;
int current_token;
int next_token;
FILE *in_fp;

// Declaration of Functions
int identify(char ch);
void add_character(void);
void get_character(void);
void get_not_empty(void);
int lexeme(void);

// Declaration of Classes
// In numerical order
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

// Current Tokens (Copied and pasted from iCollege link)
// In numerical order
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define MOD_OP_OP 25
#define LEFT_PAREN 26
#define RIGHT_PAREN 27
#define FOR_CODE 30
#define IF_CODE 31
#define ELSE_CODE 32
#define WHILE_CODE 33
#define DO_CODE 34
#define INT_CODE 35
#define FLOAT_CODE 36
#define SWITCH_CODE 37
#define LESS_THAN_OP 36
#define LESS_EQUAL_OP 37
#define GREATER_THAN_OP 40
#define GREATER_EQUAL_OP 41
#define IS_EQUAL_OP 42
#define NOT_EQUAL_OP 43

#define OPEN_INDEX
#define CLOSE_INDEX

#define OPEN_BLOCK
#define CLOSE_BLOCK

#define STRING_LITERAL
#define STRING_CLOSE

#define DECLARE_INT
#define DECLARE_CHAR
#define DECLARE_VOID
#define DECLARE_FLOAT
#define DECLARE_STRING

// In order
#define DECLARE_PERL_SCALAR
#define DECLARE_PERL_ARRAY
#define DECLARE_PERL_HASH

// Main Function
// Opens file contents and parses the data contained
int main(void) {
     if ((in_fp = fopen("front.in", "r")) == NULL)
         printf("I'm sorry, I could not open front.in because it doesn't exist.\n");
     else {
         get_character();
     do {
         lexeme();
     } while (next_token != EOF);
     }
     return 0;
}

// The identify function will "identify" operators as well
// as parenthesis
// identify will then return the current token
int identify(char ch) {
     switch (ch) {
         case '(':
             add_character();
             next_token = LEFT_PAREN;
             break;
         case ')':
             add_character();
             next_token = RIGHT_PAREN;
             break;

         case '{':
             add_character();
             next_token = OPEN_BLOCK;
             break;
         case '}':
             add_character();
             next_token = CLOSE_BLOCK;
             break;

         case '[':
             add_character();
             next_token = OPEN_INDEX;
             break;
         case ']':
             add_character();
             next_token = CLOSE_INDEX;
             break;

//        Perl Style Identifiers
         case '$':
             add_character();
             next_token = DECLARE_PERL_SCALAR;
             break;

         case '@':
             add_character();
             next_token = DECLARE_PERL_ARRAY;
             break;

         case '%':
             add_character();
             next_token = DECLARE_PERL_HASH;
             break;



         case '+':
             add_character();
             next_token = ADD_OP;
             break;

         case '-':
             add_character();
             next_token = SUB_OP;
             break;
         case '*':
             add_character();
             next_token = MULT_OP;
             break;
         case '/':
             add_character();
             next_token = DIV_OP;
             break;

         case '%':
             add_character();
             next_token = MOD_OP;
             break;

        case '|':
             add_character();

             if (character_class == UNKNOWN) {
                 if (next_character == '|'){
                    add_character();
                    next_token = OR_OP;
                 }
             }

             break;

        case '&':
             add_character();

             if (character_class == UNKNOWN) {
                 if (next_character == '&'){
                    add_character();
                    next_token = AND_OP;
                 }
             }

             break;


         case '>':
             add_character();
             next_token = LESS_THAN_OP;

             if (character_class == UNKNOWN) {
                 if (next_character == '='){
                    add_character();
                    next_token = LESS_EQUAL_OP;
                 }
             }

             break;

         case '<':
             add_character();
             next_token = GREATER_THAN_OP;

             if (character_class == UNKNOWN) {
                 if (next_character == '='){
                    add_character();
                    next_token = GREATER_EQUAL_OP;
                 }
             }

             break;

         case '=':
             add_character();
             next_token = ASSIGN_OP;

             if (character_class == UNKNOWN) {
                 if (next_character == '='){
                    add_character();
                    next_token = IS_EQUAL_OP;
                 }
             }

             break;

         case '!':
             add_character();
             next_token = NOT_OP;

             if (character_class == UNKNOWN) {
                 if (next_character == '='){
                    add_character();
                    next_token = NOT_EQUAL_OP;
                 }
             }

             break;

         case "\"":
            add_character();

            if (next_token!= STRING_LITERAL)
                next_token = STRING_LITERAL;
            else
                next_token = STRING_CLOSE;

         break;

         default:
             add_character();
             next_token = EOF;
             break;
     }
     return next_token;
}

// add_character will add a character to the lexeme
void add_character(void) {
    if (length_of_lexeme <= 98) {
        lexeme[length_of_lexeme++] = next_character;
        lexeme[length_of_lexeme] = '\0';
    } else
    printf("I cannot process this lexeme because it's length is too long.\n");
}


// get_character will get the next character from
// of the input
// get_character will also identify the character
// class the input belongs to
void get_character(void) {
     if ((next_character = getc(in_fp)) != EOF) {
         if (isalpha(next_character))
             character_class = LETTER;
         else if (isdigit(next_character))
             character_class = DIGIT;
         else
             character_class = UNKNOWN;
     } else
         character_class = EOF;
}


// get_not_empty will simply call get_character
// until a non-whitespace is identified and returned
void get_not_empty(void) {
    while (isspace(next_character))
    get_character();
}


// Arithmetic Lexical Analyzer
int lexeme(void) {
     length_of_lexeme = 0;
     get_not_empty();
     switch (character_class) {
        /* Identifiers */
         case LETTER:
             add_character();
             get_character();

             while (character_class == LETTER || character_class == DIGIT) {
                 add_character();
                 get_character();


                 if (next_character == 'i'){
                    add_character();
                    get_character();

                    if (next_character == 'n'){
                        add_character();
                        get_character();

                        if (next_character == 't'){
                            add_character();
                            get_character();

                            next_token = DECLARE_INT;
                            break;
                        }
                    }
                 }

                 if (next_character == 's'){
                    add_character();
                    get_character();

                    if (next_character == 't'){
                        add_character();
                        get_character();

                        if (next_character == 'r'){
                            add_character();
                            get_character();

                            if (next_character == 'i'){
                                add_character();
                                get_character();

                                if (next_character == 'n'){
                                    add_character();
                                    get_character();

                                    if (next_character == 'g'){
                                        add_character();
                                        get_character();

                                        next_token = DECLARE_STRING;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                 }

                 if (next_character == 'c'){
                    add_character();
                    get_character();

                    if (next_character == 'h'){
                        add_character();
                        get_character();

                        if (next_character == 'a'){
                            add_character();
                            get_character();

                            if (next_character == 'r'){
                                add_character();
                                get_character();

                                next_token = DECLARE_CHAR;
                                break;
                            }
                        }
                    }
                 }

                 if (next_character == 'f'){
                    add_character();
                    get_character();

                    if (next_character == 'l'){
                        add_character();
                        get_character();

                        if (next_character == 'o'){
                            add_character();
                            get_character();

                            if (next_character == 'a'){
                                add_character();
                                get_character();

                                if (next_character == 't'){
                                    add_character();
                                    get_character();

                                    next_token = DECLARE_FLOAT;
                                    break;
                                }
                            }
                        }
                    }
                 }

                 if (next_character == 'v'){
                    add_character();
                    get_character();

                    if (next_character == 'o'){
                        add_character();
                        get_character();

                        if (next_character == 'i'){
                            add_character();
                            get_character();

                            if (next_character == 'd'){
                                add_character();
                                get_character();

                                next_token = DECLARE_VOID;
                                break;
                            }
                        }
                    }
                 }
             }

             if (next_token != STRING_LITERAL)
                    next_token = IDENT;

             break;
        
             
//        Integer Literals
         case DIGIT:
             add_character();
             get_character();
             while (character_class == DIGIT) {
                 add_character();
                 get_character();
             }

             /* floats */
             if (character_class == UNKNOWN){
                if (next_character == '.'){
                    add_character();
                    get_character();

                    while (character_class == DIGIT) {
                        add_character();
                        get_character();
                    }

                    if (next_character == 'f'){
                        add_character();
                        get_character();
                        next_token = FLOAT_CODE;
                    }
                }
             }

             if (next_token != STRING_LITERAL && next_token != FLOAT_CODE)
                next_token = INT_LIT;

             break;
             
//        To handle parenthesis and operators
         case UNKNOWN:
             identify(next_character);
             get_character();
             break;
           
             
        case EOF:
             next_token = EOF;
             lexeme[0] = 'E';
             lexeme[1] = 'O';
             lexeme[2] = 'F';
             lexeme[3] = '\0';
             break;
     }
    
    printf("The next current_token is: %d. \n", next_token);
    printf("The next lexeme is: %s.\n", lexeme);
     return next_token;

