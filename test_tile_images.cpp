/*
 * @Author: Ivan Chichvarin ichichvarin@humanplus.ru
 * @Date: 2024-06-12 20:43:24
 * @LastEditors: Ivan Chichvarin ichichvarin@humanplus.ru
 * @LastEditTime: 2024-06-12 23:19:57
 * @FilePath: /CopyOnWrite/test_tile_images.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <algorithm>
#include "drawer.h"
#include <iostream>
using namespace std;
void AssertImpl(bool value, const std::string& expr_str, const std::string& file, const std::string& func, unsigned line,
                const std::string& hint) {
    
    if (!value) {
        cerr << file << "("s << line << "): "s << func << ": "s;
        cerr << "Assert("s << expr_str << ") failed."s;
        if (!hint.empty()) {
            cerr << " Hint: "s << hint;
        }
        cerr << endl;
        abort();
    }
} 

#define ASSERT_HINT(expr, hint) AssertImpl((expr), #expr, __FILE__, __FUNCTION__, __LINE__, (hint))

template <typename T, typename U>
void AssertEqualImpl(const T& t, const U& u, const std::string& t_str, const std::string& u_str, const std::string& file,
                     const std::string& func, unsigned line, const std::string& hint) {
    
    if (t != u) {
        cerr << boolalpha;
        cerr << file << "("s << line << "): "s << func << ": "s;
        cerr << "ASSERT_EQUAL("s << t_str << ", "s << u_str << ") failed: "s;
        cerr << t << " != "s << u << "."s;
        if (!hint.empty()) {
            cerr << " Hint: "s << hint;
        }
        cerr << endl;
        abort();
    }
} 

#define ASSERT_EQUAL(a, b) AssertEqualImpl((a), (b), #a, #b, __FILE__, __FUNCTION__, __LINE__,""s)
#define ASSERT_EQUAL_HINT(a, b, hint) AssertEqualImpl((a), (b), #a, #b, __FILE__, __FUNCTION__, __LINE__, (hint))

template <typename TestFunc>
void RunTestImpl(const TestFunc& func, const std::string& test_name) {
    func();
    cerr << test_name << " OK"s << endl;
}

#define RUN_TEST(func) RunTestImpl(func, #func) 
// ------------------- Начало модульных тестов ----------------------
void CheckTileFill(const Tile &tile, char color){
        for (auto i = 0; i < Tile::SIZE; ++i){
            for (auto j = 0; j < Tile::SIZE; ++j){
                ASSERT_EQUAL(tile.GetPixel({i, j}), color);
        }
    }
}
void TestCreateTile(void){
    const char color = '#';
    Tile tile(color);
    
    for (int x = 0; x < tile.SIZE; x++) for (int y = 0; y < tile.SIZE; y++){
        Point p({x,y});
        ASSERT_EQUAL(tile.GetPixel(p), color);
    }
}

void TestGetPixelOutOfTileRange(void){
    const char color = '#';
    Tile tile(color);

    Point p({9,9});
    ASSERT_EQUAL(tile.GetPixel(p), ' ');
}

void TestTileFill(void){
    const char color = '#';
    Tile tile(color);
    CheckTileFill(tile, color);
    Point p1({1, 2});
    const char color_1 = '1';
    Point p2({5, 3});
    const char color_2 = '2';
    Point p3({0, 0});
    const char color_3 = '3';
    
    tile.SetPixel(p1, color_1);
    tile.SetPixel(p2, color_2);
    tile.SetPixel(p3, color_3);
    tile.SetPixel({-10, 100}, 's');
    ASSERT_EQUAL(tile.GetPixel(p1), color_1);
    ASSERT_EQUAL(tile.GetPixel(p2), color_2);
    ASSERT_EQUAL(tile.GetPixel(p3), color_3);
}

// Функция TestTranspotCatalogue является точкой входа для запуска тестов
void TestDrawer(void){
    RUN_TEST(TestCreateTile);
    RUN_TEST(TestGetPixelOutOfTileRange);
    RUN_TEST(TestTileFill);
    
}