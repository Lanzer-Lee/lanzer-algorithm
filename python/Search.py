class Search():
    def __init__(self) -> None:
        pass

    def linear_search(self,nums:list[int],target:int)->int:
        for i in range(len(nums)):
            if nums[i]==target:
                return i
        return -1

    def binary_search(self,nums:list[int],target:int)->int:
        i,j=0,len(nums)-1
        while i<=j:
            m=(i+j)//2
            if nums[m]<target:
                i=m+1
            elif nums[m]>target:
                j=m-1
            else:
                return m
        return -1
    
    def binary_search_lcro(self,nums:list[int],target:int)->int:
        i,j=0,len(nums)
        while i<j:
            m=(i+j)//2
            if nums[m]<target:
                i=m+1
            elif nums[m]>target:
                j=m
            else:
                return m
        return -1
    
    def binary_search_insertion_simple(self,nums:list[int],target:int)->int:
        i,j=0,len(nums)-1
        while i<=j:
            m=(i+j)//2
            if nums[m]<target:
                i=m+1
            elif nums[m]>target:
                j=m-1
            else:
                return m
        return i
    
    def binary_search_insertion(self,nums:list[int],target:int)->int:
        i,j=0,len(nums)-1
        while i<=j:
            m=(i+j)//2
            if nums[m]<target:
                i=m+1
            elif nums[m]>target:
                j=m-1
            else:
                j=m-1
        return i
    
    def binary_search_left_edge(self,nums:list[int],target:int)->int:
        i=self.binary_search_insertion(nums,target)
        if i==len(nums) or nums[i]!=target:
            return -1
        return i
    
    def binary_search_right_edge(self,nums:list[int],target:int)->int:
        i=self.binary_search_insertion(nums,target+1)
        j=i-1
        if j==-1 or nums[j]!=target:
            return -1
        return j
    
    def hash_search(self,nums:list[int],target:int)->int:
        hash_map=dict[int,int]()
        for i in range(len(nums)):
            hash_map[nums[i]]=i
        return hash_map.get(target,-1)
    
    def two_sum_brute(self,nums:list[int],target:int)->list[int]:
        for i in range(len(nums)-1):
            for j in range(i+1,len(nums)):
                if nums[i]+nums[j]==target:
                    return [i,j]
        return []
    
    def two_sum_hash(self,nums:list[int],target:int)->list[int]:
        dictionary={}
        for i in range(len(nums)):
            if target-nums[i] in dictionary:
                return [dictionary[target-nums[i]],i]
            dictionary[nums[i]]=i
        return []
    
def main():
    search=Search()
    target=6
    nums=[1, 3, 6, 8, 12, 15, 23, 26, 31, 35]
    target2=5
    nums2=[1, 3, 6, 6, 6, 6, 6, 10, 12, 15]
    print(search.linear_search(nums,target))
    print(search.binary_search(nums,target))
    print(search.binary_search_lcro(nums,target))
    print(search.binary_search_insertion_simple(nums2,target2))
    print(search.binary_search_insertion(nums2,target2))
    print(search.binary_search_left_edge(nums2,target))
    print(search.binary_search_right_edge(nums2,target))
    print(search.hash_search(nums2,target))
    print(search.two_sum_brute(nums,27))
    print(search.two_sum_hash(nums,27))

if __name__=='__main__':
    main()

    
