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
  Cache();
  ~Cache();
  // int를 cache에 추가한다
  void add(std::string key, int value);
  // double을 cache에 추가한다
  void add(std::string key, double value);
  // key에 해당하는 value를 cache에서 가져온다
  // 타입과 key가 동일한 원소가 없다면 false를 반환한다.
  bool get(std::string key, int &value);
  // key에 해당하는 value를 cache에서 가져온다.
  // 타입과 key가 동일한 원소가 없다면 false를 반환한다.
  bool get(std::string key, double &value);

  // 디버그 및 채점 용: 연결 리스트를 문자열로 표현하여 반환한다
  // 다음과 같이 표현된 문자열을 반환한다
  // [key1: value1] -> [key2: value2] -> ... -> [keyN: valueN]
  std::string toString();
};

#endif // CACHE_H
