// Probe program for the Problem 10 circuit visualizer (provided, do not edit; not graded).
// Compiled once per stage with -DSTAGE=1..4, so a later class that does not compile yet
// does not block the earlier stages.
// Output is line based, tab separated, and flushed after every line so that a crash
// still leaves everything printed so far.

#include <cmath>
#include <cstdio>
#include <functional>
#include <stdexcept>
#include <string>

#include "Node.hpp"
#include "Component.hpp"
#include "VoltageSource.hpp"
#include "CurrentSource.hpp"
#include "Resistor.hpp"

#if STAGE >= 2
#include "Network.hpp"
#endif
#if STAGE == 2 || STAGE == 4
#include "VoltageDivider.hpp"
#endif
#if STAGE == 3
#include "CurrentDivider.hpp"
#endif
#if STAGE == 4
#include "PracticalVsCircuit.hpp"
#endif

static std::string clean(const char *s)
{
    std::string out(s);
    for (std::size_t i = 0; i < out.size(); i++)
    {
        if (out[i] == '\t' || out[i] == '\n' || out[i] == '\r')
        {
            out[i] = ' ';
        }
    }
    return out;
}

// runs f and returns "ok" or "!type: message"
static std::string attempt(const std::function<void()> &f)
{
    try
    {
        f();
    }
    catch (const std::out_of_range &e)
    {
        return "!std::out_of_range: " + clean(e.what());
    }
    catch (const std::invalid_argument &e)
    {
        return "!std::invalid_argument: " + clean(e.what());
    }
    catch (const std::logic_error &e)
    {
        return "!std::logic_error: " + clean(e.what());
    }
    catch (const std::exception &e)
    {
        return "!std::exception: " + clean(e.what());
    }
    catch (...)
    {
        return "!unknown exception: (not derived from std::exception)";
    }
    return "ok";
}

// returns a number as text, or "!type: message" if f throws
static std::string val(const std::function<double()> &f)
{
    double v = 0;
    std::string r = attempt([&]()
                            { v = f(); });
    if (r != "ok")
    {
        return r;
    }
    if (std::isnan(v))
    {
        return "nan";
    }
    if (std::isinf(v))
    {
        return v > 0 ? "inf" : "-inf";
    }
    char buf[64];
    std::snprintf(buf, sizeof(buf), "%.15g", v);
    return buf;
}

// the value is computed first, so TRACE lines printed by the call never split this line
static void call(const char *label, const std::function<double()> &f)
{
    std::string v = val(f);
    std::printf("CALL\t%s\t%s\n", label, v.c_str());
    std::fflush(stdout);
}

static void act(const char *label, const std::function<void()> &f)
{
    std::string r = attempt(f);
    std::printf("DO\t%s\t%s\n", label, r.c_str());
    std::fflush(stdout);
}

static const char *kind(const Component *p)
{
    if (dynamic_cast<const VoltageSource *>(p) != nullptr)
    {
        return "V";
    }
    if (dynamic_cast<const CurrentSource *>(p) != nullptr)
    {
        return "I";
    }
    if (dynamic_cast<const Resistor *>(p) != nullptr)
    {
        return "R";
    }
    return "C";
}

static void comp_line(int idx, const Component *p, int a, int b)
{
    std::string value = val([&]()
                            { return p->get_value(); });
    std::string voltage = val([&]()
                              { return p->get_voltage(); });
    std::string current = val([&]()
                              { return p->get_current(); });
    std::printf("COMP\t%d\t%s\t%d\t%d\t%s\t%s\t%s\n", idx, kind(p), a, b, value.c_str(), voltage.c_str(), current.c_str());
    std::fflush(stdout);
}

#if STAGE >= 2
static void snapshot(const Network &n, const char *name)
{
    std::printf("SNAP\t%s\n", name);
    int nn = n.get_num_nodes();
    int nc = n.get_num_components();
    std::printf("NN\t%d\nNC\t%d\n", nn, nc);
    for (int i = 0; i < nn; i++)
    {
        std::string v = val([&]()
                            { return n.get_node_voltage(i); });
        std::printf("NODE\t%d\t%s\n", i, v.c_str());
    }
    std::fflush(stdout);
    for (int c = 0; c < nc; c++)
    {
        const Component *p = n.dbg_component(c);
        if (p == nullptr)
        {
            std::printf("COMP\t%d\tnull\n", c);
            continue;
        }
        comp_line(c, p, n.dbg_node_index(p->get_node_a()), n.dbg_node_index(p->get_node_b()));
    }
    std::printf("ENDSNAP\n");
    std::fflush(stdout);
}
#endif

int main()
{
#if STAGE == 1
    // bench test: three components across the same two nodes, node voltages set by hand
    Node n0(0.0), n1(0.0);
    VoltageSource vs(5.0, &n0, &n1); // value, terminal A, terminal B
    call("vs.get_voltage() while both nodes are at 0 V", [&]()
         { return vs.get_voltage(); });
    n1.set_voltage(5.0);
    Resistor r(1000.0, &n0, &n1);
    CurrentSource cs(0.002, &n0, &n1);
    std::printf("SNAP\tbench\nNN\t2\nNC\t3\nNODE\t0\t0\nNODE\t1\t5\n");
    comp_line(0, &vs, 0, 1);
    comp_line(1, &r, 0, 1);
    comp_line(2, &cs, 0, 1);
    std::printf("ENDSNAP\n");
    call("vs.get_voltage()", [&]()
         { return vs.get_voltage(); });
    call("r.get_current()", [&]()
         { return r.get_current(); });
    call("cs.get_current()", [&]()
         { return cs.get_current(); });
    call("cs.get_voltage()", [&]()
         { return cs.get_voltage(); });
    act("r.set_value(-5)", [&]()
        { r.set_value(-5); });
    call("r.get_value() after r.set_value(-5)", [&]()
         { return r.get_value(); });
    act("r.set_value(0)", [&]()
        { r.set_value(0); });
    act("r.get_current() with 0 ohm", [&]()
        { r.get_current(); });
    act("r.set_value(250)", [&]()
        { r.set_value(250); });
    call("r.get_current() after r.set_value(250)", [&]()
         { return r.get_current(); });
    Resistor loose;
    loose.set_value(100);
    act("get_current() on a resistor that is not connected", [&]()
        { loose.get_current(); });
    Component *base_ptr = new Resistor();
    act("Component *p = new Resistor(); p->set_value(-1)", [&]()
        { base_ptr->set_value(-1); });
    delete base_ptr;
#endif

#if STAGE == 2
    double res[3] = {1000, 2000, 3000};
    VoltageDivider *d = nullptr;
    std::printf("CTOR\tbegin\n");
    std::string r = attempt([&]()
                            { d = new VoltageDivider(9.0, res, 3); });
    std::printf("CTOR\t%s\n", r.c_str());
    std::fflush(stdout);
    if (d != nullptr)
    {
        snapshot(*d, "constructed");
        call("get_num_resistors()", [&]()
             { return d->get_num_resistors(); });
        call("get_source_voltage()", [&]()
             { return d->get_source_voltage(); });
        call("get_loop_current()", [&]()
             { return d->get_loop_current(); });
        call("get_resistance(0)", [&]()
             { return d->get_resistance(0); });
        call("get_resistance(2)", [&]()
             { return d->get_resistance(2); });
        call("get_resistor_voltage(0)", [&]()
             { return d->get_resistor_voltage(0); });
        call("get_resistor_voltage(1)", [&]()
             { return d->get_resistor_voltage(1); });
        call("get_resistor_voltage(2)", [&]()
             { return d->get_resistor_voltage(2); });
        act("set_resistance(1, 5000)", [&]()
            { d->set_resistance(1, 5000); });
        act("set_source_voltage(18)", [&]()
            { d->set_source_voltage(18); });
        snapshot(*d, "changed");
        call("get_loop_current() after the changes", [&]()
             { return d->get_loop_current(); });
        call("get_resistor_voltage(1) after the changes", [&]()
             { return d->get_resistor_voltage(1); });
        act("get_resistance(-1)", [&]()
            { d->get_resistance(-1); });
        act("get_resistance(3)", [&]()
            { d->get_resistance(3); });
        act("get_resistor_voltage(3)", [&]()
            { d->get_resistor_voltage(3); });
        act("set_resistance(3, 100)", [&]()
            { d->set_resistance(3, 100); });
        act("set_resistance(0, -1)", [&]()
            { d->set_resistance(0, -1); });
        Network *base = d;
        delete base; // through the base pointer: ~Network is virtual
    }
    act("VoltageDivider(9, res, 0)", [&]()
        { VoltageDivider bad(9.0, res, 0); });
#endif

#if STAGE == 3
    double res[3] = {1000, 2000, 2000};
    CurrentDivider *d = nullptr;
    std::printf("CTOR\tbegin\n");
    std::string r = attempt([&]()
                            { d = new CurrentDivider(0.006, res, 3); });
    std::printf("CTOR\t%s\n", r.c_str());
    std::fflush(stdout);
    if (d != nullptr)
    {
        snapshot(*d, "constructed");
        call("get_num_resistors()", [&]()
             { return d->get_num_resistors(); });
        call("get_source_current()", [&]()
             { return d->get_source_current(); });
        call("get_resistor_voltage()", [&]()
             { return d->get_resistor_voltage(); });
        call("get_resistance(1)", [&]()
             { return d->get_resistance(1); });
        call("get_resistor_current(0)", [&]()
             { return d->get_resistor_current(0); });
        call("get_resistor_current(1)", [&]()
             { return d->get_resistor_current(1); });
        call("get_resistor_current(2)", [&]()
             { return d->get_resistor_current(2); });
        act("set_resistance(2, 1000)", [&]()
            { d->set_resistance(2, 1000); });
        act("set_source_current(0.01)", [&]()
            { d->set_source_current(0.01); });
        snapshot(*d, "changed");
        call("get_resistor_voltage() after the changes", [&]()
             { return d->get_resistor_voltage(); });
        call("get_resistor_current(2) after the changes", [&]()
             { return d->get_resistor_current(2); });
        act("get_resistance(-1)", [&]()
            { d->get_resistance(-1); });
        act("get_resistance(3)", [&]()
            { d->get_resistance(3); });
        act("get_resistor_current(3)", [&]()
            { d->get_resistor_current(3); });
        act("set_resistance(3, 100)", [&]()
            { d->set_resistance(3, 100); });
        act("set_resistance(0, -1)", [&]()
            { d->set_resistance(0, -1); });
        Network *base = d;
        delete base;
    }
    act("CurrentDivider(0.006, res, 0)", [&]()
        { CurrentDivider bad(0.006, res, 0); });
#endif

#if STAGE == 4
    PracticalVsCircuit *p = nullptr;
    std::printf("CTOR\tbegin\n");
    std::string r = attempt([&]()
                            { p = new PracticalVsCircuit(12.0, 1000.0, 2000.0); });
    std::printf("CTOR\t%s\n", r.c_str());
    std::fflush(stdout);
    if (p != nullptr)
    {
        snapshot(*p, "constructed");
        VoltageDivider *as_divider = p;
        call("get_source_voltage()", [&]()
             { return p->get_source_voltage(); });
        call("get_source_voltage() through a VoltageDivider *", [&]()
             { return as_divider->get_source_voltage(); });
        call("ptr->VoltageDivider::get_source_voltage()", [&]()
             { return as_divider->VoltageDivider::get_source_voltage(); });
        call("get_load_power()", [&]()
             { return p->get_load_power(); });
        act("set_load(3000)", [&]()
            { p->set_load(3000); });
        call("get_source_voltage() after set_load(3000)", [&]()
             { return p->get_source_voltage(); });
        call("get_load_power() after set_load(3000)", [&]()
             { return p->get_load_power(); });
        call("maximum_power_transfer(900)", [&]()
             { return p->maximum_power_transfer(900) ? 1.0 : 0.0; });
        call("maximum_power_transfer(1000)", [&]()
             { return p->maximum_power_transfer(1000) ? 1.0 : 0.0; });
        snapshot(*p, "matched");
        call("get_load_power() with the matched load", [&]()
             { return p->get_load_power(); });
        act("set_load(-100)", [&]()
            { p->set_load(-100); });
        act("maximum_power_transfer(-100)", [&]()
            { p->maximum_power_transfer(-100); });
        Network *base = p;
        delete base;
    }
    act("PracticalVsCircuit(12, -1000, 2000)", [&]()
        { PracticalVsCircuit bad(12.0, -1000.0, 2000.0); });
    act("PracticalVsCircuit(12, 1000, -100)", [&]()
        { PracticalVsCircuit bad(12.0, 1000.0, -100.0); });
#endif
    std::printf("DONE\n");
    return 0;
}