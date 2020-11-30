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
auto hill_climbing_r_alg = [](auto get_random_sol, auto get_all_neighbours, auto goal, int max_iterations, auto callback) {
    auto current_solution = get_random_sol();
    for (int iteration = 0; iteration < max_iterations; iteration++)
    {
        auto next_solutions = get_all_neighbours(current_solution);
        uniform_int_distribution<int> uniform_dist(0, next_solutions.size()-1);
        auto next_sol = next_solutions.at(uniform_dist(e1));
        if (goal(current_solution) > goal(next_sol)) {
            current_solution = next_sol;
        }
        callback(iteration, current_solution);
    }
    return current_solution;
};
//Algorytm Wspinaczkowy ( randomowe pobieranie sąsiadów)


int main(int argc, char **argv)
{
 
    if ( argc != 4){
        cout << "Insert 3 arguments\n1.Function Name(booth, matyas, levi)\n2.Range-Min\n3.Range-Max\n";
        return -1;
    }

    string x_arg = argv[2];
    int x_argc = stoi(x_arg);

    string y_arg = argv[3];
    int y_argc = stoi(y_arg);

    uniform_real_distribution<double> uniform_dist(x_argc, y_argc);
    int max_iterations = 100000;


    // functions 
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
    // functions 


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

    if ((argc > 1) && (string(argv[1]) == "booth"))
    {
        auto goal = booth;

        auto solution = hill_climbing_r_alg(
            init,
            neighbours,
            goal,
            max_iterations,
            [goal](int i, vector<double> v){
            cout << i << " " << goal(v) << endl;
        });

        cout << "#booth result: [ " ;
        for (auto e : solution)
        cout << e << " ";
        cout << "] -> " << goal(solution) << endl;

    } else if((argc > 1) && (string(argv[1]) == "matyas"))
    {
        auto goal = matyas;

        auto solution = hill_climbing_r_alg(
            init,
            neighbours,
            goal,
            max_iterations,
            [goal](int i, vector<double> v){
            cout << i << " " << goal(v) << endl;
        });

        cout << "#matyas result: [ " ;
        for (auto e : solution)
        cout << e << " ";
        cout << "] -> " << goal(solution) << endl;

    }else if(string(argv[1]) == "levi"){
        auto goal = levi;

        
        auto solution = hill_climbing_r_alg(
            init,
            neighbours,
            goal,
            max_iterations,
            [goal](int i, vector<double> v){
            cout << i << " " << goal(v) << endl;
        });

        cout << "#levi result: [ " ;
        for (auto e : solution)
        cout << e << " ";
        cout << "] -> " << goal(solution) << endl;
    }else{
        cout << "You can only choose following functions: \n1.booth / matyas / levi\n";
    }

}
