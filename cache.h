#ifndef CACHE_H
#define CACHE_H

#include <string>

// 해시 테이블 크기
const int HASH_SIZE = 20;

// 캐시 노드 구조체
struct CacheNode {
    std::string key;
    union {
        int intValue;
        double doubleValue;
    } value;
    bool isIntValue;
    CacheNode* next;
    CacheNode(std::string key, int value) : key(key), isIntValue(true), next(nullptr) {
        this->value.intValue = value;
    }
    CacheNode(std::string key, double value) : key(key), isIntValue(false), next(nullptr) {
        this->value.doubleValue = value;
    }
};

// 해시 클래스
class Hash {
public:
    // 해시 함수
    int hash(std::string key);
};

// 캐시 클래스
class Cache {
private:
    // 해시 테이블
    CacheNode* table[HASH_SIZE];

public:
    // 생성자
    Cache();

    // 소멸자
    ~Cache();

    // 캐시에 정수 값 추가
    void add(std::string key, int value);

    // 캐시에 실수 값 추가
    void add(std::string key, double value);

    // 키에 해당하는 정수 값 가져오기
    bool get(std::string key, int &value) const;

    // 키에 해당하는 실수 값 가져오기
    bool get(std::string key, double &value) const;

    // 캐시 정보 문자열로 변환
    std::string toString() const;
};

#endif // CACHE_H
