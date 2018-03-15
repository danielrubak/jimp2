#include "CCounter.h"

std::unique_ptr<ccounter::Counter> ccounter::Init() {
    std::unique_ptr<ccounter::Counter> newStructPointer = std::make_unique<ccounter::Counter>();
    return newStructPointer;
}

void ccounter::Inc(std::string key, std::unique_ptr<ccounter::Counter>* counter) {
    auto iter = counter->get()->countersMap.find(key);
    if ( iter != counter->get()->countersMap.end() ) {
        // second because i want to increment int value for key
        (*iter).second++;
    } else {
        counter->get()->countersMap.insert( std::pair<std::string, int>(key, 1) );
    }
}

int ccounter::Counts(const std::unique_ptr<ccounter::Counter> &counter, std::string key) {
    // without get() because &
    auto iter = counter->countersMap.find(key);
    if ( iter == counter->countersMap.end() ) {
        return 0;
    } else
        return (*iter).second;
}

void ccounter::SetCountsTo(std::string key, int value, std::unique_ptr<ccounter::Counter> *counter) {
    auto iter = counter->get()->countersMap.find(key);
    if ( iter != counter->get()->countersMap.end() ) {
        (*iter).second = value;
    } else
        counter->get()->countersMap.insert( std::pair<std::string, int>(key, value) );
}