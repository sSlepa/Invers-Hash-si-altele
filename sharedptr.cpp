template<typename T>
class SharedPtr {
private:
    T* ptr;
    std::atomic<size_t>* ref_count;
public:

    explicit SharedPtr(T* p = nullptr) : ptr(p) {
        ref_count = new std::atomic<size_t>(p ? 1 : 0);
    }
    SharedPtr(const SharedPtr& other) {
        ptr = other.ptr;
        ref_count = other.ref_count;
        if (ref_count) {
            ref_count->fetch_add(1, std::memory_order_relaxed);
        }
    }

    SharedPtr(SharedPtr&& other) noexcept {
        ptr = other.ptr;
        ref_count = other.ref_count;
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            if (ptr) {
                ref_count->fetch_add(1, std::memory_order_relaxed);
            }
        }
        return *this;
    }
    SharedPtr& operator=(SharedPtr&& other) noexcept {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            other.ptr = nullptr;
            other.ref_count = nullptr;
        }
        return *this;
    }

    ~SharedPtr() {
        release();
    }

    void release() {
        if (ref_count && ref_count->fetch_sub(1, std::memory_order_acq_rel) == 1) {
            delete ptr;
            delete ref_count;
        }
        ptr = nullptr;
        ref_count = nullptr;
    }
    T* get() const {
        return ptr;
    }
    T& operator*() const {
        return *ptr;
    }
    T* operator->() const {
        return ptr;
    }
    size_t use_count() const {
        return ref_count ? ref_count->load(std::memory_order_relaxed) : 0;
    }

};
