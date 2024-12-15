#ifndef COLOR_H
#define COLOR_H

#include "ColorT.h"

#include <cstdint>

#include "NumberUtils.h"

namespace lerksy {

class Color
{
public:
    constexpr Color() = default;
    constexpr Color(uint8_t red, uint8_t green, uint8_t blue)
    {
        mParts[0] = red;
        mParts[1] = green;
        mParts[2] = blue;
    }
    constexpr Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
    {
        mParts[0] = red;
        mParts[1] = green;
        mParts[2] = blue;
        mParts[3] = alpha;
    }

    static constexpr Color fromString(const std::string_view &hexString)
    {
        auto strSize = hexString.size();
        if (strSize < 6 || strSize > 9) {
            return {};
        }
        std::string_view localString;
        if (strSize == 7 || strSize == 9) {
            if (hexString[0] != '#') {
                return {};
            }
            localString = hexString.substr(1, strSize - 1);
            strSize -= 1;
        } else {
            localString = hexString;
        }

        if (strSize % 2 != 0) {
            return {};
        }

        Color ret;
        for (int i = 0; i < strSize / 2; ++i) {
            ret.mParts[i] = fromHex(localString.substr(i * 2, 2));
        }
        return ret;
    }
    constexpr bool operator==(const Color &other) const
    {
        return std::bit_cast<uint32_t>(mParts) == std::bit_cast<uint32_t>(other.mParts);
    }

    template<typename T>
    constexpr ColorT<T> getColorT() const
    {
        ColorT<T> ret;
        for (int i = 0; i < 3; ++i) {
            ret.setValue(mParts[i], i);
        }
        return ret;
    }

private:
    uint8_t mParts[4] = {0, 0, 0, 255};
};

} // namespace lerksy

#endif //COLOR_H
