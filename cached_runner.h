#ifndef CACHED_RUNNER_H
#define CACHED_RUNNER_H

#include "cache.h"
#include "task_runner.h"
#include <string>

class CachedRunner {
private:
    Cache& cache;
    TaskRunner taskRunner;
    int hitCount;
    int missCount;

public:
    CachedRunner(Cache &cache);
    double multiply(std::string filename);
    int palindrome(std::string filename);
    int hits();
    int misses();
};

#endif
