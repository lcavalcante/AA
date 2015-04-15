//Lucas
#include <iostream>
#include <cstdio>
#include <sstream>
#include <utility>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iterator>
#include <math.h>
#include <queue>
#include <map>
#include <new>
#include <set>
#include <stack>

#define NUM 700
#define MAXINT 2147483647

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct node
{
        int numleaves, add, sum;
        void split(node& l, node& r)
        {
                l.add += add;
                l.sum += add * l.numleaves;
                r.add += add;
                r.sum += add * r.numleaves;
                add = 0;
        }
        void merge(node& l, node& r)
        {
                numleaves = l.numleaves + r.numleaves;
                add = 0;
                sum = l.sum + r.sum;
        }
};
void update_single_subtree(node& n, int inc){
        n.add += inc;
        n.sum += inc * n.numleaves;
}
