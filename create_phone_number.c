//it's just the function used on the solution...

char *create_phone_number(char phnum[15], const unsigned char nums[10])
{
// write to phnum and return it
// it must be nul-terminated
	*phnum = '\0';
  phnum[0] = '(';
  phnum[4] = ')';
  phnum[5] = ' ';
  phnum[9] = '-';
  for(int i = 0; i < 3; i++){
    phnum[i+1] = nums[i] + '0';
  }
  for(int i = 0; i < 3; i++){
    phnum[6+i] = nums[3+i] + '0';
  }
  for(int i = 0; i < 4; i++){
    phnum[10+i] = nums[6+i] + '0';
  }
  phnum[14] = '\0'; 
    return phnum;
}
