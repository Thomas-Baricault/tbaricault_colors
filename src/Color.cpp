/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include <algorithm>
#include <stdexcept>

#include <tbaricault/str.hpp>
#include <tbaricault/uniconvert.hpp>

#include "colors/Color.hpp"


namespace tbaricault::colors
{

    Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) noexcept
        : r(r)
        , g(g)
        , b(b)
        , a(a)
    {
        return;
    }

    Color::Color(RGBA rgba) noexcept
        : r(rgba & 0xff)
        , g((rgba >> 8) & 0xff)
        , b((rgba >> 16) & 0xff)
        , a((rgba >> 24) & 0xff)
    {
        return;
    }

    Color::Color(Constant constant) noexcept
        : Color(static_cast<RGBA>(constant))
    {
        return;
    }

    Color::Color(std::string_view str)
    {
        if (!str.empty() && str.at(0) == '#')
        {
            if (str.length() >= 7)
            {
                this->r = tbaricault::uniconvert::convert<std::string, unsigned long>(std::string(str.substr(1, 2)), 16);
                this->g = tbaricault::uniconvert::convert<std::string, unsigned long>(std::string(str.substr(3, 2)), 16);
                this->b = tbaricault::uniconvert::convert<std::string, unsigned long>(std::string(str.substr(5, 2)), 16);
            }
            if (str.length() == 7)
            {
                this->a = 0xff;
                return;
            }
            if (str.length() == 9)
            {
                this->a = tbaricault::uniconvert::convert<std::string, unsigned long>(std::string(str.substr(7, 2)), 16);
                return;
            }
        }
        throw std::invalid_argument("convertion failed");
    }

    Color& Color::operator+=(const Color& other) noexcept
    {
        this->r = static_cast<unsigned char>(std::min(this->r + other.r, 255));
        this->g = static_cast<unsigned char>(std::min(this->g + other.g, 255));
        this->b = static_cast<unsigned char>(std::min(this->b + other.b, 255));
        this->a = static_cast<unsigned char>(std::min(this->a + other.a, 255));
        return (*this);
    }

    Color& Color::operator-=(const Color& other) noexcept
    {
        this->r = static_cast<unsigned char>(std::max(this->r - other.r, 0));
        this->g = static_cast<unsigned char>(std::max(this->g - other.g, 0));
        this->b = static_cast<unsigned char>(std::max(this->b - other.b, 0));
        this->a = static_cast<unsigned char>(std::max(this->a - other.a, 0));
        return (*this);
    }

    Color Color::operator+(const Color& other) const noexcept
    {
        return Color(
            static_cast<unsigned char>(std::min(this->r + other.r, 255)),
            static_cast<unsigned char>(std::min(this->g + other.g, 255)),
            static_cast<unsigned char>(std::min(this->b + other.b, 255)),
            static_cast<unsigned char>(std::min(this->a + other.a, 255))
        );
    }

    Color Color::operator-(const Color& other) const noexcept
    {
        return Color(
            static_cast<unsigned char>(std::max(this->r - other.r, 0)),
            static_cast<unsigned char>(std::max(this->g - other.g, 0)),
            static_cast<unsigned char>(std::max(this->b - other.b, 0)),
            static_cast<unsigned char>(std::max(this->a - other.a, 0))
        );
    }

    bool Color::operator==(const Color& other) const noexcept
    {
        return (
            this->r == other.r &&
            this->g == other.g &&
            this->b == other.b &&
            this->a == other.a
        );
    }

    bool Color::operator!=(const Color& other) const noexcept
    {
        return (
            this->r != other.r ||
            this->g != other.g ||
            this->b != other.b ||
            this->a != other.a
        );
    }

    Color::operator RGBA() const noexcept
    {
        return (
             this->r        +
            (this->g << 8)  +
            (this->b << 16) +
            (this->a << 24)
        );
    }

    Color::operator std::string() const
    {
        const unsigned char components[4] = {this->r, this->g, this->b, this->a};
        std::string result;
        result.reserve(7);
        result += '#';
        for (unsigned char i = 0; i < (this->a == 0xff ? 3 : 4); i++)
        {
            result += tbaricault::str::hex.at(components[i] / 16);
            result += tbaricault::str::hex.at(components[i] % 16);
        }
        return (result);
    }

}
