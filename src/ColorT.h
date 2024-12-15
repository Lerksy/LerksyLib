#ifndef COLORT_H
#define COLORT_H

template<typename T>
concept ColorViableT = std::is_integral_v<T> || std::is_floating_point_v<T>;

template<ColorViableT T>
class ColorT
{
public:
    constexpr ColorT() = default;
    constexpr ColorT(T red, T green, T blue, T alpha)
    {
        r = red;
        g = green;
        b = blue;
        a = alpha;
    }
    constexpr ColorT(T red, T green, T blue)
    {
        r = red;
        g = green;
        b = blue;
        a = std::is_integral_v<T> ? 255 : 1.;
    }

    constexpr T &operator[](int i) { return value(i); }
    constexpr const T &operator[](int i) const { return value(i); }

    constexpr T &value(int i)
    {
        switch (i) {
        case 0: return r;
        case 1: return g;
        case 2: return b;
        case 3: return a;
        default: {
            static T invalid;
            invalid = {};
            return invalid;
        }
        }
    }

    constexpr const T &value(int i) const
    {
        switch (i) {
        case 0: return r;
        case 1: return g;
        case 2: return b;
        case 3: return a;
        default: {
            static T invalid;
            invalid = {};
            return invalid;
        }
        }
    }

    template<ColorViableT U>
    constexpr bool setValue(U val, int index)
    {
        if (index < 0 || index > 3) {
            return false;
        }
        if (val < 0) {
            return false;
        }
        if constexpr ((std::is_integral_v<U> && std::is_integral_v<T>)
                      || (std::is_floating_point_v<U> && std::is_floating_point_v<T>)) {
            value(index) = val;
            return true;
        }
        if constexpr (std::is_integral_v<T>) {
            if (val > 1) {
                return false;
            }
            value(index) = static_cast<T>(val * 255);
            return true;
        }
        if (val > 255) {
            return false;
        }
        value(index) = static_cast<U>(val) / 255;
        return true;
    }
    constexpr bool operator==(const ColorT &other) const
    {
        for (int i = 0; i < 3; ++i) {
            if (value(i) != other[i]) {
                return false;
            }
        }
        return true;
    }

    T r = {};
    T g = {};
    T b = {};
    T a = {};
};

#endif //COLORT_H
