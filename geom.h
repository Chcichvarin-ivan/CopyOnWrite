/*
 * @Author: Ivan Chichvarin ichichvarin@humanplus.ru
 * @Date: 2024-06-11 22:58:53
 * @LastEditors: Ivan Chichvarin ichichvarin@humanplus.ru
 * @LastEditTime: 2024-06-11 23:12:29
 * @FilePath: /CopyOnWrite/geom.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once

struct Point {
    int x = 0;
    int y = 0;
};

struct Size {
    int width = 0;
    int height = 0;
};

// Точка передаётся в локальных координатах.
inline bool IsPointInSize(Point p, Size size) noexcept {
    return p.x >= 0 && p.y >= 0 && p.x < size.width && p.y < size.height;
}