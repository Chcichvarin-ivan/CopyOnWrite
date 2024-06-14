/*
 * @Author: Ivan Chichvarin ichichvarin@humanplus.ru
 * @Date: 2024-06-11 23:01:03
 * @LastEditors: Ivan Chichvarin ichichvarin@humanplus.ru
 * @LastEditTime: 2024-06-15 01:00:59
 * @FilePath: /CopyOnWrite/tile.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
#include <array>
#include <cassert>

#include "geom.h"

class Tile {
public:
    // Размер тайла 8*8 пикселей.
    constexpr static int SIZE = 8;

    // Конструктор по умолчанию. Заполняет тайл указанным цветом.
    Tile(char color = ' ') noexcept {
        pixels_colour_ = std::vector<std::vector<char>>(SIZE, std::vector<char>(SIZE, color)); 
        // -------------- не удалять ------------
        assert(instance_count_ >= 0);
        ++instance_count_;  // Увеличиваем счётчик тайлов (для целей тестирования).
        // -------------- не удалять ------------
    }

    Tile(const Tile& other) {
        pixels_colour_ = other.pixels_colour_;
        // -------------- не удалять ------------
        assert(instance_count_ >= 0);
        ++instance_count_;  // Увеличиваем счётчик тайлов (для целей тестирования).
        // -------------- не удалять ------------
    }

    ~Tile() {
        // -------------- Не удалять ------------
        --instance_count_;  // Уменьшаем счётчик тайлов.
        assert(instance_count_ >= 0);
        // -------------- не удалять ------------
    }

    /**
     * Изменяет цвет пикселя тайла.
     * Если координаты выходят за пределы тайла, метод ничего не делает.
     */
    void SetPixel(Point p, char color) noexcept {
        if((p.x >= 0)&&(p.x <= SIZE)&&(p.y >= 0)&&(p.y <=  SIZE)){
            pixels_colour_[p.x][p.y] = color;
        }
    }

    /**
     * Возвращает цвет пикселя. Если координаты выходят за пределы тайла, возвращается пробел.
     */
    char GetPixel(Point p) const noexcept {
        if((p.x >= 0)&&(p.x < SIZE)&&(p.y >= 0)&&(p.y <  SIZE)){
            return pixels_colour_[p.x][p.y];
        }else{
            return ' ';    
        }
    }

    // Возвращает количество экземпляра класса Tile в программе.
    static int GetInstanceCount() noexcept {
        // -------------- не удалять ------------
        return instance_count_;
        // -------------- не удалять ------------
    }

private:
    // -------------- не удалять ------------
    inline static int instance_count_ = 0;
    // -------------- не удалять ------------
    std::vector<std::vector<char>> pixels_colour_;
};