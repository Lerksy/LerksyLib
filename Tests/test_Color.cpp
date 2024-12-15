#include <Catch>

#include <Color>

TEST_CASE("Color")
{
    constexpr lerksy::Color num(255, 255, 255);
    constexpr lerksy::Color hex = lerksy::Color::fromString("#ffffff");
    STATIC_REQUIRE(num == hex);

    STATIC_REQUIRE(lerksy::Color::fromString("fff") == lerksy::Color());
}

TEST_CASE("ColorT from Color")
{
    constexpr lerksy::Color num(255, 255, 255);

    STATIC_REQUIRE(num.getColorT<int>() == ColorT<int>{255, 255, 255});
    STATIC_REQUIRE(num.getColorT<float>() == ColorT<float>{1., 1., 1.});
}