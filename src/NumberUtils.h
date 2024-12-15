#ifndef NUMBERUTILS_H
#define NUMBERUTILS_H

#include <cstdint>
#include <string_view>

namespace lerksy {

constexpr bool isDigit(uint8_t c) { return c >= '0' && c <= '9'; }
constexpr uint8_t fromHexChar(uint8_t c) { return isDigit(c) ? c - '0' : c - 'a' + 10; }

constexpr uint8_t fromHex(std::string_view bytes)
{
    if (bytes.size() != 2) {
        return {};
    }
    return fromHexChar(bytes[0]) * 16 + fromHexChar(bytes[1]);
}
} // namespace lerksy

#endif //NUMBERUTILS_H
