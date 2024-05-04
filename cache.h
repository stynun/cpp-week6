#ifndef CACHE_H
#define CACHE_H

#include <string>
#include <cstring>

#define CACHE_SIZE 10

class Cache {
private:
    struct CacheNode {
        std::string key;
        union {
            int intValue;
            double doubleValue;
        } value;
        bool isIntValue;
        CacheNode* next;
    };

    CacheNode* head;
    int size;

public:
    Cache();
    ~Cache();
    void add(std::string key, int value);
    void add(std::string key, double value);
    bool get(std::string key, int &value);
    bool get(std::string key, double &value);
    std::string toString();
};

#endif
