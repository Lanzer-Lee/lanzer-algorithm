class Basic():
    n=0
    res=0

    #iteration by for loop
    def for_loop(self,n)->int:
        self.n=n
        self.res=0
        for i in range(1,self.n+1):
            self.res+=i
        return self.res

    #iteration by while loop
    def while_loop(self,n)->int:
        self.n=n
        self.res=0
        i=1
        while i<=self.n:
            self.res+=i
            i+=1
        return self.res

    def while_loop_ii(self,n)->int:
        self.n=n
        self.res=0
        i=1
        while(i<=self.n):
            self.res+=i
            i+=1
            i*=2
        return self.res

    #nest
    def nested_for_loop(self,n)->str:
        self.n=n
        self.res=""
        for i in range(1,self.n+1):
            for j in range(1,self.n+1):
                self.res+=f"({i},{j}),"
        return self.res

    #recursion
    def recur(self,n)->int:
        self.n=n
        if self.n==1:
            return 1
        self.res=self.recur(self.n-1)
        return self.n+self.res

    #tail recursion
    def tail_recur(self,n,res)->int:
        self.n=n
        self.res=res
        if(self.n==0):
            return self.res
        return self.tail_recur(self.n-1,self.res+self.n)

    #recursion tree
    def fibobacci(self,n)->int:
        if(n==1 or n==2):
            return n-1
        self.res=self.fibobacci(n-1)+self.fibobacci(n-2)
        return self.res
    
    #stack
    def for_loop_recur(self,n:int)->int:
        stack=[]
        res=0
        for i in range(n,0,-1):
            stack.append(i)
        while(stack):
            res+=stack.pop()
        return res
    
    def reset(self):
        self.n=0
        self.res=0

def main():
    basic=Basic()
    print(basic.for_loop(10))
    basic.reset()
    print(basic.while_loop(10))
    basic.reset()
    print(basic.while_loop_ii(10))
    basic.reset()
    print(basic.nested_for_loop(3))
    basic.reset()
    print(basic.recur(10))
    basic.reset()
    print(basic.tail_recur(10,0))
    basic.reset()
    print(basic.fibobacci(10))
    basic.reset()
    print(basic.for_loop_recur(10))
    basic.reset()

if __name__=='__main__':
    main()