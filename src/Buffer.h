#ifndef BUFFER_H
#define BUFFER_H

#include <cstdint>
#include <cstring>

namespace lerksy {

class Buffer
{
public:
    Buffer() = default;
    ~Buffer();

    template<typename T>
    void insertValue(T val)
    {
        prepareSpace(sizeof(T));
        writeData(&val, sizeof(T));
    }
    template<typename T>
    void getValue(T *val)
    {
        auto readPtr = getReadLocation();
        if (mReadSize + sizeof(T) > mDataSize) {
            std::memset(val, 0, sizeof(T));
            return;
        }
        std::memcpy(val, readPtr, sizeof(T));
        mReadSize += sizeof(T);
    }

private:
    void prepareSpace(int64_t size);
    void allocateSpace(int64_t size);
    void writeData(void *data, int64_t size);
    [[nodiscard]] uint8_t *getWriteLocation() const { return mData + mDataSize; }
    [[nodiscard]] uint8_t *getReadLocation() const { return mData + mReadSize; }

    uint8_t *mData = nullptr;
    int64_t mDataSize = 0;
    int64_t mAllocatedSize = 0;
    int64_t mReadSize = 0;
};

} // namespace lerksy

#endif //BUFFER_H
