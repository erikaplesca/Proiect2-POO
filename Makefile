CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra
SRCS = main.cpp angajat.cpp client.cpp masina.cpp reparatie.cpp factura.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = autoservice

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
