#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <stdexcept>
#include <cmath>

#include "Frequency.hpp"

const double THRESHOLD = 1e-9;

/* Provided test cases */

// TEST_CASE("Export example", "[frequency]"){
//     Frequency fdef;
//     fdef.gaussian(12.0, 9*M_PI);
//     fdef.export_csv("output");
// }

TEST_CASE("Test default construction", "[frequency]")
{
    Frequency fdef;

    REQUIRE(fdef.get_component() == 301);
    REQUIRE(std::abs(fdef.get_increment() - 0.1) <= THRESHOLD);
}

TEST_CASE("Test construction with arguments", "[frequency]")
{
    int comp = 201;
    double incr = 0.02;
    Frequency farg(comp, incr);

    REQUIRE(farg.get_component() == comp);
    REQUIRE(std::abs(farg.get_increment() - incr) <= THRESHOLD);

    // must call the frequency constructor directly to check throws in constructor
    // invalid number of components
    REQUIRE_THROWS_AS(Frequency(-1, incr), std::invalid_argument);
    REQUIRE_THROWS_AS(Frequency(Frequency::MAX_COMPONENTS_NUM + 1, incr), std::invalid_argument);
    // invalid incr
    REQUIRE_THROWS_AS(Frequency(comp, -1), std::invalid_argument);
    REQUIRE_THROWS_AS(Frequency(comp, 0), std::invalid_argument);
}

TEST_CASE("Test default construction zeros", "[frequency]")
{
    Frequency zero;

    const int comp = zero.get_component();
    double incr = zero.get_increment();

    // arrays to hold exported data
    double freqs[comp];
    double amps[comp];

    zero.export_frequency(freqs, amps);

    for (int i = 0; i < comp; i++)
    {
        // check freq component according to equation
        double freq_diff = std::abs(freqs[i] - static_cast<double>(i) * incr);
        REQUIRE(freq_diff <= THRESHOLD);
        // all amps should be zero
        double amp_diff = std::abs(amps[i] - 0);
        REQUIRE(amp_diff <= THRESHOLD);
    }
}

/* Add your test cases below */