#include <assert.h>

template<typename T>
class Vector {
private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
public:
    Vector() {
        // allocate 2 elements initially
        ReAlloc(2);
    }

    Vector(size_t initSize) {
        m_Size = initSize;
        m_Data = (T*)::operator new(m_Size * sizeof(T));
        ReAlloc(m_Size);
    }
    
    ~Vector() {
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    void Clear() {
        for (size_t i = 0; i < m_Size; i++) {
            m_Data[i].~T();
        }
        m_Size = 0;
    }

    void PushBack(const T& value) {
        if (m_Size >= m_Capacity) {
            // growing by 1.5 times
            ReAlloc(m_Capacity + m_Capacity / 2 + 1);
        }
        m_Data[m_Size++] = value;
    }
    void PushBack(const T&& value) {
        if (m_Size >= m_Capacity) {
            // growing by 1.5 times
            ReAlloc(m_Capacity + m_Capacity / 2 + 1);
        }
        m_Data[m_Size++] = std::move(value);
    }

    void PopBack() {
        assert(m_Size > 0);
        m_Size--;
        m_Data[m_Size].~T();
    }

    template<typename... Args>
    T& EmplaceBack(Args&&... args) {
        if (m_Size >= m_Capacity) {
            // growing by 1.5 times
            ReAlloc(m_Capacity + m_Capacity / 2 + 1);
        }
        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
        // m_Data[m_Size] = T(std::forward<Args>(args)...);
        return m_Data[m_Size++];
    }

    constexpr size_t Size() const {
        return m_Size;
    }

    T* Data() {
        return m_Data;
    }
    const T* Data() const {
        return m_Data;
    }

    T& operator[] (size_t index) {
        assert(index < m_Size);
        return m_Data[index];
    }
    const T& operator[] (size_t index) const {
        assert(index < m_Size);
        return m_Data[index];
    }

private:
    void ReAlloc(size_t newCapacity) {
        // 1. allocate a new block of memory
        // 2. copy/move old elements into new block
        // 3. delete old block of memory

        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

        // if realloc is downsizing
        if (newCapacity < m_Size) {
            m_Size = newCapacity;
        }

        for (size_t i = 0; i < m_Size; i++) {
            newBlock[i] = std::move(m_Data[i]);
        }

        for (size_t i = 0; i < m_Size; i++) {
            m_Data[i].~T();
        }

        ::operator delete(m_Data, m_Capacity * sizeof(T));
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
};
