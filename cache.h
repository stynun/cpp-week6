#ifndef CACHE_H
#define CACHE_H

#include <string>

// 캐시 노드 구조체 정의
struct CacheNode {
    std::string key; // 키
    union {
        int intValue;     // 정수 값
        double doubleValue; // 실수 값
    } value;
    bool isIntValue; // 값의 타입 (정수일 경우 true, 실수일 경우 false)
    CacheNode* next; // 다음 노드를 가리키는 포인터

    // 생성자 (키와 정수 값이 주어졌을 때)
    CacheNode(std::string key, int value) : key(key), isIntValue(true), next(nullptr) {
        this->value.intValue = value;
    }

    // 생성자 (키와 실수 값이 주어졌을 때)
    CacheNode(std::string key, double value) : key(key), isIntValue(false), next(nullptr) {
        this->value.doubleValue = value;
    }
};

// 캐시 클래스 정의
class Cache {
private:
    CacheNode* head; // 캐시의 헤드 포인터
    int size; // 캐시의 크기
    static const int CACHE_SIZE = 10; // 캐시의 최대 크기

public:
    Cache(); // 생성자
    ~Cache(); // 소멸자

    // 정수 값을 캐시에 추가하는 함수
    void add(std::string key, int value);

    // 실수 값을 캐시에 추가하는 함수
    void add(std::string key, double value);

    // 키에 해당하는 정수 값을 가져오는 함수
    bool get(std::string key, int &value);

    // 키에 해당하는 실수 값을 가져오는 함수
    bool get(std::string key, double &value);

    // 캐시 정보를 문자열로 반환하는 함수
    std::string toString() const;
};

#endif // CACHE_H
