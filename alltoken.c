#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IDENTIFIERS 1000
#define MAX_OPERATORS 1000
#define MAX_PREPROCESSORS 1000
#define MAX_FUNCTIONS 1000
#define MAX_LINE_LENGTH 1000

char *identifiers[MAX_IDENTIFIERS];
int identifier_count = 0;

char *operators[MAX_OPERATORS];
int operator_count = 0;

char *preprocessors[MAX_PREPROCESSORS];
int preprocessor_count = 0;

char *functions[MAX_FUNCTIONS];
int function_count = 0;

void add_identifier(char *identifier) {
    for (int i = 0; i < identifier_count; i++) {
        if (strcmp(identifier, identifiers[i]) == 0) {
            return;
        }
    }
    identifiers[identifier_count++] = identifier;
}

void add_operator(char *operator) {
    for (int i = 0; i < operator_count; i++) {
        if (strcmp(operator, operators[i]) == 0) {
            return;
        }
    }
    operators[operator_count++] = operator;
}

void add_preprocessor(char *preprocessor) {
    for (int i = 0; i < preprocessor_count; i++) {
        if (strcmp(preprocessor, preprocessors[i]) == 0) {
            return;
        }
    }
    preprocessors[preprocessor_count++] = preprocessor;
}

void add_function(char *function) {
    for (int i = 0; i < function_count; i++) {
        if (strcmp(function, functions[i]) == 0) {
            return;
        }
    }
    functions[function_count++] = function;
}

void print_identifiers() {
    printf("Identifiers: ");
    for (int i = 0; i < identifier_count; i++) {
        printf("%s ", identifiers[i]);
    }
    printf("\n");
}

void print_operators() {
    printf("Operators: ");
    for (int i = 0; i < operator_count; i++) {
        printf("%s ", operators[i]);
    }
    printf("\n");
}

void print_preprocessors() {
    printf("Preprocessors: ");
    for (int i = 0; i < preprocessor_count; i++) {
        printf("%s ", preprocessors[i]);
    }
    printf("\n");
}

void print_functions() {
    printf("Functions: ");
    for (int i = 0; i < function_count; i++) {
        printf("%s ", functions[i]);
    }
    printf("\n");
}

int is_identifier(char *token) {
    if (!isalpha(token[0])) {
        return 0;
    }
    for (int i = 1; i < strlen(token); i++) {
        if (!isalnum(token[i])) {
            return 0;
        }
    }
    return 1;
}

int is_operator(char *token) {
    char operators[] = "+-*/=><!&|^%~";
    if (strlen(token) > 1) {
        return 0;
    }
    for (int i = 0; i < strlen(operators); i++) {
        if (operators[i] == token[0]) {
            return 1;
        }
    }
    return 0;
}

int is_preprocessor(char *token) {
    if (token[0] == '#') {
        add_preprocessor(token);
        return 1;
    }
    return 0;
}

   
int is_function(char *line) {
    char *open_bracket = strchr(line, '(');
    if (open_bracket == NULL) {
        return 0;
    }
    char function_name[MAX_LINE_LENGTH];
    int i = 0;
    while (isalnum(*(open_bracket - i - 1)) || *(open_bracket - i - 1) == '_') {
        function_name[i] = *(open_bracket - i - 1);
        i++;
    }
    function_name[i] = '\0';
    if (strlen(function_name) == 0) {
        return 0;
    }
    add_function(function_name);
    return 1;
}

int is_valid_syntax(char *line) {
    int i = 0;
    while (line[i] != '\0') {
        if (line[i] == '(') {
            if (!is_function(line + i)) {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

int is_comment(char *line) {
    if (strstr(line, "//") != NULL || strstr(line, "/*") != NULL) {
        return 1;
    }
    return 0;
}

int is_comment_english(char *line) {
    if (strstr(line, "//") != NULL) {
        char *comment = strchr(line, '/');
        comment++;
        comment++;
        while (*comment == ' ') {
            comment++;
        }
        if (isalpha(*comment)) {
            return 1;
        }
    }
    return 0;
}

int is_valid_math_expression(char *line) {
    int bracket_count = 0;
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == '(') {
            bracket_count++;
        } else if (line[i] == ')') {
            bracket_count--;
            if (bracket_count < 0) {
                return 0;
            }
        } else if (!isdigit(line[i]) && !is_operator(line + i)) {
            return 0;
        }
    }
    if (bracket_count != 0) {
        return 0;
    }
    return 1;
}

void parse_cpp_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            if (is_identifier(token)) {
                add_identifier(token);
            } else if (is_operator(token)) {
                add_operator(token);
            } else if (is_preprocessor(token)) {
                add_preprocessor(token);
            }
            token = strtok(NULL, " \t\n");
        }
        if (strstr(line, ";") != NULL && !is_valid_syntax(line)) {
            printf("Error: Invalid syntax: %s", line);
        }
        if (is_comment(line) && !is_comment_english(line)) {
            printf("Error: Invalid English grammar: %s", line);
        }
        if (is_valid_math_expression(line)) {
            printf("Valid math expression: %s", line);
        }
    }
    fclose(fp);
}

int main() {
    parse_cpp_file("test.cpp");
    print_identifiers();
    print_operators();
    print_preprocessors();
    print_functions();
    return 0;
}
