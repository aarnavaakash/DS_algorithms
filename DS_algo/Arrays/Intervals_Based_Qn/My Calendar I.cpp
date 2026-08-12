typedef pair<int, int> P;
class MyCalendar {
public:

    vector<P> calendar;
    MyCalendar() {

    }

    bool book(int start, int end) {
        for(int i = 0; i<calendar.size(); i++) {
            P curr = calendar[i];
            if(!(end <= curr.first || start >= curr.second))
                return false;
        }

        calendar.push_back({start, end});
        return true;
    }
};

class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {

    }

    bool book(int start, int end) {

        auto it = st.lower_bound({start, end});

        if(it != st.end() && it->first < end) {
            return false;
        }

        if(it != st.begin()) {
            auto prevIt = prev(it);
            if(start < prevIt->second) {
                return false;
            }
        }

        st.insert({start, end});
        return true;
    }
};

class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {

    }

    bool book(int start, int end) {
        auto it = st.upper_bound({start, end});

        if(it != st.end() && end > it->second) {

            return false;

        }

        st.insert({end, start});
        return true;
    }
};

class MyCalendar {

    List<int[]> calendar;

    public MyCalendar() {

        calendar = new ArrayList<>();
    }

    public boolean book(int start, int end) {

        for (int[] curr : calendar) {

            if (!(end <= curr[0] || start >= curr[1])) {
                return false;
            }
        }

        calendar.add(new int[]{start, end});
        return true;
    }
}

class MyCalendar {

    TreeSet<int[]> st;

    public MyCalendar() {

        st = new TreeSet<>((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
    }

    public boolean book(int start, int end) {

        int[] event = new int[]{start, end};
        int[] next = st.ceiling(event);

        if (next != null && next[0] < end) {
            return false;
        }

        int[] prev = st.floor(event);
        if (prev != null && start < prev[1]) {
            return false;
        }

        st.add(new int[]{start, end});
        return true;
    }
}

class MyCalendar {

    TreeSet<int[]> st;

    public MyCalendar() {

        st = new TreeSet<>((a, b) -> a[1] != b[1] ? a[1] - b[1] : a[0] - b[0]);
    }

    public boolean book(int start, int end) {

        int[] event = new int[]{end, start};
        int[] next = st.ceiling(event);

        if (next != null && next[1] < end) {
            return false;
        }

        st.add(new int[]{end, start});
        return true;
    }
}
