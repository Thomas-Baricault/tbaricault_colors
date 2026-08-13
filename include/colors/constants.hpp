#pragma once


namespace tbaricault::colors
{

    /**
     * @brief 32-bit RGBA color type
     * 
     * The color is stored as a single 32-bit unsigned integer:
     * 
     * - 1st byte = Red
     * 
     * - 2nd byte = Green
     * 
     * - 3rd byte = Blue
     * 
     * - 4th byte = Alpha
     */
    using RGBA = unsigned int;


    /**
     * @brief Named color constants
     */
    enum class Constant : RGBA
    {

        Transparent = 0x00000000,
        Black = 0xff000000,
        Navy = 0xff7f0000,
        Blue = 0xffff0000,
        Green = 0xff007f00,
        Teal = 0xff7f7f00,
        Azure = 0xffff7f00,
        Lime = 0xff00ff00,
        SpringGreen = 0xff7fff00,
        Cyan = 0xffffff00,
        Maroon = 0xff00007f,
        Purple = 0xff7f007f,
        Indigo = 0xffff007f,
        Olive = 0xff007f7f,
        Grey = 0xff7f7f7f,
        Chartreuse = 0xff00ff7f,
        LightGreen = 0xff7fff7f,
        ElectricBlue = 0xffffff7f,
        Red = 0xff0000ff,
        Pink = 0xff7f00ff,
        Magenta = 0xffff00ff,
        Orange = 0xff007fff,
        LightCoral = 0xff7f7fff,
        Yellow = 0xff00ffff,
        WitchHazel = 0xff7fffff,
        White = 0xffffffff,

    };

}
