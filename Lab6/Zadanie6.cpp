#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <numeric>
#include <algorithm>

using namespace std;
random_device r;
default_random_engine e1(r());


//Algorytm Wspinaczkowy ( randomowe pobieranie sąsiadów)
auto hill_climbing_r_alg = [](auto get_random_sol, auto get_all_neighbours, auto goal, int max_iterations) {
    auto current_solution = get_random_sol();
    for (int iteration = 0; iteration < max_iterations; iteration++)
    {
        auto next_solutions = get_all_neighbours(current_solution);
        uniform_int_distribution<int> uniform_dist(0, next_solutions.size()-1);
        auto next_sol = next_solutions.at(uniform_dist(e1));
        if (goal(current_solution) > goal(next_sol)) {
            current_solution = next_sol;
        }
        // uśrednić
                        // to jest do wykresów callback(iteration, current_solution);
    }
    return current_solution;
};
//Algorytm Wspinaczkowy ( randomowe pobieranie sąsiadów)

int main(int argc, char **argv)
{
    
    uniform_real_distribution<double> uniform_dist(-10, 10);
    int max_iterations = 100000;

    auto booth = [](vector<double> d) {
        double x = d.at(0);
        double y = d.at(1);
        return pow((x + 2*y - 7),2) + pow((2*x + y - 5),2);
    };

    auto matyas = [](vector<double> d) {
        double x = d.at(0);
        double y = d.at(1);
        return 0.26*(x*x + y*y) - 0.48*x*y;
    };

    auto levi = [](vector<double> d) {
        double x = d.at(0);
        double y = d.at(1);
        return pow(sin(3*M_PI*x),2) + pow((x-1),2)*(1 + pow(sin(3*M_PI*x),2)) + pow((y-1),2)*(1 + pow(sin(2*M_PI*x),2));
    };

    auto init = [&uniform_dist]() {
        vector<double> x(2);
        x[0] = uniform_dist(e1);
        x[1] = uniform_dist(e1);
        return x;
    };

    auto neighbours = [](vector<double> x, double dx = 0.001) {
        vector<vector<double> > ret;
        for (int i = 0; i < x.size(); i++)
        {
            auto nx = x;
            nx[i] += dx;
            ret.push_back(nx);
            nx[i] -= 2.0 * dx;
            ret.push_back(nx);
        }
        return ret;
    };

    //auto goal = booth;
    auto goal = matyas;
   // auto goal = levi;
    auto solution = hill_climbing_r_alg(
        init,
        neighbours,
        goal,
        max_iterations,
        [goal](int i, vector<double> v){
            cout << i << " " << goal(v) << endl;
        });

    cout << "result: [ " ;
    for (auto e : solution)
        cout << e << " ";
    cout << "] -> " << goal(solution) << endl;

}

