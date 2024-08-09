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

string to_camel_case(const char *text, char *camel) {
  string solution = "";
  int end_of_word = 0;
  for(int i = 0; i < static_cast<int>(text.size()); i++){
    if(text[i] == 45 || text[i] == 95)
      end_of_word = 1;
    else if(end_of_word == 1){
      end_of_word = 0;
      if(text[i] >= 97 && text[i] <= 122)
        solution += text[i] - 32;
      else
        solution += text[i]; 
    }
    else
      solution += text[i];
  }
  return solution;
}

/*Solução famosa por ser ideal:
  std::string to_camel_case(std::string text)
  {
    for(int i = 0; i < text.size(); ++i)
    {
      if(text[i] == '-' || text[i] == '_')
      {
        text.erase(i,1);
        text[i] = toupper(text[i]);
      }
    }
    return text;
  }
*/
