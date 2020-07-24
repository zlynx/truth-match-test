# truth-match-test
Test and benchmarking inspired by https://stackoverflow.com/questions/63003802/whats-the-fastest-way-to-interpret-a-bool-string-into-a-number-in-c/

A user named wovano challenged me just by posting graphs. Actual data!
I decided to take this to the next level by implementing all of the code in question with Google Test and Benchmark.

A summary of results so far:

On a Power9 CPU:

    -----------------------------------------------------------
    Benchmark                 Time             CPU   Iterations
    -----------------------------------------------------------
    BM_zlynx1_tobool       20.8 ns         20.8 ns     34717649
    BM_zlynx2_tobool       41.9 ns         41.9 ns     16708237
    BM_wovano_tobool       21.7 ns         21.7 ns     32041080
    BM_chux1_tobool        49.0 ns         49.0 ns     14163944
    BM_chux2_tobool        95.7 ns         95.7 ns      7399286
    BM_user1_tobool        21.3 ns         21.3 ns     32978284
    BM_user2_tobool         132 ns          132 ns      5324223

On a Ryzen 3900X:

    -----------------------------------------------------------
    Benchmark                 Time             CPU   Iterations
    -----------------------------------------------------------
    BM_zlynx1_tobool       15.5 ns         15.5 ns     41861511
    BM_zlynx2_tobool       30.7 ns         30.7 ns     23307588
    BM_wovano_tobool       14.4 ns         14.4 ns     48624468
    BM_chux1_tobool        34.0 ns         34.0 ns     21465379
    BM_chux2_tobool        25.6 ns         25.6 ns     26965281
    BM_user_tobool         44.2 ns         44.2 ns     15756835

The test results are too noisy so I will summarize. The implementations here that do less, run faster in general.

I wrote the tests so that they should handle "true", "false", "True", "False", "1", "0", "" and a 500 byte string.
The only implementations that pass are zlynx2 (that's mine, I fixed it to pass!) and user (user is short for an anonymous user).
