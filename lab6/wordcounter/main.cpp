#include "WordCounter.h"
using namespace datastructures;

int main() {
    //WordCounter counter;
    //WordCounter counter {Word("enigma"), Word("puzzle")};
    WordCounter counter {Word("a"), Word("p"), Word("a"), Word("a")};
    //WordCounter counter {Word("a"), Word("p"), Word("a"), Word("a"), Word("hi"), Word("voltage")};
    std::vector <std::pair<datastructures::Word, datastructures::Counts> > vec = counter.GetVector();
    for (auto it : vec) {
        std::cout << "WORD: " << it.first.GetWord() << ", COUNTER: " << it.second.GetCounter() << std::endl;
    }
    std::cout << counter["a"] << std::endl;
    std::cout << "DistinctWords: " << counter.DistinctWords() << std::endl;
    std::cout << "TotalWords: " << counter.TotalWords() << std::endl;

    return 0;
}