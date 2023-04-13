# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/nguye/esp/esp-idf/components/bootloader/subproject"
  "D:/khongday/idf-i2c/Oled_I2C/build/bootloader"
  "D:/khongday/idf-i2c/Oled_I2C/build/bootloader-prefix"
  "D:/khongday/idf-i2c/Oled_I2C/build/bootloader-prefix/tmp"
  "D:/khongday/idf-i2c/Oled_I2C/build/bootloader-prefix/src/bootloader-stamp"
  "D:/khongday/idf-i2c/Oled_I2C/build/bootloader-prefix/src"
  "D:/khongday/idf-i2c/Oled_I2C/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/khongday/idf-i2c/Oled_I2C/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
