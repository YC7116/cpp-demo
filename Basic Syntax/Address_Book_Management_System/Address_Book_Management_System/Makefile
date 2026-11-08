# 编译�?
CXX = g++
# 编译选项�?-g 开启调试，-Wall 显示警告�?-Iinclude 指定头文件路�?
CXXFLAGS = -g -Wall -Iinclude

# 目标可执行文�?
TARGET = output/main.exe

# 所有的源文件（src 目录下的所�? .cpp 文件�?
SOURCES = src/*.cpp

# 默认编译任务
all: $(TARGET)

# 链接生成可执行文�?
$(TARGET):
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# 清理编译产物
clean:
	del $(TARGET)