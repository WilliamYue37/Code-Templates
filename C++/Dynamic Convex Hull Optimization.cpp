struct Sol {
    int m;
    ll b;

    ll compute(int x) const {
        return (ll)m * x + b;
    }

    ld intersect(Sol r) const {
        return (ld)(this->b - r.b)/(r.m - this->m);
    }

    bool operator<(const Sol& other) const {
        return this->m < other.m;
    }
};

class CHT {
public:
    multiset<Sol> hull;

    void insert(Sol part, int x = 0) {
        auto same = hull.lower_bound(part);
        if (same != hull.end() && same->m == part.m) {
            if (same->compute(x) >= part.compute(x)) return;
            hull.erase(same);
        }

        auto above = hull.upper_bound(part);
        auto below = hull.lower_bound(part);
        if (above != hull.end() && below != hull.begin() && (--below)->intersect(part) >= part.intersect(*above)) return;

        while (true) {
            auto up1 = hull.upper_bound(part);
            if (up1 == hull.end()) break;
            auto up2 = hull.upper_bound(*up1);
            if (up2 == hull.end()) break;

            ll t1 = part.intersect(*up1);
            ll t2 = up1->intersect(*up2);

            if (t1 < t2) break;

            hull.erase(up1);
        }

        while (true) {
            auto lo1 = hull.lower_bound(part);
            if (lo1 == hull.begin()) break; --lo1;
            auto lo2 = hull.lower_bound(*lo1);
            if (lo2 == hull.begin()) break; --lo2;

            ll t1 = lo2->intersect(*lo1);
            ll t2 = lo1->intersect(part);

            if (t1 < t2) break;

            hull.erase(lo1);
        }

        hull.insert(part);
    }

    ll query(int x) {
        while (hull.size() >= 2) {
            Sol f = *hull.begin();
            Sol s = *hull.upper_bound(f);
            if (f.compute(x) > s.compute(x)) break;
            hull.erase(hull.begin());
        }
        if (hull.size() > 0) return hull.begin()->compute(x);
        else return -1;
    }
};
