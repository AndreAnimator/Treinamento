#include <stdio.h>
#include <string.h>

void to_camel_case(const char *text, char *camel);
void tester(const char *text, const char *expected);
  
int main()
{
    tester("", "");
    tester("the_stealth_warrior", "theStealthWarrior");
    tester("The-Stealth-Warrior", "TheStealthWarrior");
    tester("A-B-C", "ABC");
}

void tester(const char *text, const char *expected) {
    //não compara as strings
    char submitted[strlen(text) + 1];
    to_camel_case(text, submitted);
}

void to_camel_case(const char *text, char *camel) {
    char string[strlen(text)];
    for(int i=0; i < strlen(text); i++){
        string[i] = text[i];
    }
    for(int i=0; i < strlen(text); i++){
        camel[i] = text[i];
    }
    for(int i=0; i < strlen(string); i++){
        if(i < strlen(string) - 1){
            if(string[i] == 45 || string[i] == 95){
                printf("\n uai");
                if(string[i+1] > 96 && string[i+1] < 123){
                    string[i+1] -= 32;
                    camel[i+1] -= 32;
                    for(int j = i; j < strlen(string); j++){
                        camel[j] = string[j+1];
                    }
                    for(int u = 0; u < strlen(string); u++){
                        string[u] = camel[u];
                        if(u == strlen(string)-1){
                            string[u] = 0;
                        }
                    }
                }
                else{
                    for(int j = i; j < strlen(string); j++){
                        camel[j] = string[j+1];
                    }
                    for(int u = 0; u < strlen(string); u++){
                        string[u] = camel[u];
                        if(u == strlen(string)-1){
                            string[u] = 0;
                        }
                    }
                }
            }
        }
    }
}
