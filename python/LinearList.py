import random

class Array():
    def __init__(self,length:int):
        self.length=length
        self.nums=[0]*length

    def random_access(self)->int:
        random_index=random.randint(0,len(self.nums)-1)
        return self.nums[random_index]

    def extend(self,enlarge:int)->list[int]:
        res=[0]*(len(self.nums)+enlarge)
        for i in range(len(self.nums)):
            res[i]=self.nums[i]
        self.nums=res   

    def insert(self,num,index:int)->None:
        for i in range(self.length-1,index,-1):
            self.nums[i]=self.nums[i-1]
        self.nums[index]=num

    def remove(self,index):
        res=self.nums[index]
        for i in range(index,self.length-1):
            self.nums[i]=self.nums[i+1]
        return res
    
    def traverse(self,fun):
        for i,num in enumerate(self.nums):
            fun(i,num)

    def find(self,target):
        for i in range(self.length):
            if(self.nums[i]==target):
                return i
        return -1
    
class ListNode():
    def __init__(self,val=0) -> None:
        self.val=val
        self.next:ListNode|None=None

class LinkedList():
    def __init__(self,val=0) -> None:
        self.head=ListNode(val)

    def insert(self,node1:ListNode,node2:ListNode)->None:
        #insert node2 after node1
        node3=node1.next
        node1.next=node2
        node2.next=node3

    def remove(self,node:ListNode)->None:
        #remove the node after node
        if not node.next:
            return
        node1=node.next
        node2=node1.next
        node.next=node2

    def access(self,index:int)->ListNode|None:
        #access node on index
        current_node=self.head
        for _ in range(index):
            if not current_node:
                return None
            current_node=current_node.next
        return current_node
    
    def find(self,target)->None:
        current_node=self.head
        index=0
        while(current_node):
            if(current_node.val==target):
                return index,current_node
            current_node=current_node.next
            index+=1
        return -1,None
    
    def traverse(self,func)->None:
        print('traverse:')
        current_node=self.head
        index=0
        while(current_node):
            func(index,current_node.val)
            current_node=current_node.next
            index+=1

class List():
    def __init__(self) -> None:
        self._capacity:int=10
        self._arr:list[int]=[0]*self._capacity
        self._size:int=0
        self._extend_ratio:int=2

    def size(self)->int:
        return self._size
    
    def capacity(self)->int:
        return self._capacity
    
    def extend_capacity(self)->None:   
        self._arr+=[0]*self._capacity*(self._extend_ratio-1)
        self._capacity*=self._extend_ratio
    
    def get(self,index:int)->int:
        if(index<0 or index>=self._size):
            raise IndexError('Index exceed bound')
        return self._arr[index]
    
    def set(self,num:int,index:int)->None:
        if(index<0 or index>=self._size):
            raise IndexError('Index exceed bound')
        self._arr[index]=num

    def add(self,num:int)->None:
        if(self._size==self._capacity):
            self.extend_capacity()
        self._arr[self._size]=num
        self._size+=1

    def insert(self,num:int,index:int)->None:
        if(index<0 or index>self._size):
            raise IndexError('Index exceed bound')
        if(self._size==self._capacity):
            self.extend_capacity()
        for i in range(self._size,index,-1):
            self._arr[i]=self._arr[i-1]
        self._arr[index]=num
        self._size+=1

    def remove(self,index:int)->int:
        if(index<0 or index>=self._size):
            raise IndexError('Index exceed bound')
        res=self._arr[index]
        for i in range(index,self._size-1):
            self._arr[i]=self._arr[i+1]
        self._size-=1
        return res
    

def main():
    print('array demo')
    arr=Array(10)
    arr.traverse(print)
    for i in range(10):
        arr.insert(i,i)
    arr.traverse(print)
    print(arr.random_access())
    print(arr.remove(5))
    arr.traverse(print)
    print(arr.find(5))
    print(arr.find(6))
    print('linked list demo')
    link=LinkedList(0)
    p1=ListNode(1)
    p2=ListNode(2)
    p3=ListNode(3)
    link.traverse(print)
    link.insert(link.head,p2)
    link.traverse(print)
    link.insert(link.head,p1)
    link.traverse(print)
    link.insert(p2,p3)
    link.traverse(print)
    print(link.find(5))
    print(link.find(2))
    print(link.access(2).val)
    link.remove(p1)
    link.traverse(print)
    print('list demo')
    li=List()
    for i in range(10):
        li.insert(i,0)
    print(li._arr)
    
if __name__=='__main__':
    main()