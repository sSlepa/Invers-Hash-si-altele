template <typename T>
class unique_ptr {
private:
    T* ptr;
public:

    explicit unique_ptr(T* p = nullptr) : ptr(p) {}

    ~unique_ptr() {
        delete ptr;
    }

    unique_ptr(unique_ptr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }
    unique_ptr& operator=(unique_ptr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    T* get() const {
        return ptr;
    }
    T& operator*() const {
        return *ptr;
    }
    T* operator->() const {
        return ptr;
    }
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }

};
