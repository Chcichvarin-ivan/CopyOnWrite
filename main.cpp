/*
 * @Author: Ivan Chichvarin ichichvarin@humanplus.ru
 * @Date: 2024-06-11 22:56:35
 * @LastEditors: Ivan Chichvarin ichichvarin@humanplus.ru
 * @LastEditTime: 2024-06-11 23:11:31
 * @FilePath: /CopyOnWrite/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <cmath>
#include <iostream>

#include "drawer.h"

constexpr int STAR_COUNT = 20;

int main() {
    {
        Image img = LoadImage(
            " CCCC             \n"
            "CC  CC   ##    ## \n"
            "CC      ####  ####\n"
            "CC  CC   ##    ## \n"
            " CCCC             \n");
        Print(img, std::cout);
    }

    {
        Image img{{30, 20}, '.'};

        DrawLine(img, {3, 2}, {26, 5}, '#');
        DrawLine(img, {26, 5}, {21, 18}, '#');
        DrawLine(img, {21, 18}, {3, 2}, '#');

        Print(img, std::cout);
    }
}