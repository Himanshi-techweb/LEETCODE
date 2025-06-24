class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n=arr.size();
        vector<int> in(n,1);
        vector<int> de(n,1);
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[i]>arr[prev] && in[i]<1+in[prev]){
                    in[i]=1+in[prev];
                }
            }
        }
        
        for(int i=n-2;i>=0;i--)//Implementing the algorithm to find temp2[i].
	{
		for(int j=n-1;j>i;j--)
		{
			if(arr[i]>arr[j])
				de[i]=max(de[i],de[j]+1);
		}
	}
        int maxi=0;int cnt1=0;int cnt2=0;
        for(int i=0;i<n;i++){
            if(in[i]==1 || de[i]==1)continue;
           maxi=max(maxi,in[i]+de[i]-1); 
        }
        return n-maxi;
    }
};