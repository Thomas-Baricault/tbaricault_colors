/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <string>
#include <string_view>

#include "constants.hpp"


namespace tbaricault::colors
{


    /**
     * @brief RGBA color representation
     */
    class Color final
    {

        public:

            /**
             * @brief Red channel
             */
            unsigned char r = 0;

            /**
             * @brief Green channel
             */
            unsigned char g = 0;

            /**
             * @brief Blue channel
             */
            unsigned char b = 0;

            /**
             * @brief Alpha channel
             */
            unsigned char a = 0;


            /**
             * @brief Constructs a fully transparent black color by default
             */
            Color() noexcept = default;

            /**
             * @brief Copy constructor
             * 
             * @param other Color to copy
             */
            Color(const Color& other) noexcept = default;

            /**
             * @brief Move constructor
             * 
             * @param other Color to move
             */
            Color(Color&& other) noexcept = default;

            /**
             * @brief Constructs a color from individual RGBA components
             * 
             * @param r Red component
             * @param g Green component
             * @param b Blue component
             * @param a Alpha component
             */
            Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255) noexcept;

            /**
             * @brief Constructs a color from a packed RGBA value
             * 
             * @param rgba 32-bit RGBA value
             */
            Color(RGBA rgba) noexcept;

            /**
             * @brief Constructs a color from a predefined constant
             * 
             * @param constant Named color constant
             */
            Color(Constant constant) noexcept;

            /**
             * @brief Contructs a color from its string representation
             * 
             * @param str String representation
             * 
             * @throws std::invalid_argument If conversion failed
             */
            Color(std::string_view str);

            /**
             * @brief Destructor
             */
            ~Color() noexcept = default;

            /**
             * @brief Copy assignment operator
             * 
             * @param other Color to copy
             * 
             * @return Reference to this color
             */
            Color& operator=(const Color& other) noexcept = default;

            /**
             * @brief Move assignment operator
             * 
             * @param other Color to move
             * 
             * @return Reference to this color
             */
            Color& operator=(Color&& other) noexcept = default;

            /**
             * @brief Adds another color component-wise (clamped to 255)
             * 
             * @param other Color to add
             * 
             * @return Reference to this color
             */
            Color& operator+=(const Color& other) noexcept;

            /**
             * @brief Subtracts another color component-wise (clamped to 0)
             * 
             * @param other Color to subtract
             * 
             * @return Reference to this color
             */
            Color& operator-=(const Color& other) noexcept;

            /**
             * @brief Component-wise addition of two colors (clamped to 255)
             * 
             * @param other Color to add
             * 
             * @return Resulting color
             */
            Color operator+(const Color& other) const noexcept;

            /**
             * @brief Component-wise subtraction of two colors (clamped to 0)
             * 
             * @param other Color to add
             * 
             * @return Resulting color
             */
            Color operator-(const Color& other) const noexcept;

            /**
             * @brief Checks whether two colors are identical
             * 
             * @param other Color to compare with
             * 
             * @return `true` if both colors are equal, `false` otherwise
             */
            bool operator==(const Color& other) const noexcept;

            /**
             * @brief Checks whether two colors are different
             * 
             * @param other Color to compare with
             * 
             * @return `true` if colors differ, `false` otherwise
             */
            bool operator!=(const Color& other) const noexcept;

            /**
             * @brief Converts the color to a packed RGBA value
             */
            operator RGBA() const noexcept;

            /**
             * @brief Converts the color to its string representation
             */
            operator std::string() const;

    };

}
