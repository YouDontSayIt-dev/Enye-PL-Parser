#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char word[100];
char **words = NULL;
int num_words = 0;

//DECLARATIVE STATEMENTS
int pos;
int expected;

void parse_declaration();
void parse_declarator();
void parse_initializer();
void assignment();
void expression();
void term();
void factor();

void parse_declaration() {
    if (strncmp(words[pos], "INT_KW", 6) == 0) {
        // pos += 6;
        pos++;
        parse_declarator();
        printf("Found int declaration\n");
    } 
    else if (strncmp(words[pos], "CHAR_KW", 7) == 0) {
        // pos += 7;
        pos++;
        parse_declarator();
        printf("Found char declaration\n");
    } 
    else if (strncmp(words[pos], "FLOAT_KW", 8) == 0) {
        // pos += 8;
        pos++;
        parse_declarator();
        printf("Found float declaration\n");
    }
    else if (strncmp(words[pos], "STRING_KW", 9) == 0) {
        // pos += 9;
        pos++;
        parse_declarator();
        printf("Found string declaration\n");
    }
    else {
        printf("Invalid declaration\n");
    }
}

void parse_declarator() {
    while (strcmp(words[pos], "SEMI_COLON") == 1) {
        if (strcmp(words[pos], "ASS_OPR") == 0) {
            // pos+=7;
            pos++;
            parse_initializer();
        }
        // pos+= 10;
        pos++;
    }
}

void parse_initializer() {
    while (strcmp(words[pos], "SEMI_COLON") == 1) {
        // pos+= 10;
        pos++;
    }
}


//ASSIGNMENT STATEMENTS
// void match(int expected) {
//     if (strcmp(words[pos], expected) == 0) {
//         pos++;
//     } else {
//         printf("Error: unexpected token %s\n", words[pos]);
//         exit(1);
//     }
// }

// void match2(char* expected, int i) {
//     if (strcmp(words[pos], expected[i]) == 0) {
//         pos++;
//     } else {
//         printf("Error: unexpected token %s\n", words[pos]);
//         exit(1);
//     }
// }

// void assignment() {
//     char* variable = lookahead;
//     match2(words, pos);
//     match('=');
//     expression();
//     match(';');
//     printf("Assigning value to variable %s\n", *variable);
// }

// void expression() {
//     term();
//     while (strcmp(words[pos], '+') == 0 || strcmp(words[pos], '-') == 0) {
//         match2(words, pos);
//         term();
//     }
// }

// void term() {
//     factor();
//     while (strcmp(words[pos], '*') == 0 || strcmp(words[pos], '/') == 0) {
//         match(words, pos);
//         factor();
//     }
// }

// void factor() {
//     match2(words, pos);
//     else if (strcmp(words[pos], '(') == 0) {
//         match('(');
//         expression();
//         match(')');
//     } else {
//         printf("Error: unexpected token %s\n", words[pos]);
//         exit(1);
//     }
// }


int main() {
    FILE *file;
    char *filename = "file.txt";

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fscanf(file, "%s", word) != EOF) {
        words = (char **) realloc(words, (num_words + 1) * sizeof(char *));
        words[num_words] = (char *) malloc((strlen(word) + 1) * sizeof(char));
        strcpy(words[num_words], word);
        num_words++;
    }

    fclose(file);

    parse_declaration();
    // expression();
    // if(words[pos] == "int"){
    //     printf("int");
    // }else
    //     printf("not int");
    // printf("%s", words[pos]);
    // printf("%c", word[pos]);

    // Print the words in the array
    // for (int i = 0; i < num_words; i++) {
    //     printf("%s\n", words[i]);
    // }

    // Deallocate memory
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}
