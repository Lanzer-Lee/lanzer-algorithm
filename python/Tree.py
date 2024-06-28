from collections import deque

class TreeNode():
    def __init__(self, val: int = 0):
        self.val: int = val  
        self.height: int = 0  
        self.left: TreeNode | None = None  
        self.right: TreeNode | None = None  

class BinaryTree():
    def __init__(self,root:TreeNode|None) -> None:
        self.root=root

    def level_order(self)->list[int]:
        queue=deque()
        queue.append(self.root)
        res=[]
        while queue:
            node:TreeNode=queue.popleft()
            res.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        return res
    
    def pre_order(self,node:TreeNode|None,res:list[int]):
        if node is None:
            return 
        res.append(node.val)
        self.pre_order(node.left,res)
        self.pre_order(node.right,res)

    def in_order(self,node:TreeNode|None,res:list[int]):
        if node is None:
            return
        self.in_order(node.left,res)
        res.append(node.val)
        self.in_order(node.right,res)

    def post_order(self,node:TreeNode|None,res:list[int]):
        if node is None:
            return
        self.post_order(node.left,res)
        self.post_order(node.right,res)
        res.append(node.val)

    def list_to_tree_dfs(self,arr:list[int],i:int)->TreeNode|None:
        if i<0 or i>=len(arr) or arr[i] is None:
            return None
        node=TreeNode(arr[i])
        node.left=self.list_to_tree_dfs(arr,2*i+1)
        node.right=self.list_to_tree_dfs(arr,2*i+2)
        return node
    
    def list_to_tree(self,arr:list[int])->TreeNode|None:
        self.root=self.list_to_tree_dfs(arr,0)

class ArrayBinaryTree():
    def __init__(self,arr:list[int|None]) -> None:
        self.tree=list(arr)

    def size(self):
        return len(self.tree)
    
    def val(self,i:int)->int|None:
        if i<0 or i>=self.size():
            return None
        return self.tree[i]
    
    def left(self,i:int)->int|None:
        return 2*i+1
    
    def right(self,i:int)->int|None:
        return 2*i+2
    
    def parent(self,i:int)->int|None:
        return (i-1)//2
    
    def level_order(self)->list[int]:
        self.res=[]
        for i in range(self.size()):
            if self.val(i) is not None:
                self.res.append(self.val(i))
        return self.res
    
    def dfs(self,i:int,order:str):
        if self.val(i) is None:
            return
        if order=='pre':
            self.res.append(self.val(i))
        self.dfs(self.left(i),order)
        if order=='in':
            self.res.append(self.val(i))
        self.dfs(self.right(i),order)
        if order=='post':
            self.res.append(self.val(i))

    def pre_order(self)->list[int]:
        self.res=[]
        self.dfs(0,order='pre')
        return self.res
    
    def in_order(self)->list[int]:
        self.res=[]
        self.dfs(0,order='in')
        return self.res
    
    def post_order(self)->list[int]:
        self.res=[]
        self.dfs(0,order='post')
        return self.res
    
class BinarySearchTree(BinaryTree):
    def __init__(self, root: TreeNode | None = None) -> None:
        super().__init__(root)

    def get_root(self)->TreeNode|None:
        return self.root
    
    def search(self,target:int)->TreeNode|None:
        node=self.root
        while node is not None:
            if node.val<target:
                node=node.right
            elif node.val>target:
                node=node.left
            else:
                break
        return node
    
    def insert(self,num:int):
        if self.root is None:
            self.root=TreeNode(num)
            return
        node=self.root
        pre_node=None
        while node is not None:
            if node.val==num:
                return
            pre_node=node
            if(node.val<num):
                node=node.right
            else:
                node=node.left
        node=TreeNode(num)
        if pre_node.val<num:
            pre_node.right=node
        else:
            pre_node.left=node

    def remove(self,num:int):
        if self.root is None:
            return
        node,pre_node=self.root,None
        while node is not None:
            if node.val==num:
                break
            pre_node=node
            if node.val<num:
                node=node.right
            else:
                node=node.left
        if node is None:
            return
        if node.left is None or node.right is None:
            child=node.left or node.right
            if node!=self.root:
                if pre_node.left==node:
                    pre_node.left=child
                else:
                    pre_node.right=child
            else:
                self.root=child
        else:
            temp:TreeNode=node.right
            while temp.left is not None:
                temp=temp.left
            self.remove(temp.val)
            node.val=temp.val

class AVLTree(BinaryTree):
    def __init__(self, root: TreeNode | None=None) -> None:
        super().__init__(root)

    def get_root(self)->TreeNode|None:
        return self.root

    def height(self,node:TreeNode|None)->int:
        if node is not None:
            return node.height
        return -1

    def update_height(self,node:TreeNode|None):
        node.height=max([self.height(node.left),self.height(node.right)])+1

    def balance_factor(self,node:TreeNode|None)->int:
        if node is None:
            return 0
        return self.height(node.left)-self.height(node.right)

    def right_rotate(self,node:TreeNode|None)->TreeNode|None:
        pass

    def left_rotate(self,node:TreeNode|None)->TreeNode|None:
        pass

    def rotate(self,node:TreeNode|None)->TreeNode|None:
        pass

    def insert(self,val:int):
        pass

    def insert_helper(self,node:TreeNode|None,val:int)->TreeNode|None:
        pass

    def remove(self,val:int):
        pass

    def remove_helper(self,node:TreeNode|None,val:int)->TreeNode|None:
        pass

    def search(self,val:int)->TreeNode|None:
        pass

def main():
    root=TreeNode()
    tree=BinaryTree(root)
    tree.list_to_tree([1, 2, 3, 4, 5, 6, 7])

    res=tree.level_order()
    print(res)

    res.clear()
    tree.pre_order(tree.root,res)
    print(res)

    res.clear()
    tree.in_order(tree.root,res)
    print(res)

    res.clear()
    tree.post_order(tree.root,res)
    print(res)

    atree=ArrayBinaryTree([1, 2, 3, 4, 5, 6, 7])
    print('-------')

    res=atree.level_order()
    print(res)

    res.clear()
    res=atree.pre_order()
    print(res)

    res.clear()
    res=atree.in_order()
    print(res)

    res.clear()
    res=atree.post_order()
    print(res)

    print('----------')
    bst=BinarySearchTree()
    nums= [8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15]
    for num in nums:
        bst.insert(num)

    res.clear()
    res=bst.level_order()
    print(res)

if __name__=='__main__':
    main()


    


