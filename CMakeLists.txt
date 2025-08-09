cmake_minimum_required(VERSION 3.16)
project(calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# サブディレクトリ追加
# CMakeプロジェクトを階層構造で構成し、
# それぞれのディレクトリで個別のCMakeLists.txtを管理する
add_subdirectory(src)
add_subdirectory(test)
