#include <iostream>
#include <vector>
long long a, n, m, x, t;
//a-first stop; t-second stop get on; m-final stop; x- stop wanted
std::vector<std::vector<long long>> bus_change;

std::vector<long long> add(std::vector<long long> a, std::vector<long long> b) {
    a[0] += b[0];
    a[1] += b[1];
    return a;
};

int main(){
    std::cin >> a >> n >> m >> x;
    if (n == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }
    else if (n == 2) {
        std::cout << a << std::endl;
        return 0;
    }
    else if (n == 3) {
        if (a != m) return -1;
        if (x == 3) std::cout << 0 << std::endl;
        if (x == 2 || x == 1) std::cout << a << std::endl;
        return 0;
    };
    std::vector<std::vector<long long>> mid(n, std::vector<long long>(2, 0));
    bus_change = mid;
    bus_change[0] = { 1,0 };
    bus_change[1] = { 0,1 };
    for (int i = 2; i != n; ++i) {
        bus_change[i] = add(bus_change[i - 1], bus_change[i - 2]);
    };
    std::vector<long long> m_vec = { 0, 0 };
    for (int i = 0; i != (n - 3); ++i) {
        m_vec = add(m_vec, bus_change[i]);
    };
    m_vec = add(m_vec, bus_change[0]);
    t = (m - m_vec[0] * a) / m_vec[1];
    m_vec = { 0, 0 };
    for (int i = 0; i != (x-2); ++i) {/////////////////////////////////////////////////////////x+1/x-1
        m_vec = add(m_vec, bus_change[i]);
    };
    m_vec = add(m_vec, bus_change[0]);
    std::cout << (m_vec[0] * a + m_vec[1] * t) << std::endl;

    return 0;
}

