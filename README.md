# truth-match-test
Test and benchmarking inspired by https://stackoverflow.com/questions/63003802/whats-the-fastest-way-to-interpret-a-bool-string-into-a-number-in-c/

A user named wovano challenged me just by posting graphs. Actual data!
I decided to take this to the next level by implementing all of the code in question with Google Test and Benchmark.

A summary of results so far:

On a Ryzen 3900X:

    ------------------------------------------------------------
    Benchmark                  Time             CPU   Iterations
    ------------------------------------------------------------
    BM_zlynx1_tobool        15.6 ns         15.6 ns     34940037
    BM_zlynx2_tobool        30.1 ns         30.1 ns     23208760
    BM_wovano1_tobool       14.7 ns         14.7 ns     47891667
    BM_wovano2_tobool       20.0 ns         20.0 ns     34996469
    BM_chux1_tobool         31.5 ns         31.5 ns     21909135
    BM_chux2_tobool         25.3 ns         25.3 ns     27068521
    BM_user1_tobool         14.1 ns         14.1 ns     49916508
    BM_user2_tobool         44.4 ns         44.4 ns     15614261

The test results are too noisy so I will summarize. The implementations here that do less, run faster in general.

I wrote the tests so that they should handle "true", "false", "True", "False", "1", "0", "" and a 500 byte string.
The only implementations that pass are wovano2, zlynx2 (that's mine, I fixed it to pass!) and user (user is short for an anonymous user).
