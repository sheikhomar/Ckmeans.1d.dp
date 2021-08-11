#include <iostream>
#include "Ckmeans.1d.dp.h"

int main() 
{
    std::cout << "Hello world!\n";

    std::vector<double> x = {-4, -5, -1, 0, 4, -4, -6, 7, 8, 10, 22};
    std::vector<double> y = {1.0};
    size_t length = x.size();
    size_t k = 10;
    size_t minK = k;
    size_t maxK = k;
    const double * xp(x.data()), * yp (y.data());
    std::vector<int> clusters(x.size());
    std::string method = "linear";
    std::string estimateK = "BIC";
    std::vector<double> BIC(maxK - minK + 1);

    // cdef double [:] sizes = np.zeros(max_k, dtype=np.float64)
    std::vector<double> sizes(maxK);
    std::vector<double> centers(maxK);
    std::vector<double> withinss(maxK);
    
    double * center_p (centers.data()), * sp (sizes.data());
    double * bp (BIC.data()), * wp (withinss.data());
    int * cluster_p (clusters.data());

    kmeans_1d_dp(xp, length, yp, minK, maxK,
               cluster_p, center_p, wp, sp, bp,
               estimateK, method, L2);

    std::cout << "Done!\n";

    return 0;
}