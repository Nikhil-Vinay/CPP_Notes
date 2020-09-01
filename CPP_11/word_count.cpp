
// word count
#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef map<string, size_t> WordCountMapType;
typedef map<string, size_t>::iterator WordCountMapTypeItr;

WordCountMapType wordsInFile(const char * const fileName)
{
   std::ifstream file(fileName);
   WordCountMapType wordCounts;
   for (std::string word; file >> word; ) {
      ++wordCounts[word];
   }
   return wordCounts;
}

int main()
{
   WordCountMapType word_map = wordsInFile("nik.txt");
   cout<<"total word count = "<<word_map.size()<<endl;
  
   for(WordCountMapTypeItr it = word_map.begin(); it != word_map.end(); it++) {
      cout<<"count of word "<<it->first<<" : "<<it->second<<endl;
   } 
   return 0;
}
