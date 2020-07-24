#include "functions.h"
#include "test-cases.h"
#include <benchmark/benchmark.h>

static void BM_zlynx1_tobool(benchmark::State &state) {
  for (auto _ : state) {
    for (const auto &i : test_case_inputs) {
      benchmark::DoNotOptimize(zlynx1_tobool(i.data()));
    }
  }
}

static void BM_zlynx2_tobool(benchmark::State &state) {
  for (auto _ : state) {
    for (const auto &i : test_case_inputs) {
      benchmark::DoNotOptimize(zlynx2_tobool(i.data()));
    }
  }
}

static void BM_wovano1_tobool(benchmark::State &state) {
  for (auto _ : state) {
    for (const auto &i : test_case_inputs) {
      benchmark::DoNotOptimize(wovano1_tobool(i.data()));
    }
  }
}

static void BM_wovano2_tobool(benchmark::State &state) {
  for (auto _ : state) {
    for (const auto &i : test_case_inputs) {
      benchmark::DoNotOptimize(wovano2_tobool(i.data()));
    }
  }
}

static void BM_chux1_tobool(benchmark::State &state) {
  for (auto _ : state) {
    for (const auto &i : test_case_inputs) {
      benchmark::DoNotOptimize(chux1_tobool(i.data()));
    }
  }
}

static void BM_chux2_tobool(benchmark::State &state) {
  for (auto _ : state) {
    for (const auto &i : test_case_inputs) {
      benchmark::DoNotOptimize(chux2_tobool(i.data()));
    }
  }
}

static void BM_user1_tobool(benchmark::State &state) {
  for (auto _ : state) {
    for (const auto &i : test_case_inputs) {
      benchmark::DoNotOptimize(user1_tobool(i.data()));
    }
  }
}

static void BM_user2_tobool(benchmark::State &state) {
  for (auto _ : state) {
    for (const auto &i : test_case_inputs) {
      benchmark::DoNotOptimize(user2_tobool(i.data(), i.length()));
    }
  }
}

BENCHMARK(BM_zlynx1_tobool);
BENCHMARK(BM_zlynx2_tobool);
BENCHMARK(BM_wovano1_tobool);
BENCHMARK(BM_wovano2_tobool);
BENCHMARK(BM_chux1_tobool);
BENCHMARK(BM_chux2_tobool);
BENCHMARK(BM_user1_tobool);
BENCHMARK(BM_user2_tobool);

BENCHMARK_MAIN();
