#include "WordCounter.h"

bool operator==(datastructures::Word w1, datastructures::Word w2) {
    return w1.GetWord() == w2.GetWord();
}

bool operator<(const datastructures::Word w1, const datastructures::Word w2) {
    std::string s1 = w1.GetWord();
    std::string s2 = w2.GetWord();
    if ( s1 < s2 ) {
        return true;
    } else {
        return false;
    }
}

// Word methods
datastructures::Word::Word(std::string w) : word(w) {}

std::string datastructures::Word::GetWord() const {
    return word;
}

bool datastructures::Word::operator<(const Word &w) const {
    return word < w.word;
}

bool datastructures::Word::operator>(const Word &w) const {
    return word > w.word;
}

bool datastructures::Word::operator==(const Word &w) const {
    return word == w.word;
}

bool datastructures::Word::operator!=(const Word &w) const {
    return word != w.word;
}

bool datastructures::Word::operator<=(const Word &w) const {
    return word <= w.word;
}

bool datastructures::Word::operator>=(const Word &w) const {
    return word >= w.word;
}

// Counts
datastructures::Counts::Counts(int i) : counter(i) {}

datastructures::Counts & datastructures::Counts::operator++() {
    this->counter ++;
    return *this;
}

int datastructures::Counts::GetCounter() {
    return counter;
}

bool datastructures::Counts::operator<(const Counts &c) const {
    return counter < c.counter;
}

bool datastructures::Counts::operator>(const Counts &c) const {
    return counter > c.counter;
}

bool datastructures::Counts::operator==(const Counts &c) const {
    return counter == c.counter;
}

bool datastructures::Counts::operator!=(const Counts &c) const {
    return counter != c.counter;
}

bool datastructures::Counts::operator<=(const Counts &c) const {
    return counter <= c.counter;
}

bool datastructures::Counts::operator>=(const Counts &c) const {
    return counter >= c.counter;
}

// WordCounter methods

datastructures::WordCounter::WordCounter() {}

datastructures::WordCounter::WordCounter(std::initializer_list<Word> list) {
    for ( auto word : list ) {
        std::cout << word.GetWord() << std::endl;
        if ( dict.size() == 0 ) {
            dict.push_back(std::make_pair (word, Counts(1)));
        } else {
            bool incrCounter = false;
            for ( auto &it : dict ) {
                if ( it.first.GetWord() == word ) {
                    it.second.operator++();
                    incrCounter = true;
                    break;
                }
            }
            if ( !incrCounter ) {
                dict.push_back(std::make_pair (word, Counts(1)));
            }
        }
    }
}

int datastructures::WordCounter::DistinctWords() {
    if ( dict.size() == 0 ) {
        return 0;
    } else {
        int wordCounter = 0;
        for (auto it : dict)
            wordCounter++;
        return wordCounter;
    }
}

int datastructures::WordCounter::TotalWords() {
    if ( dict.size() == 0 ) {
        return 0;
    } else {
        int wordCounter = 0;
        for (auto it : dict)
            wordCounter += it.second.GetCounter();
        return wordCounter;
    }
}

std::set<datastructures::Word> datastructures::WordCounter::Words() {
    std::set<Word> words;
    for (auto it : dict) {
        words.insert(Word(it.first.GetWord()));
    }
    return words;
}

std::vector <std::pair<datastructures::Word, datastructures::Counts> > datastructures::WordCounter::GetVector() {
    return dict;
};

int datastructures::WordCounter::operator[](std::string str) {
    for ( auto it : dict ) {
        if ( it.first.GetWord() == str ) {
            return it.second.GetCounter();
        }
    }
    return 0;
}
