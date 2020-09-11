#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> pbds;

int main(){
	pbds oset;
	oset.insert(1);
	oset.insert(3);
	oset.insert(4);
	oset.insert(10);
	oset.insert(15);
	for (size_t i=0; i<oset.size(); i++)
		cout << i << " " << *oset.find_by_order(i) << endl;
	cout << oset.order_of_key(11)<<endl;
	cout << oset.order_of_key(10)<<endl;
	cout << oset.order_of_key(100)<<endl;
	int n;
	cin>>n;
	vector<int> v(n);
	for (int i=0;i<n; i++)
		cin>>v[i];
	pbds inv;
	int inv_counter=0;
	
	for (size_t i=0;i<v.size(); i++){
		inv_counter += (inv.size() - inv.order_of_key(v[i]));
		inv.insert(v[i]);
	}
	
	cout << inv_counter << endl;

	return 0;
}
