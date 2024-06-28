import heapq

class MaxHeap():
    def __init__(self,nums:list[int]):
        self.heap=nums
        for i in range(self.parent(self.size()-1),-1,-1):
            self.sift_down(i)

    def left(self,i:int)->int:
        return 2*i+1
    
    def right(self,i:int)->int:
        return 2*i+2
    
    def parent(self,i:int)->int:
        return (i-1)//2
    
    def swap(self,i:int,j:int):
        self.heap[i],self.heap[j]=self.heap[j],self.heap[i]

    def size(self)->int:
        return len(self.heap)
    
    def is_empty(self)->bool:
        return self.size()==0
    
    def peek(self)->int:
        return self.heap[0]

    def sift_down(self,i:int):
        while True:
            left,right,max_node=self.left(i),self.right(i),i
            if left<self.size() and self.heap[left]>self.heap[i]:
                max_node=left
            if right<self.size() and self.heap[right]>self.heap[i]:
                max_node=right
            if max_node==i:
                break
            self.swap(i,max_node)
            i=max_node

    def sift_up(self,i:int):
        while True:
            parent_index=self.parent(i)
            if parent_index<0 or self.heap[i]<=self.heap[parent_index]:
                break
            self.swap(i,parent_index)
            i=parent_index

    def push(self,val:int):
        self.heap.append(val)
        self.sift_up(self.size()-1)

    def pop(self)->int:
        if self.is_empty():
            raise IndexError('Empty Heap')
        self.swap(0,self.size()-1)
        res=self.heap.pop()
        self.sift_down(0)
        return res
    
    def print(self):
        print(self.heap)

class MinHeap(MaxHeap):
    def __init__(self, nums: list[int]):
        self.heap=nums
        for i in range(self.parent(self.size()-1),-1,-1):
            self.sift_down(i)

    def sift_down(self,i:int):
        while True:
            left,right,min_node=self.left(i),self.right(i),i
            if left<self.size() and self.heap[left]<self.heap[i]:
                min_node=left
            if right<self.size() and self.heap[right]<self.heap[i]:
                min_node=right
            if min_node==i:
                break
            self.swap(i,min_node)
            i=min_node

    def sift_up(self,i:int):
        while True:
            parent_index=self.parent(i)
            if parent_index<0 or self.heap[i]>=self.heap[parent_index]:
                break
            self.swap(i,parent_index)
            i=parent_index

def min_k_heap(nums:list[int],k:int)->list[int]:
    heap=MaxHeap([])
    for i in range(k):
        heap.push(nums[i])
    for i in range(k,len(nums)):
        if nums[i]<heap.peek():
            heap.pop()
            heap.push(nums[i])
    return heap.heap

def top_k_heap(nums: list[int], k: int) -> list[int]:
    """基于堆查找数组中最大的 k 个元素"""
    # 初始化小顶堆
    heap = []
    # 将数组的前 k 个元素入堆
    for i in range(k):
        heapq.heappush(heap, nums[i])
    # 从第 k+1 个元素开始，保持堆的长度为 k
    for i in range(k, len(nums)):
        # 若当前元素大于堆顶元素，则将堆顶元素出堆、当前元素入堆
        if nums[i] > heap[0]:
            heapq.heappop(heap)
            heapq.heappush(heap, nums[i])
    return heap
 

def main():
    max_heap=MaxHeap([9, 8, 6, 6, 7, 5, 2, 1, 4, 3, 6, 2])
    max_heap.print()
    max_heap.push(7)
    max_heap.print()
    max_heap.pop()
    max_heap.print()
    print(top_k_heap([9, 8, 6, 6, 7, 5, 2, 1, 4, 3, 6, 2],5))
    print('----------')
    min_heap=MinHeap([9, 8, 6, 6, 7, 5, 2, 1, 4, 3, 6, 2])
    min_heap.print()
    min_heap.push(7)
    min_heap.print()
    min_heap.pop()
    min_heap.print()

if __name__=='__main__':
    main()
