// A program that calculates the scores of all students in a course
// Created: Wei Gong  2026-11-16 16:43:44

// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2026 FreeTech <open-src@qq.com>

// CourseGrade calculation using a top-down, stepwise refinement approach

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <print>
using std::print;

#include <istream>
using std::istream;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include <algorithm>
using std::ranges::stable_sort;


//顶层分解
struct Grade; //类型声明
using CourseGrade = vector<Grade>; //类型别名

extern void read(CourseGrade& cg);
extern void computeSort(CourseGrade& cg);
extern void print(CourseGrade& cg);

int main()
{
    CourseGrade courseGrade;

    read(courseGrade);
    computeSort(courseGrade);
    print(courseGrade);

    return 0;
}

struct Grade //类型定义
{
    string name;
    double midterm;
    double final;
    vector<double> homework;
    double total; //总成绩，该数据成员可声明，也可不用声明
};

// 第二层分解，暂时不考虑错误处理
extern istream& operator>>(istream& is, Grade& g);
void read(CourseGrade& cg)
{
    print("Reading all student grades (name midterm final homework) from a file... \n");
    ifstream ifs("../../coursegrade.dat");
    // read and store all the grades
    string line;
    istringstream iss;
    while (std::getline(ifs, line)) { // std::getline按行读取成功时，返回good的ifs
        iss.str(line); // 字符串输入流iss封装字符串line进行流式输入
        Grade g; // 假定能够对g进行iss >> g读取操作
        if (iss >> g) {
            cg.push_back(g); // 读取成绩成功后，添加g到cg中
        } else {
            iss.clear();
        }
    }
    if(ifs.eof()) print("Reading done!\n\n");  // 读取完毕则打印
}

extern double score(Grade& g);
void computeSort(CourseGrade& cg)
{
    print("Processing all student grades... \n");
    for(auto& g: cg){
        g.total = score(g);  //假定能够进行score(g)操作
    }
    stable_sort(cg, [](auto& g1, auto& g2){
        return g1.total <= g2.total;
    });
    print("Processing done!\n\n");
}


void print(CourseGrade& cg)
{
    print("Course: {}\nCredit: {}\n", "software construction and implementation", 5);
    print("name      total\n");
    for(auto &g: cg){
        print("{:<10}{:<.1f}\n", g.name, g.total);
    }
}

// 第三层分解，暂时不考虑错误处理
istream& operator>>(istream& is, Grade& g)
{
    print("  Reading a student grade... ");
    if (is) is >> g.name >> g.midterm >> g.final;
    if (is){
        for (double h;is >> h;)
            g.homework.push_back(h);

        if(is.eof()) {
            is.clear();
            print("Done!  {}\n", g.name);
        }
    }
    if(!is) print("Error!\n");
    return is;
}

extern double median(vector<double> vec);
double score(Grade& g)
{
    return 0.2 * g.midterm + 0.4 * g.final + 0.4 * median(g.homework);
}

// 第四层的未知计算
double median(vector<double> vec)
{
    // todo
    return 0.0;
}
