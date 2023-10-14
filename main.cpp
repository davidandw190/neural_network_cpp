
#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>


int main() {


    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previous_time;
    std::mt19937_64 random_engine(std::chrono::system_clock::now().time_since_epoch().count());

    return 0;

}
