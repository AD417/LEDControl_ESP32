#include <unordered_map>
#include <string>

#include <FastLED.h>

#include "Program.h"

struct StringHash {
    std::size_t operator()(const String& s) const {
        return std::hash<std::string>()(s.c_str());
    }
};

// Equality comparison function for the String type
struct StringEqual {
    bool operator()(const String& s1, const String& s2) const {
        return s1 == s2;
    }
};

std::unordered_map<String, CRGB, StringHash, StringEqual> COLORS;
std::unordered_map<String, String, StringHash, StringEqual> COLOR_SHORTHAND;

void initColors() {
    COLORS["black"] = CRGB::Black;
    COLORS["blue"] = CRGB::Blue;
    COLORS["daytime"] = CRGB::LightCoral;
    COLORS["green"] = CRGB::Green;
    COLORS["magenta"] = CRGB::Magenta;
    COLORS["midnight"] = CRGB::Indigo;
    COLORS["orange"] = CRGB::Orange;
    COLORS["pink"] = CRGB::HotPink;
    COLORS["purple"] = CRGB::MediumPurple;
    COLORS["red"] = CRGB::Red;
    COLORS["white"] = CRGB::White;
    COLORS["yellow"] = CRGB::Yellow;

    COLOR_SHORTHAND["b"] = "blue";
    // COLOR_SHORTHAND["c"] = "custom";
    COLOR_SHORTHAND["d"] = "daytime";
    COLOR_SHORTHAND["g"] = "green";
    // Collision with magenta.
    COLOR_SHORTHAND["i"] = "midnight";
    // Collision with blue.
    COLOR_SHORTHAND["k"] = "black";
    COLOR_SHORTHAND["m"] = "purple";
    COLOR_SHORTHAND["o"] = "orange";
    COLOR_SHORTHAND["p"] = "pink";
    COLOR_SHORTHAND["r"] = "red";
    COLOR_SHORTHAND["w"] = "white";
    COLOR_SHORTHAND["y"] = "yellow";
}

CRGB getColorFromString(String color) {
    if (color.length() == 1) {
        try {
            color = COLOR_SHORTHAND.at(color);
        } catch (const std::out_of_range& e) {
            return Program::color;
        }
    }
    try {
        return COLORS.at(color);
    } catch (const std::out_of_range& e) {
        return Program::color;
    }
}