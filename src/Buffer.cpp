#include "Buffer.h"

#include <cmath>

namespace lerksy {

Buffer::~Buffer()
{
    std::free(mData);
}

void Buffer::prepareSpace(int64_t size)
{
    if (mAllocatedSize - mDataSize > size) {
        return;
    }
    allocateSpace(size);
}
void Buffer::allocateSpace(int64_t size)
{
    const int64_t newSize = mDataSize + size + 1;
    int64_t finalAllocate = mDataSize + mDataSize / 2;
    if (finalAllocate < newSize) {
        finalAllocate = newSize;
    }
    if (!mData) {
        mData = static_cast<uint8_t *>(std::malloc(finalAllocate));
        mAllocatedSize = finalAllocate;
        return;
    }

    auto *newBuffer = static_cast<uint8_t *>(std::malloc(finalAllocate));
    std::memcpy(newBuffer, mData, mDataSize);
    std::free(mData);
    mData = newBuffer;
    mAllocatedSize = finalAllocate;
}

void Buffer::writeData(void *data, int64_t size)
{
    auto ptr = getWriteLocation();
    std::memcpy(ptr, data, size);
    mDataSize += size;
}

} // namespace lerksy