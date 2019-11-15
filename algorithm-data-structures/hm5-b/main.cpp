#include <bits/stdc++.h>
using namespace std;

double EPS = 1e-9;


// rectangle with integer coordinates
struct rectangle_i
{
  int x_start, x_end, y;
  rectangle_i() { x_start = x_end = y = 0; }
  rectangle_i(int _x_start, int _x_end, int _y)
      : x_start(_x_start), x_end(_x_end), y(_y){}
};
//order based on y-values
bool operator<(const rectangle_i a, rectangle_i b)
{
    return a.y < b.y;
}

//display all x_values
void displayXVlaues(vector< pair< int,  rectangle_i > >  x_values)
{
  for(auto it = x_values.begin(); it != x_values.end(); it++)
  {
    cout << it->first << " (" << it->second.x_start << ", " << it->second.x_end <<", " << it->second.y  << ")" << endl;
  }
}

int main() {
  //freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int n;
  cin >> n;

  //array to store x_values along with their rectangles
  vector < pair<int, rectangle_i> > x_values;

  for(int i = 0 ; i < n ; i++)
  {
    rectangle_i rectangle;
    cin >> rectangle.x_start >> rectangle.x_end >> rectangle.y ;

    x_values.push_back( make_pair(rectangle.x_start, rectangle)) ;
    x_values.push_back( make_pair(rectangle.x_end, rectangle));
  }
  //sort all x_values
  sort(x_values.begin(), x_values.end());

  //displayXVlaues(x_values);

  long long area = 0;
  priority_queue<rectangle_i> sweep;

  for(int i = 0; i< x_values.size() ; i++)
  {
    if (sweep.empty())
    {
      sweep.push(x_values[i].second);
    }
    else
    {
      area += (x_values[i].first - x_values[i-1].first) *sweep.top().y;
      //case new rectanlge_i.
      if( x_values[i].first == x_values[i].second.x_start )
        sweep.push(x_values[i].second);
      // delete all tops that are no longer under the sweep line
      while(sweep.top().x_end <= x_values[i].first && !sweep.empty())
        sweep.pop();
    }
  }

  cout <<area;

  return 0;
}
