#include "cached_runner.h"
#include <fstream>
#include <iostream>

CachedRunner::CachedRunner(Cache &cache) : cache(cache), taskRunner(TaskRunner()) {
    hitCount = 0;
    missCount = 0;
}

double CachedRunner::multiply(std::string filename) {
    double result;
    if (cache.get(filename, result)) {
        hitCount++;
        return result;
    } else {
        double newResult = taskRunner.multiply(filename);
        cache.add(filename, newResult);
        missCount++;
        return newResult;
    }
}

int CachedRunner::palindrome(std::string filename) {
    int result;
    if (cache.get(filename, result)) {
        hitCount++;
        return result;
    } else {
        int newIndex = taskRunner.palindrome(filename);
        cache.add(filename, newIndex);
        missCount++;
        return newIndex;
    }
}

int CachedRunner::hits() {
    return hitCount;
}

int CachedRunner::misses() {
    return missCount;
}
