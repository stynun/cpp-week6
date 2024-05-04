#include "cache.h"
#include <sstream>

Cache::Cache() {
    head = nullptr;
    size = 0;
}

Cache::~Cache() {
    CacheNode* current = head;
    while (current != nullptr) {
        CacheNode* temp = current;
        current = current->next;
        delete temp;
    }
}

void Cache::add(std::string key, int value) {
    if (size >= CACHE_SIZE) {
        // Cache is full, remove the oldest entry
        CacheNode* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    // 새로운 노드를 추가할 때 정수 값에 대한 생성자 호출
    CacheNode* newNode = new CacheNode(key, value);
    newNode->next = head;
    head = newNode;
    size++;
}

void Cache::add(std::string key, double value) {
    if (size >= CACHE_SIZE) {
        // Cache is full, remove the oldest entry
        CacheNode* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    // 새로운 노드를 추가할 때 실수 값에 대한 생성자 호출
    CacheNode* newNode = new CacheNode(key, value);
    newNode->next = head;
    head = newNode;
    size++;
}

bool Cache::get(std::string key, int &value) {
    CacheNode* current = head;
    while (current != nullptr) {
        if (current->key == key && current->isIntValue) {
            value = current->value.intValue;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool Cache::get(std::string key, double &value) {
    CacheNode* current = head;
    while (current != nullptr) {
        if (current->key == key && !current->isIntValue) {
            value = current->value.doubleValue;
            return true;
        }
        current = current->next;
    }
    return false;
}

std::string Cache::toString() const {
    std::ostringstream oss;
    CacheNode* current = head;
    bool isFirst = true; // 첫 번째 캐시인지 여부를 확인하기 위한 변수

    while (current != nullptr) {
        if (!isFirst) {
            // 첫 번째 캐시가 아닌 경우에만 "->" 출력
            oss << " -> ";
        } else {
            isFirst = false; // 첫 번째 캐시를 처리한 후에는 false로 변경
        }

        oss << "[";

        // 키에 대한 연산이 palindrome인지 multiply인지 확인
        if (current->key.find("palindrome") != std::string::npos) {
            oss << "palindrome(";
        } else if (current->key.find("multiply") != std::string::npos) {
            oss << "multiply(";
        }

        // 키의 이름 출력
        oss << current->key << "): ";

        // 값의 타입에 따라 출력 형식이 달라짐
        if (current->isIntValue) {
            oss << current->value.intValue;
        } else {
            oss << current->value.doubleValue;
        }

        oss << "]";
        current = current->next;
    }
    oss << "\n"; // TASK # 위에 공백 추가
    return oss.str();
}
