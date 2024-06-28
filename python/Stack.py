from LinearList import ListNode

class Stack():
    def __init__(self) -> None:
        self.stack=[]
        self.top=-1

    def Push(self,num):
        self.stack.append(num)
        self.top+=1

    def Pop(self):
        self.top-=1
        return self.stack.pop()
    
    def top(self):
        return self.stack[-1]
    
    def length(self):
        return self.top+1
    
    def is_empty(self):
        return self.top==-1
    
class LinkedListStack():
    def __init__(self) -> None:
        self._top=None
        self._size=0

    def length(self):
        return self._size
    
    def is_empty(self):
        return self._size==0
    
    def push(self,val):
        node=ListNode(val)
        node.next=self._top
        self._top=node
        self._size+=1

    def pop(self):
        res=self._top.val
        self._top=self._top.next
        self._size-=1
        return res
    
    def top(self):
        if(self.is_empty()):
            raise IndexError('Stack Empty')
        return self._top.val
    
    def to_list(self):
        arr=[]
        node=self._top
        while(node):
            arr.append(node.val)
            node=node.next
        arr.reverse()
        return arr

class ArrayStack():
    def __init__(self):
        self._stack=[]
    
    def size(self):
        return len(self._stack)
    
    def is_empty(self):
        return self.size()==0
    
    def push(self,num):
        self._stack.append(num)

    def pop(self):
        if(self.is_empty()):
            raise IndexError('Stack has been empty')
        return self._stack.pop()
    
    def top(self):
        if(self.is_empty()):
            raise IndexError('Stack has been empty')
        return self._stack[-1]

def main():
    print('stack demo')
    stack=Stack()
    for i in range(10):
        stack.Push(i)
        print(stack.stack)
    for i in range(10):
        stack.Pop()
        print(stack.stack)
    print('linked list demo')
    stack=LinkedListStack()
    for i in range(10):
        stack.push(i)
        print(stack.to_list())
    for i in range(10):
        stack.pop()
        print(stack.to_list())


if __name__=='__main__':
    main()