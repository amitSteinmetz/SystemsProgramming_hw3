#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getLine(char s[]);
int getWord(char w[]);
int substring(char* str1, char* str2);
int similar(char *s, char *t, int n);
void print_lines(char* str);
void print_similar_words(char * str);


#define WORD 30
#define LINE 256

int main() {

    char new_line_symbol;

    char word1[WORD];   // The search string 
    getWord(word1);
   
    char word2[WORD];   // Choice 
    getWord(word2);

    scanf("%c\n", &new_line_symbol);

    if (word2[0] == 'a')
    {
        print_lines(word1);
    }

    else  // word2[0] == 'b'
    {
        print_similar_words(word1);
    }

    return 0;
}

int getLine(char s[])
{
    int counter = 0; // count amount of letters in the line

    for (int i = 0; i < LINE; i++)
    {
        if (scanf("%c", &s[i]) == EOF)  // In case that file has ended
        {
            counter = -1;
            break;
        }

        if (s[i] == '\n') // In case that line has ended
        {
            s[i+1] = '\0';

            break;
        } 
        
        counter++;
    }

    return counter;
}

int getWord(char w[])
{
    int counter = 0; // Count amount of letters in the word

    if (scanf("%s", w) == EOF) // In case that file has ended
    {
        counter = -1;
    }

    for (int i = 0; i < WORD; i++) 
    {
        if (w[i] == '\0') break; // In case that word has ended
        
        if (counter != -1)
        {
            counter++;
        }
    }

    return counter;
}

int substring(char* str1, char* str2) 
{
    int str1_length = strlen(str1); 
    int str2_length = strlen(str2);

    int i = 0, j = 0;

    while (i < str1_length && j < str2_length)
    {
        // First case: the letters are same, lets promote both i, j!

        if (str2[j] == str1[i])
        {
            i++;
            j++;
        }

        // Second case: the next letters not same, but again first letter of str2 are same to str1[i]

        else if (str1[i] == str2[0])
        {
            i++;
            j = 1; // Because str2[0] is good, but str2 in current j not good, so lets continue from str2[0]
        }

        // Third case: nothing the same, promote only i, and reset j

        else 
        {
            i++;
            j = 0;
        }
    }
    
    if (j == str2_length)  // meaning that promote j str2_length times, and we promoted it only when it was same to str1[i]
    {
        return 1;
    }
    
    return 0;
}

int similar(char *s, char *t, int n)
{
    int s_length = strlen(s); 
    int t_length = strlen(t);

    int n_counter = 0;

    int i = 0, j = 0;

    while (i < s_length && j < t_length)
    {
        // First case: the letters are same, lets promote both i, j!

        if (t[j] == s[i])
        {
            i++;
            j++;
        }

        // Second case: letters not same, promote only i

        else
        {
            i++;
            n_counter++; // we will need to delete the unsame letter in 's', so count it.
        }
    }

    while (i < s_length)  // maybe we found all of 't' in 's', but maybe there is more letters in 's' that we'll need to delete!
    {
        n_counter++;
        i++;
    }

    if (j == t_length && n_counter <= n)  // meaning that promote j t_length times, and we promoted it only when it was same to s[i]
    {
        return 1;
    }

    return 0;
}

void print_lines(char* str)
{
    char line[LINE];
    int strLine = 0;
    
    while (1)
    {
        strLine = getLine(line);

        if (strLine == -1) // Meaning that we arrived to end of file
        {
            break;
        }
        
        // Check if 'str' is in this line as a substring:

        int check_str_line = substring(line, str);

        // If 'str' exist in the line, print the line:

        if (check_str_line == 1)
        {
            printf("%s", line);
            bzero(line, LINE); // to avoid errors
        }

    }
}

void print_similar_words(char * str)
{
    char word[WORD];
    int strWord = 0;
    
    while (1)
    {
        strWord = getWord(word);

        if (strWord == -1) // Meaning that we arrived to end of file
        {
            break;
        }
        
        // check if 'str' is similar to word:

        int check_str_word = similar(word, str, 1);

        // if str indid similar to the word, print the word:

        if (check_str_word == 1)
        {
            printf("%s\n", word);
            bzero(word, WORD); // to avoid errors
        }
    } 
}

















/* 
    Example how to use the input file - especially how to copy it to a variant in order to analyze it:

    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE , stdin);
    printf("Read: %s", buffer);
*/