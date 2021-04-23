#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
 
template <typename T, typename Comparator = less<T>>
using super_set = tree<T, null_type, Comparator, rb_tree_tag,
                       tree_order_statistics_node_update>;
 
// order_of_key(T x)
// -> returns the number of elements strictly smaller than x

// find_by_order(size_t i) 
// -> returns iterator to i-th largest element (counting from 0)