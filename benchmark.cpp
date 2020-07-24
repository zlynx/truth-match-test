#include "functions.h"
#include "test-cases.h"
#include <benchmark/benchmark.h>

static void BM_zlynx_tobool(benchmark::State &state) {
  for (auto _ : state) {
    for (const auto &i : test_case_inputs) {
      benchmark::DoNotOptimize(zlynx_tobool(i.data()));
    }
  }
}

static void BM_wovano_tobool(benchmark::State &state) {
  for (auto _ : state) {
    for (const auto &i : test_case_inputs) {
      benchmark::DoNotOptimize(wovano_tobool(i.data()));
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

static void BM_user_tobool(benchmark::State &state) {
  for (auto _ : state) {
    for (const auto &i : test_case_inputs) {
      benchmark::DoNotOptimize(user_tobool(i.data(), i.length()));
    }
  }
}

BENCHMARK(BM_zlynx_tobool);
BENCHMARK(BM_wovano_tobool);
BENCHMARK(BM_chux1_tobool);
BENCHMARK(BM_chux2_tobool);
BENCHMARK(BM_user_tobool);

BENCHMARK_MAIN();
