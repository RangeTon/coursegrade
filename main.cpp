// A program that calculates the scores of all students in a course
// Created: Wei Gong  2026-11-16 16:43:44

// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2026 FreeTech <open-src@qq.com>

// CourseGrade calculation using a top-down, stepwise refinement approach

#include <vector>
#include <string>

using std::vector;
using std::string;

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

// 第二层的未知计算
void read(CourseGrade& cg)
{
    // todo
}
void computeSort(CourseGrade& cg)
{
    // todo
}
void print(CourseGrade& cg)
{
    // todo
}
