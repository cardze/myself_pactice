#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int GCD(int t, int v)
{
  if (t % v == 0)
  {
    return v;
  }

  else

    return GCD(v, t % v);
}

int next_bigger_factor(int smaller_one, int target)
{
  for (int i = smaller_one + 1; i < target; i++)
  {
    if (target % i == 0)
    {
      printf("debug : %d\n", i);
      return i;
    }
  }
  return target;
}

int main()
{
  int num_input = 0;
  cin >> num_input;
  for (int i = 0; i < num_input; i++)
  {
    int target_x, target_y;
    cin >> target_x >> target_y;
    int steps = 1e9;
    for(int i=1; i<=1e5 ; i++){
      steps = min(steps, (target_x+i-1)/i + (target_y+i-1)/i + i-1);
    }
    cout<<steps<<endl;

    // deal small one first
    // long long int m = 1, pre_m = 1;
    // long long int steps = 0;
    // m = GCD(target_x, target_y);
    // steps += (m - pre_m);
    // pre_m = m;
    // steps += (target_x / m);
    // than deal the bigger one
    // while (target_y / m > (next_bigger_factor(m, target_y) - m) + target_y / next_bigger_factor(m, target_y))
    // {
    //   steps += (next_bigger_factor(m, target_y) - m);
    //   m = next_bigger_factor(m, target_y);
    // }
    // steps += target_y / m;
    // printf("%d\n", steps);
  }

  return 0;
}