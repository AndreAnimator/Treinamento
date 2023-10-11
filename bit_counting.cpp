//novamente só a função
//minha função:
#include <bitset>
using namespace std;

unsigned int countBits(unsigned long long n){
  bitset<64> b(n);
  int count = 0;
  string mystring = b.to_string<char,char_traits<char>,allocator<char> >();
  for(size_t i = 1; i <= mystring.size(); i++){
    if(mystring[i-1] == '1')
      count++;
  }
  return count;
}

//a com melhores práticas:
#include <limits>
#include <bitset>
inline constexpr unsigned int countBits(const unsigned long long n) noexcept {
  std::bitset<std::numeric_limits<unsigned long long>::digits> b(n);
  return b.count();
}
