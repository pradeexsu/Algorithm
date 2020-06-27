#include<iostream>
#include<vector>
using namespace std;
void subseq(string s, vector<string> &v, string outs = ""){
	if(!s.length()){
		v.push_back(outs);
		return;
	}
	subseq(s.substr(1), v, outs);
	subseq(s.substr(1), v, outs + s[0]);

}

void subseq2(string s, vector<string> &v, string outs = ""){
	if(!s.length()){
		v.push_back(outs);
		return;
	}
	subseq(s.substr(1), v, outs + s[0]);
	subseq(s.substr(1), v, outs);

}

void permute(vector<char> &v, int i){
	if(i==v.size()){
		for(int k=0;k<v.size();k++)
			printf("%c ",v[k]);
		printf("\n");
		return;
	}
	for (int k = i; k < v.size(); ++k)
	{
		if(i!=k && v[i]==v[k])
			continue;
		swap(v[i], v[k]);
		permute(v,i+1);
		swap(v[i],v[k]);
	}
	return;

}

void permutation(char *in, int i){
		// Base Case
		if(in[i]=='\0'){
			cout<<in<<endl;
			return ;
		}
		//Recursive Case...
		for(int j=i;in[j];j++){
			swap(in[i], in[j]);
			permutation(in, i+1);
			swap(in[i], in[j]);
		}
}
	
int main(){
	//char in[100];
	// std::vector<int> v ={1,2,3};
	//cin>>in;
	// for(int i:v){
		// cout<<i<<" ";
	// }
	// cout<<"\n";
	std::vector<char> v{'A','C','C'};
	// subseq("ABC",v);
	permute(v, 0);
	// for(auto i:v)
		// cout<<i<<"\n";
	// permute(v,0);
	// for(int i:v){
	// 	cout<<i<<" ";
	// }
//	permutation(in, 0);
	return 0;
}
