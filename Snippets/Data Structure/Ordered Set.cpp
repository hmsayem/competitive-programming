#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

int main() {
  /// Ordered Set
  typedef tree< int, null_type, less<int>, rb_tree_tag,
  tree_order_statistics_node_update> ordered_set;

  ordered_set X;
  X.insert(value);
  cout<<*X.find_by_order(index)<<endl;
  cout<<X.order_of_key(value)<<endl;  


  /// Ordered Multiset. Notice the less_equal<int> parameter.
  typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
  tree_order_statistics_node_update> ordered_multiset;

  ordered_multiset x;
  x.erase(x.find_by_order(x.order_of_key(0))); /// erasing is tricky

  // Pair <int,int> Ordered Set
  typedef tree<pair<int,int>, null_type, less_equal<pair<int,int>>, rb_tree_tag,
  tree_order_statistics_node_update> ordered_pair;

  return 0;
}
