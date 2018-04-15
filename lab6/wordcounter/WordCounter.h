#ifndef JIMP2_WORDCOUNTER_H
#define JIMP2_WORDCOUNTER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

namespace datastructures {
    class Word {
    public:
        Word(std::string w);
        std::string GetWord() const;
        bool operator<(const Word &w) const;
        bool operator>(const Word &w) const;
        bool operator==(const Word &w) const;
        bool operator!=(const Word &w) const;
        bool operator<=(const Word &w) const;
        bool operator>=(const Word &w) const;
    private:
        std::string word;
    };

    class Counts {
    public:
        Counts(int i);
        int GetCounter();
        Counts & operator++();
        bool operator<(const Counts &c) const;
        bool operator>(const Counts &c) const;
        bool operator==(const Counts &c) const;
        bool operator!=(const Counts &c) const;
        bool operator<=(const Counts &c) const;
        bool operator>=(const Counts &c) const;
    private:
        int counter;
    };

    class WordCounter {
    public:
        WordCounter();
        WordCounter(std::initializer_list<Word> list);
        std::vector <std::pair<Word, Counts> > GetVector();
        int DistinctWords();
        int TotalWords();
        std::set<Word> Words();
        int operator[] (std::string str);
    private:
        std::vector <std::pair<Word, Counts> > dict;
    };
}

bool operator==(datastructures::Word w1, datastructures::Word w2);
bool operator<(const datastructures::Word w1, const datastructures::Word w2);
//bool operator>(datastructures::Word w1, datastructures::Word w2);

#endif //JIMP2_WORDCOUNTER_H
