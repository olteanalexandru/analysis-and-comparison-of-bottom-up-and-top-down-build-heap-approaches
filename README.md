You are required to compare the two build heap procedures in the average case.
Remember that for the average case you have to repeat the measurements m times (m=5)
and report their average; also for the average case, make sure you always use the same
input sequence for the two methods – to make the comparison fair.
2. This is how the analysis should be performed:
- vary the dimension of the input array (n) between [100…10000], with an increment
of maximum 500 (we suggest 100).
- for each dimension, generate the appropriate input sequence for the method; run the
method, counting the operations (assignments and comparisons, may be counted
together for this assignment).
! Only the assignments and comparisons performed on the input structure and its
corresponding auxiliary variables matter.
Generate a chart which compares the two methods under the total number of operations,
in the average case. If one of the curves cannot be visualized correctly because the other
has a larger growth rate, place that curve on a separate chart as well. Name your chart
and the curves on it appropriately.