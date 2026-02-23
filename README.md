# Advanced Algorithms and Data Structures Repository

This repository features a diverse collection of advanced algorithms and data structures, along with implementations for solving various computational problems. Each file demonstrates a specific approach or solution, providing insights into efficient algorithm design and usage.

## Contents

### Algorithms

1. **String Matching Algorithms** (`StringMatching/`)
   - **Aho-Corasick Algorithm (`AhoCorasick.h`)**: Multi-pattern string matching using trie-based approach with failure links. Efficiently finds all occurrences of multiple pattern strings in a text.
   - **Rabin-Karp Algorithm (`RabinKarp.cpp`)**: Efficient string searching using rolling hash technique with polynomial hashing.
   - **KMP String Matching (`String Matching.cpp`)**: Knuth-Morris-Pratt algorithm implementation using prefix function for pattern matching.

2. **Primality Testing** (`Primality/`)
   - **Rabin-Miller Test (`RabinMiller.cpp`)**: Probabilistic primality test supporting very large numbers (up to 300+ digits) with custom arbitrary-precision arithmetic.
   - **Fermat's Little Theorem (`FermaPrimeChecker.cpp`)**: Fast probabilistic primality testing for numbers up to 10<sup>18</sup> using fast exponentiation.
   - **Sieve of Eratosthenes (`Sieve.cpp`)**: Classic algorithm to find all prime numbers up to a given limit (up to 500,000).

3. **Graph Algorithms** (`Graph/`)
   - **Lee's Algorithm (`lee.cpp`)**: BFS-based pathfinding in 2D grids, finds shortest path while avoiding obstacles.
   - **Susan Problem (`susan.cpp`)**: 3D variant of Lee's algorithm for navigating tower structures with special tiles (pbinfo.ro problem).
   - **K-Shortest Paths (`chromosome.cpp`)**: Dijkstra-based approach to find K shortest distinct paths from source to destination.
   - **Coupling Algorithm (`Cuplaj.cpp`)**: Solves coupling or pairing problems using graph theory principles.

4. **Hashing Techniques and Optimization** (`Misc/`)
   - **Hash Pairs (`HashPairs_ExponentialLOG.cpp`)**: Custom hash function for storing pairs in unordered_map with polynomial hashing.
   - **Fast Exponentiation (`HashPairs_ExponentialLOG.cpp`)**: Binary exponentiation for fast power computation.

5. **Performance Measurement** (`Misc/`)
   - **CPU Clock (`CPU_Clock.cpp`)**: High-resolution timing utility using Windows API for algorithm benchmarking.

### Data Structures

1. **Tree Structures** (`DataStructures/`)
   - **Trie with Autocomplete (`Trie_Autocomplete.cpp`)**: Prefix tree implementation with insert, search, startsWith, and autocomplete functionality. Efficiently finds all words matching a given prefix with DFS traversal.
   - **Red-Black Tree Insertion (`RB_Insert.cpp`)**: Implements insertion with balancing via rotations and color adjustments.
   - **Subarray Divisibility (`Subarray_Divisibility.cpp`)**: CSES.fi problem implemented using red-black trees instead of standard maps for efficient prefix sum tracking.

2. **Caching and Concurrency** (`ConcurrencyAdvanced/`)
   - **LRU Cache (`LRU_Cache.cpp`)**: Thread-safe Least Recently Used cache with template support for arbitrary key-value types, using mutex locks and unordered_map.
   - **Producer-Consumer Queue (`ProducerConsumer.cpp`)**: Thread-safe bounded queue implementation with condition variables for synchronization between producers and consumers.
   - **Rate Limiter (`RateLimiter.cpp`)**: Token bucket algorithm for rate limiting with automatic token refill. Thread-safe implementation using steady_clock for precise timing and mutex locks.
   - **Thread Pool (`ThreadPool.cpp`)**: Pool of worker threads that execute tasks from a queue. Supports dynamic task submission, graceful shutdown, and proper cleanup using condition variables for synchronization.
   - **Read-Write Lock (`ReadWriteLock.cpp`)**: Synchronization primitive allowing concurrent reads but exclusive writes. Implements writer starvation prevention by blocking new readers when writers are waiting.
   - **Deadlock Detector (`DeadLockDetect.cpp`)**: Detects circular wait conditions (deadlocks) using DFS cycle detection on a wait graph. Tracks thread-resource relationships and identifies potential deadlocks.
   - **Ring Buffer (`RingBuffer.cpp`)**: Thread-safe fixed-size circular buffer for streaming data. Overwrites oldest data when full, supports push/pop operations with mutex synchronization.
   - **Sliding Window Counter (`SlidingWindow.cpp`)**: Counts events within a configurable time window (e.g., requests in last 60 seconds). Automatically evicts expired events and aggregates counts by timestamp.
   - **Lock-Free Stack (`LockFreeStack.cpp`)**: Thread-safe stack using atomic CAS (compare-and-swap) instead of mutexes. Uses a singly linked list with compare_exchange_weak for lock-free push/pop operations.

3. **Smart Pointers (Custom Implementations)** (`SmartPointers/`)
   - **Shared Pointer (`sharedptr.cpp`)**: Custom implementation of std::shared_ptr with atomic reference counting and proper RAII resource management.
   - **Unique Pointer (`uniqueptr.cpp`)**: Custom implementation of std::unique_ptr with exclusive ownership, move semantics, and automatic cleanup.

4. **Linear Data Structures** (`DataStructures/`)
   - **Deque Parsing (`deque_Parse.cpp`)**: Efficient input parser that processes and loads data into C++ STL Deque.
   - **Linked Lists (`liste.cpp`)**: Collection of linked list operations and utilities.

### Specialized Implementations (`Misc/`)

1. **Matrix Operations**
   - **Matrix Filling (`Fill_mat_with_L.cpp`)**: Efficiently fills matrices based on specific rules or conditions.

2. **Data Processing**
   - **Normalization (`normalizare.cpp`)**: Applies data normalization techniques for specific datasets.
   - **Stack Trace Processing (`StackTrace.cpp`)**: Processes stack trace samples to detect function entry/exit points by comparing consecutive samples.

## Usage

Each file is an independent implementation. The source code is written in C++ and can be compiled and executed as follows:

```bash
# Replace folder/filename.cpp with the desired file
g++ -std=c++17 -o output folder/filename.cpp
./output
```
