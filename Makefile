# LTOFLAGS += -flto -fno-fat-lto-objects
LTOFLAGS += -flto
OPTFLAGS += -O3 $(LTOFLAGS)
#OPTFLAGS += -mcpu=native
FLAGS = -Wall -W -pedantic -g $(OPTFLAGS) -pthread -MMD 
CSTD = -std=c11
CXXSTD = -std=c++17
CFLAGS = $(FLAGS) $(CSTD) $(EXTRA)
CXXFLAGS = $(FLAGS) $(CXXSTD) $(EXTRA)
LDFLAGS += -pthread $(LTOFLAGS)

# You could comipile these yourself
# Or install:
# apt install libbenchmark-dev libgtest-dev
# dnf install google-benchmark-devel gtest-devel
#FLAGS += -I../../benchmark/include
#LDFLAGS += -L../../benchmark/build/src
#LDFLAGS += -L../../benchmark/build/lib
#FLAGS += -I../../benchmark/googletest/googletest/include

CXX = /usr/bin/clang++
CC = /usr/bin/clang

OBJS += test-cases.o
OBJS += zlynx_tobool.o
OBJS += wovano_tobool.o
OBJS += chux_tobool.o
OBJS += user_tobool.o

all: truth-match-benchmark truth-match-test

truth-match-benchmark: LDLIBS += -lbenchmark
truth-match-benchmark: benchmark.o $(OBJS)
	$(CXX) $(FLAGS) $(CXXSTD) $(EXTRA) $(LDFLAGS) $^ $(LDLIBS) -o $@

truth-match-test: LDLIBS += -lgtest
truth-match-test: test.o $(OBJS)
	$(CXX) $(FLAGS) $(CXXSTD) $(EXTRA) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	rm -f *.o *.d truth-match-benchmark truth-match-test

-include *.d

.PHONY: all clean
