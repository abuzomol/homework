#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> adjlist;
typedef vector<pair<int, ii>> edgelist;
typedef long long ll;
typedef vector<ll> vll;
#define MA(a, b) ((a) > (b) ? (a) : (b))
#define MI(a, b) ((a) < (b) ? (a) : (b))
#define AB(a) (-(a) < (a) ? (a) : -(a))
#define na(x) ((x) < P ? (x) : (x)-P)

#define all(c) (c).begin(), (c).end()
#define tr(c, i) \
  for (decltype((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define rtr(c, i) \
  for (decltype((c).rbegin()) i = (c).rbegin(); i != (c).rend(); i++)
#define pb push_back
#define mp make_pair

double EPS = 1e-9;

struct point_i
{
  int x, y;
  // constructors
  point_i() { x = y = 0; }
  point_i(int _x, int _y) : x(_x), y(_y) {}
  // sort lexicographically by x coordinates, first and then by y-coordinate
  bool operator<(point_i other) const
  {
    if (x != other.x)
      return (x < other.x);
    else
      return y < other.y;
  }
};

// More precise point location.
struct point
{
  double x, y;
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}

  bool operator<(point other) const
  {
    if (fabs(x - other.x) > EPS)
      return x < other.x;
    else
      return y < other.y;
  }
  bool operator==(point other)
  {
    return (fabs(x - other.x < EPS)) && (fabs(y - other.y) < EPS);
  }
};

double dist(point p, point q) { return hypot(p.x - q.x, p.y - q.y); }

double DEG_to_RAD(double theta);

double rotate(point p, double theta) { double rad = DEG_to_RAD(theta); }

double DEG_to_RAD(double theta)
{
  double pi = 3.14159265358979323846;
  return theta * pi / 180;
}

// rectangle with integer coordinates
struct rectangle_i
{
  int x_start, x_end, y;
  rectangle_i() { x_start = x_end = y = 0; }
  rectangle_i(int _x_start, int _x_end, int _y)
      : x_start(_x_start), x_end(_x_end), y(_y)
  {
  }

  bool operator<(rectangle_i other) { return x_start < other.x_start; }
};
// compare based on x_end
bool compareRectangle(rectangle_i a, rectangle_i b)
{
  return a.x_end < b.x_end;
}

bool intersects(rectangle_i a, rectangle_i b) { return a.x_end > b.x_start; }

bool contains(rectangle_i a, rectangle_i b)
{
  return (a.x_start <= b.x_start) && (a.x_end >= b.x_end);
}

void display(vector<rectangle_i>& A)
{
  tr(A, it) cout << (*it).x_start << " " << (*it).x_end << " " << (*it).y
                 << endl;
}

/*ll silhouette(vector<rectangle_i> &L )
{
    sort(all(L)); // sort by x_start
    //make a copy of L
    vector< rectangle_i> LL;
    tr(L, it)
        LL.pb(*it);
    //sort by x_end
    sort(all(LL), compare);

    //create a map for y values. Act like static priority queue for y values but
changes the key records. map< int, vector<rectangle_i> > rec_map; for(int i = 0;
i< L.size(); i++)
    {
        auto it = rec_map.find(L[i].y);
        //check if y values already in map
        if (it != rec_map.end()) {
            auto it_lower = lower_bound(all(rec_map[L[i].y] ) , L[i].x_start );

            int x_start = L[i].x_start;
            int x_end = L[i].x_end;
            //case 1: pred intersects with new rectangle, change initial start
            if ( it_lower->x_end  > L[i].x_start )
            {
                x_start = it_lower-> x_start;
            }
            //case 2: segments intersects with next rectangles
            auto it_upper = lower_bound(all(rec_map[L[i].y] ) , L[i].x_start );

           // rec_map[L[i].y].pb(L[i]);
        }
        //case y is not yet in the map
        else {
            pair<int, vector<rectangle_i>> t;
            t.first = L[i].y;
            t.second.pb(L[i]);
            rec_map.insert(t);
        }
    }

    *//*map< int , int > sweep;
    for (auto it = rec_map.rbegin(); it < rec_map.rend() ; it++)
    {

    }*//*
    //return ll(0);*/
//}

struct interval
{
  int x_start;
  int x_end;

  interval() : x_start(0), x_end() {}
  interval(int start, int end) : x_start(start), x_end(end) {}

  // order by x_start
  bool operator<(const interval& other) { return x_start <= other.x_start; }
};
// displayInterval
void displayInterval(vector<interval>& A)
{
  tr(A, it) cout << it->x_start << " " << it->x_end << endl;
}
// order by x_end
bool compareInterval(interval& x, interval& y) { return x.x_end <= y.x_end; }

// interval x intersects y. No containment
bool intersects(interval& x, interval& y)
{
  bool in1 = x.x_start < y.x_end < x.x_end;
  bool in2 = y.x_start < x.x_end < y.x_end;

  bool in3 = x.x_start < y.x_start < x.x_end;
  bool in4 = y.x_start < x.x_start < y.x_end;

  return in1 || in2 || in3 || in4;
}
// does x contains y?
bool contains(interval& x, interval& y)
{
  return x.x_start <= y.x_start <= y.x_end <= x.x_end;
}
void displayMap(map<int, pair<vector<interval>, vector<interval>>>& rec_map)
{
  tr(rec_map, itt)
  {
    cout << itt->first << " " << endl;
    cout << "x_start" << endl;
    displayInterval(itt->second.first);
    cout << "x_end" << endl;
    displayInterval(itt->second.second);
    cout << "-------------------" << endl;
  }
}
int main()
{
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  int n;
  cin >> n;

  map<int, pair<vector<interval>, vector<interval>>> rec_map;
  int y;

  for (int i = 0; i < n; ++i)
  {
    interval t;
    cin >> t.x_start >> t.x_end >> y;

    auto it = rec_map.find(y);

    if (it == rec_map.end())  // case y is not in map yet
    {
      vector<interval> temp, tempp;
      temp.pb(t);
      tempp.pb(t);  // copy of temp
      rec_map.insert(mp(y, mp(temp, tempp)));
    }
    else
    {  // case y is already in the map
      rec_map[y].first.pb(t);
      rec_map[y].second.pb(t);
    }
  }
  tr(rec_map, itt)
  {
    sort(all(itt->second.first));                    // order by x_start
    sort(all(itt->second.second), compareInterval);  // order by y_start
  }

  displayMap(rec_map);

  // Sweep from y max top to least bottom
  ll area = 0;
  vector<interval> current;

  // sweep from above; sweep from last element in the map
  rtr(rec_map, itt)
  {
    int y = itt->first;
    vector<interval> y_intervals = itt->second.first;

    for (int i = 0; i < y_intervals.size(); i++)
    {
      auto lower = lower_bound(all(current), y_intervals[i]);
      if (lower == current.end())
      {
        current.push_back(y_intervals[i]);
      }
      else
      {
        int xIntervalStart, xIntervalEnd;
        if (contains( y_intervals[i],*lower))
        {
          xIntervalEnd = lower->x_start;
          xIntervalStart = lower->x_end;
          //compute the area of difference regions of bigger interval y_interval[i]
          area += (xIntervalEnd - y_intervals[i].x_start )*y;
          area += (y_intervals[i].x_end - xIntervalStart )*y;
        }
      }
    }
  }
  cout <<"area:" <<area;

  return 0;
}
